#ifndef INTERRUPT_H
#define INTERRUPT_H

#include "stm32f401xc.h"

//Generic macro
#define Peripheral_REG(PORT_ID, REG_ID) ((unsigned int*)(PORT_ID + REG_ID))

//peripheral clock enable register
#define RCC_APB2ENR     Peripheral_REG(0x40023800,0x44)
//SYSCFG
#define SYSCFG_EXTICR1  Peripheral_REG(0x40013800, 0x08)
//EXTI
#define EXTI_IMR        Peripheral_REG(0x40013C00, 0x00)
#define EXTI_FTSR       Peripheral_REG(0x40013C00, 0x0C)
#define EXTI_PR         Peripheral_REG(0x40013C00,  0x14)

// NVIC
#define NVIC_ISER0      Peripheral_REG(0xE000E100,0x00)

void SYSCFG_EnableClock();
void Configuration_EXTI(unsigned char PIN);

#endif /* INTERRUPT_H */
