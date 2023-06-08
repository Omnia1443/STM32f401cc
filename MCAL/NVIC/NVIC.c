/*
 * NVIC.c
 *
 *  Created on: 21 Mar 2023
 *      Author: Omnia
 */
#include "Std_Types.h"
#include "Bit_Math.h"
#include "NVIC_Piv.h"
#include "NVIC_Cfg.h"
#include "NVIC.h"

u8 IPR[84];

NVIC_enuErrorStatus_t NVIC_enuSetEnable(NVIC_enuIRQ_t Cpy_enuIRQ)
{
	NVIC_enuErrorStatus_t Loc_enuErrorStatus = NVIC_enuOk;

	if((Cpy_enuIRQ >= NVIC_enuWWDG) && (Cpy_enuIRQ <= NVIC_enuI2C1_EV))
	{
		NVIC_ISER0 = (1<<Cpy_enuIRQ);
	}
	else if((Cpy_enuIRQ >= NVIC_enuI2C1_ER) && (Cpy_enuIRQ <= NVIC_enuDMA2_Stream4))
	{
		NVIC_ISER1 = (1<<(Cpy_enuIRQ-32));
	}
	else if((Cpy_enuIRQ >= NVIC_enuOTG_FS) && (Cpy_enuIRQ <= NVIC_enuSPI4))
	{
		NVIC_ISER2 = (1<<(Cpy_enuIRQ-64));
	}
	else
	{
		Loc_enuErrorStatus = NVIC_enuNok;
	}

	return Loc_enuErrorStatus;
}

NVIC_enuErrorStatus_t NVIC_enuClearEnable(NVIC_enuIRQ_t Cpy_enuIRQ)
{
	NVIC_enuErrorStatus_t Loc_enuErrorStatus = NVIC_enuOk;

	if((Cpy_enuIRQ >= NVIC_enuWWDG) && (Cpy_enuIRQ <= NVIC_enuI2C1_EV))
	{
		NVIC_ICER0 = (1<<Cpy_enuIRQ);
	}
	else if((Cpy_enuIRQ >= NVIC_enuI2C1_ER) && (Cpy_enuIRQ <= NVIC_enuDMA2_Stream4))
	{
		NVIC_ICER1 = (1<<(Cpy_enuIRQ-32));
	}
	else if((Cpy_enuIRQ >= NVIC_enuOTG_FS) && (Cpy_enuIRQ <= NVIC_enuSPI4))
	{
		NVIC_ICER2 = (1<<(Cpy_enuIRQ-64));
	}
	else
	{
		Loc_enuErrorStatus = NVIC_enuNok;
	}

	return Loc_enuErrorStatus;
}

NVIC_enuErrorStatus_t NVIC_enuSetPending(NVIC_enuIRQ_t Cpy_enuIRQ)
{
	NVIC_enuErrorStatus_t Loc_enuErrorStatus = NVIC_enuOk;

	if((Cpy_enuIRQ >= NVIC_enuWWDG) && (Cpy_enuIRQ <= NVIC_enuI2C1_EV))
	{
		NVIC_ISPR0 = (1<<Cpy_enuIRQ);
	}
	else if((Cpy_enuIRQ >= NVIC_enuI2C1_ER) && (Cpy_enuIRQ <= NVIC_enuDMA2_Stream4))
	{
		NVIC_ISPR1 = (1<<(Cpy_enuIRQ-32));
	}
	else if((Cpy_enuIRQ >= NVIC_enuOTG_FS) && (Cpy_enuIRQ <= NVIC_enuSPI4))
	{
		NVIC_ISPR2 = (1<<(Cpy_enuIRQ-64));
	}
	else
	{
		Loc_enuErrorStatus = NVIC_enuNok;
	}

	return Loc_enuErrorStatus;
}

