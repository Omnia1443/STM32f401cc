/*
 * RCC.c
 *
 *  Created on: 4 Feb 2023
 *      Author: Omnia
 */

#include "Std_Types.h"
#include "Bit_Math.h"
#include "RCC.h"
#include "RCC_Piv.h"
#include "RCC_Cfg.h"

RCC_enuErrorStatus_t RCC_enuEnableHSE(void)
{
	u8 count = 255;
	RCC_enuErrorStatus_t Loc_enuErrorStatus = RCC_enuOk;

	RCC_CR |= RCC_HSE_ON;

	while(!(RCC_CR & RCC_HSE_RDY) && count)
	{
		count--;
	}

	if(count == 0)
	{
		Loc_enuErrorStatus = RCC_enuNok;
	}

	return Loc_enuErrorStatus;
}

RCC_enuErrorStatus_t RCC_enuEnableHSI(void)
{
	u8 count = 255;
	RCC_enuErrorStatus_t Loc_enuErrorStatus = RCC_enuOk;

	RCC_CR |= RCC_HSI_ON;

	while(!(RCC_CR & RCC_HSI_RDY) && count)
	{
		count--;
	}

	if(count == 0)
	{
		Loc_enuErrorStatus = RCC_enuNok;
	}

	return Loc_enuErrorStatus;
}

RCC_enuErrorStatus_t RCC_enuEnablePLL(void)
{
	u8 count = 255;
	RCC_enuErrorStatus_t Loc_enuErrorStatus = RCC_enuOk;

	RCC_CR |= RCC_PLL_ON;

	while(!(RCC_CR & RCC_PLL_RDY) && count)
	{
		count--;
	}

	if(count == 0)
	{
		Loc_enuErrorStatus = RCC_enuNok;
	}

	return Loc_enuErrorStatus;
}

RCC_enuErrorStatus_t RCC_enuDisableHSE(void)
{
	u8 count = 255;
	RCC_enuErrorStatus_t Loc_enuErrorStatus = RCC_enuOk;

	RCC_CR &= RCC_HSE_OFF;

	while((RCC_CR & RCC_HSI_RDY) && count)
	{
		count--;
	}

	if(count == 0)
	{
		Loc_enuErrorStatus = RCC_enuNok;
	}

	return Loc_enuErrorStatus;
}

RCC_enuErrorStatus_t RCC_enuDisableHSI(void)
{
	u8 count = 255;
	RCC_enuErrorStatus_t Loc_enuErrorStatus = RCC_enuOk;

	RCC_CR &= RCC_HSI_OFF;

	while((RCC_CR & RCC_HSI_RDY) && count)
	{
		count--;
	}

	if(count == 0)
	{
		Loc_enuErrorStatus = RCC_enuNok;
	}

	return Loc_enuErrorStatus;
}

RCC_enuErrorStatus_t RCC_enuDisablePLL(void)
{
	u8 count = 255;
	RCC_enuErrorStatus_t Loc_enuErrorStatus = RCC_enuOk;

	RCC_CR &= RCC_PLL_OFF;

	while((RCC_CR & RCC_HSI_RDY) && count)
	{
		count--;
	}

	if(count == 0)
	{
		Loc_enuErrorStatus = RCC_enuNok;
	}

	return Loc_enuErrorStatus;
}

RCC_enuErrorStatus_t RCC_enuAHBprescaler(u8 Cpy_u8Prescaler)
{
	RCC_enuErrorStatus_t Loc_enuErrorStatus = RCC_enuOk;
	u32 Loc_u32temp = RCC_CFGR;

	Loc_u32temp &= RCC_AHB_PRE_CLR;

	switch(Cpy_u8Prescaler)
	{
		case 1:  Loc_u32temp &= RCC_AHB_PRE_CLR;     break;
		case 2:  Loc_u32temp |= RCC_AHB_PRE_2;       break;
		case 4:  Loc_u32temp |= RCC_AHB_PRE_4;       break;
		case 8:  Loc_u32temp |= RCC_AHB_PRE_8;       break;
		case 16: Loc_u32temp |= RCC_AHB_PRE_16;      break;
		case 64: Loc_u32temp |= RCC_AHB_PRE_64;      break;
		case 128: Loc_u32temp |= RCC_AHB_PRE_128;    break;
		case 256: Loc_u32temp |= RCC_AHB_PRE_256;    break;
		case 512: Loc_u32temp |= RCC_AHB_PRE_512;    break;
		default: Loc_enuErrorStatus = RCC_enuNok;    break;
	}

	RCC_CFGR = Loc_u32temp;

	return Loc_enuErrorStatus;
}

