/*
 * Systick_Piv.h
 *
 *  Created on: 25 Mar 2023
 *      Author: Omnia
 */

#ifndef SYSTICK_PIV_H_
#define SYSTICK_PIV_H_


#define PRESCALER			0
#define NO_PRESCALER		1
#define ENABLE_REQ			2
#define DISABLE_REQ			3

#define RELOAD_MASK			0x00FFFFFF

#define STK_CTRL			*((volatile u32*)0xE000E010)
#define ENABLE				0
#define TICKINT				1
#define CLKSOURCE			2
#define COUNTFLAG			16

#define STK_LOAD			*((volatile u32*)0xE000E014)

#define STK_VAL				*((volatile u32*)0xE000E018)

#define STK_CALIB			*((volatile u32*)0xE000E01C)
#define SKEW				30
#define NOREF				31




#endif /* SYSTICK_PIV_H_ */