NVIC_enuErrorStatus_t NVIC_enuClearPending(NVIC_enuIRQ_t Cpy_enuIRQ)
{
	NVIC_enuErrorStatus_t Loc_enuErrorStatus = NVIC_enuOk;

	if((Cpy_enuIRQ >= NVIC_enuWWDG) && (Cpy_enuIRQ <= NVIC_enuI2C1_EV))
	{
		NVIC_ICPR0 = (1<<Cpy_enuIRQ);
	}
	else if((Cpy_enuIRQ >= NVIC_enuI2C1_ER) && (Cpy_enuIRQ <= NVIC_enuDMA2_Stream4))
	{
		NVIC_ICPR1 = (1<<(Cpy_enuIRQ-32));
	}
	else if((Cpy_enuIRQ >= NVIC_enuOTG_FS) && (Cpy_enuIRQ <= NVIC_enuSPI4))
	{
		NVIC_ICPR2 = (1<<(Cpy_enuIRQ-64));
	}
	else
	{
		Loc_enuErrorStatus = NVIC_enuNok;
	}

	return Loc_enuErrorStatus;
}

NVIC_enuErrorStatus_t NVIC_enuGetPending(NVIC_enuIRQ_t Cpy_enuIRQ, NVIC_enuPendingState_t* Add_enuValue)
{
	NVIC_enuErrorStatus_t Loc_enuErrorStatus = NVIC_enuOk;

	if(Add_enuValue != NULL)
	{
		if((Cpy_enuIRQ >= NVIC_enuWWDG) && (Cpy_enuIRQ <= NVIC_enuI2C1_EV))
		{
			if(NVIC_ISPR0 & (1<<Cpy_enuIRQ))
			{
				*Add_enuValue = NVIC_enuPending;
			}
			else
			{
				*Add_enuValue = NVIC_enuNoPending;
			}
		}
		else if((Cpy_enuIRQ >= NVIC_enuI2C1_ER) && (Cpy_enuIRQ <= NVIC_enuDMA2_Stream4))
		{
			if(NVIC_ISPR1 & (1<<(Cpy_enuIRQ-32)))
			{
				*Add_enuValue = NVIC_enuPending;
			}
			else
			{
				*Add_enuValue = NVIC_enuNoPending;
			}
		}
		else if((Cpy_enuIRQ >= NVIC_enuOTG_FS) && (Cpy_enuIRQ <= NVIC_enuSPI4))
		{
			if(NVIC_ISPR2 & (1<<(Cpy_enuIRQ-64)))
			{
				*Add_enuValue = NVIC_enuPending;
			}
			else
			{
				*Add_enuValue = NVIC_enuNoPending;
			}
		}
		else
		{
			Loc_enuErrorStatus = NVIC_enuNok;
		}
	}
	else
	{
		Loc_enuErrorStatus = NVIC_enuNullPtr;
	}

	return Loc_enuErrorStatus;
}

NVIC_enuErrorStatus_t NVIC_enuSetPriorityGrouping(NVIC_enuGroupPriority_t Cpy_enuPriorityGrouping)
{
	NVIC_enuErrorStatus_t Loc_enuErrorStatus = NVIC_enuOk;

	switch(Cpy_enuPriorityGrouping)
	{
		case NVIC_enuGroup4bits: AIRCR = NVIC_GROUPING4; break;
		case NVIC_enuGroup3bits: AIRCR = NVIC_GROUPING3; break;
		case NVIC_enuGroup2bits: AIRCR = NVIC_GROUPING2; break;
		case NVIC_enuGroup1bit:  AIRCR = NVIC_GROUPING1; break;
		case NVIC_enuGroup0bit:  AIRCR = NVIC_GROUPING0; break;
		default: Loc_enuErrorStatus = NVIC_enuNok; 		 break;
	}

	return Loc_enuErrorStatus;
}

