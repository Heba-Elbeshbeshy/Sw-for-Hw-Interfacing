/*
 * RCC.h
 *
 *  Created on: Jan 8, 2022
 *      Author: Heba Elbeshbeshy
 */

#ifndef INC_RCC_H_
#define INC_RCC_H_

#include "stm32f401xc.h"

//Generic macro
#define GPIO_REG(PORT_ID, REG_ID) ((unsigned int*)(PORT_ID + REG_ID))

//Generic macro
#define Peripheral_REG(PORT_ID, REG_ID) ((unsigned int*)(PORT_ID + REG_ID))

//peripheral clock enable register
#define RCC_AHB1ENR     Peripheral_REG(0x40023800,0x30)
#define RCC_APB2ENR     Peripheral_REG(0x40023800,0x44)

#endif /* INC_RCC_H_ */
