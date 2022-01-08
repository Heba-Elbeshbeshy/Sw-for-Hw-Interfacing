#include "INTERRUPT.h"

//void Configuration_EXTI(void)
//{
//    // System configuration controller clock enable
//    *RCC_APB2ENR |= (0x01 << 14);
//
//    *SYSCFG_EXTICR1 &= ~(0x0f << 4 * 0);
//
//    *EXTI_IMR |= 1 << 0;
//    *EXTI_FTSR |= 1 << 0;
//
//    *NVIC_ISER0 = 1 << 6;
//}
// System configuration controller clock enable
void SYSCFG_EnableClock()
{
	*RCC_APB2ENR |= (0x01 << 14);
}

void Configuration_EXTI(unsigned char PIN)
{
//                       PA
    *SYSCFG_EXTICR1 &= ~(0x0f << 4 * 0);
//                       PB
//  *SYSCFG_EXTICR1 |= (0x01 << 4 * PIN);

    *EXTI_IMR |= 1 << PIN;

    *EXTI_FTSR |= 1 << PIN;

}

void NVIC_Controller(unsigned char Stream_NM)
{
//	 *NVIC_ISER0 = 1 << (6+PIN);
	 *NVIC_ISER1 = 1 << (24 + Stream_NM);//DMA_2
//	 *NVIC_ISER0 = 1 << (11+ Stream_NM);//DMA_1
}