NVIC_enuErrorStatus_t NVIC_enuSetPriority(NVIC_enuIRQ_t Cpy_enuIRQ, u8 Cpy_u8PriorityNumber)
{
	NVIC_enuErrorStatus_t Loc_enuErrorStatus = NVIC_enuOk;

	if((Cpy_enuIRQ >= NVIC_enuWWDG) && (Cpy_enuIRQ <= NVIC_enuEXTI1))
	{
		NVIC_IPR0 = Cpy_u8PriorityNumber;
	}
	else if((Cpy_enuIRQ >= NVIC_enuEXTI2) && (Cpy_enuIRQ <= NVIC_enuDMA1_Stream4))
	{
		NVIC_IPR0 = Cpy_u8PriorityNumber << 8;
	}
	else if((Cpy_enuIRQ >= NVIC_enuDMA1_Stream5) && (Cpy_enuIRQ <= NVIC_enuEXTI9))
	{
		NVIC_IPR0 = Cpy_u8PriorityNumber << 16;
	}
	else if((Cpy_enuIRQ >= NVIC_enuTIM1_BRK_TIM9) && (Cpy_enuIRQ <= NVIC_enuI2C1_EV))
	{
		NVIC_IPR0 = Cpy_u8PriorityNumber << 24;
	}
	else if((Cpy_enuIRQ >= NVIC_enuI2C1_ER) && (Cpy_enuIRQ <= NVIC_enuUSART2))
	{
		NVIC_IPR1 = Cpy_u8PriorityNumber;
	}
	else if((Cpy_enuIRQ >= NVIC_enuEXTI15) && (Cpy_enuIRQ <= NVIC_enuDMA1_Stream7))
	{
		NVIC_IPR1 = Cpy_u8PriorityNumber << 8;
	}
	else if((Cpy_enuIRQ >= NVIC_enuSDIO) && (Cpy_enuIRQ <= NVIC_enuSPI3))
	{
		NVIC_IPR1 = Cpy_u8PriorityNumber << 16;
	}
	else if((Cpy_enuIRQ >= NVIC_enuDMA2_Stream0) && (Cpy_enuIRQ <= NVIC_enuDMA2_Stream4))
	{
		NVIC_IPR1 = Cpy_u8PriorityNumber << 24;
	}
	else if((Cpy_enuIRQ >= NVIC_enuOTG_FS) && (Cpy_enuIRQ <= NVIC_enuUSART6))
	{
		NVIC_IPR2 = Cpy_u8PriorityNumber;
	}
	else if((Cpy_enuIRQ >= NVIC_enuUSART6) && (Cpy_enuIRQ <= NVIC_enuI2C3_ER))
	{
		NVIC_IPR2 = Cpy_u8PriorityNumber << 8;
	}
	else if((Cpy_enuIRQ >= NVIC_enuFPU) && (Cpy_enuIRQ <= NVIC_enuSPI4))
	{
		NVIC_IPR2 = Cpy_u8PriorityNumber << 16;
	}
	else
	{
		Loc_enuErrorStatus = NVIC_enuNok;
	}

	return Loc_enuErrorStatus;
}

