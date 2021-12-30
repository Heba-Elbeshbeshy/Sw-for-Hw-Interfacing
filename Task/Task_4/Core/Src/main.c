
#include "INTERRUPT.h"
#include "GPIO.h"

unsigned char NUM = 0;
unsigned int Segment_Number[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};

void Display_SevenSeg(unsigned char NUM);
void DisableInterrupt(void);
void EnableInterrupt(void);

int main(void)
{
	unsigned char LOCALNUM;
    GPIO_EnableClock(0);  // Enable GPIOA
    GPIO_EnableClock(1);  // Enable GPIOB
    SYSCFG_EnableClock(); // Enable SYSCFG

    // Configuration_EXTI
	Configuration_EXTI(0);
	Configuration_EXTI(1);

	// Button GPIOB pin0
	GPIO_Init(1, 0, INPUT, PULL_UP);
	// Button GPIOB pin1
	GPIO_Init(1, 1, INPUT, PULL_UP);

    // SEV-SEG
    for(int i=0; i < 7; i++){GPIO_Init(0, i , OUTPUT, PUSH_PULL);}

    while (1)
    {
    	DisableInterrupt();
    	LOCALNUM = NUM;
    	EnableInterrupt();
    	Display_SevenSeg(LOCALNUM);
    }
    return 0;
}

// ISR INC
void MY_EXTI0()
{
	if(NUM==9){NUM=9;}
	else{NUM +=1;}

    // Clear
    *EXTI_PR |= 1 << 0;
}

// ISR DEC
void MY_EXTI1()
{
	if(NUM==0){NUM=0;}
	else{NUM -=1;}

	// Clear
    *EXTI_PR |= 1 << 1;
}

void Display_SevenSeg(unsigned char NUM)
{
	for(int i=0; i < 7; i++){GPIO_WritePin(0, i, (Segment_Number[NUM]>>i)&1);}
}

void DisableInterrupt(void)
{
	*EXTI_IMR &= ~(0xff << 0);
}
void EnableInterrupt(void)
{
	*EXTI_IMR |= 1 << 0;
	*EXTI_IMR |= 1 << 1;
}
