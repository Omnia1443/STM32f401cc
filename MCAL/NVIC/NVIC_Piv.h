/*
 * NVIC_Piv.h
 *
 *  Created on: 21 Mar 2023
 *      Author: Omnia
 */

#ifndef NVIC_PIV_H_
#define NVIC_PIV_H_


#define NVIC_GROUPING4		  0x05FA0300
#define NVIC_GROUPING3		  0x05FA0400
#define NVIC_GROUPING2		  0x05FA0500
#define NVIC_GROUPING1		  0x05FA0600
#define NVIC_GROUPING0		  0x05FA0700

#define NVIC_BASE_ADDRESS     0xE000E100

#define NVIC_ISER0            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000000))
#define NVIC_ISER1            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000004))
#define NVIC_ISER2            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000008))
#define NVIC_ISER3            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x0000000C))
#define NVIC_ISER4            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000010))
#define NVIC_ISER5            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000014))
#define NVIC_ISER6            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000018))
#define NVIC_ISER7            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x0000001C))

#define NVIC_ICER0            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000080))
#define NVIC_ICER1            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000084))
#define NVIC_ICER2            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000088))
#define NVIC_ICER3            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x0000008C))
#define NVIC_ICER4            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000090))
#define NVIC_ICER5            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000094))
#define NVIC_ICER6            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000098))
#define NVIC_ICER7            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x0000009C))

#define NVIC_ISPR0            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000100))
#define NVIC_ISPR1            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000104))
#define NVIC_ISPR2            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000108))
#define NVIC_ISPR3            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x0000010C))
#define NVIC_ISPR4            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000110))
#define NVIC_ISPR5            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000114))
#define NVIC_ISPR6            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000118))
#define NVIC_ISPR7            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x0000011C))

#define NVIC_ICPR0            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000180))
#define NVIC_ICPR1            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000184))
#define NVIC_ICPR2            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000188))
#define NVIC_ICPR3            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x0000018C))
#define NVIC_ICPR4            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000190))
#define NVIC_ICPR5            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000194))
#define NVIC_ICPR6            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000198))
#define NVIC_ICPR7            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x0000019C))

#define NVIC_IABR0            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000200))
#define NVIC_IABR1            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000204))
#define NVIC_IABR2            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000208))
#define NVIC_IABR3            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x0000020C))
#define NVIC_IABR4            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000210))
#define NVIC_IABR5            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000214))
#define NVIC_IABR6            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000218))
#define NVIC_IABR7            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x0000021C))

#define NVIC_IPR              ((volatile u8*)(NVIC_BASE_ADDRESS + 0x00000300))

#define NVIC_IPR0             *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000300))
#define NVIC_IPR1             *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000304))
#define NVIC_IPR2             *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000308))
#define NVIC_IPR3             *((volatile u32*)(NVIC_BASE_ADDRESS + 0x0000030C))
#define NVIC_IPR4             *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000310))
#define NVIC_IPR5             *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000314))
#define NVIC_IPR6             *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000318))
#define NVIC_IPR7             *((volatile u32*)(NVIC_BASE_ADDRESS + 0x0000031C))
#define NVIC_IPR8             *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000320))
#define NVIC_IPR9             *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000324))
#define NVIC_IPR10            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000328))
#define NVIC_IPR11            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x0000032C))
#define NVIC_IPR12            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000330))
#define NVIC_IPR13            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000334))
#define NVIC_IPR14            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000338))
#define NVIC_IPR15            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x0000033C))
#define NVIC_IPR16            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000340))
#define NVIC_IPR17            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000344))
#define NVIC_IPR18            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000348))
#define NVIC_IPR19            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x0000034C))
#define NVIC_IPR20            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000350))
#define NVIC_IPR21            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000354))
#define NVIC_IPR22            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000358))
#define NVIC_IPR23            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x0000035C))
#define NVIC_IPR24            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000360))
#define NVIC_IPR25            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000364))
#define NVIC_IPR26            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000368))
#define NVIC_IPR27            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x0000036C))
#define NVIC_IPR28            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000370))
#define NVIC_IPR29            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000374))
#define NVIC_IPR30            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000378))
#define NVIC_IPR31            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x0000037C))
#define NVIC_IPR32            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000380))
#define NVIC_IPR33            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000384))
#define NVIC_IPR34            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000388))
#define NVIC_IPR35            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x0000038C))
#define NVIC_IPR36            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000390))
#define NVIC_IPR37            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000394))
#define NVIC_IPR38            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000398))
#define NVIC_IPR39            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x0000039C))
#define NVIC_IPR40            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x000003A0))
#define NVIC_IPR41            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x000003A4))
#define NVIC_IPR42            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x000003A8))
#define NVIC_IPR43            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x000003AC))
#define NVIC_IPR44            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x000003B0))
#define NVIC_IPR45            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x000003B4))
#define NVIC_IPR46            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x000003B8))
#define NVIC_IPR47            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x000003BC))
#define NVIC_IPR48            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x000003C0))
#define NVIC_IPR49            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x000003C4))
#define NVIC_IPR50            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x000003C8))
#define NVIC_IPR51            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x000003CC))
#define NVIC_IPR52            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x000003D0))
#define NVIC_IPR53            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x000003D4))
#define NVIC_IPR54            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x000003D8))
#define NVIC_IPR55            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x000003DC))
#define NVIC_IPR56            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x000003E0))
#define NVIC_IPR57            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x000003E4))
#define NVIC_IPR58            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x000003E8))
#define NVIC_IPR59            *((volatile u32*)(NVIC_BASE_ADDRESS + 0x000003EC))

#define NVIC_STIR             *((volatile u32*)(NVIC_BASE_ADDRESS + 0x00000E00))

#define ACTLR				  *((volatile u32*)0xE000E008)
#define CPUID				  *((volatile u32*)0xE000ED00)
#define ICSR				  *((volatile u32*)0xE000ED04)
#define VTOR				  *((volatile u32*)0xE000ED08)
#define AIRCR				  *((volatile u32*)0xE000ED0C)
#define SCR					  *((volatile u32*)0xE000ED10)
#define CCR					  *((volatile u32*)0xE000ED14)
#define SHPR1				  *((volatile u32*)0xE000ED18)
#define SHPR2				  *((volatile u32*)0xE000ED1C)
#define SHPR3				  *((volatile u32*)0xE000ED20)
#define SHCSR				  *((volatile u32*)0xE000ED24)
#define CFSR				  *((volatile u32*)0xE000ED28)
#define MMSR				  *((volatile u8*)0xE000ED28)
#define BFSR				  *((volatile u8*)0xE000ED29)
#define UFSR				  *((volatile u16*)0xE000ED2A)
#define HFSR				  *((volatile u32*)0xE000ED2C)
#define MMAR				  *((volatile u32*)0xE000ED34)
#define BFAR				  *((volatile u32*)0xE000ED38)
#define AFSR				  *((volatile u32*)0xE000ED3C)


#endif /* NVIC_PIV_H_ */
