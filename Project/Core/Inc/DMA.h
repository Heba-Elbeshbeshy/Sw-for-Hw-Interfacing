/*
 * DMA.h
 *
 *  Created on: Jan 3, 2022
 *      Author: Heba Elbeshbeshy
 */

#ifndef INC_DMA_H_
#define INC_DMA_H_

#include "RCC.h"

//Peripheral_ID
#define DMA_1 ((unsigned char)0)
#define DMA_2 ((unsigned char)1)
//Stream_NM
#define Stream_0    ((unsigned char)0)
#define Stream_1    ((unsigned char)1)
#define Stream_2    ((unsigned char)2)
#define Stream_3    ((unsigned char)3)
#define Stream_4    ((unsigned char)4)
#define Stream_5    ((unsigned char)5)
#define Stream_6    ((unsigned char)6)
#define Stream_7    ((unsigned char)7)
//Trigger_SRC
#define Software    ((unsigned char)0)
//Item_Size
#define Byte        ((unsigned int)0x00) // 00: Byte (8-bit)
#define Half_word   ((unsigned int)0x01) // 01: Half-word (16-bit)
#define Word        ((unsigned int)0x02) // 10: Word (32-bit)
//Mode
#define Direct_Mode ((unsigned char)0)
#define FIFO        ((unsigned char)1)
//Transfer_Type
#define Single      ((unsigned int)0x00)
#define Brust_4     ((unsigned int)0x01)
#define Brust_8     ((unsigned int)0x02)
#define Brust_16    ((unsigned int)0x03)
//TransferCompelete
#define TransferCompelete    ((unsigned char)0)


//0x4002 6000 - 0x4002 63FF DMA1
#define DMA1_LISR         Peripheral_REG(0x40026000 , 0x0000) //DMA1_LISR  0x0000
#define DMA1_HISR         Peripheral_REG(0x40026000 , 0x0004) //DMA1_HISR 0x0004
#define DMA1_LIFCR        Peripheral_REG(0x40026000 , 0x0008) //DMA1_LIFCR 0x0008
#define DMA1_HIFCR        Peripheral_REG(0x40026000 , 0x000C) //DMA1_HIFCR 0x000C

#define DMA1_S0CR         Peripheral_REG(0x40026000 , 0x0010)//DMA1_S0CR 0x0010
#define DMA1_S0NDTR       Peripheral_REG(0x40026000 , 0x0014)//DMA1_S0NDTR 0x0014
#define DMA1_S0PAR        Peripheral_REG(0x40026000 , 0x0018)//DMA1_S0PAR 0x0018
#define DMA1_S0M0AR       Peripheral_REG(0x40026000 , 0x001C)//DMA1_S0M0AR 0x001C
#define DMA1_S0M1AR       Peripheral_REG(0x40026000 , 0x0020)//DMA1_S0M1AR 0x0020
#define DMA1_S0FCR        Peripheral_REG(0x40026000 , 0x0024)//DMA1_S0FCR 0x0024

#define DMA1_S1CR         Peripheral_REG(0x40026000 , 0x0028)//DMA1_S1CR 0x0028
#define DMA1_S1NDTR       Peripheral_REG(0x40026000 , 0x002C)//DMA1_S1NDTR 0x002C
#define DMA1_S1PAR        Peripheral_REG(0x40026000 , 0x0030)//DMA1_S1PAR 0x0030
#define DMA1_S1M0AR       Peripheral_REG(0x40026000 , 0x0034)//DMA1_S1M0AR 0x0034
#define DMA1_S1M1AR       Peripheral_REG(0x40026000 , 0x0038)//DMA1_S1M1AR 0x0038
#define DMA1_S1FCR        Peripheral_REG(0x40026000 , 0x003C)//DMA1_S1FCR 0x003C

