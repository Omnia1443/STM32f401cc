/*
 * GPIO_Piv.h
 *
 *  Created on: 20 Mar 2023
 *      Author: Omnia
 */

#ifndef GPIO_PIV_H_
#define GPIO_PIV_H_


#define GPIO_INPUT        3
#define GPIO_OUTPUT       1
#define GPIO_ALT_FUN      2
#define GPIO_ANALOG       3

#define GPIO_OPENDRAIN    3
#define GPIO_PULLUP       1
#define GPIO_PULLDOWN     2

#define GPIOA_BASE_ADD    0x40020000
#define GPIOB_BASE_ADD    0x40020400
#define GPIOC_BASE_ADD    0x40020800
#define GPIOD_BASE_ADD    0x40020C00
#define GPIOE_BASE_ADD    0x40021000
#define GPIOH_BASE_ADD    0x40021C00


#define GPIOA_MODER       *((volatile u32*)(GPIOA_BASE_ADD + 0x00000000))
#define GPIOB_MODER       *((volatile u32*)(GPIOB_BASE_ADD + 0x00000000))
#define GPIOC_MODER       *((volatile u32*)(GPIOC_BASE_ADD + 0x00000000))
#define GPIOD_MODER       *((volatile u32*)(GPIOD_BASE_ADD + 0x00000000))
#define GPIOE_MODER       *((volatile u32*)(GPIOE_BASE_ADD + 0x00000000))
#define GPIOH_MODER       *((volatile u32*)(GPIOH_BASE_ADD + 0x00000000))

#define GPIOA_OTYPER      *((volatile u32*)(GPIOA_BASE_ADD + 0x00000004))
#define GPIOB_OTYPER      *((volatile u32*)(GPIOB_BASE_ADD + 0x00000004))
#define GPIOC_OTYPER      *((volatile u32*)(GPIOC_BASE_ADD + 0x00000004))
#define GPIOD_OTYPER      *((volatile u32*)(GPIOD_BASE_ADD + 0x00000004))
#define GPIOE_OTYPER      *((volatile u32*)(GPIOE_BASE_ADD + 0x00000004))
#define GPIOH_OTYPER      *((volatile u32*)(GPIOH_BASE_ADD + 0x00000004))

#define GPIOA_OSPEEDR     *((volatile u32*)(GPIOA_BASE_ADD + 0x00000008))
#define GPIOB_OSPEEDR     *((volatile u32*)(GPIOB_BASE_ADD + 0x00000008))
#define GPIOC_OSPEEDR     *((volatile u32*)(GPIOC_BASE_ADD + 0x00000008))
#define GPIOD_OSPEEDR     *((volatile u32*)(GPIOD_BASE_ADD + 0x00000008))
#define GPIOE_OSPEEDR     *((volatile u32*)(GPIOE_BASE_ADD + 0x00000008))
#define GPIOH_OSPEEDR     *((volatile u32*)(GPIOH_BASE_ADD + 0x00000008))

#define GPIOA_PUPDR       *((volatile u32*)(GPIOA_BASE_ADD + 0x0000000C))
#define GPIOB_PUPDR       *((volatile u32*)(GPIOB_BASE_ADD + 0x0000000C))
#define GPIOC_PUPDR       *((volatile u32*)(GPIOC_BASE_ADD + 0x0000000C))
#define GPIOD_PUPDR       *((volatile u32*)(GPIOD_BASE_ADD + 0x0000000C))
#define GPIOE_PUPDR       *((volatile u32*)(GPIOE_BASE_ADD + 0x0000000C))
#define GPIOH_PUPDR       *((volatile u32*)(GPIOH_BASE_ADD + 0x0000000C))

