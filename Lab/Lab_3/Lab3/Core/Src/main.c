#include "stm32f401cc_interface.h"

void delay(int secs)
{
for(int i=0; i<secs; i++){}
}

int main(void) {
	        RCC_AHB1ENR |= (1<<0);
                GPIOA_MODER &= ~(1<<(2*0));
                GPIOA_MODER |= (1<<(2*0));
                GPIOA_OTYPER &= ~(1<<0);

  while (1) {
	  GPIOA_ODR |= (1<<0);
	  delay(1000000);
		
            GPIOA_ODR &= ~(1<<0);
            delay(1000000);
	   }
   return 0;
}




