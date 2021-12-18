/*
 * Author : Abdullah Drwesh
 * Date   : 8/12/2021
 * Version: 1.0.0
 */

#ifndef KEYPAD_H
#define KEYPAD_H

#include "stm32f401xc.h"

#define Released ((unsigned char)1)
#define Pressed ((unsigned char)0)

void KeyPad_Init();
void KeyPad_Manage();
unsigned char KeyPad_GetKey();


#endif /* KEYPAD_H */
