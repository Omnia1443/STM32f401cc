/*
 * UART.c
 *
 *  Created on: 14 Apr 2023
 *      Author: Omnia
 */

#include "Std_Types.h"
#include "Bit_Math.h"
#include "UART_Piv.h"
#include "UART_Cfg.h"
#include "UART.h"
#include "RCC.h"
#include "GPIO.h"
#include "NVIC.h"

u8 UART_TXData1, UART_RXData1, UART_TXData2, UART_RXData2, UART_TXData6, UART_RXData6;

void UART1_vidInit(void)
{
	/* Enable peripheral clock */
	RCC_enuEnablePeriphalAPB2(RCC_enuUSART1);

	/* Initialise GPIO TX pin */
	GPIO_enuInit(GPIO_enuPortB,GPIO_enuPin6,GPIO_enuAltFunPushPull);
	GPIO_enuSetAlternativeFunction(GPIO_enuPortB,GPIO_enuPin6,GPIO_enuAF7);
	/* Initialise GPIO RX pin */
	GPIO_enuInit(GPIO_enuPortB,GPIO_enuPin7,GPIO_enuAltFunOpenDrain);
	GPIO_enuSetAlternativeFunction(GPIO_enuPortB,GPIO_enuPin7,GPIO_enuAF7);

	/* Enable interrupts in NVIC */
	NVIC_enuSetEnable(NVIC_enuUSART1);

	/* 8 data bits */
	CLR_BIT(UART1_CR1,M);

	/* configure baud rate */
#if BAUD_RATE1 == 9600
	UART1_BRR = UART_BRR_MASK & 0x00000683;
#elif BAUD_RATE1 == 115200
	UART1_BRR = UART_BRR_MASK & 0x0000008B;
#endif

#if PARITY1 == ENABLE
	SET_BIT(UART1_CR1,PCE);
#elif PARITY1 == DISABLE
	CLR_BIT(UART1_CR1,PCE);
#endif

#if PARITY_MODE1 == EVEN
	CLR_BIT(UART1_CR1,PS);
#elif PARITY_MODE1 == ODD
	SET_BIT(UART1_CR1,PS);
#endif

#if STOP_BIT1 == 1
	UART1_CR2 &= ONE_STOP;
#elif STOP_BIT1 == 2
	UART1_CR2 &= ONE_STOP;
	UART1_CR2 |= TWO_STOP;
#endif

#if CLK_POLARITY1 == LOW
	CLR_BIT(UART1_CR2,CPOL);
#elif CLK_POLARITY1 == HIGH
	SET_BIT(UART1_CR2,CPOL);
#endif

#if CLK_PHASE1 == FIRST
	CLR_BIT(UART1_CR2,CPHA);
#elif CLK_PHASE1 == SECOND
	SET_BIT(UART1_CR2,CPHA);
#endif

	/* enable receiver */
	SET_BIT(UART1_CR1,RE);
	/* enable transmitter */
	SET_BIT(UART1_CR1,TE);
	/* enable UART */
	SET_BIT(UART1_CR1,UE);

	/* Clear status Register */
	UART1_SR &= UART_CLR_SR;

	/* Enable interrupts */
	SET_BIT(UART1_CR1,RXNEIE);
	SET_BIT(UART1_CR1,TCIE);
	SET_BIT(UART1_CR1,TXEIE);
}

UART_enuErrorStatus_t UART1_enuSend(u8 Cpy_u8Data)
{
	UART_enuErrorStatus_t Loc_enuErrorStatus = UART_enuOk;

	UART_TXData1 = Cpy_u8Data;

	return Loc_enuErrorStatus;
}

UART_enuErrorStatus_t UART1_enuRecieve(u8* Add_pu8Data)
{
	UART_enuErrorStatus_t Loc_enuErrorStatus = UART_enuOk;

	if(Add_pu8Data != NULL)
	{
		*Add_pu8Data = UART_RXData1;
	}
	else
	{
		Loc_enuErrorStatus = UART_enuNullPtr;
	}

	return Loc_enuErrorStatus;
}

