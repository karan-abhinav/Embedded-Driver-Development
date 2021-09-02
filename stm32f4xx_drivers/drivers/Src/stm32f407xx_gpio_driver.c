/*
 * stm32f407xx_gpio_driver.c
 *
 *  Created on: Sep 2, 2021
 *      Author: LearningBee
 */
#include "stm32f407xx_gpio_driver.h"

/*
 *Peripheral clock setup
 */
/************************************************************
 * @FunctionName 		:	GPIO_PeriClockControl
 * @brief				:	enable the clock of GPIOx peripheral
 *
 * @param[in]			:
 * @param[in]			:
 *
 * @return				:	None
 *
 * @Note				:
 ************************************************************/

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		//Enable the Clock
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_EN();
		}else if (pGPIOx == GPIOB)
		{
			GPIOB_PCLK_EN();
		}else if (pGPIOx == GPIOC)
		{
			GPIOC_PCLK_EN();
		}else if (pGPIOx == GPIOD)
		{
			GPIOD_PCLK_EN();
		}else if (pGPIOx == GPIOE)
		{
			GPIOE_PCLK_EN();
		}else if (pGPIOx == GPIOF)
		{
			GPIOF_PCLK_EN();
		}else if (pGPIOx == GPIOG)
		{
			GPIOG_PCLK_EN();
		}else if (pGPIOx == GPIOH)
		{
			GPIOH_PCLK_EN();
		}else if (pGPIOx == GPIOI)
		{
			GPIOI_PCLK_EN();
		}
	}else
	{
		//Disable the clock
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_DI();
		}else if (pGPIOx == GPIOB)
				{
					GPIOB_PCLK_DI();
				}else if (pGPIOx == GPIOC)
				{
					GPIOC_PCLK_DI();
				}else if (pGPIOx == GPIOD)
				{
					GPIOD_PCLK_DI();
				}else if (pGPIOx == GPIOE)
				{
					GPIOE_PCLK_DI();
				}else if (pGPIOx == GPIOF)
				{
					GPIOF_PCLK_DI();
				}else if (pGPIOx == GPIOG)
				{
					GPIOG_PCLK_DI();
				}else if (pGPIOx == GPIOH)
				{
					GPIOH_PCLK_DI();
				}else if (pGPIOx == GPIOI)
				{
					GPIOI_PCLK_DI();
				}
	}


}

/*
 * Init and De-int
 */
/************************************************************
 * @FunctionName 		:
 * @brief			:
 *
 * @param[in]		:
 * @param[in]		:
 *
 * @return			:
 *
 * @Note			:
 ************************************************************/

void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
	uint32_t temp = 0;		//temp register
	//Enable the peripheral clock
	GPIO_PeriClockControl(pGPIOHandle->pGPIOx, ENABLE);

	//1. Configure the mode of the GPIO pin

	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG)
	{
		//Non interrupt mode
		temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->MODER &= ~(3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		pGPIOHandle->pGPIOx->MODER |= temp;

	}else
	{
		//Interupt mode will code later
	}
	temp = 0;
	//2. COnfigure the speed
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEEDR &= ~(3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OSPEEDR |= temp;
	temp = 0;
	//3. Configure the o/P type
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OTYPER &= ~(1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OTYPER |= temp;
	temp = 0;
	//4. COnfigure the PuPd setting
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->PUPDR &= ~(3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->PUPDR |= temp;
	temp = 0;
	//5. Configure the alternate functionality
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode == GPIO_MODE_ALTFN)
	{
		uint8_t temp1, temp2;
		temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8;
		temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8;
		pGPIOHandle->pGPIOx->AF[temp1] &= ~(0xF << (4 * temp2));
		pGPIOHandle->pGPIOx->AF[temp1] |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4 * temp2));
	}

}
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{
	//Enable the Clock
			if(pGPIOx == GPIOA)
			{
				GPIOA_REG_RESET();
			}else if (pGPIOx == GPIOB)
			{
				GPIOB_REG_RESET();
			}else if (pGPIOx == GPIOC)
			{
				GPIOC_REG_RESET();
			}else if (pGPIOx == GPIOD)
			{
				GPIOD_REG_RESET();
			}else if (pGPIOx == GPIOE)
			{
				GPIOE_REG_RESET();
			}else if (pGPIOx == GPIOF)
			{
				GPIOF_REG_RESET();
			}else if (pGPIOx == GPIOG)
			{
				GPIOG_REG_RESET();
			}else if (pGPIOx == GPIOH)
			{
				GPIOH_REG_RESET();
			}else if (pGPIOx == GPIOI)
			{
				GPIOI_REG_RESET();
			}

}

/*
 * Data Read and Write OPerations
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	uint8_t value;
	value = (uint8_t)((pGPIOx->IDR >> PinNumber)& 0x00000001);
	return value;
}
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
	uint16_t value;
	value = (uint16_t)pGPIOx->IDR;
	return value;
}
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber,uint8_t Value)
{
	if(Value == GPIO_PIN_SET)
	{
		pGPIOx->ODR |= (1 << PinNumber);
	}else
	{
		pGPIOx->ODR &= ~(1 << PinNumber);
	}
}
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx,uint8_t Value)
{
	pGPIOx->ODR = Value;
}

void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber)
{
	pGPIOx->ODR ^= (1 << PinNumber);
}
