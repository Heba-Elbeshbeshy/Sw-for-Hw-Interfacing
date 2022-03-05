/*
 * main.c
 *
 *  Created on: Dec 31, 2021
 *      Author: Heba Elbeshbeshy
 */

#include "GPIO.h"
#include "DMA.h"
#include "INTERRUPT.h"

#define BUF_SIZE ((unsigned int)100)

unsigned int SCR_Arr[BUF_SIZE];
unsigned int DEST_Arr[BUF_SIZE];

void Led_CallOut_Notification(void);

int main(void)
{
	for(unsigned int i=0; i<BUF_SIZE; i++)
	{
		SCR_Arr[i]  = 100*(i+1);
		DEST_Arr[i] = 0;
	}

	GPIO_EnableClock(0);  // Enable GPIOA
	GPIO_Init(0, 0, OUTPUT, PUSH_PULL); //Red Led
	GPIO_Init(0, 2, OUTPUT, PUSH_PULL); //Green Led

	DMA_Init(DMA_2, Stream_0);
	DMA_ChannelParameters(DMA_2, Stream_0, Software, SCR_Arr, DEST_Arr, BUF_SIZE, M2M,  Word, FIFO, Brust_4);

	NVIC_Controller(DMA_2, Stream_0);
	DMA_Req_To_Start_Transfer(DMA_2, Stream_0);

    while (1){}
    return 0;
}

void Led_CallOut_Notification()
{
	if((SCR_Arr[0] == DEST_Arr[0]) && (SCR_Arr[99] == DEST_Arr[99]))
	{
		GPIO_WritePin(0, 0, 0); //Red Led
		GPIO_WritePin(0, 2, 1); //Green Led
	}
	else{
		GPIO_WritePin(0, 0, 1); //Red Led
		GPIO_WritePin(0, 2, 0); //Green Led
	}
}



