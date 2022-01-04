/*
 * USART.c
 *
 *  Created on: Jan 1, 2022
 *      Author: Heba Elbeshbeshy
 */
#include "USART.h"


void USART_EnableClock(void) {
	*RCC_APB1ENR  |= (1 << 17);
}

void UR_INIT(void)
{
	*USART_CR1    |= (1 << 13); //  UE: USART enable
	*USART_BRR     = 0x683; // 9600 BuadRate
	*USART_CR1    |= (1 << 3); // TE: Transmitter enable
    *USART_CR1    &= ~(0x01 << 12); //  M: Word length character size 8
    *USART_CR1    &= ~(0x01 << 15); // OVERSampling
  	*USART_CR2    &= ~(0x03 << 12); //3:12 STOP bits
  	*GPIOA_AFRL   |= 0x07 << (4*2);
}

void UR_Transmit(char *str)
{
	while ((*str) != '\0')
    {
		while((((*USART_SR) >> 6)&1))
		{
		   *USART_DR = *str;
		   (str++);
		}
    }
}