RCC_enuErrorStatus_t RCC_enuAPB1prescaler(u8 Cpy_u8Prescaler)
{
	RCC_enuErrorStatus_t Loc_enuErrorStatus = RCC_enuOk;
	u32 Loc_u32temp = RCC_CFGR;

	Loc_u32temp &= RCC_APB1_PRE_CLR;

	switch(Cpy_u8Prescaler)
	{
		case 1:  Loc_u32temp &= RCC_APB1_PRE_CLR;  break;
		case 2:  Loc_u32temp |= RCC_APB1_PRE_2;    break;
		case 4:  Loc_u32temp |= RCC_APB1_PRE_4;    break;
		case 8:  Loc_u32temp |= RCC_APB1_PRE_8;    break;
		case 16: Loc_u32temp |= RCC_APB1_PRE_16;   break;
		default: Loc_enuErrorStatus = RCC_enuNok;  break;
	}

	RCC_CFGR = Loc_u32temp;

	return Loc_enuErrorStatus;
}

RCC_enuErrorStatus_t RCC_enuAPB2prescaler(u8 Cpy_u8Prescaler)
{
	RCC_enuErrorStatus_t Loc_enuErrorStatus = RCC_enuOk;

	u32 Loc_u32temp = RCC_CFGR;

	Loc_u32temp &= RCC_APB2_PRE_CLR;

	switch(Cpy_u8Prescaler)
	{
		case 1:  Loc_u32temp &= RCC_APB2_PRE_CLR;  break;
		case 2:  Loc_u32temp |= RCC_APB2_PRE_2;    break;
		case 4:  Loc_u32temp |= RCC_APB2_PRE_4;    break;
		case 8:  Loc_u32temp |= RCC_APB2_PRE_8;    break;
		case 16: Loc_u32temp |= RCC_APB2_PRE_16;   break;
		default: Loc_enuErrorStatus = RCC_enuNok;  break;
	}

	RCC_CFGR = Loc_u32temp;

	return Loc_enuErrorStatus;
}

RCC_enuErrorStatus_t RCC_enuClockSelect(RCC_enuPLLClockSource_t Cpy_enuClkSource)
{
	RCC_enuErrorStatus_t Loc_enuErrorStatus = RCC_enuOk;

	u32 Loc_u32temp = RCC_CFGR;

	Loc_u32temp &= RCC_SWITCH_CLR;

	switch(Cpy_enuClkSource)
	{
		case RCC_enuHSI:  Loc_u32temp |= RCC_SWITCH_HSI;    break;
		case RCC_enuHSE:  Loc_u32temp |= RCC_SWITCH_HSE;    break;
		case RCC_enuPLL:  Loc_u32temp |= RCC_SWITCH_PLL;    break;
		default:          Loc_enuErrorStatus = RCC_enuNok;  break;
	}

	RCC_CFGR = Loc_u32temp;

	return Loc_enuErrorStatus;
}

RCC_enuErrorStatus_t RCC_enuClockStatus(RCC_enuPLLClockSource_t Cpy_enuClkSource)
{
	RCC_enuErrorStatus_t Loc_enuErrorStatus = RCC_enuOk;

	u32 Loc_u32temp = RCC_CFGR;

	Loc_u32temp &= RCC_CHECK_MASK;

	switch(Cpy_enuClkSource)
	{
		case RCC_enuHSI:
			if(Loc_u32temp != RCC_CHECK_HSI)
		    {
				Loc_enuErrorStatus = RCC_enuNok;
		    }
			break;
		case RCC_enuHSE:
			if(Loc_u32temp != RCC_CHECK_HSE)
			{
				Loc_enuErrorStatus = RCC_enuNok;
			}
			break;
		case RCC_enuPLL:
			if(Loc_u32temp != RCC_CHECK_PLL)
			{
				Loc_enuErrorStatus = RCC_enuNok;
			}
			break;
		default:
			Loc_enuErrorStatus = RCC_enuNok;
			break;
	}

	return Loc_enuErrorStatus;
}

