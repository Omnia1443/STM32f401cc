/*
 * LED.c
 *
 *  Created on: 24 Mar 2023
 *      Author: Omnia
 */
#include "Std_Types.h"
#include "GPIO.h"
#include "LED.h"


LED_enuErrorStatus_t LED_enuInit(LED_strState_t* Add_strState)
{
	GPIO_enuErrorStatus_t Loc_enuErrorStatusGPIO;
	LED_enuErrorStatus_t Loc_enuErrorStatus = LED_enuOk;

	if(Add_strState != NULL)
	{
		if((Add_strState->LED_strPort >= LED_enuPortA) && (Add_strState->LED_strPort <= LED_enuPortH))
		{
			if((Add_strState->LED_strPin >= LED_enuPin0) && (Add_strState->LED_strPin <= LED_enuPin15))
			{
				switch(Add_strState->LED_strDirection)
				{
					case LED_enuPushPull:
						Loc_enuErrorStatusGPIO = GPIO_enuInit(Add_strState->LED_strPort,Add_strState->LED_strPin,GPIO_enuOutputPushPull);
						if(Loc_enuErrorStatusGPIO == GPIO_enuNok)
						{
							Loc_enuErrorStatus = LED_enuNok;
						}
						break;
					case LED_enuOpenDrain:
						Loc_enuErrorStatusGPIO = GPIO_enuInit(Add_strState->LED_strPort,Add_strState->LED_strPin,GPIO_enuOutputOpenDrain);
						if(Loc_enuErrorStatusGPIO == GPIO_enuNok)
						{
							Loc_enuErrorStatus = LED_enuNok;
						}
						break;
					default:
						Loc_enuErrorStatus = LED_enuNok;
						break;
				}
			}
			else
			{
				Loc_enuErrorStatus = LED_enuNok;
			}
		}
		else
		{
			Loc_enuErrorStatus = LED_enuNok;
		}
	}
	else
	{
		Loc_enuErrorStatus = LED_enuNullPtr;
	}

	return Loc_enuErrorStatus;
}

LED_enuErrorStatus_t LED_enuOn(LED_strState_t* Add_strState)
{
	GPIO_enuErrorStatus_t Loc_enuErrorStatusGPIO;
	LED_enuErrorStatus_t Loc_enuErrorStatus = LED_enuOk;

	if(Add_strState != NULL)
	{
		if((Add_strState->LED_strPort >= LED_enuPortA) && (Add_strState->LED_strPort <= LED_enuPortH))
		{
			if((Add_strState->LED_strPin >= LED_enuPin0) && (Add_strState->LED_strPin <= LED_enuPin15))
			{
				switch(Add_strState->LED_strInterface)
				{
					case LED_enuActiveHigh:
						Loc_enuErrorStatusGPIO = GPIO_enuSetPin(Add_strState->LED_strPort,Add_strState->LED_strPin);
						if(Loc_enuErrorStatusGPIO == GPIO_enuNok)
						{
							Loc_enuErrorStatus = LED_enuNok;
						}
						break;
					case LED_enuActiveLow:
						Loc_enuErrorStatusGPIO = GPIO_enuClearPin(Add_strState->LED_strPort,Add_strState->LED_strPin);
						if(Loc_enuErrorStatusGPIO == GPIO_enuNok)
						{
							Loc_enuErrorStatus = LED_enuNok;
						}
						break;
					default:
						Loc_enuErrorStatus = LED_enuNok;
						break;
				}
			}
			else
			{
				Loc_enuErrorStatus = LED_enuNok;
			}
		}
		else
		{
			Loc_enuErrorStatus = LED_enuNok;
		}
	}
	else
	{
		Loc_enuErrorStatus = LED_enuNullPtr;
	}

	return Loc_enuErrorStatus;
}

LED_enuErrorStatus_t LED_enuOff(LED_strState_t* Add_strState)
{
	GPIO_enuErrorStatus_t Loc_enuErrorStatusGPIO;
	LED_enuErrorStatus_t Loc_enuErrorStatus = LED_enuOk;

	if(Add_strState != NULL)
	{
		if((Add_strState->LED_strPort >= LED_enuPortA) && (Add_strState->LED_strPort <= LED_enuPortH))
		{
			if((Add_strState->LED_strPin >= LED_enuPin0) && (Add_strState->LED_strPin <= LED_enuPin15))
			{
				switch(Add_strState->LED_strInterface)
				{
					case LED_enuActiveHigh:
						Loc_enuErrorStatusGPIO = GPIO_enuClearPin(Add_strState->LED_strPort,Add_strState->LED_strPin);
						if(Loc_enuErrorStatusGPIO == GPIO_enuNok)
						{
							Loc_enuErrorStatus = LED_enuNok;
						}
						break;
					case LED_enuActiveLow:
						Loc_enuErrorStatusGPIO = GPIO_enuSetPin(Add_strState->LED_strPort,Add_strState->LED_strPin);
						if(Loc_enuErrorStatusGPIO == GPIO_enuNok)
						{
							Loc_enuErrorStatus = LED_enuNok;
						}
						break;
					default:
						Loc_enuErrorStatus = LED_enuNok;
						break;
				}
			}
			else
			{
				Loc_enuErrorStatus = LED_enuNok;
			}
		}
		else
		{
			Loc_enuErrorStatus = LED_enuNok;
		}
	}
	else
	{
		Loc_enuErrorStatus = LED_enuNullPtr;
	}

	return Loc_enuErrorStatus;
}

LED_enuErrorStatus_t LED_enuToggle(LED_strState_t* Add_strState)
{
	GPIO_enuErrorStatus_t Loc_enuErrorStatusGPIO;
	LED_enuErrorStatus_t Loc_enuErrorStatus = LED_enuOk;

	if(Add_strState != NULL)
	{
		if((Add_strState->LED_strPort >= LED_enuPortA) && (Add_strState->LED_strPort <= LED_enuPortH))
		{
			if((Add_strState->LED_strPin >= LED_enuPin0) && (Add_strState->LED_strPin <= LED_enuPin15))
			{
				Loc_enuErrorStatusGPIO = GPIO_enuTogglePin(Add_strState->LED_strPort,Add_strState->LED_strPin);
				if(Loc_enuErrorStatusGPIO == GPIO_enuNok)
				{
					Loc_enuErrorStatus = LED_enuNok;
				}
			}
			else
			{
				Loc_enuErrorStatus = LED_enuNok;
			}
		}
		else
		{
			Loc_enuErrorStatus = LED_enuNok;
		}
	}
	else
	{
		Loc_enuErrorStatus = LED_enuNullPtr;
	}

	return Loc_enuErrorStatus;
}
