/*
 * GPIO.C
 *
 *  Created on: Nov 24, 2021
 *      Author: ADVINTIC
 */
#include "GPIO.h"
#include "stm32f401xc.h"
#include "stm32f401cc_interface.h"

void delay(int secs)
{
for(int i=0; i<secs; i++){}
}

void GPIO_Init( char Port, unsigned int PIN_NO, unsigned int PIN_Dir, unsigned int Default_State)
{
	//enable clock of port
	switch (Port)
	{
		case('A'):
				RCC_AHB1ENR |= (0x01 <<0);
				//configure moder register for pin direction
				switch(PIN_Dir)
				{
					case (INPUT):
							GPIOA_MODER &= ~(0x03 << 2*PIN_NO);
					break;
					case (OUTPUT):
							GPIOA_MODER |= (0x01 << 2*PIN_NO);
					break;
					case (ALTERNATE_FUN):
							GPIOA_MODER |= (0x02 << 2*PIN_NO);
					break;
					case (ANALOG):
							GPIOA_MODER |= (0x03 << 2*PIN_NO);
					break;
				}// end switch
				//configure default state
				if (PIN_Dir == OUTPUT)
				{
		        	switch(Default_State)
			        {
			        	case(PUSH_PULL):
						    GPIOA_OTYPER &= ~(0x01<<PIN_NO);
				        break;
				        case(OPEN_DRAIN):
					     	GPIOA_OTYPER |= (0x01<<PIN_NO);
				        break;
		          	}
				}
				else if (PIN_Dir == INPUT)
				{
				switch(Default_State)
				{
					case(PULL_UP):
	     	                             GPIOB_PUPDR |= (0x01<< 2*PIN_NO);
					break;
					case(PULL_DOWN):
	     	                             GPIOB_PUPDR |= (0x02<< 2*PIN_NO);
					break;
				}//end switch
				}
		break;
		case('B'):
				RCC_AHB1ENR |= (0x01 <<1);
				//configure moder register for pin direction
				switch(PIN_Dir)
				{
					case (INPUT):
							GPIOB_MODER &= ~(0x03 << 2*PIN_NO);
					break;
					case (OUTPUT):
							GPIOB_MODER |= (0x01 << 2*PIN_NO);
					break;
					case (ALTERNATE_FUN):
							GPIOB_MODER |= (0x02 << 2*PIN_NO);
					break;
					case (ANALOG):
							GPIOB_MODER |= (0x03 << 2*PIN_NO);
					break;
				}// end switch
				//configure default state
				if (PIN_Dir == OUTPUT)
				{
		        	switch(Default_State)
			        {
			        	case(PUSH_PULL):
						    GPIOA_OTYPER &= ~(0x01<<PIN_NO);
				        break;
				        case(OPEN_DRAIN):
					     	GPIOA_OTYPER |= (0x01<<PIN_NO);
				        break;
		          	}
				}
				else if (PIN_Dir == INPUT)
				{
				switch(Default_State)
				{
					case(PULL_UP):
	     	            GPIOB_PUPDR |= (0x01<< 2*PIN_NO);
					break;
					case(PULL_DOWN):
	     	              GPIOB_PUPDR |= (0x02<< 2*PIN_NO);
					break;
				}//end switch
				}
		break;
	}
   return 0;
}

unsigned char GPIO_ReadPin(char Port, unsigned int PIN_NO)
{
	unsigned char result;
	switch(Port)
	{
		case('A'):
			if(!((GPIOA_MODER >> (2*PIN_NO)) & 1))
			{
				result = (GPIOA_IDR >> PIN_NO)& 1;
			}
		break;
		case('B'):
			if(!((GPIOB_MODER >> (2*PIN_NO)) & 1))
			{
				result = (GPIOB_IDR >> PIN_NO)& 1;
			}
		break;
	}// end switch
	return result;
}

void GPIO_WritePin(char Port, unsigned int Data, unsigned int NUMBER, unsigned int SHIFT_VALUE)
{
//	unsigned char result;
	switch(Port)
	{
		case('A'):
//			if(GPIOA_MODER >> (2*PIN_NO) & 1)
//			{
			     if(Data)
			     {
			    	 GPIOA_ODR |= (NUMBER<<SHIFT_VALUE);
			     }
			     else
			     {
			    	 GPIOA_ODR &= ~(NUMBER<<SHIFT_VALUE);
			     }
//			}
		break;
		case('B'):
//		     if(GPIOB_MODER >> (2*PIN_NO) & 1)
//		        {
			 if(Data)
			 {
				 GPIOB_ODR |= (NUMBER<<SHIFT_VALUE);
			 }
			 else
			 {
				 GPIOB_ODR &= ~(NUMBER<<SHIFT_VALUE);
			 }
//		        }
		break;
	}// end switch

}
