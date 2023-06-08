/*
 * Swtich.c
 *
 *  Created on: 24 Mar 2023
 *      Author: Omnia
 */
#include "Std_Types.h"
#include "GPIO.h"
#include "Switch.h"


Switch_enuErrorStatus_t Switch_enuInit(Switch_strState_t* Add_strState)
{
	GPIO_enuErrorStatus_t Loc_enuErrorStatusGPIO;
	Switch_enuErrorStatus_t Loc_enuErrorStatus = Switch_enuOk;

	if(Add_strState != NULL)
	{
		if((Add_strState->Switch_strPort >= Switch_enuPortA) && (Add_strState->Switch_strPort <= Switch_enuPortH))
		{
			if((Add_strState->Switch_strPin >= Switch_enuPin0) && (Add_strState->Switch_strPin <= Switch_enuPin15))
			{
				switch(Add_strState->Switch_strDirection)
				{
					case Switch_enuPullUp:
						Loc_enuErrorStatusGPIO = GPIO_enuInit(Add_strState->Switch_strPort,Add_strState->Switch_strPin,GPIO_enuInputPullUp);
						if(Loc_enuErrorStatusGPIO == GPIO_enuNok)
						{
							Loc_enuErrorStatus = Switch_enuNok;
						}
						break;
					case Switch_enuPullDown:
						Loc_enuErrorStatusGPIO = GPIO_enuInit(Add_strState->Switch_strPort,Add_strState->Switch_strPin,GPIO_enuInputPullDown);
						if(Loc_enuErrorStatusGPIO == GPIO_enuNok)
						{
							Loc_enuErrorStatus = Switch_enuNok;
						}
						break;
					case Switch_enuOpenDrain:
						Loc_enuErrorStatusGPIO = GPIO_enuInit(Add_strState->Switch_strPort,Add_strState->Switch_strPin,GPIO_enuInputOpenDrain);
						if(Loc_enuErrorStatusGPIO == GPIO_enuNok)
						{
							Loc_enuErrorStatus = Switch_enuNok;
						}
						break;
					default:
						Loc_enuErrorStatus = Switch_enuNok;
				}
			}
			else
			{
				Loc_enuErrorStatus = Switch_enuNok;
			}
		}
		else
		{
			Loc_enuErrorStatus = Switch_enuNok;
		}
	}
	else
	{
		Loc_enuErrorStatus = Switch_enuNullPtr;
	}

	return Loc_enuErrorStatus;
}

Switch_enuErrorStatus_t Switch_enuGetStatus(Switch_strState_t* Add_strState)
{
	u8 Loc_u8Temp;
	GPIO_enuErrorStatus_t Loc_enuErrorStatusGPIO;
	Switch_enuErrorStatus_t Loc_enuErrorStatus = Switch_enuOk;

	if(Add_strState != NULL)
	{
		if(Add_strState->Switch_strstate != NULL)
		{
			if((Add_strState->Switch_strPort >= Switch_enuPortA) && (Add_strState->Switch_strPort <= Switch_enuPortH))
			{
				if((Add_strState->Switch_strPin >= Switch_enuPin0) && (Add_strState->Switch_strPin <= Switch_enuPin15))
				{
					switch(Add_strState->Switch_strDirection)
					{
						case Switch_enuPullUp:
							Loc_enuErrorStatusGPIO = GPIO_enuGetPin(Add_strState->Switch_strPort,Add_strState->Switch_strPin,&Loc_u8Temp);
							if(Loc_enuErrorStatusGPIO == GPIO_enuOk)
							{
								if(Loc_u8Temp == GPIO_enuHigh)
								{
									*(Add_strState->Switch_strstate) = Switch_enuReleased;
								}
								else if(Loc_u8Temp == GPIO_enuLow)
								{
									*(Add_strState->Switch_strstate) = Switch_enuPressed;
								}
								else
								{
									Loc_enuErrorStatus = Switch_enuNok;
								}
							}
							else
							{
								Loc_enuErrorStatus = Switch_enuNok;
							}
							break;
						case Switch_enuPullDown:
							Loc_enuErrorStatusGPIO = GPIO_enuGetPin(Add_strState->Switch_strPort,Add_strState->Switch_strPin,&Loc_u8Temp);
							if(Loc_enuErrorStatusGPIO == GPIO_enuOk)
							{
								if(Loc_u8Temp == GPIO_enuHigh)
								{
									*(Add_strState->Switch_strstate) = Switch_enuPressed;
								}
								else if(Loc_u8Temp == GPIO_enuLow)
								{
									*(Add_strState->Switch_strstate) = Switch_enuReleased;
								}
								else
								{
									Loc_enuErrorStatus = Switch_enuNok;
								}
							}
							else
							{
								Loc_enuErrorStatus = Switch_enuNok;
							}
							break;
						case Switch_enuOpenDrain:
							Loc_enuErrorStatusGPIO = GPIO_enuGetPin(Add_strState->Switch_strPort,Add_strState->Switch_strPin,&Loc_u8Temp);
							if(Loc_enuErrorStatusGPIO == GPIO_enuOk)
							{
								if(Loc_u8Temp == GPIO_enuHigh)
								{
									*(Add_strState->Switch_strstate) = Switch_enuHigh;
								}
								else if(Loc_u8Temp == GPIO_enuLow)
								{
									*(Add_strState->Switch_strstate) = Switch_enuLow;
								}
								else
								{
									Loc_enuErrorStatus = Switch_enuNok;
								}
							}
							else
							{
								Loc_enuErrorStatus = Switch_enuNok;
							}
							break;
						default:
							Loc_enuErrorStatus = Switch_enuNok;
					}
				}
				else
				{
					Loc_enuErrorStatus = Switch_enuNok;
				}
			}
			else
			{
				Loc_enuErrorStatus = Switch_enuNok;
			}
		}
		else
		{
			Loc_enuErrorStatus = Switch_enuNullPtr;
		}
	}
	else
	{
		Loc_enuErrorStatus = Switch_enuNullPtr;
	}

	return Loc_enuErrorStatus;
}
