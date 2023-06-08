/*
 * Switch_Task.h
 *
 *  Created on: 2 Apr 2023
 *      Author: Omnia
 */

#ifndef SWITCH_TASK_H_
#define SWITCH_TASK_H_


typedef enum{
	Switch_enuOk,
	Switch_enuNok,
	Switch_enuNullPtr,
}Switch_enuErrorStatus_t;

typedef enum
{
	Switch_enuPortA,
	Switch_enuPortB,
	Switch_enuPortC,
	Switch_enuPortD,
	Switch_enuPortE,
	Switch_enuPortH,
}Swicth_enuPort_t;

typedef enum{
	Switch_enuPin0,
	Switch_enuPin1,
	Switch_enuPin2,
	Switch_enuPin3,
	Switch_enuPin4,
	Switch_enuPin5,
	Switch_enuPin6,
	Switch_enuPin7,
	Switch_enuPin8,
	Switch_enuPin9,
	Switch_enuPin10,
	Switch_enuPin11,
	Switch_enuPin12,
	Switch_enuPin13,
	Switch_enuPin14,
	Switch_enuPin15,
}Switch_enuPin_t;

typedef enum{
	Switch_enuPullUp,
	Switch_enuPullDown,
	Switch_enuOpenDrain,
}Switch_enuDirection_t;

typedef enum{
	Switch_enuPressed,
	Switch_enuReleased,
	Switch_enuHigh,
	Switch_enuLow,
}Switch_enuStatus_t;

typedef struct{
	Swicth_enuPort_t Switch_strPort;
	Switch_enuPin_t Switch_strPin;
	Switch_enuDirection_t Switch_strDirection;
	Switch_enuStatus_t* Switch_strstate;
}Switch_strState_t;

Switch_enuErrorStatus_t Switch_enuInit(Switch_strState_t* Add_strState);

Switch_enuErrorStatus_t Switch_enuGetStatus(Switch_strState_t* Add_strState);

void Switch_vidTask(void);

Switch_enuErrorStatus_t Switch_vidGetStatus(Switch_enuStatus_t* Add_enuState);


#endif /* SWITCH_TASK_H_ */
