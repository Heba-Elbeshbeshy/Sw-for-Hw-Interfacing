/*
 * Author : Abdullah Drwesh
 * Date   : 7/12/2021
 * Version: 1.0.0
 */
#include "GPIO.h"
#include "Keypad.h"

unsigned char counter = 0;
unsigned char sevenSegHex[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

void delay(int secs);
void KeyPad_CallOut_Button_Pressed_Notification();
void Display_Key_On_SevSeg(unsigned char counter);

int main(void)
{
  GPIO_EnableClock('A');
  for (int i = 0; i < 7; i++) {GPIO_Init('A', i, OUTPUT, PUSH_PULL);}
  KeyPad_Init();

  while (1)
  {
	 KeyPad_Manage();
  }
  return 0;
}

void delay(int secs)
{
    for (int i = 0; i < secs; i++) {}
}
void KeyPad_CallOut_Button_Pressed_Notification()
{
	counter = KeyPad_GetKey();
	Display_Key_On_SevSeg(counter);
}
void Display_Key_On_SevSeg(unsigned char counter)
{
	for (int i = 0; i < 7; i++)
    {
		GPIO_WritePin('A', i, (sevenSegHex[counter] & (1 << i)) >> i);
    }
	delay(100000);
}