RCC_enuErrorStatus_t RCC_enuConfigurePLL(u16 Cpy_u16P_value, u16 Cpy_u16Q_value, u16 Cpy_u16M_value, u16 Cpy_u16N_value)
{
	u32 Loc_u32Val = RCC_PLLCFGR;

	RCC_enuErrorStatus_t Loc_enuErrorStatus = RCC_enuOk;

	Loc_u32Val &= 0xF0FC8000;

	if((Cpy_u16Q_value >= RCC_PLL_Q_MIN) && (Cpy_u16Q_value <= RCC_PLL_Q_MAX))
	{
		Loc_u32Val |= (Cpy_u16Q_value<<24);
	}
	else
	{
		Loc_enuErrorStatus = RCC_enuNok;
	}

	if((Cpy_u16P_value >= RCC_PLL_P_MIN) && (Cpy_u16P_value <= RCC_PLL_P_MAX))
	{
		Loc_u32Val |= (Cpy_u16P_value<<16);
	}
	else
	{
		Loc_enuErrorStatus = RCC_enuNok;
	}

	if((Cpy_u16N_value >= RCC_PLL_N_MIN) && (Cpy_u16N_value <= RCC_PLL_N_MAX) && (Cpy_u16N_value != RCC_PLL_N_WRONG))
	{
		Loc_u32Val |= (Cpy_u16N_value<<6);
	}
	else
	{
		Loc_enuErrorStatus = RCC_enuNok;
	}

	if((Cpy_u16M_value >= RCC_PLL_M_MIN) && (Cpy_u16M_value <= RCC_PLL_M_MAX))
	{
		Loc_u32Val |= Cpy_u16M_value;
	}
	else
	{
		Loc_enuErrorStatus = RCC_enuNok;
	}

	RCC_PLLCFGR = Loc_u32Val;

	return Loc_enuErrorStatus;
}

RCC_enuErrorStatus_t RCC_enuSelectPLLSource(RCC_enuPLLClockSource_t Cpy_enuClkSource)
{
	RCC_enuErrorStatus_t Loc_enuErrorStatus = RCC_enuOk;

	switch(Cpy_enuClkSource)
	{
		case RCC_enuHSI: RCC_PLLCFGR &= ~(1<<22); break;
		case RCC_enuHSE: RCC_PLLCFGR |= (1<<22);  break;
		default: Loc_enuErrorStatus = RCC_enuNok; break;
	}

	return Loc_enuErrorStatus;
}

RCC_enuErrorStatus_t RCC_enuEnablePeriphalAPB1(RCC_enuAPB1_Peripharl_t Cpy_enuPeripharl)
{
	RCC_enuErrorStatus_t Loc_enuErrorStatus = RCC_enuOk;

	if((Cpy_enuPeripharl >= RCC_enuTIM2) && (Cpy_enuPeripharl <= RCC_enuPWR))
	{
		RCC_APB1ENR |= (1<<Cpy_enuPeripharl);
	}
	else
	{
		Loc_enuErrorStatus = RCC_enuNok;
	}

	return Loc_enuErrorStatus;
}

RCC_enuErrorStatus_t RCC_enuEnablePeriphalAPB2(RCC_enuAPB2_Peripharl_t Cpy_enuPeripharl)
{
	RCC_enuErrorStatus_t Loc_enuErrorStatus = RCC_enuOk;

	if((Cpy_enuPeripharl >= RCC_enuTIM1) && (Cpy_enuPeripharl <= RCC_enuTIM11))
	{
		RCC_APB2ENR |= (1<<Cpy_enuPeripharl);
	}
	else
	{
		Loc_enuErrorStatus = RCC_enuNok;
	}

	return Loc_enuErrorStatus;
}

RCC_enuErrorStatus_t RCC_enuEnablePeriphalAHB1(RCC_enuAHB1_Peripharl_t Cpy_enuPeripharl)
{
	RCC_enuErrorStatus_t Loc_enuErrorStatus = RCC_enuOk;

	if((Cpy_enuPeripharl >= RCC_enuGPIOA) && (Cpy_enuPeripharl <= RCC_enuDMA2))
	{
		RCC_AHB1ENR |= (1<<Cpy_enuPeripharl);
	}
	else
	{
		Loc_enuErrorStatus = RCC_enuNok;
	}

	return Loc_enuErrorStatus;
}

