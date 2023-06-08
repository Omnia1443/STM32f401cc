/*
 * GPIO.c
 *
 *  Created on: 20 Mar 2023
 *      Author: Omnia
 */
#include "Std_Types.h"
#include "Bit_Math.h"
#include "RCC.h"
#include "GPIO_Piv.h"
#include "GPIO_Cfg.h"
#include "GPIO.h"


GPIO_enuErrorStatus_t GPIO_enuInit(GPIO_enuPort_t Cpy_enuPort, GPIO_enuPins_t Cpy_enuPin, GPIO_enuDirection_t Cpy_enuDirection)
{
	GPIO_enuErrorStatus_t Loc_enuErrorStatus = GPIO_enuOk;
	volatile u32 Loc_u32ModeTemp, Loc_u32TypeTemp;
	if((Cpy_enuPin >= GPIO_enuPin0) && (Cpy_enuPin <= GPIO_enuPin15))
	{
		switch(Cpy_enuPort)
		{
			case GPIO_enuPortA:
				RCC_enuEnablePeriphalAHB1(RCC_enuGPIOA);
				Loc_u32ModeTemp = GPIOA_MODER;
				Loc_u32ModeTemp &= ~(GPIO_INPUT<<(Cpy_enuPin*2));
				switch(Cpy_enuDirection)
				{
					case GPIO_enuInputOpenDrain:
						Loc_u32TypeTemp = GPIOA_PUPDR;
						Loc_u32ModeTemp &= ~(GPIO_INPUT<<(Cpy_enuPin*2));
						Loc_u32TypeTemp &= ~(GPIO_OPENDRAIN<<(Cpy_enuPin*2));
						GPIOA_PUPDR = Loc_u32TypeTemp;
					break;

					case GPIO_enuInputPullUp:
						Loc_u32TypeTemp = GPIOA_PUPDR;
						Loc_u32ModeTemp &= ~(GPIO_INPUT<<(Cpy_enuPin*2));
						Loc_u32TypeTemp &= ~(GPIO_OPENDRAIN<<(Cpy_enuPin*2));
						Loc_u32TypeTemp |= (GPIO_PULLUP<<(Cpy_enuPin*2));
						GPIOA_PUPDR = Loc_u32TypeTemp;
					break;

					case GPIO_enuInputPullDown:
						Loc_u32TypeTemp = GPIOA_PUPDR;
						Loc_u32ModeTemp &= ~(GPIO_INPUT<<(Cpy_enuPin*2));
						Loc_u32TypeTemp &= ~(GPIO_OPENDRAIN<<(Cpy_enuPin*2));
						Loc_u32TypeTemp |= (GPIO_PULLDOWN<<(Cpy_enuPin*2));
						GPIOA_PUPDR = Loc_u32TypeTemp;
					break;

					case GPIO_enuOutputPushPull:
						Loc_u32ModeTemp |= (GPIO_OUTPUT<<(Cpy_enuPin*2));
						GPIOA_OTYPER &= ~(1<<Cpy_enuPin);
					break;

					case GPIO_enuOutputOpenDrain:
						Loc_u32ModeTemp |= (GPIO_OUTPUT<<(Cpy_enuPin*2));
						GPIOA_OTYPER |= (1<<Cpy_enuPin);
					break;

					case GPIO_enuAltFunPushPull:
						Loc_u32ModeTemp |= (GPIO_ALT_FUN<<(Cpy_enuPin*2));
						GPIOA_OTYPER &= ~(1<<Cpy_enuPin);
					break;

					case GPIO_enuAltFunOpenDrain:
						Loc_u32ModeTemp |= (GPIO_ALT_FUN<<(Cpy_enuPin*2));
						GPIOA_OTYPER |= (1<<Cpy_enuPin);
					break;

					case GPIO_enuAnalog:
						Loc_u32ModeTemp |= (GPIO_ANALOG<<(Cpy_enuPin*2));
					break;

					default: Loc_enuErrorStatus = GPIO_enuNok;
					break;
				}
				GPIOA_MODER = Loc_u32ModeTemp;
				break;

			case GPIO_enuPortB:
				RCC_enuEnablePeriphalAHB1(RCC_enuGPIOB);
				Loc_u32ModeTemp = GPIOB_MODER;
				Loc_u32ModeTemp &= ~(GPIO_INPUT<<(Cpy_enuPin*2));
				switch(Cpy_enuDirection)
				{
					case GPIO_enuInputOpenDrain:
						Loc_u32TypeTemp = GPIOB_PUPDR;
						Loc_u32ModeTemp &= ~(GPIO_INPUT<<(Cpy_enuPin*2));
						Loc_u32TypeTemp &= ~(GPIO_OPENDRAIN<<(Cpy_enuPin*2));
						GPIOB_PUPDR = Loc_u32TypeTemp;
					break;

					case GPIO_enuInputPullUp:
						Loc_u32TypeTemp = GPIOB_PUPDR;
						Loc_u32ModeTemp &= ~(GPIO_INPUT<<(Cpy_enuPin*2));
						Loc_u32TypeTemp &= ~(GPIO_OPENDRAIN<<(Cpy_enuPin*2));
						Loc_u32TypeTemp |= (GPIO_PULLUP<<(Cpy_enuPin*2));
						GPIOB_PUPDR = Loc_u32TypeTemp;
					break;

					case GPIO_enuInputPullDown:
						Loc_u32TypeTemp = GPIOB_PUPDR;
						Loc_u32ModeTemp &= ~(GPIO_INPUT<<(Cpy_enuPin*2));
						Loc_u32TypeTemp &= ~(GPIO_OPENDRAIN<<(Cpy_enuPin*2));
						Loc_u32TypeTemp |= (GPIO_PULLDOWN<<(Cpy_enuPin*2));
						GPIOB_PUPDR = Loc_u32TypeTemp;
					break;

					case GPIO_enuOutputPushPull:
						Loc_u32ModeTemp |= (GPIO_OUTPUT<<(Cpy_enuPin*2));
						GPIOB_OTYPER &= ~(1<<Cpy_enuPin);
					break;

					case GPIO_enuOutputOpenDrain:
						Loc_u32ModeTemp |= (GPIO_OUTPUT<<(Cpy_enuPin*2));
						GPIOB_OTYPER |= (1<<Cpy_enuPin);
					break;

					case GPIO_enuAltFunPushPull:
						Loc_u32ModeTemp |= (GPIO_ALT_FUN<<(Cpy_enuPin*2));
						GPIOB_OTYPER &= ~(1<<Cpy_enuPin);
					break;

					case GPIO_enuAltFunOpenDrain:
						Loc_u32ModeTemp |= (GPIO_ALT_FUN<<(Cpy_enuPin*2));
						GPIOB_OTYPER |= (1<<Cpy_enuPin);
					break;

					case GPIO_enuAnalog:
						Loc_u32ModeTemp |= (GPIO_ANALOG<<(Cpy_enuPin*2));
					break;

					default: Loc_enuErrorStatus = GPIO_enuNok;
					break;
				}
				GPIOB_MODER = Loc_u32ModeTemp;
			break;

			case GPIO_enuPortC:
				RCC_enuEnablePeriphalAHB1(RCC_enuGPIOC);
				Loc_u32ModeTemp = GPIOC_MODER;
				Loc_u32ModeTemp &= ~(GPIO_INPUT<<(Cpy_enuPin*2));
				switch(Cpy_enuDirection)
				{
					case GPIO_enuInputOpenDrain:
						Loc_u32TypeTemp = GPIOC_PUPDR;
						Loc_u32ModeTemp &= ~(GPIO_INPUT<<(Cpy_enuPin*2));
						Loc_u32TypeTemp &= ~(GPIO_OPENDRAIN<<(Cpy_enuPin*2));
						GPIOC_PUPDR = Loc_u32TypeTemp;
					break;

					case GPIO_enuInputPullUp:
						Loc_u32TypeTemp = GPIOC_PUPDR;
						Loc_u32ModeTemp &= ~(GPIO_INPUT<<(Cpy_enuPin*2));
						Loc_u32TypeTemp &= ~(GPIO_OPENDRAIN<<(Cpy_enuPin*2));
						Loc_u32TypeTemp |= (GPIO_PULLUP<<(Cpy_enuPin*2));
						GPIOC_PUPDR = Loc_u32TypeTemp;
					break;

					case GPIO_enuInputPullDown:
						Loc_u32TypeTemp = GPIOC_PUPDR;
						Loc_u32ModeTemp &= ~(GPIO_INPUT<<(Cpy_enuPin*2));
						Loc_u32TypeTemp &= ~(GPIO_OPENDRAIN<<(Cpy_enuPin*2));
						Loc_u32TypeTemp |= (GPIO_PULLDOWN<<(Cpy_enuPin*2));
						GPIOC_PUPDR = Loc_u32TypeTemp;
					break;

					case GPIO_enuOutputPushPull:
						Loc_u32ModeTemp |= (GPIO_OUTPUT<<(Cpy_enuPin*2));
						GPIOC_OTYPER &= ~(1<<Cpy_enuPin);
					break;

					case GPIO_enuOutputOpenDrain:
						Loc_u32ModeTemp |= (GPIO_OUTPUT<<(Cpy_enuPin*2));
						GPIOC_OTYPER |= (1<<Cpy_enuPin);
					break;

					case GPIO_enuAltFunPushPull:
						Loc_u32ModeTemp |= (GPIO_ALT_FUN<<(Cpy_enuPin*2));
						GPIOC_OTYPER &= ~(1<<Cpy_enuPin);
					break;

					case GPIO_enuAltFunOpenDrain:
						Loc_u32ModeTemp |= (GPIO_ALT_FUN<<(Cpy_enuPin*2));
						GPIOC_OTYPER |= (1<<Cpy_enuPin);
					break;

					case GPIO_enuAnalog:
						Loc_u32ModeTemp |= (GPIO_ANALOG<<(Cpy_enuPin*2));
					break;

					default: Loc_enuErrorStatus = GPIO_enuNok;
					break;
				}
				GPIOC_MODER = Loc_u32ModeTemp;
			break;

			case GPIO_enuPortD:
				RCC_enuEnablePeriphalAHB1(RCC_enuGPIOD);
				Loc_u32ModeTemp = GPIOD_MODER;
				Loc_u32ModeTemp &= ~(GPIO_INPUT<<(Cpy_enuPin*2));
				switch(Cpy_enuDirection)
				{
					case GPIO_enuInputOpenDrain:
						Loc_u32TypeTemp = GPIOD_PUPDR;
						Loc_u32ModeTemp &= ~(GPIO_INPUT<<(Cpy_enuPin*2));
						Loc_u32TypeTemp &= ~(GPIO_OPENDRAIN<<(Cpy_enuPin*2));
						GPIOD_PUPDR = Loc_u32TypeTemp;
					break;

					case GPIO_enuInputPullUp:
						Loc_u32TypeTemp = GPIOD_PUPDR;
						Loc_u32ModeTemp &= ~(GPIO_INPUT<<(Cpy_enuPin*2));
						Loc_u32TypeTemp &= ~(GPIO_OPENDRAIN<<(Cpy_enuPin*2));
						Loc_u32TypeTemp |= (GPIO_PULLUP<<(Cpy_enuPin*2));
						GPIOD_PUPDR = Loc_u32TypeTemp;
					break;

					case GPIO_enuInputPullDown:
						Loc_u32TypeTemp = GPIOD_PUPDR;
						Loc_u32ModeTemp &= ~(GPIO_INPUT<<(Cpy_enuPin*2));
						Loc_u32TypeTemp &= ~(GPIO_OPENDRAIN<<(Cpy_enuPin*2));
						Loc_u32TypeTemp |= (GPIO_PULLDOWN<<(Cpy_enuPin*2));
						GPIOD_PUPDR = Loc_u32TypeTemp;
					break;

					case GPIO_enuOutputPushPull:
						Loc_u32ModeTemp |= (GPIO_OUTPUT<<(Cpy_enuPin*2));
						GPIOD_OTYPER &= ~(1<<Cpy_enuPin);
					break;

					case GPIO_enuOutputOpenDrain:
						Loc_u32ModeTemp |= (GPIO_OUTPUT<<(Cpy_enuPin*2));
						GPIOD_OTYPER |= (1<<Cpy_enuPin);
					break;

					case GPIO_enuAltFunPushPull:
						Loc_u32ModeTemp |= (GPIO_ALT_FUN<<(Cpy_enuPin*2));
						GPIOD_OTYPER &= ~(1<<Cpy_enuPin);
					break;

					case GPIO_enuAltFunOpenDrain:
						Loc_u32ModeTemp |= (GPIO_ALT_FUN<<(Cpy_enuPin*2));
						GPIOD_OTYPER |= (1<<Cpy_enuPin);
					break;

					case GPIO_enuAnalog:
						Loc_u32ModeTemp |= (GPIO_ANALOG<<(Cpy_enuPin*2));
					break;

					default: Loc_enuErrorStatus = GPIO_enuNok;
					break;
				}
				GPIOD_MODER = Loc_u32ModeTemp;
			break;

			case GPIO_enuPortE:
				RCC_enuEnablePeriphalAHB1(RCC_enuGPIOE);
				Loc_u32ModeTemp = GPIOE_MODER;
				Loc_u32ModeTemp &= ~(GPIO_INPUT<<(Cpy_enuPin*2));
				switch(Cpy_enuDirection)
				{
					case GPIO_enuInputOpenDrain:
						Loc_u32TypeTemp = GPIOE_PUPDR;
						Loc_u32ModeTemp &= ~(GPIO_INPUT<<(Cpy_enuPin*2));
						Loc_u32TypeTemp &= ~(GPIO_OPENDRAIN<<(Cpy_enuPin*2));
						GPIOE_PUPDR = Loc_u32TypeTemp;
					break;

					case GPIO_enuInputPullUp:
						Loc_u32TypeTemp = GPIOE_PUPDR;
						Loc_u32ModeTemp &= ~(GPIO_INPUT<<(Cpy_enuPin*2));
						Loc_u32TypeTemp &= ~(GPIO_OPENDRAIN<<(Cpy_enuPin*2));
						Loc_u32TypeTemp |= (GPIO_PULLUP<<(Cpy_enuPin*2));
						GPIOE_PUPDR = Loc_u32TypeTemp;
					break;

					case GPIO_enuInputPullDown:
						Loc_u32TypeTemp = GPIOE_PUPDR;
						Loc_u32ModeTemp &= ~(GPIO_INPUT<<(Cpy_enuPin*2));
						Loc_u32TypeTemp &= ~(GPIO_OPENDRAIN<<(Cpy_enuPin*2));
						Loc_u32TypeTemp |= (GPIO_PULLDOWN<<(Cpy_enuPin*2));
						GPIOE_PUPDR = Loc_u32TypeTemp;
					break;

					case GPIO_enuOutputPushPull:
						Loc_u32ModeTemp |= (GPIO_OUTPUT<<(Cpy_enuPin*2));
						GPIOE_OTYPER &= ~(1<<Cpy_enuPin);
					break;

					case GPIO_enuOutputOpenDrain:
						Loc_u32ModeTemp |= (GPIO_OUTPUT<<(Cpy_enuPin*2));
						GPIOE_OTYPER |= (1<<Cpy_enuPin);
					break;

					case GPIO_enuAltFunPushPull:
						Loc_u32ModeTemp |= (GPIO_ALT_FUN<<(Cpy_enuPin*2));
						GPIOE_OTYPER &= ~(1<<Cpy_enuPin);
					break;

					case GPIO_enuAltFunOpenDrain:
						Loc_u32ModeTemp |= (GPIO_ALT_FUN<<(Cpy_enuPin*2));
						GPIOE_OTYPER |= (1<<Cpy_enuPin);
					break;

					case GPIO_enuAnalog:
						Loc_u32ModeTemp |= (GPIO_ANALOG<<(Cpy_enuPin*2));
					break;

					default: Loc_enuErrorStatus = GPIO_enuNok;
					break;
				}
				GPIOE_MODER = Loc_u32ModeTemp;
			break;

			case GPIO_enuPortH:
				RCC_enuEnablePeriphalAHB1(RCC_enuGPIOH);
				Loc_u32ModeTemp = GPIOH_MODER;
				Loc_u32ModeTemp &= ~(GPIO_INPUT<<(Cpy_enuPin*2));
				switch(Cpy_enuDirection)
				{
					case GPIO_enuInputOpenDrain:
						Loc_u32TypeTemp = GPIOH_PUPDR;
						Loc_u32ModeTemp &= ~(GPIO_INPUT<<(Cpy_enuPin*2));
						Loc_u32TypeTemp &= ~(GPIO_OPENDRAIN<<(Cpy_enuPin*2));
						GPIOH_PUPDR = Loc_u32TypeTemp;
					break;

					case GPIO_enuInputPullUp:
						Loc_u32TypeTemp = GPIOH_PUPDR;
						Loc_u32ModeTemp &= ~(GPIO_INPUT<<(Cpy_enuPin*2));
						Loc_u32TypeTemp &= ~(GPIO_OPENDRAIN<<(Cpy_enuPin*2));
						Loc_u32TypeTemp |= (GPIO_PULLUP<<(Cpy_enuPin*2));
						GPIOH_PUPDR = Loc_u32TypeTemp;
					break;

					case GPIO_enuInputPullDown:
						Loc_u32TypeTemp = GPIOH_PUPDR;
						Loc_u32ModeTemp &= ~(GPIO_INPUT<<(Cpy_enuPin*2));
						Loc_u32TypeTemp &= ~(GPIO_OPENDRAIN<<(Cpy_enuPin*2));
						Loc_u32TypeTemp |= (GPIO_PULLDOWN<<(Cpy_enuPin*2));
						GPIOH_PUPDR = Loc_u32TypeTemp;
					break;

					case GPIO_enuOutputPushPull:
						Loc_u32ModeTemp |= (GPIO_OUTPUT<<(Cpy_enuPin*2));
						GPIOH_OTYPER &= ~(1<<Cpy_enuPin);
					break;

					case GPIO_enuOutputOpenDrain:
						Loc_u32ModeTemp |= (GPIO_OUTPUT<<(Cpy_enuPin*2));
						GPIOH_OTYPER |= (1<<Cpy_enuPin);
					break;

					case GPIO_enuAltFunPushPull:
						Loc_u32ModeTemp |= (GPIO_ALT_FUN<<(Cpy_enuPin*2));
						GPIOH_OTYPER &= ~(1<<Cpy_enuPin);
					break;

					case GPIO_enuAltFunOpenDrain:
						Loc_u32ModeTemp |= (GPIO_ALT_FUN<<(Cpy_enuPin*2));
						GPIOH_OTYPER |= (1<<Cpy_enuPin);
					break;

					case GPIO_enuAnalog:
						Loc_u32ModeTemp |= (GPIO_ANALOG<<(Cpy_enuPin*2));
					break;

					default: Loc_enuErrorStatus = GPIO_enuNok;
					break;
				}
				GPIOH_MODER = Loc_u32ModeTemp;
			break;

			default: Loc_enuErrorStatus = GPIO_enuNok;
			break;
		}
	}
	else
	{
		Loc_enuErrorStatus = GPIO_enuNok;
	}

	return Loc_enuErrorStatus;
}

