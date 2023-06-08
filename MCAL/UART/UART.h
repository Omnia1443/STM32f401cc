/*
 * UART.h
 *
 *  Created on: 14 Apr 2023
 *      Author: Omnia
 */

#ifndef UART_H_
#define UART_H_


typedef enum{
	UART_enuOk,
	UART_enuNok,
	UART_enuNullPtr,
}UART_enuErrorStatus_t;

void UART1_vidInit(void);

UART_enuErrorStatus_t UART1_enuSend(u8 Cpy_u8Data);

UART_enuErrorStatus_t UART1_enuRecieve(u8* Add_pu8Data);

void UART2_vidInit(void);

UART_enuErrorStatus_t UART2_enuSend(u8 Cpy_u8Data);

UART_enuErrorStatus_t UART2_enuRecieve(u8* Add_pu8Data);

void UART6_vidInit(void);

UART_enuErrorStatus_t UART6_enuSend(u8 Cpy_u8Data);

UART_enuErrorStatus_t UART6_enuRecieve(u8* Add_pu8Data);


#endif /* UART_H_ */
