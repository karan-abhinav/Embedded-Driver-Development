/*
 * stm32f407xx_gpio_driver.h
 *
 *  Created on: Sep 2, 2021
 *      Author: LearningBee
 */

#ifndef INC_STM32F407XX_GPIO_DRIVER_H_
#define INC_STM32F407XX_GPIO_DRIVER_H_
#include "stm32f407xx.h"

/*
 * GPIO_PinNumber
 */
#define GPIO_PIN_NO_0		0
#define GPIO_PIN_NO_1		1
#define GPIO_PIN_NO_2		2
#define GPIO_PIN_NO_3		3
#define GPIO_PIN_NO_4		4
#define GPIO_PIN_NO_5		5
#define GPIO_PIN_NO_6		6
#define GPIO_PIN_NO_7		7
#define GPIO_PIN_NO_8		8
#define GPIO_PIN_NO_9		9
#define GPIO_PIN_NO_10		10
#define GPIO_PIN_NO_11		11
#define GPIO_PIN_NO_12		12
#define GPIO_PIN_NO_13		13
#define GPIO_PIN_NO_14		14
#define GPIO_PIN_NO_15		15

/*
 * GPIO_PinMode
 */
#define GPIO_MODE_IN		0
#define GPIO_MODE_OUT		1
#define GPIO_MODE_ALTFN		2
#define GPIO_MODE_ANALOG	3
#define GPIO_MODE_RT		4
#define GPIO_MODE_FT		5
#define GPIO_MODE_RFT		6

/*
 * GPIO_PinSpeed
 */
#define GPIO_SPEED_LOW 			0
#define GPIO_SPEED_MEDIUM		1
#define GPIO_SPEED_FAST 		2
#define GPIO_SPEED_HIGH 		3

/*
 * GPIO_PinOPType
 */
#define GPIO_OP_TYPE_PP			0
#define GPIO_OP_TYPE_OD			1

/*
 * GPIO_PinPuPdControl
 */
#define GPIO_NO_PUPD			0
#define GPIO_PIN_PU				1
#define GPIO_PIN_PD				2

/*
 * This is a pin configuration structure for the GPIO pins
 */
typedef struct
{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinAltFunMode;
}GPIO_PinConfig_t;


/*
 * This is the handle structure for GPIO
 */
typedef struct
{
	//1. This should hold the base address of the GPIO port to which the pin belongs*/
	GPIO_RegDef_t *pGPIOx;
	//2. This holds the pin configuration settings
	GPIO_PinConfig_t GPIO_PinConfig;
}GPIO_Handle_t;

/*********************************************************************************
 * 						APIs Supported by the driver
 * 		For more information about the APIs check the function definitions
 *********************************************************************************/

/*
 *Peripheral clock setup
 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);

/*
 * Init and De-int
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

/*
 * Data Read and Write OPerations
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber,uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx,uint8_t Value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber);

#endif /* INC_STM32F407XX_GPIO_DRIVER_H_ */