void UART2_vidInit(void)
{
	/* Enable peripheral clock */
	RCC_enuEnablePeriphalAPB1(RCC_enuUSART2);

	/* Initialise GPIO TX pin */
	GPIO_enuInit(GPIO_enuPortA,GPIO_enuPin2,GPIO_enuAltFunPushPull);
	GPIO_enuSetAlternativeFunction(GPIO_enuPortA,GPIO_enuPin2,GPIO_enuAF7);
	/* Initialise GPIO RX pin */
	GPIO_enuInit(GPIO_enuPortA,GPIO_enuPin3,GPIO_enuAltFunOpenDrain);
	GPIO_enuSetAlternativeFunction(GPIO_enuPortA,GPIO_enuPin3,GPIO_enuAF7);

	/* Enable interrupts in NVIC */
	NVIC_enuSetEnable(NVIC_enuUSART2);

	/* 8 data bits */
	CLR_BIT(UART2_CR1,M);

	/* configure baud rate */
#if BAUD_RATE2 == 9600
	UART2_BRR = UART_BRR_MASK & 0x00000683;
#elif BAUD_RATE2 == 115200
	UART2_BRR = UART_BRR_MASK & 0x0000008B;
#endif

#if PARITY2 == ENABLE
	SET_BIT(UART2_CR1,PCE);
#elif PARITY2 == DISABLE
	CLR_BIT(UART2_CR1,PCE);
#endif

#if PARITY_MODE2 == EVEN
	CLR_BIT(UART2_CR1,PS);
#elif PARITY_MODE2 == ODD
	SET_BIT(UART2_CR1,PS);
#endif

#if STOP_BIT2 == 1
	UART2_CR2 &= ONE_STOP;
#elif STOP_BIT2 == 2
	UART2_CR2 &= ONE_STOP;
	UART2_CR2 |= TWO_STOP;
#endif

#if CLK_POLARITY2 == LOW
	CLR_BIT(UART2_CR2,CPOL);
#elif CLK_POLARITY2 == HIGH
	SET_BIT(UART2_CR2,CPOL);
#endif

#if CLK_PHASE2 == FIRST
	CLR_BIT(UART2_CR2,CPHA);
#elif CLK_PHASE2 == SECOND
	SET_BIT(UART2_CR2,CPHA);
#endif

	/* enable receiver */
	SET_BIT(UART2_CR1,RE);
	/* enable transmitter */
	SET_BIT(UART2_CR1,TE);
	/* enable UART */
	SET_BIT(UART2_CR1,UE);

	/* Clear status Register */
	UART2_SR &= UART_CLR_SR;

	/* Enable interrupts */
	SET_BIT(UART2_CR1,RXNEIE);
	SET_BIT(UART2_CR1,TCIE);
	SET_BIT(UART2_CR1,TXEIE);
}

UART_enuErrorStatus_t UART2_enuSend(u8 Cpy_u8Data)
{
	UART_enuErrorStatus_t Loc_enuErrorStatus = UART_enuOk;

	UART_TXData2 = Cpy_u8Data;

	return Loc_enuErrorStatus;
}

UART_enuErrorStatus_t UART2_enuRecieve(u8* Add_pu8Data)
{
	UART_enuErrorStatus_t Loc_enuErrorStatus = UART_enuOk;

	if(Add_pu8Data != NULL)
	{
		*Add_pu8Data = UART_RXData2;
	}
	else
	{
		Loc_enuErrorStatus = UART_enuNullPtr;
	}

	return Loc_enuErrorStatus;
}

