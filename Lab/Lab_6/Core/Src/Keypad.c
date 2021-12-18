/*
 * Author : Abdullah Drwesh
 * Date   : 8/12/2021
 * Version: 1.0.0
 */
#include "GPIO.h"
#include "Keypad.h"

#include "stm32f401cc_interface.h"

unsigned char KeyPadButtonState = Released;
unsigned char Key_Pressed_Num = 0;
unsigned char KeyPad_array[3][4] = {{1,4,7,'*'},
		                    {2,5,8,0},
                                   {3,6,9,'#'}};

void KeyPad_Init()
{
	 GPIO_EnableClock(1);

	  for (int i = 0; i < 3; i++)
	  {
	      GPIO_Init(1, i, OUTPUT, PUSH_PULL);
	  }
	  for (int i = 3; i < 7; i++)
	  {
		  GPIO_Init(1, i, INPUT, PULL_UP);
	  }
}

unsigned char KeyPad_GetKey()
{
	if(KeyPadButtonState == Pressed)
	{
		KeyPadButtonState = Released;
	    return Key_Pressed_Num;
	}
	else
	{
		return 0;
	}
}

void KeyPad_Manage()
{
	if(KeyPadButtonState == Pressed)
	{
		KeyPad_CallOut_Button_Pressed_Notification();
	}

	else if(KeyPadButtonState == Released)
	{
		for(int i=0; i < 3; i++)
		{
			GPIO_WritePin(1, i, 0);
			for(int j=0; j < 4; j++)
			{
				if (GPIO_ReadPin(1, (j+3)) == 0 && !(i == 0 && j == 3) && !(i == 2 && j == 3) && KeyPadButtonState == Released)
				{
					//Saving Key
					Key_Pressed_Num = KeyPad_array[i][j];
					//Change State
					KeyPadButtonState = Pressed;
					KeyPad_CallOut_Button_Pressed_Notification();
				}
			 }
			GPIO_WritePin(1, i, 1);
		 }
	 }

}
