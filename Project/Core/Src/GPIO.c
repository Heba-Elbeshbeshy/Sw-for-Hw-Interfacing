#include "GPIO.h"


#define _OUTTYPE_MASK ((unsigned char)0x01)
#define _OUTTYPE_SHIFT 0

#define _PUPD_MASK ((unsigned char)0x06)
#define _PUPD_SHIFT 1

unsigned int *LOOKUP[2][5] =
{{GPIOA_MODER, GPIOA_OTYPER, GPIOA_PUPDR, GPIOA_IDR, GPIOA_ODR},
 {GPIOB_MODER, GPIOB_OTYPER, GPIOB_PUPDR,  GPIOB_IDR, GPIOB_ODR}};

void GPIO_EnableClock(unsigned char PortID) {
     *RCC_AHB1ENR |= (0x01 << PortID);
}

void GPIO_Init(unsigned char PortID, unsigned char PinNum, unsigned char PinMode,
               unsigned char DefaultState) {
               
      *LOOKUP[PortID][0] &= ~(0x03 << 2 * PinNum);
      *LOOKUP[PortID][0] |= PinMode << 2 * PinNum;

      *LOOKUP[PortID][1] &= ~(1 << PinNum);
      *LOOKUP[PortID][1] |= ((DefaultState & _OUTTYPE_MASK) >> _OUTTYPE_SHIFT) << PinNum;

      *LOOKUP[PortID][2] &= ~(0x03 << 2 * PinNum);
      *LOOKUP[PortID][2] |= ((DefaultState & _PUPD_MASK) >> _PUPD_SHIFT) << (2 * PinNum); 
}

unsigned char GPIO_WritePin(unsigned char PortID, unsigned char PinNum,
                            unsigned char Data) {
  unsigned char result;
     if (((*LOOKUP[PortID][0] & (0x03 << 2 * PinNum)) >> (2 * PinNum)) == 1) {
        if (Data) {
          *LOOKUP[PortID][4] |= (1 << PinNum);
        } else {
          *LOOKUP[PortID][4] &= ~(1 << PinNum);
        }
        result = OK;
      } else {
        result = NOK;
      }

  return result;
}

unsigned char GPIO_ReadPin(unsigned char PortID, unsigned char PinNum) {
  unsigned char data = 0;

  data = (*LOOKUP[PortID][3] & (1 << PinNum)) >> PinNum;
  return data;
}