GPIO_enuErrorStatus_t GPIO_enuSetPin(GPIO_enuPort_t Cpy_enuPort, GPIO_enuPins_t Cpy_enuPin)
{
	GPIO_enuErrorStatus_t Loc_enuErrorStatus = GPIO_enuOk;

	if((Cpy_enuPin >= GPIO_enuPin0) && (Cpy_enuPin <= GPIO_enuPin15))
	{
		switch(Cpy_enuPort)
		{
			case GPIO_enuPortA: GPIOA_BSRR = (1<<Cpy_enuPin); break;
			case GPIO_enuPortB: GPIOB_BSRR = (1<<Cpy_enuPin); break;
			case GPIO_enuPortC: GPIOC_BSRR = (1<<Cpy_enuPin); break;
			case GPIO_enuPortD: GPIOD_BSRR = (1<<Cpy_enuPin); break;
			case GPIO_enuPortE: GPIOE_BSRR = (1<<Cpy_enuPin); break;
			case GPIO_enuPortH: GPIOH_BSRR = (1<<Cpy_enuPin); break;
			default: Loc_enuErrorStatus = GPIO_enuNok;        break;
		}
	}
	else
	{
		Loc_enuErrorStatus = GPIO_enuNok;
	}

	return Loc_enuErrorStatus;
}

