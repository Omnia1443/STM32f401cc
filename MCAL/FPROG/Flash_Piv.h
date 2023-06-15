/*
 * Flash_Piv.h
 *
 *  Created on: 13 Jun 2023
 *      Author: Omnia
 */

#ifndef FLASH_PIV_H_
#define FLASH_PIV_H_


#define FLASH_SECTOR0_MASK		0xFFFFFF87
#define FLASH_SECTOR1_MASK		0x00000008
#define FLASH_SECTOR2_MASK		0x00000010
#define FLASH_SECTOR3_MASK		0x00000018
#define FLASH_SECTOR4_MASK		0x00000020
#define FLASH_SECTOR5_MASK		0x00000028
#define FLASH_SECTOR6_MASK		0x00000030
#define FLASH_SECTOR7_MASK		0x00000038
#define FLASH_USR_SPEC_MASK		0x00000060
#define FLASH_USR_CNFG_MASK		0x00000068

#define FLASH_BASE_ADDRESS		0x40023C00

#define FLASH_ACR				*((volatile u32*)(FLASH_BASE_ADDRESS + 0x00))
#define PRFTEN					8
#define ICEN					9
#define DCEN					10
#define ICRST					11
#define DCRST					12

#define FLASH_KEYR				*((volatile u32*)(FLASH_BASE_ADDRESS + 0x04))

#define FLASH_OPTKEYR			*((volatile u32*)(FLASH_BASE_ADDRESS + 0x08))

#define FLASH_SR				*((volatile u32*)(FLASH_BASE_ADDRESS + 0x0C))
#define EOP						0
#define OPERR					1
#define WRPERR					4
#define PGAERR					5
#define PGPERR					6
#define PGSERR					7
#define RDERR					8
#define BSY						16

#define FLASH_CR				*((volatile u32*)(FLASH_BASE_ADDRESS + 0x10))
#define PG						0
#define SER						1
#define MER						2
#define STRT					16
#define EOPIE					24
#define ERRIE					25
#define LOCK					31

#define FLASH_OPTCR				*((volatile u32*)(FLASH_BASE_ADDRESS + 0x14))
#define OPTLOCK					0
#define OPTSTRT					1
#define WDG_SW					5
#define NRST_STOP				6
#define NRST_STDBY				7
#define SPRMOD					31


#endif /* FLASH_PIV_H_ */
