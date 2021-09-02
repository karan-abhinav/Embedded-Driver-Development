/*
 * stm32f407xx.h
 *
 *  Created on: Sep 1, 2021
 *      Author: LearningBee
 */

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#include <stdint.h>


/*
 * General definition macros
 */

#define  __vo 	volatile


/*
 * Base Addresses of the Memories
 */

#define FLASH_BASEADDR		0x08000000U  /*Base Address of the Flash Memory*/
#define SRAM1_BASEADDR		0x20000000U
#define	SRAM2_BASEADDR		0x2001C000U

/*
 *  Base Addresses of various Peripheral Bus domains
 */
#define  PERIPH_BASE_ADDR	0x40000000U
#define  APB1_BASE_ADDR		PERIPH_BASE_ADDR
#define  APB2_BASE_ADDR		0x40010000U
#define  AHB1_BASE_ADDR		0x40020000U
#define  AHB2_BASE_ADDR		0x50000000U

/*
 *  Base Addresses of GPIO peripherals hanging on AHB1 bus
 */
#define GPIOA_BASE_ADDR			(AHB1_BASE_ADDR + 0x0000)
#define GPIOB_BASE_ADDR			(AHB1_BASE_ADDR + 0x0400)
#define GPIOC_BASE_ADDR			(AHB1_BASE_ADDR + 0x0800)
#define GPIOD_BASE_ADDR			(AHB1_BASE_ADDR + 0x0C00)
#define GPIOE_BASE_ADDR			(AHB1_BASE_ADDR + 0x1000)
#define GPIOF_BASE_ADDR			(AHB1_BASE_ADDR + 0x1400)
#define GPIOG_BASE_ADDR			(AHB1_BASE_ADDR + 0x1800)
#define GPIOH_BASE_ADDR			(AHB1_BASE_ADDR + 0x1C00)
#define GPIOI_BASE_ADDR			(AHB1_BASE_ADDR + 0x2000)
#define RCC_BASE_ADDR			(AHB1_BASE_ADDR + 0x3800)

/**********************************Peripheral register definition structures******************************/

/*
 * Note : Registers of a peripheral are specific to MCU
 * e.g : Number of registers of SPI peripheral of STM32F4xx family of MCUs may be different (more or less)
 * Compared to number of registers of SPI peripheral of STM32Lx or STM32F0x family of MCUs
 * Please check your device RM
 */
typedef struct
{
	__vo uint32_t MODER;		/*GPIO port mode register    Address offset: 0x00 */
	__vo uint32_t OTYPER;	/* */
	__vo uint32_t OSPEEDR;	/* */
	__vo uint32_t PUPDR;		/* */
	__vo uint32_t IDR;		/* */
	__vo uint32_t ODR;		/* */
	__vo uint32_t BSRR;		/* */
	__vo uint32_t LCKR;		/* */
	__vo uint32_t AF[2];		/* */
}GPIO_RegDef_t;

/*
 * RCC register definition structures
 */