RCC_enuErrorStatus_t RCC_enuEnablePeriphalAHB2(RCC_enuAHB2_Peripharl_t Cpy_enuPeripharl)
{
	RCC_enuErrorStatus_t Loc_enuErrorStatus = RCC_enuOk;

	if(Cpy_enuPeripharl == RCC_enuOTGFS)
	{
		RCC_AHB2ENR |= (1<<Cpy_enuPeripharl);
	}
	else
	{
		Loc_enuErrorStatus = RCC_enuNok;
	}

	return Loc_enuErrorStatus;
}

RCC_enuErrorStatus_t RCC_enuDisablePeriphalAPB1(RCC_enuAPB1_Peripharl_t Cpy_enuPeripharl)
{
	RCC_enuErrorStatus_t Loc_enuErrorStatus = RCC_enuOk;

	if((Cpy_enuPeripharl >= RCC_enuTIM2) && (Cpy_enuPeripharl <= RCC_enuPWR))
	{
		RCC_APB1ENR &= ~(1<<Cpy_enuPeripharl);
	}
	else
	{
		Loc_enuErrorStatus = RCC_enuNok;
	}

	return Loc_enuErrorStatus;
}

RCC_enuErrorStatus_t RCC_enuDisablePeriphalAPB2(RCC_enuAPB2_Peripharl_t Cpy_enuPeripharl)
{
	RCC_enuErrorStatus_t Loc_enuErrorStatus = RCC_enuOk;

	if((Cpy_enuPeripharl >= RCC_enuTIM1) && (Cpy_enuPeripharl <= RCC_enuTIM11))
	{
		RCC_APB2ENR &= ~(1<<Cpy_enuPeripharl);
	}
	else
	{
		Loc_enuErrorStatus = RCC_enuNok;
	}

	return Loc_enuErrorStatus;
}

RCC_enuErrorStatus_t RCC_enuDisablePeriphalAHB1(RCC_enuAHB1_Peripharl_t Cpy_enuPeripharl)
{
	RCC_enuErrorStatus_t Loc_enuErrorStatus = RCC_enuOk;

	if((Cpy_enuPeripharl >= RCC_enuGPIOA) && (Cpy_enuPeripharl <= RCC_enuDMA2))
	{
		RCC_AHB1ENR &= ~(1<<Cpy_enuPeripharl);
	}
	else
	{
		Loc_enuErrorStatus = RCC_enuNok;
	}

	return Loc_enuErrorStatus;
}

RCC_enuErrorStatus_t RCC_enuDisablePeriphalAHB2(RCC_enuAHB2_Peripharl_t Cpy_enuPeripharl)
{
	RCC_enuErrorStatus_t Loc_enuErrorStatus = RCC_enuOk;

	if(Cpy_enuPeripharl == RCC_enuOTGFS)
	{
		RCC_AHB2ENR &= ~(1<<Cpy_enuPeripharl);
	}
	else
	{
		Loc_enuErrorStatus = RCC_enuNok;
	}

	return Loc_enuErrorStatus;
}

RCC_enuErrorStatus_t RCC_enuGetClockFrequency(u32* Add_u32Freq)
{
	RCC_enuErrorStatus_t Loc_enuClockSourceStatus;
	RCC_enuErrorStatus_t Loc_enuErrorStatus = RCC_enuOk;

	if(Add_u32Freq != NULL)
	{
		Loc_enuClockSourceStatus = RCC_enuClockStatus(RCC_enuHSI);
		if(Loc_enuClockSourceStatus == RCC_enuOk)
		{
			*Add_u32Freq = 16;
		}
		else
		{
			Loc_enuClockSourceStatus = RCC_enuClockStatus(RCC_enuHSE);
			if(Loc_enuClockSourceStatus == RCC_enuOk)
			{
				*Add_u32Freq = 24;
			}
			else
			{
				Loc_enuClockSourceStatus = RCC_enuClockStatus(RCC_enuPLL);
				if(Loc_enuClockSourceStatus == RCC_enuOk)
				{
					if(RCC_PLLCFGR & (1<<22))
					{
						*Add_u32Freq = ((24 * (RCC_PLLCFGR & RCC_PLLN_MASK))/(RCC_PLLCFGR & RCC_PLLM_MASK))/(RCC_PLLCFGR & RCC_PLLP_MASK);
					}
					else
					{
						*Add_u32Freq = 16;
					}
				}
				else
				{
					Loc_enuErrorStatus = RCC_enuNok;
				}
			}
		}
	}
	else
	{
		Loc_enuErrorStatus = RCC_enuNok;
	}

	return Loc_enuErrorStatus;
}
