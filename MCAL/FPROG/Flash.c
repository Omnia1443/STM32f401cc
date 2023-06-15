/*
 * Flash.c
 *
 *  Created on: 13 Jun 2023
 *      Author: Omnia
 */

#include "Std_Types.h"
#include "Bit_Math.h"
#include "Flash_Piv.h"
#include "Flash.h"

FlashErrorStatus_t Flash_enuWrite(u32 Cpy_u32MemoryAddress, u64 Cpy_u64Data, FlashPage_t Cpy_enuPageSize)
{
	FlashErrorStatus_t Loc_enuErrorStatus = Flash_enuOk;
	u8 Loc_u8Counter = 0;

	if((Cpy_u32MemoryAddress <= 0x0803FFFF) && (Cpy_u32MemoryAddress >= 0x08000000))
	{
		/* unlock control register */
		FLASH_KEYR = 0x45670123;
		FLASH_KEYR = 0xCDEF89AB;

		while((FLASH_CR & (1 << LOCK)) && (Loc_u8Counter < 20))
		{
			Loc_u8Counter++;
		}

		if(Loc_u8Counter == 20)
		{
			Loc_enuErrorStatus = Flash_enuNok;
		}
		else
		{
			/* check if flash memory operation ongoing or not */
			if(!(FLASH_SR & (1 << BSY)))
			{
				/* activate programming */
				FLASH_CR |= (1 << PG);

				/* write on flash */
				switch(Cpy_enuPageSize)
				{
					case Flash_enuByte:
						(*(volatile u32*)Cpy_u32MemoryAddress) = (u8)Cpy_u64Data;
						break;
					case Flash_enuWord:
						(*(volatile u32*)Cpy_u32MemoryAddress) = (u16)Cpy_u64Data;
						break;
					case Flash_enuHalfWord:
						(*(volatile u32*)Cpy_u32MemoryAddress) = (u32)Cpy_u64Data;
						break;
					case Flash_enuDoubleWord:
						(*(volatile u32*)Cpy_u32MemoryAddress) = (u64)Cpy_u64Data;
						break;
				}

				while(FLASH_SR & (1 << BSY));
			}
			else
			{
				Loc_enuErrorStatus = Flash_enuNok;
			}
		}

	}
	else
	{
		Loc_enuErrorStatus = Flash_enuNok;
	}

	/* Lock Flash register */
	FLASH_CR |= (1 << LOCK);

	return Loc_enuErrorStatus;
}

FlashErrorStatus_t Flash_enuSectorErase(FlashSector_t Cpy_enuSectorNumber)
{
	FlashErrorStatus_t Loc_enuErrorStatus = Flash_enuOk;
	u32 Loc_u32Var;
	u8 Loc_u8Counter = 0;

	/* unlock control register */
	FLASH_KEYR = 0x45670123;
	FLASH_KEYR = 0xCDEF89AB;

	while((FLASH_CR & (1 << LOCK)) && (Loc_u8Counter < 20))
	{
		Loc_u8Counter++;
	}

	if(Loc_u8Counter == 20)
	{
		Loc_enuErrorStatus = Flash_enuNok;
	}
	else
	{
		/* check if flash memory operation ongoing or not */
		if(!(FLASH_SR & (1 << BSY)))
		{
		/* activate sector erase */
		FLASH_CR |= (1 << SER);

		Loc_u32Var = FLASH_CR;

		switch(Cpy_enuSectorNumber)
		{
			case Flash_enuSector0:
				Loc_u32Var &= FLASH_SECTOR0_MASK;
				FLASH_CR = Loc_u32Var;
				break;
			case Flash_enuSector1:
				Loc_u32Var &= FLASH_SECTOR0_MASK;
				Loc_u32Var |= FLASH_SECTOR1_MASK;
				FLASH_CR = Loc_u32Var;
				break;
			case Flash_enuSector2:
				Loc_u32Var &= FLASH_SECTOR0_MASK;
				Loc_u32Var |= FLASH_SECTOR2_MASK;
				FLASH_CR = Loc_u32Var;
				break;
			case Flash_enuSector3:
				Loc_u32Var &= FLASH_SECTOR0_MASK;
				Loc_u32Var |= FLASH_SECTOR3_MASK;
				FLASH_CR = Loc_u32Var;
				break;
			case Flash_enuSector4:
				Loc_u32Var &= FLASH_SECTOR0_MASK;
				Loc_u32Var |= FLASH_SECTOR4_MASK;
				FLASH_CR = Loc_u32Var;
				break;
			case Flash_enuSector5:
				Loc_u32Var &= FLASH_SECTOR0_MASK;
				Loc_u32Var |= FLASH_SECTOR5_MASK;
				FLASH_CR = Loc_u32Var;
				break;
			case Flash_enuSector6:
				Loc_u32Var &= FLASH_SECTOR0_MASK;
				Loc_u32Var |= FLASH_SECTOR6_MASK;
				FLASH_CR = Loc_u32Var;
				break;
			case Flash_enuSector7:
				Loc_u32Var &= FLASH_SECTOR0_MASK;
				Loc_u32Var |= FLASH_SECTOR7_MASK;
				FLASH_CR = Loc_u32Var;
				break;
			case Flash_enuUserSpec:
				Loc_u32Var &= FLASH_SECTOR0_MASK;
				Loc_u32Var |= FLASH_USR_SPEC_MASK;
				FLASH_CR = Loc_u32Var;
				break;
			case Flash_enuUserConfig:
				Loc_u32Var &= FLASH_SECTOR0_MASK;
				Loc_u32Var |= FLASH_USR_CNFG_MASK;
				FLASH_CR = Loc_u32Var;
				break;
			default:
				Loc_enuErrorStatus = Flash_enuNok;
				break;
		}

		/* start erase operation */
		FLASH_CR |= (1 << STRT);

		while(FLASH_SR & (1 << BSY));
		}
		else
		{
			Loc_enuErrorStatus = Flash_enuNok;
		}
	}

	/* Lock Flash register */
	FLASH_CR |= (1 << LOCK);

	return Loc_enuErrorStatus;
}

FlashErrorStatus_t Falsh_enuMassErase(void)
{
	FlashErrorStatus_t Loc_enuErrorStatus = Flash_enuOk;
	u8 Loc_u8Counter = 0;

	/* unlock control register */
	FLASH_KEYR = 0x45670123;
	FLASH_KEYR = 0xCDEF89AB;

	while((FLASH_CR & (1 << LOCK)) && (Loc_u8Counter < 20))
	{
		Loc_u8Counter++;
	}

	if(Loc_u8Counter == 20)
	{
		Loc_enuErrorStatus = Flash_enuNok;
	}
	else
	{
		/* check if flash memory operation ongoing or not */
		if(!(FLASH_SR & (1 << BSY)))
		{
			/* activate mass erase */
			FLASH_CR |= (1 << MER);

			/* start erase operation */
			FLASH_CR |= (1 << STRT);

			while(FLASH_SR & (1 << BSY));
		}
		else
		{
			Loc_enuErrorStatus = Flash_enuNok;
		}
	}

	/* Lock Flash register */
	FLASH_CR |= (1 << LOCK);

	return Loc_enuErrorStatus;
}