#define DMA1_S2CR         Peripheral_REG(0x40026000 , 0x0040)//DMA1_S2CR 0x0040
#define DMA1_S2NDTR       Peripheral_REG(0x40026000 , 0x0044)//DMA1_S2NDTR 0x0044
#define DMA1_S2PAR        Peripheral_REG(0x40026000 , 0x0048)//DMA1_S2PAR 0x0048
#define DMA1_S2M0AR       Peripheral_REG(0x40026000 , 0x004C)//DMA1_S2M0AR 0x004C
#define DMA1_S2M1AR       Peripheral_REG(0x40026000 , 0x0050)//DMA1_S2M1AR 0x0050
#define DMA1_S2FCR        Peripheral_REG(0x40026000 , 0x0054)//DMA1_S2FCR 0x0054

#define DMA1_S3CR         Peripheral_REG(0x40026000 , 0x0058)//DMA1_S3CR 0x0058
#define DMA1_S3NDTR       Peripheral_REG(0x40026000 , 0x005C)//DMA1_S3NDTR 0x005C
#define DMA1_S3PAR        Peripheral_REG(0x40026000 , 0x0060)//DMA1_S3PAR 0x0060
#define DMA1_S3M0AR       Peripheral_REG(0x40026000 , 0x0064)//DMA1_S3M0AR 0x0064
#define DMA1_S3M1AR       Peripheral_REG(0x40026000 , 0x0068)//DMA1_S3M1AR 0x0068
#define DMA1_S3FCR        Peripheral_REG(0x40026000 , 0x006C)//DMA1_S3FCR 0x006C

#define DMA1_S4CR         Peripheral_REG(0x40026000 , 0x0070)//DMA1_S4CR 0x0070
#define DMA1_S4NDTR       Peripheral_REG(0x40026000 , 0x0074)//DMA1_S4NDTR 0x0074
#define DMA1_S4PAR        Peripheral_REG(0x40026000 , 0x0078)//DMA1_S4PAR 0x0078
#define DMA1_S4M0AR       Peripheral_REG(0x40026000 , 0x007C)//DMA1_S4M0AR 0x007C
#define DMA1_S4M1AR       Peripheral_REG(0x40026000 , 0x0080)//DMA1_S4M1AR 0x0080
#define DMA1_S4FCR        Peripheral_REG(0x40026000 , 0x0084)//DMA1_S4FCR 0x0084

#define DMA1_S5CR         Peripheral_REG(0x40026000 , 0x0088)//DMA1_S5CR 0x0088
#define DMA1_S5NDTR       Peripheral_REG(0x40026000 , 0x008C)//DMA1_S5NDTR 0x008C
#define DMA1_S5PAR        Peripheral_REG(0x40026000 , 0x0090)//DMA1_S5PAR 0x0090
#define DMA1_S5M0AR       Peripheral_REG(0x40026000 , 0x0094)//DMA1_S5M0AR 0x0094
#define DMA1_S5M1AR       Peripheral_REG(0x40026000 , 0x0098)//DMA1_S5M1AR 0x0098
#define DMA1_S5FCR        Peripheral_REG(0x40026000 , 0x009C)//DMA1_S5FCR 0x009C

#define DMA1_S6CR         Peripheral_REG(0x40026000 , 0x00A0)//DMA1_S6CR 0x00A0
#define DMA1_S6NDTR       Peripheral_REG(0x40026000 , 0x00A4)//DMA1_S6NDTR 0x00A4
#define DMA1_S6PAR        Peripheral_REG(0x40026000 , 0x00A8)//DMA1_S6PAR 0x00A8
#define DMA1_S6M0AR       Peripheral_REG(0x40026000 , 0x00AC)//DMA1_S6M0AR 0x00AC
#define DMA1_S6M1AR       Peripheral_REG(0x40026000 , 0x00B0)//DMA1_S6M1AR 0x00B0
#define DMA1_S6FCR        Peripheral_REG(0x40026000 , 0x00B4)//DMA1_S6FCR 0x00B4

#define DMA1_S7CR         Peripheral_REG(0x40026000 , 0x00B8)//DMA1_S7CR 0x00B8
#define DMA1_S7NDTR       Peripheral_REG(0x40026000 , 0x00BC)//DMA1_S7NDTR 0x00BC
#define DMA1_S7PAR        Peripheral_REG(0x40026000 , 0x00C0)//DMA1_S7PAR 0x00C0
#define DMA1_S7M0AR       Peripheral_REG(0x40026000 , 0x00C4)//DMA1_S7M0AR 0x00C4
#define DMA1_S7M1AR       Peripheral_REG(0x40026000 , 0x00C8)//DMA1_S7M1AR 0x00C8
#define DMA1_S7FCR        Peripheral_REG(0x40026000 , 0x00CC)//DMA1_S7FCR 0x00CC

