/*
 * RCC.h
 *
 *  Created on: 4 Feb 2023
 *      Author: Omnia
 */

#ifndef RCC_H_
#define RCC_H_

typedef enum{
	RCC_enuOk,
	RCC_enuNok,
	RCC_enuNullPtr,
}RCC_enuErrorStatus_t;

typedef enum{
	RCC_enuTIM2,
	RCC_enuTIM3,
	RCC_enuTIM4,
	RCC_enuTIM5,
	RCC_enuWWDG   = 11,
	RCC_enuSPI2   = 14,
	RCC_enuSPI3,
	RCC_enuUSART2 = 17,
	RCC_enuISC1   = 21,
	RCC_enuISC2,
	RCC_enuISC3,
	RCC_enuPWR    = 28,
}RCC_enuAPB1_Peripharl_t;

typedef enum{
	RCC_enuTIM1,
	RCC_enuUSART1 = 4,
	RCC_enuUSART6,
	RCC_enuADC1   = 8,
	RCC_enuSDIO   = 11,
	RCC_enuSPI1,
	RCC_enuSPI4,
	RCC_enuSYSCFG,
	RCC_enuTIM9   = 16,
	RCC_enuTIM10,
	RCC_enuTIM11,
}RCC_enuAPB2_Peripharl_t;

typedef enum{
	RCC_enuGPIOA,
	RCC_enuGPIOB,
	RCC_enuGPIOC,
	RCC_enuGPIOD,
	RCC_enuGPIOE,
	RCC_enuGPIOH = 7,
	RCC_enuCRC   = 12,
	RCC_enuDMA1  = 21,
	RCC_enuDMA2,
}RCC_enuAHB1_Peripharl_t;

typedef enum{
	RCC_enuOTGFS = 7,
}RCC_enuAHB2_Peripharl_t;

typedef enum{
	RCC_enuHSI,
	RCC_enuHSE,
	RCC_enuPLL,
}RCC_enuPLLClockSource_t;

RCC_enuErrorStatus_t RCC_enuEnableHSE(void);

RCC_enuErrorStatus_t RCC_enuEnableHSI(void);

RCC_enuErrorStatus_t RCC_enuEnablePLL(void);

RCC_enuErrorStatus_t RCC_enuConfigurePLL(u16 Cpy_u16P_value, u16 Cpy_u16Q_value, u16 Cpy_u16M_value, u16 Cpy_u16N_value);

RCC_enuErrorStatus_t RCC_enuSelectPLLSource(RCC_enuPLLClockSource_t Cpy_enuClkSource);

RCC_enuErrorStatus_t RCC_enuDisableHSE(void);

RCC_enuErrorStatus_t RCC_enuDisableHSI(void);

RCC_enuErrorStatus_t RCC_enuDisablePLL(void);

RCC_enuErrorStatus_t RCC_enuAHBprescaler(u8 Cpy_u8Prescaler);

RCC_enuErrorStatus_t RCC_enuAPB1prescaler(u8 Cpy_u8Prescaler);

RCC_enuErrorStatus_t RCC_enuAPB2prescaler(u8 Cpy_u8Prescaler);

RCC_enuErrorStatus_t RCC_enuClockSelect(RCC_enuPLLClockSource_t Cpy_enuClkSource);

RCC_enuErrorStatus_t RCC_enuClockStatus(RCC_enuPLLClockSource_t Cpy_enuClkSource);

RCC_enuErrorStatus_t RCC_enuEnablePeriphalAPB1(RCC_enuAPB1_Peripharl_t Cpy_enuPeripharl);

RCC_enuErrorStatus_t RCC_enuEnablePeriphalAPB2(RCC_enuAPB2_Peripharl_t Cpy_enuPeripharl);

RCC_enuErrorStatus_t RCC_enuEnablePeriphalAHB1(RCC_enuAHB1_Peripharl_t Cpy_enuPeripharl);

RCC_enuErrorStatus_t RCC_enuEnablePeriphalAHB2(RCC_enuAHB2_Peripharl_t Cpy_enuPeripharl);

RCC_enuErrorStatus_t RCC_enuDisablePeriphalAPB1(RCC_enuAPB1_Peripharl_t Cpy_enuPeripharl);

RCC_enuErrorStatus_t RCC_enuDisablePeriphalAPB2(RCC_enuAPB2_Peripharl_t Cpy_enuPeripharl);

RCC_enuErrorStatus_t RCC_enuDisablePeriphalAHB1(RCC_enuAHB1_Peripharl_t Cpy_enuPeripharl);

RCC_enuErrorStatus_t RCC_enuDisablePeriphalAHB2(RCC_enuAHB2_Peripharl_t Cpy_enuPeripharl);

RCC_enuErrorStatus_t RCC_enuGetClockFrequency(u32* Add_u32Freq);

#endif /* RCC_H_ */