typedef struct{
		__vo uint32_t RCC_CR;			/* RCC clock control register					Address offset: 0x00 */
		__vo uint32_t RCC_PLLCFGR;		/* RCC PLL configuration register				Address offset: 0x04 */
		__vo uint32_t RCC_CFGR;			/* RCC clock configuration register				Address offset: 0x08 */
		__vo uint32_t RCC_CIR;			/* RCC clock interrupt register					Address offset: 0x0C */
		__vo uint32_t RCC_AHB1RSTR;		/* RCC AHB1 peripheral reset register			Address offset: 0x10 */
		__vo uint32_t RCC_AHB2RSTR;		/* RCC AHB2 peripheral reset register			Address offset: 0x14 */
		__vo uint32_t RCC_AHB3RSTR;		/* RCC AHB3 peripheral reset register			Address offset: 0x18 */
		uint32_t	  RESERVED0;		/* Reserved, 0x1C */
		__vo uint32_t RCC_APB1RSTR;		/* RCC APB1 peripheral reset register			Address offset: 0x20 */
		__vo uint32_t RCC_APB2RSTR;		/* RCC APB2 peripheral reset register			Address offset: 0x24 */
		uint32_t      RESERVED1[2];		/* Reserved, 0x28 - 0x2C */
		__vo uint32_t RCC_AHB1ENR;		/* RCC AHB1 peripheral clock register			Address offset: 0x30 */
		__vo uint32_t RCC_AHB2ENR;		/* RCC AHB2 peripheral clock enable register	Address offset: 0x34 */
		__vo uint32_t RCC_AHB3ENR;		/* RCC AHB3 peripheral clock enable register	Address offset: 0x38 */
		uint32_t      RESERVED2;		/* Reserved, 0x3C*/
		__vo uint32_t RCC_APB1ENR;		/* RCC APB1 peripheral clock enable register	Address offset: 0x40 */
		__vo uint32_t RCC_APB2ENR;		/* RCC APB2 peripheral clock enable register	Address offset: 0x44 */
		uint32_t      RESERVED3[2];		/* Reserved, 0x48 - 0x4C */
		__vo uint32_t RCC_AHB1LPENR;	/* RCC AHB1 peripheral clock enable in low power mode register		Address offset: 0x50 */
		__vo uint32_t RCC_AHB2LPENR;	/* RCC AHB2 peripheral clock enable in low power mode register		Address offset: 0x54 */
		__vo uint32_t RCC_AHB3LPENR;	/* RCC AHB3 peripheral clock enable in low power mode register		Address offset: 0x58 */
		uint32_t      RESERVED4;		/* Reserved, 0x5C	*/
		__vo uint32_t RCC_APB1LPENR;	/* RCC APB1 peripheral clock enable in low power mode register		Address offset: 0x60 */
		__vo uint32_t RCC_APB2LPENR;	/* RCC APB2 peripheral clock enabled in low power mode register		Address offset: 0x64 */
		uint32_t      RESERVED5[2];		/* Reserved, 0x68 - 0x6C */
		__vo uint32_t RCC_BDCR;			/* RCC Backup domain control register			Address offset: 0x70 */
		__vo uint32_t RCC_CSR;			/* RCC clock control & status register			Address offset: 0x74 */
		uint32_t      RESERVED6[2];		/* Reserved, 0x78 - 0x7C */
		__vo uint32_t RCC_SSCGR;		/* RCC spread spectrum clock generation register	Address offset: 0x80 */
		__vo uint32_t RCC_PLLI2SCFGR;	/* RCC PLLI2S configuration register			Address offset: 0x84 */
		__vo uint32_t RCC_PLLSAICFGR;	/* RCC PLL configuration register				Address offset: 0x88 */
		__vo uint32_t RCC_DCKCFGR;		/* RCC Dedicated Clock Configuration Register   Address offset: 0x8C */
}RCC_RegDef_t;


/*
 * GPIO Peripheral Definitions (Peripheral Base addresses type casted to GPIO_RegDef_t
 */

#define GPIOA	((GPIO_RegDef_t*)GPIOA_BASE_ADDR)
#define GPIOB	((GPIO_RegDef_t*)GPIOB_BASE_ADDR)
#define GPIOC	((GPIO_RegDef_t*)GPIOC_BASE_ADDR)
#define GPIOD	((GPIO_RegDef_t*)GPIOD_BASE_ADDR)
#define GPIOE	((GPIO_RegDef_t*)GPIOE_BASE_ADDR)
#define GPIOF	((GPIO_RegDef_t*)GPIOF_BASE_ADDR)
#define GPIOG	((GPIO_RegDef_t*)GPIOG_BASE_ADDR)
#define GPIOH	((GPIO_RegDef_t*)GPIOH_BASE_ADDR)
#define GPIOI	((GPIO_RegDef_t*)GPIOI_BASE_ADDR)

#define RCC		((RCC_RegDef_t*)RCC_BASE_ADDR)

/*
 * Clock Enable macros of GPIOx peripherals
 */

