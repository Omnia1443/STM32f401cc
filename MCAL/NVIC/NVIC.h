/*
 * NVIC.h
 *
 *  Created on: 21 Mar 2023
 *      Author: Omnia
 */

#ifndef NVIC_H_
#define NVIC_H_


typedef enum{
	NVIC_enuOk,
	NVIC_enuNok,
	NVIC_enuNullPtr,
}NVIC_enuErrorStatus_t;

typedef enum{
	NVIC_enuWWDG,
	NVIC_enuEXTI16,
	NVIC_enuEXTI21,
	NVIC_enuEXTI22,
	NVIC_enuFLASH,
	NVIC_enuRCC,
	NVIC_enuEXTI0,
	NVIC_enuEXTI1,
	NVIC_enuEXTI2,
	NVIC_enuEXTI3,
	NVIC_enuEXTI4,
	NVIC_enuDMA1_Stream0,
	NVIC_enuDMA1_Stream1,
	NVIC_enuDMA1_Stream2,
	NVIC_enuDMA1_Stream3,
	NVIC_enuDMA1_Stream4,
	NVIC_enuDMA1_Stream5,
	NVIC_enuDMA1_Stream6,
	NVIC_enuADC,
	NVIC_enuEXTI9 = 23,
	NVIC_enuTIM1_BRK_TIM9,
	NVIC_enuTIM1_UP_TIM10,
	NVIC_enuTIM1_TRG_COM_TIM11,
	NVIC_enuTIM1_CC,
	NVIC_enuTIM2,
	NVIC_enuTIM3,
	NVIC_enuTIM4,
	NVIC_enuI2C1_EV,
	NVIC_enuI2C1_ER,
	NVIC_enuI2C2_EV,
	NVIC_enuI2C2_ER,
	NVIC_enuSPI1,
	NVIC_enuSPI2,
	NVIC_enuUSART1,
	NVIC_enuUSART2,
	NVIC_enuEXTI15 = 40,
	NVIC_enuEXTI17,
	NVIC_enuEXTI18,
	NVIC_enuDMA1_Stream7 = 47,
	NVIC_enuSDIO = 49,
	NVIC_enuTIM5,
	NVIC_enuSPI3,
	NVIC_enuDMA2_Stream0 = 56,
	NVIC_enuDMA2_Stream1,
	NVIC_enuDMA2_Stream2,
	NVIC_enuDMA2_Stream3,
	NVIC_enuDMA2_Stream4,
	NVIC_enuOTG_FS = 67,
	NVIC_enuDMA2_Stream5,
	NVIC_enuDMA2_Stream6,
	NVIC_enuDMA2_Stream7,
	NVIC_enuUSART6,
	NVIC_enuI2C3_EV,
	NVIC_enuI2C3_ER,
	NVIC_enuFPU = 81,
	NVIC_enuSPI4 = 84,
}NVIC_enuIRQ_t;

typedef enum{
	NVIC_enuPending,
	NVIC_enuNoPending,
}NVIC_enuPendingState_t;

typedef enum{
	NVIC_enuActive,
	NVIC_enuNotActive,
}NVIC_enuStatus_t;

typedef enum{
	NVIC_enuGroup4bits,
	NVIC_enuGroup3bits,
	NVIC_enuGroup2bits,
	NVIC_enuGroup1bit,
	NVIC_enuGroup0bit,
}NVIC_enuGroupPriority_t;

NVIC_enuErrorStatus_t NVIC_enuSetEnable(NVIC_enuIRQ_t Cpy_enuIRQ);

NVIC_enuErrorStatus_t NVIC_enuClearEnable(NVIC_enuIRQ_t Cpy_enuIRQ);

NVIC_enuErrorStatus_t NVIC_enuSetPending(NVIC_enuIRQ_t Cpy_enuIRQ);

NVIC_enuErrorStatus_t NVIC_enuClearPending(NVIC_enuIRQ_t Cpy_enuIRQ);

NVIC_enuErrorStatus_t NVIC_enuGetPending(NVIC_enuIRQ_t Cpy_enuIRQ, NVIC_enuPendingState_t* Add_enuValue);

NVIC_enuErrorStatus_t NVIC_enuSetPriorityGrouping(NVIC_enuGroupPriority_t Cpy_enuPriorityGrouping);

NVIC_enuErrorStatus_t NVIC_enuSetPriority(NVIC_enuIRQ_t Cpy_enuIRQ, u8 Cpy_u8PriorityNumber);

NVIC_enuErrorStatus_t NVIC_enuGetPriority(NVIC_enuIRQ_t Cpy_enuIRQ, u8* Add_u8PriorityNumber);

NVIC_enuErrorStatus_t NVIC_enuGetActiveStatus(NVIC_enuIRQ_t Cpy_enuIRQ, NVIC_enuStatus_t* Add_enuStatus);




#endif /* NVIC_H_ */
