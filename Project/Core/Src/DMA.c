/*
 * DMA.c
 *
 *  Created on: Jan 3, 2022
 *      Author: Heba Elbeshbeshy
 */
#include "DMA.h"

// DMA 1-2 STream 0--7 Reg 6
unsigned int *DMA_LOOKUP[2][8][6] =
{{{DMA1_S0CR, DMA1_S0NDTR, DMA1_S0PAR, DMA1_S0M0AR, DMA1_S0M1AR, DMA1_S0FCR},
  {DMA1_S1CR, DMA1_S1NDTR, DMA1_S1PAR, DMA1_S1M0AR, DMA1_S1M1AR, DMA1_S1FCR},
  {DMA1_S2CR, DMA1_S2NDTR, DMA1_S2PAR, DMA1_S2M0AR, DMA1_S2M1AR, DMA1_S2FCR},
  {DMA1_S3CR, DMA1_S3NDTR, DMA1_S3PAR, DMA1_S3M0AR, DMA1_S3M1AR, DMA1_S3FCR},
  {DMA1_S4CR, DMA1_S4NDTR, DMA1_S4PAR, DMA1_S4M0AR, DMA1_S4M1AR, DMA1_S4FCR},
  {DMA1_S5CR, DMA1_S5NDTR, DMA1_S5PAR, DMA1_S5M0AR, DMA1_S5M1AR, DMA1_S5FCR},
  {DMA1_S6CR, DMA1_S6NDTR, DMA1_S6PAR, DMA1_S6M0AR, DMA1_S6M1AR, DMA1_S6FCR},
  {DMA1_S7CR, DMA1_S7NDTR, DMA1_S7PAR, DMA1_S7M0AR, DMA1_S7M1AR, DMA1_S7FCR}},
{{DMA2_S0CR, DMA2_S0NDTR, DMA2_S0PAR, DMA2_S0M0AR, DMA2_S0M1AR, DMA2_S0FCR},
 {DMA2_S1CR, DMA2_S1NDTR, DMA2_S1PAR, DMA2_S1M0AR, DMA2_S1M1AR, DMA2_S1FCR},
 {DMA2_S2CR, DMA2_S2NDTR, DMA2_S2PAR, DMA2_S2M0AR, DMA2_S2M1AR, DMA2_S2FCR},
 {DMA2_S3CR, DMA2_S3NDTR, DMA2_S3PAR, DMA2_S3M0AR, DMA2_S3M1AR, DMA2_S3FCR},
 {DMA2_S4CR, DMA2_S4NDTR, DMA2_S4PAR, DMA2_S4M0AR, DMA2_S4M1AR, DMA2_S4FCR},
 {DMA2_S5CR, DMA2_S5NDTR, DMA2_S5PAR, DMA2_S5M0AR, DMA2_S5M1AR, DMA2_S5FCR},
 {DMA2_S6CR, DMA2_S6NDTR, DMA2_S6PAR, DMA2_S6M0AR, DMA2_S6M1AR, DMA2_S6FCR},
 {DMA2_S7CR, DMA2_S7NDTR, DMA2_S7PAR, DMA2_S7M0AR, DMA2_S7M1AR, DMA2_S7FCR}}};

unsigned int *DMA_INTTERRUPT_LOOKUP[2][4] = {{DMA1_LISR, DMA1_HISR, DMA1_LIFCR, DMA1_HIFCR},
                                            {DMA2_LISR, DMA2_HISR, DMA2_LIFCR, DMA2_HIFCR}};


void DMA_Init(unsigned char Peripheral_ID, unsigned char Stream_NM)
{
	*RCC_AHB1ENR |= (0x01 << ( Peripheral_ID + (unsigned char)21 ));//	 DMAEN
}