#define GPIOA_IDR         *((volatile u32*)(GPIOA_BASE_ADD + 0x00000010))
#define GPIOB_IDR         *((volatile u32*)(GPIOB_BASE_ADD + 0x00000010))
#define GPIOC_IDR         *((volatile u32*)(GPIOC_BASE_ADD + 0x00000010))
#define GPIOD_IDR         *((volatile u32*)(GPIOD_BASE_ADD + 0x00000010))
#define GPIOE_IDR         *((volatile u32*)(GPIOE_BASE_ADD + 0x00000010))
#define GPIOH_IDR         *((volatile u32*)(GPIOH_BASE_ADD + 0x00000010))

#define GPIOA_ODR         *((volatile u32*)(GPIOA_BASE_ADD + 0x00000014))
#define GPIOB_ODR         *((volatile u32*)(GPIOB_BASE_ADD + 0x00000014))
#define GPIOC_ODR         *((volatile u32*)(GPIOC_BASE_ADD + 0x00000014))
#define GPIOD_ODR         *((volatile u32*)(GPIOD_BASE_ADD + 0x00000014))
#define GPIOE_ODR         *((volatile u32*)(GPIOE_BASE_ADD + 0x00000014))
#define GPIOH_ODR         *((volatile u32*)(GPIOH_BASE_ADD + 0x00000014))

#define GPIOA_BSRR        *((volatile u32*)(GPIOA_BASE_ADD + 0x00000018))
#define GPIOB_BSRR        *((volatile u32*)(GPIOB_BASE_ADD + 0x00000018))
#define GPIOC_BSRR        *((volatile u32*)(GPIOC_BASE_ADD + 0x00000018))
#define GPIOD_BSRR        *((volatile u32*)(GPIOD_BASE_ADD + 0x00000018))
#define GPIOE_BSRR        *((volatile u32*)(GPIOE_BASE_ADD + 0x00000018))
#define GPIOH_BSRR        *((volatile u32*)(GPIOH_BASE_ADD + 0x00000018))

#define GPIOA_LCKR        *((volatile u32*)(GPIOA_BASE_ADD + 0x0000001C))
#define GPIOB_LCKR        *((volatile u32*)(GPIOB_BASE_ADD + 0x0000001C))
#define GPIOC_LCKR        *((volatile u32*)(GPIOC_BASE_ADD + 0x0000001C))
#define GPIOD_LCKR        *((volatile u32*)(GPIOD_BASE_ADD + 0x0000001C))
#define GPIOE_LCKR        *((volatile u32*)(GPIOE_BASE_ADD + 0x0000001C))
#define GPIOH_LCKR        *((volatile u32*)(GPIOH_BASE_ADD + 0x0000001C))

#define GPIOA_AFRL        *((volatile u32*)(GPIOA_BASE_ADD + 0x00000020))
#define GPIOB_AFRL        *((volatile u32*)(GPIOB_BASE_ADD + 0x00000020))
#define GPIOC_AFRL        *((volatile u32*)(GPIOC_BASE_ADD + 0x00000020))
#define GPIOD_AFRL        *((volatile u32*)(GPIOD_BASE_ADD + 0x00000020))
#define GPIOE_AFRL        *((volatile u32*)(GPIOE_BASE_ADD + 0x00000020))
#define GPIOH_AFRL        *((volatile u32*)(GPIOH_BASE_ADD + 0x00000020))

#define GPIOA_AFRH        *((volatile u32*)(GPIOA_BASE_ADD + 0x00000024))
#define GPIOB_AFRH        *((volatile u32*)(GPIOB_BASE_ADD + 0x00000024))
#define GPIOC_AFRH        *((volatile u32*)(GPIOC_BASE_ADD + 0x00000024))
#define GPIOD_AFRH        *((volatile u32*)(GPIOD_BASE_ADD + 0x00000024))
#define GPIOE_AFRH        *((volatile u32*)(GPIOE_BASE_ADD + 0x00000024))
#define GPIOH_AFRH        *((volatile u32*)(GPIOH_BASE_ADD + 0x00000024))


#endif /* GPIO_PIV_H_ */
