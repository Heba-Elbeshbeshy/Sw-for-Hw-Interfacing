/*
 * Author : Abdullah Drwesh
 * Date   : 7/12/2021
 * Version: 1.0.0
 */
#ifndef GPIO_H
#define GPIO_H

#include "RCC.h"

// Result Status
#define OK ((unsigned char)0)
#define NOK ((unsigned char)1)

// Mode Types
#define INPUT ((unsigned char)0x00)
#define OUTPUT ((unsigned char)0x01)
#define ALTERNATE_FUN ((unsigned char)0x02)
#define ANALOG ((unsigned char)0x03)

// Output modes
#define PUSH_PULL ((unsigned char)0x00)
#define OPEN_DRAIN ((unsigned char)0x01)

// Resistor modes
#define NO_PULL_UP_DOWN ((unsigned char)0x00)
#define PULL_UP ((unsigned char)0x02)
#define PULL_DOWN ((unsigned char)0x04)

//PortA
#define GPIOA_MODER  Peripheral_REG(0x40020000,0x00)
#define GPIOA_OTYPER Peripheral_REG(0x40020000,0x04)
#define GPIOA_PUPDR  Peripheral_REG(0x40020000,0x0C)
#define GPIOA_IDR    Peripheral_REG(0x40020000,0x10)
#define GPIOA_ODR    Peripheral_REG(0x40020000,0x14)
//PortB
#define GPIOB_MODER  Peripheral_REG(0x40020400,0x00)
#define GPIOB_OTYPER Peripheral_REG(0x40020400,0x04)
#define GPIOB_PUPDR  Peripheral_REG(0x40020400,0x0C)
#define GPIOB_IDR    Peripheral_REG(0x40020400,0x10)
#define GPIOB_ODR    Peripheral_REG(0x40020400,0x14)

void GPIO_EnableClock(unsigned char PortID);
void GPIO_Init(unsigned char PortID, unsigned char PinNum, unsigned char PinDir,unsigned char DefaultState);
unsigned char GPIO_WritePin(unsigned char PortID, unsigned char PinNum,unsigned char Data);
unsigned char GPIO_ReadPin(unsigned char PortID, unsigned char PinNum);

#endif /* GPIO_H */
