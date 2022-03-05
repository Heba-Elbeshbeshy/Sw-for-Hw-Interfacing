/*
 * DMA.c
 *
 *  Created on: Jan 3, 2022
 *      Author: Heba Elbeshbeshy
 */
#include "DMA.h"

 unsigned char State = 0;

// DMA 1-2     STream 0--7       Reg6
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

unsigned int ClearFlags[4] = {0, 6, 16, 22};// DMA_L/H_IFCR

void DMA_Init(unsigned char Peripheral_ID, unsigned char Stream_NM)
{
	*RCC_AHB1ENR |= (0x01 << ( Peripheral_ID + (unsigned char)21)); //DMAEN
}

//A function to initialize the DMA channel parameters
void DMA_ChannelParameters(unsigned char Peripheral_ID, unsigned char Stream_NM,
		unsigned char Trigger_Src, unsigned int * Src_Add, unsigned int * Dest_Add, unsigned int NM_Of_Transfer,
		unsigned int DIR, unsigned int Item_Size, unsigned char Mode, unsigned int Transfer_Type)
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
	*DMA_LOOKUP[Peripheral_ID][Stream_NM][0] |= (DIR << 6);

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
			*DMA_LOOKUP[Peripheral_ID][Stream_NM][5] |= (0x03 << 0); //11: full FIFO
    //      Bit 7 FEIE: FIFO error interrupt enable
			*DMA_LOOKUP[Peripheral_ID][Stream_NM][5] |= (0x01 << 0); //1: FE interrupt enabled
		break;
		case(Direct_Mode):
			*DMA_LOOKUP[Peripheral_ID][Stream_NM][5] &= ~(0x01 << 2); //0: Direct mode enabled
		    *DMA_LOOKUP[Peripheral_ID][Stream_NM][0] |= (0x01 << 1);//DMEIE  Direct mode error interrupt enable
		break;
	}

//	 Bits 24:23 MBURST: Memory burst transfer configuration
	*DMA_LOOKUP[Peripheral_ID][Stream_NM][0] |= (Transfer_Type << 23);
//	 Bits 22:21 PBURST: Peripheral burst transfer configuration
    *DMA_LOOKUP[Peripheral_ID][Stream_NM][0] |= (Transfer_Type << 21);
//	 Bit 9 PINC: Peripheral increment mode
	*DMA_LOOKUP[Peripheral_ID][Stream_NM][0] |= (0x01 << 9); //1: PINC incremented
//	 Bit 10 MINC: Memory increment mode
	*DMA_LOOKUP[Peripheral_ID][Stream_NM][0] |= (0x01 << 10); //1: MINC incremented

//   Bit 4 TCIE: Transfer complete interrupt enable
	*DMA_LOOKUP[Peripheral_ID][Stream_NM][0] |= (0x01 << 4);// 1: TC interrupt enabled
// 	 Bit 2 TEIE: Transfer error interrupt enable
	*DMA_LOOKUP[Peripheral_ID][Stream_NM][0] |= (0x01 << 2);// 1: TE interrupt enabled

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
		 *DMA_INTTERRUPT_LOOKUP[Peripheral_ID][2] |= (0x3D << ClearFlags[Stream_NM]);//DMA_LIFCR
	}
	else
	{
		 *DMA_INTTERRUPT_LOOKUP[Peripheral_ID][3] |= (0x3D << ClearFlags[Stream_NM-4]);//DMA_HIFCR
	}

//	 DMA_SxCR Bit 0 EN
	*DMA_LOOKUP[Peripheral_ID][Stream_NM][0] |= (0x01 << 0);
}

unsigned char DMA_TransferState(void)
{
	if((*DMA2_LISR >> 5)&1) //check interrupt from TC
	{
		 State = TransferComplete;
	}
	else if((*DMA2_LISR >> 3)&1) //check interrupt from TE
	{
		 State = TransferErorr;
	}
	else if((*DMA2_LISR >> 4)&1) //check interrupt from HT
	{
		 State = HalfTransfer;
	}
	else if((*DMA2_LISR >> 2)&1) //check interrupt from DM
	{
		 State = DirectModeErorr;
	}
	else if((*DMA2_LISR >> 0)&1) //check interrupt from FE
	{
		 State = FIFOErorr;
	}
	return State;
}

//ISR - A function to check the transfer complete complete
void DMA_ISR(void)
{
	State = DMA_TransferState();
	if(State == TransferComplete)
	{
	   Led_CallOut_Notification();
//	 CTCIFx: Stream x clear transfer complete interrupt flag
	  *DMA2_LIFCR |= (0x01 << 5);
	}
}
