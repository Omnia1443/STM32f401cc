/*
 * Systick.h
 *
 *  Created on: 25 Mar 2023
 *      Author: Omnia
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_


typedef enum{
	STK_enuOk,
	STK_enuNok,
	STK_enuNullPtr,
}STK_enuErrorStatus_t;

void STK_vidInit(void);

void STK_vidStart(void);

void STK_vidReloadCounter(u32 Cpy_u32ReloadValue);

STK_enuErrorStatus_t STK_enuGetCurrentValue(u32* Add_u32CurrentValue);

STK_enuErrorStatus_t STK_enuSetTickTime(u32 Cpy_u32TickTime);

STK_enuErrorStatus_t STK_enuCBF(void (*Add_cbf)(void));


#endif /* SYSTICK_H_ */
