/*
 * UART_Cfg.h
 *
 *  Created on: 14 Apr 2023
 *      Author: Omnia
 */

#ifndef UART_CFG_H_
#define UART_CFG_H_

/************** UART1 **************/
/* Select baud rate of UART 9600 or 115200 */
#define BAUD_RATE1			9600

/* Choose ENABLE or DISABLE */
#define PARITY1				DISABLE

/* Choose EVEN or ODD */
#define PARITY_MODE1		EVEN

/* Choose 1, 2 */
#define STOP_BIT1			1

/* Choose LOW or HIGH */
#define CLK_POLARITY1		LOW

/* Choose FIRST or SECOND */
#define CLK_PHASE1			FIRST


/************** UART2 **************/
/* Select baud rate of UART 9600 or 115200 */
#define BAUD_RATE2			9600

/* Choose ENABLE or DISABLE */
#define PARITY2				DISABLE

/* Choose EVEN or ODD */
#define PARITY_MODE2		EVEN

/* Choose 1, 0.5, 2, 1.5 */
#define STOP_BIT2			1

/* Choose LOW or HIGH */
#define CLK_POLARITY2		LOW

/* Choose FIRST or SECOND */
#define CLK_PHASE2			FIRST

/************** UART6 **************/
/* Select baud rate of UART 9600 or 115200 */
#define BAUD_RATE6			9600

/* Choose ENABLE or DISABLE */
#define PARITY6				DISABLE

/* Choose EVEN or ODD */
#define PARITY_MODE6		EVEN

/* Choose 1, 0.5, 2, 1.5 */
#define STOP_BIT6			1

/* Choose LOW or HIGH */
#define CLK_POLARITY6		LOW

/* Choose FIRST or SECOND */
#define CLK_PHASE6			FIRST


#endif /* UART_CFG_H_ */
