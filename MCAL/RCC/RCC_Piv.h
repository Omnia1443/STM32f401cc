/*
 * RCC_Piv.h
 *
 *  Created on: 4 Feb 2023
 *      Author: Omnia
 */

#ifndef RCC_PIV_H_
#define RCC_PIV_H_


#define RCC_PLLM_MASK		0x0000003F
#define RCC_PLLN_MASK		0x00007FC0
#define RCC_PLLP_MASK		0x00030000
#define RCC_PLLQ_MASK		0x0F000000

#define RCC_HSI_ON          0x00000001
#define RCC_HSI_OFF         0xFFFFFFFE
#define RCC_HSI_RDY         0xFFFFFFFD

#define RCC_HSE_ON          0x00010000
#define RCC_HSE_OFF         0xFFFEFFFF
#define RCC_HSE_RDY         0xFFFDFFFF

#define RCC_PLL_ON          0x01000000
#define RCC_PLL_OFF         0xFEFFFFFF
#define RCC_PLL_RDY         0xFDFFFFFF

#define RCC_PLL_Q_MIN       2
#define RCC_PLL_Q_MAX       15

#define RCC_PLL_P_MIN       2
#define RCC_PLL_P_MAX       8

#define RCC_PLL_N_MIN       2
#define RCC_PLL_N_MAX       510
#define RCC_PLL_N_WRONG     433

#define RCC_PLL_M_MIN       2
#define RCC_PLL_M_MAX       63

#define RCC_APB1_PRE_CLR    0xFFFFE3FF
#define RCC_APB1_PRE_2      0x00001000
#define RCC_APB1_PRE_4      0x00001400
#define RCC_APB1_PRE_8      0x00001800
#define RCC_APB1_PRE_16     0x00001C00

#define RCC_APB2_PRE_CLR    0xFFFF1FFF
#define RCC_APB2_PRE_2      0x00008000
#define RCC_APB2_PRE_4      0x0000A000
#define RCC_APB2_PRE_8      0x0000C000
#define RCC_APB2_PRE_16     0x0000E000

#define RCC_AHB_PRE_CLR     0xFFFFFF0F
#define RCC_AHB_PRE_2       0x00000080
#define RCC_AHB_PRE_4       0x00000090
#define RCC_AHB_PRE_8       0x000000A0
#define RCC_AHB_PRE_16      0x000000B0
#define RCC_AHB_PRE_64      0x000000C0
#define RCC_AHB_PRE_128     0x000000D0
#define RCC_AHB_PRE_256     0x000000E0
#define RCC_AHB_PRE_512     0x000000F0

#define RCC_SWITCH_CLR      0xFFFFFFF3
#define RCC_SWITCH_HSI      0x00000000
#define RCC_SWITCH_HSE      0x00000001
#define RCC_SWITCH_PLL      0x00000002

#define RCC_CHECK_MASK      0x0000000C
#define RCC_CHECK_HSI       0x00000000
#define RCC_CHECK_HSE       0x00000004
#define RCC_CHECK_PLL       0x00000008

#define RCC_BASE_ADD        0x40023800

#define RCC_CR              *((volatile u32*)(RCC_BASE_ADD + 0x00000000))
#define RCC_PLLCFGR         *((volatile u32*)(RCC_BASE_ADD + 0x00000004))
#define RCC_CFGR            *((volatile u32*)(RCC_BASE_ADD + 0x00000008))
#define RCC_CIR             *((volatile u32*)(RCC_BASE_ADD + 0x0000000C))
#define RCC_AHB1RSTR        *((volatile u32*)(RCC_BASE_ADD + 0x00000010))
#define RCC_AHB2RSTR        *((volatile u32*)(RCC_BASE_ADD + 0x00000014))
#define RCC_APB1RSTR        *((volatile u32*)(RCC_BASE_ADD + 0x00000020))
#define RCC_APB2RSTR        *((volatile u32*)(RCC_BASE_ADD + 0x00000024))
#define RCC_AHB1ENR         *((volatile u32*)(RCC_BASE_ADD + 0x00000030))
#define RCC_AHB2ENR         *((volatile u32*)(RCC_BASE_ADD + 0x00000034))
#define RCC_APB1ENR         *((volatile u32*)(RCC_BASE_ADD + 0x00000040))
#define RCC_APB2ENR         *((volatile u32*)(RCC_BASE_ADD + 0x00000044))
#define RCC_AHB1LPENR       *((volatile u32*)(RCC_BASE_ADD + 0x00000050))
#define RCC_AHB2LPENR       *((volatile u32*)(RCC_BASE_ADD + 0x00000054))
#define RCC_APB1LPENR       *((volatile u32*)(RCC_BASE_ADD + 0x00000060))
#define RCC_APB2LPENR       *((volatile u32*)(RCC_BASE_ADD + 0x00000064))
#define RCC_BDCR            *((volatile u32*)(RCC_BASE_ADD + 0x00000070))
#define RCC_CSR             *((volatile u32*)(RCC_BASE_ADD + 0x00000074))
#define RCC_SSCGR           *((volatile u32*)(RCC_BASE_ADD + 0x00000080))
#define RCC_PLLI2SCFGR      *((volatile u32*)(RCC_BASE_ADD + 0x00000084))
#define RCC_DCKCFGR         *((volatile u32*)(RCC_BASE_ADD + 0x0000008C))


#endif /* RCC_PIV_H_ */