GPIO_enuErrorStatus_t GPIO_enuClearPin(GPIO_enuPort_t Cpy_enuPort, GPIO_enuPins_t Cpy_enuPin)
{
	GPIO_enuErrorStatus_t Loc_enuErrorStatus = GPIO_enuOk;

	if((Cpy_enuPin >= GPIO_enuPin0) && (Cpy_enuPin <= GPIO_enuPin15))
	{
		switch(Cpy_enuPort)
		{
			case GPIO_enuPortA: GPIOA_BSRR = (1<<(Cpy_enuPin+16)); break;
			case GPIO_enuPortB: GPIOB_BSRR = (1<<(Cpy_enuPin+16)); break;
			case GPIO_enuPortC: GPIOC_BSRR = (1<<(Cpy_enuPin+16)); break;
			case GPIO_enuPortD: GPIOD_BSRR = (1<<(Cpy_enuPin+16)); break;
			case GPIO_enuPortE: GPIOE_BSRR = (1<<(Cpy_enuPin+16)); break;
			case GPIO_enuPortH: GPIOH_BSRR = (1<<(Cpy_enuPin+16)); break;
			default: Loc_enuErrorStatus = GPIO_enuNok;             break;
		}
	}
	else
	{
		Loc_enuErrorStatus = GPIO_enuNok;
	}

	return Loc_enuErrorStatus;
}

