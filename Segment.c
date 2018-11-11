/*
 * Segment.c
 *
 *  Created on: Nov 11, 2018
 *      Author: ziad
 */
#include <stdint.h>
#include "Segment.h"
#include "Segment_Cfg.h"
#include "GPIO.h"

#define HIGH 0xFF
#define LOW  0x00

static const uint8_t DigitsLUT [10][7] =
{
		{HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW},
			{LOW, HIGH, HIGH, LOW, LOW, LOW, LOW},
			{HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH},
			{HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH},
			{LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH},
			{HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH},
			{HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH},
			{HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW},
			{HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH},
			{HIGH, HIGH, HIGH, HIGH, LOW, HIGH, HIGH}
};

void Seg_Init(void)
{
	uint8_t LoopIndex0 =0;
	uint8_t LoopIndex1;
	for(LoopIndex0=0;LoopIndex0<NO_OF_MODULES;LoopIndex0++)
	{
		if(Seg_ConfigData[LoopIndex0].CommMode == COMMON_CATHODE)
		{
			if (Seg_ConfigData[LoopIndex0].ConnType==SEVEN_PINS)
			{
				for(LoopIndex1=0;LoopIndex1<7;LoopIndex1++)
				{
					GPIO_Write(Seg_ConfigData[LoopIndex0].SegPins[loopIndex1],DigitsLUT[0][LoopIndex1]);
				}
			}
			else
			{
				for(LoopIndex1=0;LoopIndex1<4;LoopIndex1++)
				{
					GPIO_Write(Seg_ConfigData[LoopIndex0].SegPins[LoopIndex1],(0x00 & (1<<LoopIndex1)));
				}
			}
		}
		else
		{
			if(Seg_ConfigData[LoopIndex0].ConnType == SEVEN_PINS )
			{
				for (LoopIndex1=0;LoopIndex1 <7;LoopIndex1++)
				{
					GPIO_Write(Sef_ConfigData[LoopIndex0].SegPins[LoopIndex1],~(DigitaLUT[0][LoopIndex1]));
				}
			}
			else
			{
				for(LoopIndex1=0;LoopIndex1<4;LoopIndex1++)
				{
					GPIO_Write(Seg_ConfigData[LoopIndex0].SegPins[LoopIndex1],(0x0F &(1<<LoopIndex1)));
				}
			}
		}
	}
}

Seg_CheckType Seg_Disp(uint8_t Module,uint8_t Number,Seg_DPControl DP)
{
	Seg_CheckType RetVar;
	uint8_t LoopIndex;
	if ((Module<NO_OF_MODULES)&&(Number<10))
	{
		if(Seg_ConfigData[Module].ConnMode == COMMUN_CATHODE)
		{
			if(Seg_ConfigData[Module].ConnType == SEVEN_PINS)
			{
				for(LoopIndex=0;LoopIndex<7;LoopIndex++)
				{
					GPIO_Write(Seg_ConfigData[Module].SegPins[LoopIndex],DigitsLUT[Number][LoopIndex]);
				}
			}
			else
			{
				for(LoopIndex=0;LoopIndex<4;LoopIndex++)
				{
					GPIO_Write(Seg_ConfigData[Module].SegPins[LoopIndex],(Number &(1<<LoopIndex)));
				}
			}
		}
		else
		{
			if (Seg_ConfigData[Module].ConnType == SEVEN_PINS)
			{
				for(LoopIndex=0;LoopIndex<7;LoopIndex++)
				{
					GPIO_Write(Seg_ConfigData[Module].SegPins[LoopIndex],~(DigitsLUT[Number][LoopIndex]);)
				}
			}
			else
			{
				for(LoopIndex=0;LoopIndex<4;LoopIndex)
				{
					GPIO_Write(Seg_ConfigData[Module].SegPins[LoopIndex],~(Number & (1<<LoopIndex)));
				}
			}
		}
		RetVar = SEG_OK;
	}
	else
	{
		RetVar=Seg_NOK;
	}
	return RetVar;
}

Seg_CheckType Seg_Off(uint8_t Module)
{
	Seg_CheckType RetVar;
	uint8_t LoopIndex;
	if (Module <NO_OF_MODULES)
	{
		if(Seg_ConfigData[Module].ConnMode == COMMUN_CATHODE)
		{
			if(Seg_ConfigData[Module].ConnType == SEVEN_PINS)
			{
				for(LoopIndex=0;LoopIndex<7;LoopIndex++)
				{
					GPIO_Write(Seg_ConfigData[Module].SegPins[LoopIndex],0xFF);
				}
			}
		}
		else
		{
			if(Seg_ConfigData[Module].ConnType ==SEVEN_PINS)
			{
				for(LoopIndex=0;LoopIndex<7;LoopIndex++)
				{
					GPIO_Write(Seg_ConfigData[Module].SegPins[LoopIndex],0xFF);
				}
			}
			else
			{
				for(LoopIndex = 0; LoopIndex < 4; LoopIndex++)
								{
									GPIO_Write(Seg_ConfigData[Module].SegPins[LoopIndex], 0x00);
								}
			}
		 }
		RetVar=SEG_OK;
		}
	else
	{
		RetVar=SEG_NOK;
	}
	return RetVar;
}


