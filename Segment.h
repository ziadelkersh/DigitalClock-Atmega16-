/*
 * Segment.h
 *
 *  Created on: Nov 11, 2018
 *      Author: ziad
 */

#ifndef SEGMENT_H_
#define SEGMENT_H_

#include <stdint.h>
#include "Segment_Cfg.h"

typedef enum {COMMON_ANODE, COMMON_CATHODE} SegMode;
typedef enum {FOUR_PINS, SEVEN_PINS} SegType;

typedef enum {DP_OFF, DP_ON} Seg_DPControl;
typedef enum {SEG_OK, SEG_NOK} Seg_CheckType;

typedef struct
{
	SegMode ConnMode;
	SegType ConnType;
	uint8_t SegPins[7];
} Seg_ConfigType;

extern const Seg_ConfigType Seg_ConfigData[NO_OF_MODULES];

void Seg_Init(void);
Seg_CheckType Seg_Disp(uint8_t Module, uint8_t Number, Seg_DPControl DP);
Seg_CheckType Seg_Off(uint8_t Module);




#endif /* SEGMENT_H_ */