GPIO_enuErrorStatus_t GPIO_enuTogglePin(GPIO_enuPort_t Cpy_enuPort, GPIO_enuPins_t Cpy_enuPin)
{
	GPIO_enuErrorStatus_t Loc_enuErrorStatus = GPIO_enuOk;

	if((Cpy_enuPin >= GPIO_enuPin0) && (Cpy_enuPin <= GPIO_enuPin15))
	{
		switch(Cpy_enuPort)
		{
			case GPIO_enuPortA: GPIOA_ODR ^= (1<<Cpy_enuPin); break;
			case GPIO_enuPortB: GPIOB_ODR ^= (1<<Cpy_enuPin); break;
			case GPIO_enuPortC: GPIOC_ODR ^= (1<<Cpy_enuPin); break;
			case GPIO_enuPortD: GPIOD_ODR ^= (1<<Cpy_enuPin); break;
			case GPIO_enuPortE: GPIOE_ODR ^= (1<<Cpy_enuPin); break;
			case GPIO_enuPortH: GPIOH_ODR ^= (1<<Cpy_enuPin); break;
			default: Loc_enuErrorStatus = GPIO_enuNok;        break;
		}
	}
	else
	{
		Loc_enuErrorStatus = GPIO_enuNok;
	}

	return Loc_enuErrorStatus;
}

