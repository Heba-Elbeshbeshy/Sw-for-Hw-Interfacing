/*
 * main.c
 *
 *  Created on: Dec 31, 2021
 *      Author: Heba Elbeshbeshy
 */

#include "GPIO.h"
#include "USART.h"

int main(void)
{
    GPIO_EnableClock(0);  // Enable GPIOA
    GPIO_Init(0, 2, ALTERNATE_FUN, PUSH_PULL);

    USART_EnableClock();
    UR_INIT();
    UR_Transmit("Hello World!");

    while (1){}
    return 0;
}


