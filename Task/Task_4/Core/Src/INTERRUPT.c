#include "INTERRUPT.h"

//#define PORT_B ((unsigned char)0x01)
//#define PORT_A ((unsigned char)0x0f)

// System configuration controller clock enable
void SYSCFG_EnableClock()
{
	*RCC_APB2ENR |= (0x01 << 14);
}

void Configuration_EXTI(unsigned char PIN)
{
//                       PA
//  *SYSCFG_EXTICR1 &= ~(0x0f << 4 * 0);
//                       PB
    *SYSCFG_EXTICR1 |= (0x01 << 4 * PIN);

    *EXTI_IMR |= 1 << PIN;

    *EXTI_FTSR |= 1 << PIN;

    *NVIC_ISER0 = 1 << (6+PIN);

}