//0x4002 6400 - 0x4002 67FF DMA2
// Memory to memory
#define DMA2_LISR         Peripheral_REG(0x40026400 , 0x0000) //DMA2_LISR  0x0000
#define DMA2_HISR         Peripheral_REG(0x40026400 , 0x0004) //DMA2_HISR 0x0004
#define DMA2_LIFCR        Peripheral_REG(0x40026400 , 0x0008) //DMA2_LIFCR 0x0008
#define DMA2_HIFCR        Peripheral_REG(0x40026400 , 0x000C) //DMA2_HIFCR 0x000C

#define DMA2_S0CR         Peripheral_REG(0x40026400 , 0x0010) //DMA2_S0CR 0x0010
#define DMA2_S0NDTR       Peripheral_REG(0x40026400 , 0x0014) //DMA2_S0NDTR 0x0014
#define DMA2_S0PAR        Peripheral_REG(0x40026400 , 0x0018) //DMA2_S0PAR 0x0018
#define DMA2_S0M0AR       Peripheral_REG(0x40026400 , 0x001C) //DMA2_S0M0AR 0x001C
#define DMA2_S0M1AR       Peripheral_REG(0x40026400 , 0x0020) //DMA2_S0M1AR 0x0020
#define DMA2_S0FCR        Peripheral_REG(0x40026400 , 0x0024) //DMA2_S0FCR 0x0024

#define DMA2_S1CR         Peripheral_REG(0x40026400 , 0x0028) //DMA2_S1CR 0x0028
#define DMA2_S1NDTR       Peripheral_REG(0x40026400 , 0x002C) //DMA2_S1NDTR 0x002C
#define DMA2_S1PAR        Peripheral_REG(0x40026400 , 0x0030) //DMA2_S1PAR 0x0030
#define DMA2_S1M0AR       Peripheral_REG(0x40026400 , 0x0034) //DMA2_S1M0AR 0x0034
#define DMA2_S1M1AR       Peripheral_REG(0x40026400 , 0x0038) //DMA2_S1M1AR 0x0038
#define DMA2_S1FCR        Peripheral_REG(0x40026400 , 0x003C) //DMA2_S1FCR 0x003C

#define DMA2_S2CR         Peripheral_REG(0x40026400 , 0x0040)//DMA2_S2CR 0x0040
#define DMA2_S2NDTR       Peripheral_REG(0x40026400 , 0x0044)//DMA2_S2NDTR 0x0044
#define DMA2_S2PAR        Peripheral_REG(0x40026400 , 0x0048)//DMA2_S2PAR 0x0048
#define DMA2_S2M0AR       Peripheral_REG(0x40026400 , 0x004C)//DMA2_S2M0AR 0x004C
#define DMA2_S2M1AR       Peripheral_REG(0x40026400 , 0x0050)//DMA2_S2M1AR 0x0050
#define DMA2_S2FCR        Peripheral_REG(0x40026400 , 0x0054)//DMA2_S2FCR 0x0054

#define DMA2_S3CR         Peripheral_REG(0x40026400 , 0x0058)//DMA2_S3CR 0x0058
#define DMA2_S3NDTR       Peripheral_REG(0x40026400 , 0x005C)//DMA2_S3NDTR 0x005C
#define DMA2_S3PAR        Peripheral_REG(0x40026400 , 0x0060)//DMA2_S3PAR 0x0060
#define DMA2_S3M0AR       Peripheral_REG(0x40026400 , 0x0064)//DMA2_S3M0AR 0x0064
#define DMA2_S3M1AR       Peripheral_REG(0x40026400 , 0x0068)//DMA2_S3M1AR 0x0068
#define DMA2_S3FCR        Peripheral_REG(0x40026400 , 0x006C)//DMA2_S3FCR 0x006C