NVIC_enuErrorStatus_t NVIC_enuGetPriority(NVIC_enuIRQ_t Cpy_enuIRQ, u8* Add_u8PriorityNumber)
{
	NVIC_enuErrorStatus_t Loc_enuErrorStatus = NVIC_enuOk;

	if(Add_u8PriorityNumber != NULL)
	{
		if((Cpy_enuIRQ >= NVIC_enuWWDG) && (Cpy_enuIRQ <= NVIC_enuEXTI1))
		{
			*Add_u8PriorityNumber = NVIC_IPR0;
		}
		else if((Cpy_enuIRQ >= NVIC_enuEXTI2) && (Cpy_enuIRQ <= NVIC_enuDMA1_Stream4))
		{
			*Add_u8PriorityNumber = NVIC_IPR0 >> 8;
		}
		else if((Cpy_enuIRQ >= NVIC_enuDMA1_Stream5) && (Cpy_enuIRQ <= NVIC_enuEXTI9))
		{
			*Add_u8PriorityNumber = NVIC_IPR0 >> 16;
		}
		else if((Cpy_enuIRQ >= NVIC_enuTIM1_BRK_TIM9) && (Cpy_enuIRQ <= NVIC_enuI2C1_EV))
		{
			*Add_u8PriorityNumber = NVIC_IPR0 >> 24;
		}
		else if((Cpy_enuIRQ >= NVIC_enuI2C1_ER) && (Cpy_enuIRQ <= NVIC_enuUSART2))
		{
			*Add_u8PriorityNumber = NVIC_IPR1;
		}
		else if((Cpy_enuIRQ >= NVIC_enuEXTI15) && (Cpy_enuIRQ <= NVIC_enuDMA1_Stream7))
		{
			*Add_u8PriorityNumber = NVIC_IPR1 >> 8;
		}
		else if((Cpy_enuIRQ >= NVIC_enuSDIO) && (Cpy_enuIRQ <= NVIC_enuSPI3))
		{
			*Add_u8PriorityNumber = NVIC_IPR1 >> 16;
		}
		else if((Cpy_enuIRQ >= NVIC_enuDMA2_Stream0) && (Cpy_enuIRQ <= NVIC_enuDMA2_Stream4))
		{
			*Add_u8PriorityNumber = NVIC_IPR1 >> 24;
		}
		else if((Cpy_enuIRQ >= NVIC_enuOTG_FS) && (Cpy_enuIRQ <= NVIC_enuUSART6))
		{
			*Add_u8PriorityNumber = NVIC_IPR2;
		}
		else if((Cpy_enuIRQ >= NVIC_enuUSART6) && (Cpy_enuIRQ <= NVIC_enuI2C3_ER))
		{
			*Add_u8PriorityNumber = NVIC_IPR2 >> 8;
		}
		else if((Cpy_enuIRQ >= NVIC_enuFPU) && (Cpy_enuIRQ <= NVIC_enuSPI4))
		{
			*Add_u8PriorityNumber = NVIC_IPR2 >> 16;
		}
		else
		{
			Loc_enuErrorStatus = NVIC_enuNok;
		}
	}
	else
	{
		Loc_enuErrorStatus = NVIC_enuNullPtr;
	}

	return Loc_enuErrorStatus;
}

NVIC_enuErrorStatus_t NVIC_enuGetActiveStatus(NVIC_enuIRQ_t Cpy_enuIRQ, NVIC_enuStatus_t* Add_enuStatus)
{
	NVIC_enuErrorStatus_t Loc_enuErrorStatus = NVIC_enuOk;

	if(Add_enuStatus != NULL)
	{
		if((Cpy_enuIRQ >= NVIC_enuWWDG) && (Cpy_enuIRQ <= NVIC_enuI2C1_EV))
		{
			if(NVIC_IABR0 & (1<<Cpy_enuIRQ))
			{
				*Add_enuStatus = NVIC_enuActive;
			}
			else
			{
				*Add_enuStatus = NVIC_enuNotActive;
			}
		}
		else if((Cpy_enuIRQ >= NVIC_enuI2C1_ER) && (Cpy_enuIRQ <= NVIC_enuDMA2_Stream4))
		{
			if(NVIC_IABR1 & (1<<(Cpy_enuIRQ-32)))
			{
				*Add_enuStatus = NVIC_enuActive;
			}
			else
			{
				*Add_enuStatus = NVIC_enuNotActive;
			}
		}
		else if((Cpy_enuIRQ >= NVIC_enuOTG_FS) && (Cpy_enuIRQ <= NVIC_enuSPI4))
		{
			if(NVIC_IABR2 & (1<<(Cpy_enuIRQ-64)))
			{
				*Add_enuStatus = NVIC_enuActive;
			}
			else
			{
				*Add_enuStatus = NVIC_enuNotActive;
			}
		}
		else
		{
			Loc_enuErrorStatus = NVIC_enuNok;
		}
	}
	else
	{
		Loc_enuErrorStatus = NVIC_enuNullPtr;
	}

	return Loc_enuErrorStatus;
}