GPIO_enuErrorStatus_t GPIO_enuGetPin(GPIO_enuPort_t Cpy_enuPort, GPIO_enuPins_t Cpy_enuPin, u8* Add_u8Value)
{
	GPIO_enuErrorStatus_t Loc_enuErrorStatus = GPIO_enuOk;

	if(Add_u8Value != NULL)
	{
		if((Cpy_enuPin >= GPIO_enuPin0) && (Cpy_enuPin <= GPIO_enuPin15))
		{
			switch(Cpy_enuPort)
			{
				case GPIO_enuPortA: *Add_u8Value = ((GPIOA_IDR>>Cpy_enuPin) & 0x00000001); break;
				case GPIO_enuPortB: *Add_u8Value = ((GPIOB_IDR>>Cpy_enuPin) & 0x00000001); break;
				case GPIO_enuPortC: *Add_u8Value = ((GPIOC_IDR>>Cpy_enuPin) & 0x00000001); break;
				case GPIO_enuPortD: *Add_u8Value = ((GPIOD_IDR>>Cpy_enuPin) & 0x00000001); break;
				case GPIO_enuPortE: *Add_u8Value = ((GPIOE_IDR>>Cpy_enuPin) & 0x00000001); break;
				case GPIO_enuPortH: *Add_u8Value = ((GPIOH_IDR>>Cpy_enuPin) & 0x00000001); break;
				default: Loc_enuErrorStatus = GPIO_enuNok;                                 break;
			}
		}
		else
		{
			Loc_enuErrorStatus = GPIO_enuNok;
		}
	}
	else
	{
		Loc_enuErrorStatus = GPIO_enuNullPtr;
	}

	return Loc_enuErrorStatus;
}

