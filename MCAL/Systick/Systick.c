/*
 * Systick.c
 *
 *  Created on: 25 Mar 2023
 *      Author: Omnia
 */
#include "Std_Types.h"
#include "Bit_Math.h"
#include "Systick_Piv.h"
#include "Systick_Cfg.h"
#include "Systick.h"
#include "RCC.h"

u32 STK_OV, STK_Count, STK_Reload;

void (*STK_cbf)(void) = NULL;

void STK_vidInit(void)
{
	u32 Loc_u32Temp = STK_CTRL;

	#if CLOCK_SOURCE == PRESCALER
		Loc_u32Temp &= ~(1<<CLKSOURCE);
	#elif CLOCK_SOURCE == NO_PRESCALER
		Loc_u32Temp |= (1<<CLKSOURCE);
	#endif

	#if EXCEPTION_REQ == ENABLE_REQ
		Loc_u32Temp |= (1<<TICKINT);
	#elif EXCEPTION_REQ == DISABLE_REQ
		Loc_u32Temp &= ~(1<<TICKINT);
	#endif

	STK_CTRL = Loc_u32Temp;
}

void STK_vidStart(void)
{
	u32 Loc_u32Temp = STK_CTRL;

	Loc_u32Temp |= (1<<ENABLE);

	STK_CTRL = Loc_u32Temp;
}

void STK_vidReloadCounter(u32 Cpy_u32ReloadValue)
{
	Cpy_u32ReloadValue &= RELOAD_MASK;

	STK_LOAD = Cpy_u32ReloadValue;

	/* clear current value */
	STK_VAL = 0;
}

STK_enuErrorStatus_t STK_enuGetCurrentValue(u32* Add_u32CurrentValue)
{
	STK_enuErrorStatus_t Loc_enuErrorStatus = STK_enuOk;

	if(Add_u32CurrentValue != NULL)
	{
		*Add_u32CurrentValue = STK_VAL;
	}
	else
	{
		Loc_enuErrorStatus = STK_enuNok;
	}

	return Loc_enuErrorStatus;
}

STK_enuErrorStatus_t STK_enuSetTickTime(u32 Cpy_u32TickTime)
{
	u32 F_CPU, OV_Time;
	f32 OV_Number;
	RCC_enuErrorStatus_t Loc_enuErrorStatusRCC;
	STK_enuErrorStatus_t Loc_enuErrorStatus = STK_enuOk;

	Cpy_u32TickTime *= 1000;

	Loc_enuErrorStatusRCC = RCC_enuGetClockFrequency(&F_CPU);

	if(Loc_enuErrorStatusRCC == RCC_enuOk)
	{
		/* calculate preload value */
		OV_Time = 16777216/F_CPU;
		OV_Number = (f32)Cpy_u32TickTime / OV_Time;
		STK_OV = (u32)Cpy_u32TickTime / OV_Time;
		OV_Number -= STK_OV;
		if(Cpy_u32TickTime > OV_Number)
		{
			if(OV_Number == 0)
			{
				STK_Reload = 16777215;
			}
			else
			{
				STK_OV++;
				STK_Reload = OV_Number * 16777216;
			}
		}
		else if(Cpy_u32TickTime < OV_Number)
		{
			STK_OV = (OV_Number*16777216)/OV_Time;
			STK_Reload = STK_OV;
		}
		else
		{
			STK_OV = 1;
			STK_Reload = 16777215;
		}
		STK_vidReloadCounter(STK_Reload);
	}
	else
	{
		Loc_enuErrorStatus = STK_enuNok;
	}

	return Loc_enuErrorStatus;
}

STK_enuErrorStatus_t STK_enuCBF(void (*Add_cbf)(void))
{
	STK_enuErrorStatus_t Loc_enuErrorStatus = STK_enuOk;

	if(Add_cbf != NULL)
	{
		STK_cbf = Add_cbf;
	}
	else
	{
		Loc_enuErrorStatus = STK_enuNok;
	}

	return Loc_enuErrorStatus;
}

void SysTick_Handler(void)
{
	STK_Count++;
	if(STK_Count == STK_OV)
	{
		if(STK_cbf != NULL)
		{
			STK_cbf();
		}
		STK_Count=0;
		STK_vidReloadCounter(STK_Reload);
	}
}
