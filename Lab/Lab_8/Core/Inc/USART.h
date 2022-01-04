/*
 * USART.h
 *
 *  Created on: Jan 1, 2022
 *      Author: Heba Elbeshbeshy
 */

#ifndef INC_USART_H_
#define INC_USART_H_

#define Peripheral_REG(PORT_ID, REG_ID) ((unsigned int*)(PORT_ID + REG_ID))

#define RCC_APB1ENR    Peripheral_REG(0x40023800 , 0x40)

#define USART_SR       Peripheral_REG(0x40004400 , 0x00)
#define USART_DR       Peripheral_REG(0x40004400 , 0x04)
#define USART_BRR      Peripheral_REG(0x40004400 , 0x08)
#define USART_CR1      Peripheral_REG(0x40004400 , 0x0C)
#define USART_CR2      Peripheral_REG(0x40004400 , 0x10)
#define GPIOA_AFRL     Peripheral_REG(0x40020000 , 0x20)

void USART_EnableClock(void);
void UR_Transmit(char* str);
void UR_INIT(void);

#endif /* INC_USART_H_ */