//A function to initialize the DMA channel parameters
void DMA_ChannelParameters(unsigned char Peripheral_ID, unsigned char Stream_NM,
		unsigned char Trigger_Src, unsigned int * Src_Add, unsigned int * Dest_Add, unsigned int NM_Of_Transfer,
		unsigned int Item_Size, unsigned char Mode, unsigned int Transfer_Type)
{
	//	Clear  DMA_SxCR
	*DMA_LOOKUP[Peripheral_ID][Stream_NM][0] &= ~(0xff << 0);
	// Clear DMA2_S0FCR
	*DMA_LOOKUP[Peripheral_ID][Stream_NM][5] &= ~(0xff << 0);

//	 DMA_SxCR Bit 0 Disabling
	*DMA_LOOKUP[Peripheral_ID][Stream_NM][0] &= ~(0x01 << 0);
//	 Bits 17:16 Priority level
	*DMA_LOOKUP[Peripheral_ID][Stream_NM][0] |= (0x03 << 16);//11 very high

//	 Bits 7:6 DIR: Data transfer direction
	*DMA_LOOKUP[Peripheral_ID][Stream_NM][0] |= (0x02 << 6);//10: Memory-to-memory

//	 Item_Size
//	 Bits 14:13 MSIZE: Memory data size
	*DMA_LOOKUP[Peripheral_ID][Stream_NM][0] |= (Item_Size << 13);
//	 Bits 12:11 PSIZE: Peripheral data size
	*DMA_LOOKUP[Peripheral_ID][Stream_NM][0] |= (Item_Size << 11);

	switch(Mode)
	{
		case(FIFO):
	  //	 Bit 2 DMDIS: Direct mode disable
			*DMA_LOOKUP[Peripheral_ID][Stream_NM][5] |= (0x01 << 2); //1: Direct mode disabled
	  //	 Bits 1:0 FTH: FIFO threshold selection
			*DMA_LOOKUP[Peripheral_ID][Stream_NM][5] |= (0x03 << 0); //01: 1/2 full FIFO
		break;
		case(Direct_Mode):
			*DMA_LOOKUP[Peripheral_ID][Stream_NM][5] &= ~(0x01 << 2); //0: Direct mode enabled
		break;
	}
	if(Transfer_Type == Single)
	{
//	   Bits 24:23 MBURST: Memory burst transfer configuration
	   *DMA_LOOKUP[Peripheral_ID][Stream_NM][0] &= ~(Single << 23);
//	   Bits 22:21 PBURST: Peripheral burst transfer configuration
	   *DMA_LOOKUP[Peripheral_ID][Stream_NM][0] &= ~(Single << 21);
	}
	else
	{
	   *DMA_LOOKUP[Peripheral_ID][Stream_NM][0] |= (Transfer_Type << 23);
	   *DMA_LOOKUP[Peripheral_ID][Stream_NM][0] |= (Transfer_Type << 21);
	}

//	 Bit 9 PINC: Peripheral increment mode
	*DMA_LOOKUP[Peripheral_ID][Stream_NM][0] |= (0x01 << 9); //1: PINC incremented
//	 Bit 10 MINC: Memory increment mode
	*DMA_LOOKUP[Peripheral_ID][Stream_NM][0] |= (0x01 << 10); //1: MINC incremented
//   Bit 4 TCIE: Transfer complete interrupt enable
	*DMA_LOOKUP[Peripheral_ID][Stream_NM][0] |= (0x01 << 4);// 1: TC interrupt enabled

//	 DMA2_S0PAR
	*DMA_LOOKUP[Peripheral_ID][Stream_NM][2] = (unsigned int)Src_Add;
//	 DMA2_S0M0AR
	*DMA_LOOKUP[Peripheral_ID][Stream_NM][3] = (unsigned int)Dest_Add;
//	 DMA2_S0NDTR
	*DMA_LOOKUP[Peripheral_ID][Stream_NM][1] = NM_Of_Transfer;
}

//Enabling Stream
void DMA_Req_To_Start_Transfer(unsigned char Peripheral_ID, unsigned char Stream_NM)
{
//   Clear all Interrupt flags
	if(Stream_NM < (unsigned char)4)
	{
		 *DMA_INTTERRUPT_LOOKUP[Peripheral_ID][2] = 0x3D;//STREAM0 STRAMCLEARFLAGARRAY[STREAM_NM]
//		 *DMA2_LIFCR = 0x3D;
	}
	else
	{
//		 *DMA_INTTERRUPT_LOOKUP[Peripheral_ID][3] = ;//DMA_HIFCR
		//	*DMA2_HIFCR = 0x00; //for streams akbr mn 3
	}

//	 DMA_SxCR Bit 0 EN
	*DMA_LOOKUP[Peripheral_ID][Stream_NM][0] |= (0x01 << 0);
}


//ISR - A function to check the transfer compelete
void DMA_ISR(void)
{
//	check interrupt from TC
	if((*DMA2_LISR >> 5)&1)
	{
//		 unsigned char State = TransferCompelete;
		 DMA_TransferState();
	}
	// notification
//	 CTCIFx: Stream x clear transfer complete interrupt flag
	*DMA2_LIFCR |= (0x01 << 5);
}
