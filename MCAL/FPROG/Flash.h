/*
 * Flash.h
 *
 *  Created on: 13 Jun 2023
 *      Author: Omnia
 */

#ifndef FLASH_H_
#define FLASH_H_


typedef enum{
	Flash_enuOk,
	Flash_enuNok,
	Flash_enuNullPtr,
}FlashErrorStatus_t;

typedef enum{
	Flash_enuSector0,
	Flash_enuSector1,
	Flash_enuSector2,
	Flash_enuSector3,
	Flash_enuSector4,
	Flash_enuSector5,
	Flash_enuSector6,
	Flash_enuSector7,
	Flash_enuUserSpec,
	Flash_enuUserConfig,
}FlashSector_t;

typedef enum{
	Flash_enuByte,
	Flash_enuHalfWord,
	Flash_enuWord,
	Flash_enuDoubleWord,
}FlashPage_t;

FlashErrorStatus_t Flash_enuWrite(u32 Cpy_u32MemoryAddress, u64 Cpy_u64Data, FlashPage_t Cpy_enuPageSize);

FlashErrorStatus_t Flash_enuSectorErase(FlashSector_t Cpy_enuSectorNumber);

FlashErrorStatus_t Falsh_enuMassErase(void);


#endif /* FLASH_H_ */
