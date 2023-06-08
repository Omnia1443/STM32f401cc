/*
 * GPIO.h
 *
 *  Created on: 20 Mar 2023
 *      Author: Omnia
 */

#ifndef GPIO_H_
#define GPIO_H_


typedef enum{
	GPIO_enuInputOpenDrain,
	GPIO_enuInputPullUp,
	GPIO_enuInputPullDown,
	GPIO_enuOutputPushPull,
	GPIO_enuOutputOpenDrain,
	GPIO_enuAltFunPushPull,
	GPIO_enuAltFunOpenDrain,
	GPIO_enuAnalog,
}GPIO_enuDirection_t;

typedef enum{
	GPIO_enuPortA,
	GPIO_enuPortB,
	GPIO_enuPortC,
	GPIO_enuPortD,
	GPIO_enuPortE,
	GPIO_enuPortH,
}GPIO_enuPort_t;

typedef enum{
	GPIO_enuPin0,
	GPIO_enuPin1,
	GPIO_enuPin2,
	GPIO_enuPin3,
	GPIO_enuPin4,
	GPIO_enuPin5,
	GPIO_enuPin6,
	GPIO_enuPin7,
	GPIO_enuPin8,
	GPIO_enuPin9,
	GPIO_enuPin10,
	GPIO_enuPin11,
	GPIO_enuPin12,
	GPIO_enuPin13,
	GPIO_enuPin14,
	GPIO_enuPin15,
}GPIO_enuPins_t;

typedef enum{
	GPIO_enuAF0,
	GPIO_enuAF1,
	GPIO_enuAF2,
	GPIO_enuAF3,
	GPIO_enuAF4,
	GPIO_enuAF5,
	GPIO_enuAF6,
	GPIO_enuAF7,
	GPIO_enuAF8,
	GPIO_enuAF9,
	GPIO_enuAF10,
	GPIO_enuAF11,
	GPIO_enuAF12,
	GPIO_enuAF13,
	GPIO_enuAF14,
	GPIO_enuAF15,
}GPIO_enuAltFun_t;

typedef enum{
	GPIO_enuLow,
	GPIO_enuHigh,
}GPIO_enuPinValue_t;

typedef enum{
	GPIO_enuOk,
	GPIO_enuNok,
	GPIO_enuNullPtr,
}GPIO_enuErrorStatus_t;

GPIO_enuErrorStatus_t GPIO_enuInit(GPIO_enuPort_t Cpy_enuPort, GPIO_enuPins_t Cpy_enuPin, GPIO_enuDirection_t Cpy_enuDirection);

GPIO_enuErrorStatus_t GPIO_enuSetPin(GPIO_enuPort_t Cpy_enuPort, GPIO_enuPins_t Cpy_enuPin);

GPIO_enuErrorStatus_t GPIO_enuClearPin(GPIO_enuPort_t Cpy_enuPort, GPIO_enuPins_t Cpy_enuPin);

GPIO_enuErrorStatus_t GPIO_enuTogglePin(GPIO_enuPort_t Cpy_enuPort, GPIO_enuPins_t Cpy_enuPin);

GPIO_enuErrorStatus_t GPIO_enuGetPin(GPIO_enuPort_t Cpy_enuPort, GPIO_enuPins_t Cpy_enuPin, u8* Add_u8Value);

GPIO_enuErrorStatus_t GPIO_enuSetAlternativeFunction(GPIO_enuPort_t Cpy_enuPort, GPIO_enuPins_t Cpy_enuPin, GPIO_enuAltFun_t Cpy_enuAltFun);


#endif /* GPIO_H_ */