void UART6_vidInit(void)
{
	/* Enable peripheral clock */
	RCC_enuEnablePeriphalAPB2(RCC_enuUSART6);

	/* Initialise GPIO TX pin */
	GPIO_enuInit(GPIO_enuPortA,GPIO_enuPin11,GPIO_enuAltFunPushPull);
	GPIO_enuSetAlternativeFunction(GPIO_enuPortA,GPIO_enuPin11,GPIO_enuAF8);
	/* Initialise GPIO RX pin */
	GPIO_enuInit(GPIO_enuPortA,GPIO_enuPin12,GPIO_enuAltFunOpenDrain);
	GPIO_enuSetAlternativeFunction(GPIO_enuPortA,GPIO_enuPin12,GPIO_enuAF8);

	/* Enable interrupts in NVIC */
	NVIC_enuSetEnable(NVIC_enuUSART6);

	/* 8 data bits */
	CLR_BIT(UART6_CR1,M);

	/* configure baud rate */
#if BAUD_RATE6 == 9600
	UART6_BRR = UART_BRR_MASK & 0x00000683;
#elif BAUD_RATE6 == 115200
	UART6_BRR = UART_BRR_MASK & 0x0000008B;
#endif

#if PARITY6 == ENABLE
	SET_BIT(UART6_CR1,PCE);
#elif PARITY6 == DISABLE
	CLR_BIT(UART6_CR1,PCE);
#endif

#if PARITY_MODE6 == EVEN
	CLR_BIT(UART6_CR1,PS);
#elif PARITY_MODE6 == ODD
	SET_BIT(UART6_CR1,PS);
#endif

#if STOP_BIT6 == 1
	UART6_CR2 &= ONE_STOP;
#elif STOP_BIT6 == 2
	UART6_CR2 &= ONE_STOP;
	UART6_CR2 |= TWO_STOP;
#endif

#if CLK_POLARITY6 == LOW
	CLR_BIT(UART6_CR2,CPOL);
#elif CLK_POLARITY6 == HIGH
	SET_BIT(UART6_CR2,CPOL);
#endif

#if CLK_PHASE6 == FIRST
	CLR_BIT(UART6_CR2,CPHA);
#elif CLK_PHASE6 == SECOND
	SET_BIT(UART6_CR2,CPHA);
#endif

	/* enable receiver */
	SET_BIT(UART6_CR1,RE);
	/* enable transmitter */
	SET_BIT(UART6_CR1,TE);
	/* enable UART */
	SET_BIT(UART6_CR1,UE);

	/* Clear status Register */
	UART6_SR &= UART_CLR_SR;

	/* Enable interrupts */
	SET_BIT(UART6_CR1,RXNEIE);
	SET_BIT(UART6_CR1,TCIE);
	SET_BIT(UART6_CR1,TXEIE);
}

UART_enuErrorStatus_t UART6_enuSend(u8 Cpy_u8Data)
{
	UART_enuErrorStatus_t Loc_enuErrorStatus = UART_enuOk;

	UART_TXData6 = Cpy_u8Data;

	return Loc_enuErrorStatus;
}

UART_enuErrorStatus_t UART6_enuRecieve(u8* Add_pu8Data)
{
	UART_enuErrorStatus_t Loc_enuErrorStatus = UART_enuOk;

	if(Add_pu8Data != NULL)
	{
		*Add_pu8Data = UART_RXData6;
	}
	else
	{
		Loc_enuErrorStatus = UART_enuNullPtr;
	}

	return Loc_enuErrorStatus;
}

void USART1_IRQHandler(void)
{
	if((UART1_SR & (1<<RXNE)) != 0)
	{
		UART_RXData1 = UART1_DR;
	}
	if((UART1_SR & (1<<TC)) != 0)
	{
		if(UART_TXData1)
		{
			UART1_DR = UART_TXData1;
			UART_TXData1 = 0;
		}
	}
}

void USART2_IRQHandler(void)
{
	if((UART2_SR & (1<<RXNE)) != 0)
	{
		UART_RXData2 = UART2_DR;
	}
	if((UART2_SR & (1<<TC)) != 0)
	{
		if(UART_TXData2)
		{
			UART2_DR = UART_TXData2;
			UART_TXData2 = 0;
		}
	}
}

void USART6_IRQHandler(void)
{
	if((UART6_SR & (1<<RXNE)) != 0)
	{
		UART_RXData6 = UART6_DR;
	}
	if((UART6_SR & (1<<TC)) != 0)
	{
		if(UART_TXData6)
		{
			UART6_DR = UART_TXData6;
			UART_TXData6 = 0;
		}
	}
}
