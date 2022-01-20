#include "GPIO.h"
#include "stm32f401xc.h"
#include "stm32f401cc_interface.h"

int color = 0;

int main(void)
{
	GPIO_Init('B', 3 , INPUT, PULL_UP);
	GPIO_Init('B', 5 , OUTPUT, PUSH_PULL);
	GPIO_Init('B', 6 , OUTPUT, PUSH_PULL);
	GPIO_Init('B', 7 , OUTPUT, PUSH_PULL);

  while (1)
  {
		  unsigned char Button = GPIO_ReadPin('B', 3);
		  delay(1000);
		  if (Button && !(GPIO_ReadPin('B', 3)))
			{
		      GPIO_WritePin('B', 0, 7, 5);
		      GPIO_WritePin('B', 1, color, 5);
		      color+=1;
		      if(color==8){color=1;}
			}
  }
	 return 0;
}
