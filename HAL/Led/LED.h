/*
 * LED.h
 *
 *  Created on: 24 Mar 2023
 *      Author: Omnia
 */

#ifndef LED_H_
#define LED_H_


typedef enum{
	LED_enuOk,
	LED_enuNok,
	LED_enuNullPtr,
}LED_enuErrorStatus_t;

typedef enum{
	LED_enuPortA,
	LED_enuPortB,
	LED_enuPortC,
	LED_enuPortD,
	LED_enuPortE,
	LED_enuPortH,
}LED_enuPort_t;

typedef enum{
	LED_enuPin0,
	LED_enuPin1,
	LED_enuPin2,
	LED_enuPin3,
	LED_enuPin4,
	LED_enuPin5,
	LED_enuPin6,
	LED_enuPin7,
	LED_enuPin8,
	LED_enuPin9,
	LED_enuPin10,
	LED_enuPin11,
	LED_enuPin12,
	LED_enuPin13,
	LED_enuPin14,
	LED_enuPin15,
}LED_enuPin_t;

typedef enum{
	LED_enuPushPull,
	LED_enuOpenDrain,
}LED_enuDirection_t;

typedef enum{
	LED_enuActiveLow,
	LED_enuActiveHigh,
}LED_enuInterface_t;

typedef struct{
	LED_enuPort_t LED_strPort;
	LED_enuPin_t LED_strPin;
	LED_enuDirection_t LED_strDirection;
	LED_enuInterface_t LED_strInterface;
}LED_strState_t;

LED_enuErrorStatus_t LED_enuInit(LED_strState_t* Add_strState);

LED_enuErrorStatus_t LED_enuOn(LED_strState_t* Add_strState);

LED_enuErrorStatus_t LED_enuOff(LED_strState_t* Add_strState);

LED_enuErrorStatus_t LED_enuToggle(LED_strState_t* Add_strState);

#endif /* LED_H_ */