#define DMA2_S4CR         Peripheral_REG(0x40026400 , 0x0070)//DMA2_S4CR 0x0070
#define DMA2_S4NDTR       Peripheral_REG(0x40026400 , 0x0074)//DMA2_S4NDTR 0x0074
#define DMA2_S4PAR        Peripheral_REG(0x40026400 , 0x0078)//DMA2_S4PAR 0x0078
#define DMA2_S4M0AR       Peripheral_REG(0x40026400 , 0x007C)//DMA2_S4M0AR 0x007C
#define DMA2_S4M1AR       Peripheral_REG(0x40026400 , 0x0080)//DMA2_S4M1AR 0x0080
#define DMA2_S4FCR        Peripheral_REG(0x40026400 , 0x0084)//DMA2_S4FCR 0x0084

#define DMA2_S5CR         Peripheral_REG(0x40026400 , 0x0088)//DMA2_S5CR 0x0088
#define DMA2_S5NDTR       Peripheral_REG(0x40026400 , 0x008C)//DMA2_S5NDTR 0x008C
#define DMA2_S5PAR        Peripheral_REG(0x40026400 , 0x0090)//DMA2_S5PAR 0x0090
#define DMA2_S5M0AR       Peripheral_REG(0x40026400 , 0x0094)//DMA2_S5M0AR 0x0094
#define DMA2_S5M1AR       Peripheral_REG(0x40026400 , 0x0098)//DMA2_S5M1AR 0x0098
#define DMA2_S5FCR        Peripheral_REG(0x40026400 , 0x009C)//DMA2_S5FCR 0x009C

#define DMA2_S6CR         Peripheral_REG(0x40026400 , 0x00A0)//DMA2_S6CR 0x00A0
#define DMA2_S6NDTR       Peripheral_REG(0x40026400 , 0x00A4)//DMA2_S6NDTR 0x00A4
#define DMA2_S6PAR        Peripheral_REG(0x40026400 , 0x00A8)//DMA2_S6PAR 0x00A8
#define DMA2_S6M0AR       Peripheral_REG(0x40026400 , 0x00AC)//DMA2_S6M0AR 0x00AC
#define DMA2_S6M1AR       Peripheral_REG(0x40026400 , 0x00B0)//DMA2_S6M1AR 0x00B0
#define DMA2_S6FCR        Peripheral_REG(0x40026400 , 0x00B4)//DMA2_S6FCR 0x00B4

#define DMA2_S7CR         Peripheral_REG(0x40026400 , 0x00B8)//DMA2_S7CR 0x00B8
#define DMA2_S7NDTR       Peripheral_REG(0x40026400 , 0x00BC)//DMA2_S7NDTR 0x00BC
#define DMA2_S7PAR        Peripheral_REG(0x40026400 , 0x00C0)//DMA2_S7PAR 0x00C0
#define DMA2_S7M0AR       Peripheral_REG(0x40026400 , 0x00C4)//DMA2_S7M0AR 0x00C4
#define DMA2_S7M1AR       Peripheral_REG(0x40026400 , 0x00C8)//DMA2_S7M1AR 0x00C8
#define DMA2_S7FCR        Peripheral_REG(0x40026400 , 0x00CC)//DMA2_S7FCR 0x00CC



//A function to initialize the DMA driver.
void DMA_Init(unsigned char Peripheral_ID, unsigned char Stream_NM);
//A function to initialize the DMA channel parameters, DMA Peripheral ID, Trigger source, Source address, destination address, number of transfers, transfer item size, transfer mode, transfer type(Single or burst).
void DMA_ChannelParameters(unsigned char Peripheral_ID, unsigned char Stream_NM, unsigned char Trigger_Src, unsigned int *Src_Add, unsigned int *Dest_Add, unsigned int NM_Of_Transfer,unsigned int Item_Size, unsigned char Mode, unsigned int Transfer_Type);
//A function to request from the driver to start software transfer (memory to memory).
void DMA_Req_To_Start_Transfer(unsigned char Peripheral_ID, unsigned char Stream_NM);
//A function to check the transfer state
//void DMA_Transfer_State(void);
#endif /* INC_DMA_H_ */