GPIO_enuErrorStatus_t GPIO_enuSetAlternativeFunction(GPIO_enuPort_t Cpy_enuPort, GPIO_enuPins_t Cpy_enuPin, GPIO_enuAltFun_t Cpy_enuAltFun)
{
	u32 Loc_u32AF;
	GPIO_enuErrorStatus_t Loc_enuErrorStatus = GPIO_enuOk;

	if((Cpy_enuAltFun >= GPIO_enuAF0) && (Cpy_enuAltFun <= GPIO_enuAF15))
	{
		if((Cpy_enuPin >= GPIO_enuPin0) && (Cpy_enuPin <= GPIO_enuPin7))
		{
			switch(Cpy_enuPort)
			{
				case GPIO_enuPortA:
					Loc_u32AF = GPIOA_AFRL;
					Loc_u32AF &= ~((u32)GPIO_enuAF15 << (4*Cpy_enuPin));
					Loc_u32AF |= ((u32)Cpy_enuAltFun << (4*Cpy_enuPin));
					GPIOA_AFRL = Loc_u32AF;
				break;
				case GPIO_enuPortB:
					Loc_u32AF = GPIOB_AFRL;
					Loc_u32AF &= ~((u32)GPIO_enuAF15 << (4*Cpy_enuPin));
					Loc_u32AF |= ((u32)Cpy_enuAltFun << (4*Cpy_enuPin));
					GPIOB_AFRL = Loc_u32AF;
				break;
				case GPIO_enuPortC:
					Loc_u32AF = GPIOC_AFRL;
					Loc_u32AF &= ~((u32)GPIO_enuAF15 << (4*Cpy_enuPin));
					Loc_u32AF |= ((u32)Cpy_enuAltFun << (4*Cpy_enuPin));
					GPIOC_AFRL = Loc_u32AF;
				break;
				case GPIO_enuPortD:
					Loc_u32AF = GPIOD_AFRL;
					Loc_u32AF &= ~((u32)GPIO_enuAF15 << (4*Cpy_enuPin));
					Loc_u32AF |= ((u32)Cpy_enuAltFun << (4*Cpy_enuPin));
					GPIOD_AFRL = Loc_u32AF;
				break;
				case GPIO_enuPortE:
					Loc_u32AF = GPIOE_AFRL;
					Loc_u32AF &= ~((u32)GPIO_enuAF15 << (4*Cpy_enuPin));
					Loc_u32AF |= ((u32)Cpy_enuAltFun << (4*Cpy_enuPin));
					GPIOE_AFRL = Loc_u32AF;
				break;
				case GPIO_enuPortH:
					Loc_u32AF = GPIOH_AFRL;
					Loc_u32AF &= ~((u32)GPIO_enuAF15 << (4*Cpy_enuPin));
					Loc_u32AF |= ((u32)Cpy_enuAltFun << (4*Cpy_enuPin));
					GPIOH_AFRL = Loc_u32AF;
				break;
				default:
					Loc_enuErrorStatus = GPIO_enuNok;
				break;
			}
		}
		else if((Cpy_enuPin >= GPIO_enuPin8) && (Cpy_enuPin <= GPIO_enuPin15))
		{
			switch(Cpy_enuPort)
			{
				case GPIO_enuPortA:
					Loc_u32AF = GPIOA_AFRH;
					Loc_u32AF &= ~((u32)GPIO_enuAF15 << (4*Cpy_enuPin));
					Loc_u32AF |= ((u32)Cpy_enuAltFun << (4*Cpy_enuPin));
					GPIOA_AFRH = Loc_u32AF;
				break;
				case GPIO_enuPortB:
					Loc_u32AF = GPIOA_AFRH;
					Loc_u32AF &= ~((u32)GPIO_enuAF15 << (4*Cpy_enuPin));
					Loc_u32AF |= ((u32)Cpy_enuAltFun << (4*Cpy_enuPin));
					GPIOA_AFRH = Loc_u32AF;
				break;
				case GPIO_enuPortC:
					Loc_u32AF = GPIOA_AFRH;
					Loc_u32AF &= ~((u32)GPIO_enuAF15 << (4*Cpy_enuPin));
					Loc_u32AF |= ((u32)Cpy_enuAltFun << (4*Cpy_enuPin));
					GPIOA_AFRH = Loc_u32AF;
				break;
				case GPIO_enuPortD:
					Loc_u32AF = GPIOA_AFRH;
					Loc_u32AF &= ~((u32)GPIO_enuAF15 << (4*Cpy_enuPin));
					Loc_u32AF |= ((u32)Cpy_enuAltFun << (4*Cpy_enuPin));
					GPIOA_AFRH = Loc_u32AF;
				break;
				case GPIO_enuPortE:
					Loc_u32AF = GPIOA_AFRH;
					Loc_u32AF &= ~((u32)GPIO_enuAF15 << (4*Cpy_enuPin));
					Loc_u32AF |= ((u32)Cpy_enuAltFun << (4*Cpy_enuPin));
					GPIOA_AFRH = Loc_u32AF;
				break;
				case GPIO_enuPortH:
					Loc_u32AF = GPIOA_AFRH;
					Loc_u32AF &= ~((u32)GPIO_enuAF15 << (4*Cpy_enuPin));
					Loc_u32AF |= ((u32)Cpy_enuAltFun << (4*Cpy_enuPin));
					GPIOA_AFRH = Loc_u32AF;
				break;
				default:
					Loc_enuErrorStatus = GPIO_enuNok;
				break;
			}
		}
		else
		{
			Loc_enuErrorStatus = GPIO_enuNok;
		}
	}
	else
	{
		Loc_enuErrorStatus = GPIO_enuNok;
	}

	return Loc_enuErrorStatus;
}
