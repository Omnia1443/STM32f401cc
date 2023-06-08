/*
 * UART_Piv.h
 *
 *  Created on: 14 Apr 2023
 *      Author: Omnia
 */

#ifndef UART_PIV_H_
#define UART_PIV_H_


#define ENABLE					0
#define DISABLE					1
#define EVEN					2
#define ODD						3
#define LOW						4
#define HIGH					5
#define FIRST					6
#define SECOND					7

#define PE						0
#define FE						1
#define NF						2
#define ORE						3
#define IDLE					4
#define RXNE					5
#define TC						6
#define TXE						7
#define LBD						8
#define CTS						9
#define SBK						0
#define RWU						1
#define RE						2
#define TE						3
#define IDLEIE					4
#define RXNEIE					5
#define TCIE					6
#define TXEIE					7
#define PEIE					8
#define PS						9
#define PCE						10
#define WAKE					11
#define M						12
#define UE						13
#define OVER8					15
#define LBDL					5
#define LBDIE					6
#define LBCL					8
#define CPHA					9
#define CPOL					10
#define CLKEN					11
#define LINEN					14
#define EIE						0
#define IREN					1
#define IRLP					2
#define HDSEL					3
#define NACK					4
#define SCEN					5
#define DMAR					6
#define DMAT					7
#define RTSE					8
#define CTSE					9
#define CTSIE					10
#define ONEBIT					11

#define ONE_STOP				0xFFFF4FFF
#define TWO_STOP				0x00002000

#define UART_CLR_SR				0xFFFFFC00
#define UART_SR_MASK			0x000003FF
#define UART_DR_MASK			0x000001FF
#define UART_BRR_MASK			0x0000FFFF
#define UART_CR1_MASK			0x0000BFFF
#define UART_CR2_MASK			0x00007F6F
#define UART_CR3_MASK			0x00000FFF
#define UART_GTPR_MASK			0x0000FFFF

#define UART1_BASE_ADDRESS		0x40011000
#define UART2_BASE_ADDRESS		0x40004400
#define UART6_BASE_ADDRESS		0x40011000

#define UART1_SR				*((volatile u32*)(UART1_BASE_ADDRESS + 0x00))
#define UART1_DR				*((volatile u32*)(UART1_BASE_ADDRESS + 0x04))
#define UART1_BRR				*((volatile u32*)(UART1_BASE_ADDRESS + 0x08))
#define UART1_CR1				*((volatile u32*)(UART1_BASE_ADDRESS + 0x0C))
#define UART1_CR2				*((volatile u32*)(UART1_BASE_ADDRESS + 0x10))
#define UART1_CR3				*((volatile u32*)(UART1_BASE_ADDRESS + 0x14))
#define UART1_GTPR				*((volatile u32*)(UART1_BASE_ADDRESS + 0x18))


#define UART2_SR				*((volatile u32*)(UART2_BASE_ADDRESS + 0x00))
#define UART2_DR				*((volatile u32*)(UART2_BASE_ADDRESS + 0x04))
#define UART2_BRR				*((volatile u32*)(UART2_BASE_ADDRESS + 0x08))
#define UART2_CR1				*((volatile u32*)(UART2_BASE_ADDRESS + 0x0C))
#define UART2_CR2				*((volatile u32*)(UART2_BASE_ADDRESS + 0x10))
#define UART2_CR3				*((volatile u32*)(UART2_BASE_ADDRESS + 0x14))
#define UART2_GTPR				*((volatile u32*)(UART2_BASE_ADDRESS + 0x18))


#define UART6_SR				*((volatile u32*)(UART6_BASE_ADDRESS + 0x00))
#define UART6_DR				*((volatile u32*)(UART6_BASE_ADDRESS + 0x04))
#define UART6_BRR				*((volatile u32*)(UART6_BASE_ADDRESS + 0x08))
#define UART6_CR1				*((volatile u32*)(UART6_BASE_ADDRESS + 0x0C))
#define UART6_CR2				*((volatile u32*)(UART6_BASE_ADDRESS + 0x10))
#define UART6_CR3				*((volatile u32*)(UART6_BASE_ADDRESS + 0x14))
#define UART6_GTPR				*((volatile u32*)(UART6_BASE_ADDRESS + 0x18))


#endif /* UART_PIV_H_ */
