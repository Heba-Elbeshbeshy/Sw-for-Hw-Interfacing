#ifndef INTERRUPT_H
#define INTERRUPT_H

#include "RCC.h"

//SYSCFG
#define SYSCFG_EXTICR1  Peripheral_REG(0x40013800, 0x08)
//EXTI
#define EXTI_IMR        Peripheral_REG(0x40013C00, 0x00)
#define EXTI_FTSR       Peripheral_REG(0x40013C00, 0x0C)
#define EXTI_PR         Peripheral_REG(0x40013C00,  0x14)

// NVIC
#define NVIC_ISER0      Peripheral_REG(0xE000E100,0x00)
#define NVIC_ISER1      Peripheral_REG(0xE000E100,0x04)

void SYSCFG_EnableClock();
void Configuration_EXTI(unsigned char PIN);
void NVIC_Controller(unsigned char Peripheral_ID,unsigned char Stream_NM);

#endif /* INTERRUPT_H */