#define	GPIOA_PCLK_EN()			(RCC->RCC_AHB1ENR |= (1 << 0))
#define	GPIOB_PCLK_EN()			(RCC->RCC_AHB1ENR |= (1 << 1))
#define	GPIOC_PCLK_EN()			(RCC->RCC_AHB1ENR |= (1 << 2))
#define	GPIOD_PCLK_EN()			(RCC->RCC_AHB1ENR |= (1 << 3))
#define	GPIOE_PCLK_EN()			(RCC->RCC_AHB1ENR |= (1 << 4))
#define	GPIOF_PCLK_EN()			(RCC->RCC_AHB1ENR |= (1 << 5))
#define	GPIOG_PCLK_EN()			(RCC->RCC_AHB1ENR |= (1 << 6))
#define	GPIOH_PCLK_EN()			(RCC->RCC_AHB1ENR |= (1 << 7))
#define	GPIOI_PCLK_EN()			(RCC->RCC_AHB1ENR |= (1 << 8))

/*
 * Clock Disable macros of GPIOx peripherals
 */
#define	GPIOA_PCLK_DI()			(RCC->RCC_AHB1ENR &= ~(1 << 0))
#define	GPIOB_PCLK_DI()			(RCC->RCC_AHB1ENR &= ~(1 << 1))
#define	GPIOC_PCLK_DI()			(RCC->RCC_AHB1ENR &= ~(1 << 2))
#define	GPIOD_PCLK_DI()			(RCC->RCC_AHB1ENR &= ~(1 << 3))
#define	GPIOE_PCLK_DI()			(RCC->RCC_AHB1ENR &= ~(1 << 4))
#define	GPIOF_PCLK_DI()			(RCC->RCC_AHB1ENR &= ~(1 << 5))
#define	GPIOG_PCLK_DI()			(RCC->RCC_AHB1ENR &= ~(1 << 6))
#define	GPIOH_PCLK_DI()			(RCC->RCC_AHB1ENR &= ~(1 << 7))
#define	GPIOI_PCLK_DI()			(RCC->RCC_AHB1ENR &= ~(1 << 8))

/*
 * Macros to reset GPIOx peripherals
 */
#define GPIOA_REG_RESET()        do{(RCC->RCC_AHB1RSTR |= 1<<0);  (RCC->RCC_AHB1RSTR &= ~(1<<0));}while(0)
#define GPIOB_REG_RESET()        do{(RCC->RCC_AHB1RSTR |= 1<<1);  (RCC->RCC_AHB1RSTR &= ~(1<<1));}while(0)
#define GPIOC_REG_RESET()        do{(RCC->RCC_AHB1RSTR |= 1<<2);  (RCC->RCC_AHB1RSTR &= ~(1<<2));}while(0)
#define GPIOD_REG_RESET()        do{(RCC->RCC_AHB1RSTR |= 1<<3);  (RCC->RCC_AHB1RSTR &= ~(1<<3));}while(0)
#define GPIOE_REG_RESET()        do{(RCC->RCC_AHB1RSTR |= 1<<4);  (RCC->RCC_AHB1RSTR &= ~(1<<4));}while(0)
#define GPIOF_REG_RESET()        do{(RCC->RCC_AHB1RSTR |= 1<<5);  (RCC->RCC_AHB1RSTR &= ~(1<<5));}while(0)
#define GPIOG_REG_RESET()        do{(RCC->RCC_AHB1RSTR |= 1<<6);  (RCC->RCC_AHB1RSTR &= ~(1<<6));}while(0)
#define GPIOH_REG_RESET()        do{(RCC->RCC_AHB1RSTR |= 1<<7);  (RCC->RCC_AHB1RSTR &= ~(1<<7));}while(0)
#define GPIOI_REG_RESET()        do{(RCC->RCC_AHB1RSTR |= 1<<8);  (RCC->RCC_AHB1RSTR &= ~(1<<8));}while(0)

/*
 * Some Generic Macros
 */

#define ENABLE 			1
#define DISABLE 		0
#define SET 			ENABLE
#define RESET 			DISABLE
#define GPIO_PIN_SET	SET
#define GPIO_PIN_RESET	RESET
#define FLAG_RESET		RESET
#define FLAG_SET		SET






#endif /* INC_STM32F407XX_H_ */
