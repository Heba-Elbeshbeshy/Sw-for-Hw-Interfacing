#include "GPIO.h"
#include "stm32f401xc.h"
#include "stm32f401cc_interface.h"

unsigned int Segment_Number[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
int main(void)
{
	for(int i=0; i < 7; i++)
	{
	   GPIO_Init('A', i , OUTPUT, PUSH_PULL);
	}

  while (1)
  {
	for(int j=0; j <10; j++)
	{
	   for(int i=0; i < 7; i++)
	    {
	      GPIO_WritePin('A', i, (Segment_Number[j]>>i)&1);
	    }
	   delay(1000000);
	}
  }
	 return 0;
}
