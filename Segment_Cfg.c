/*
 * Segment_Cfg.c
 *
 *  Created on: Nov 11, 2018
 *      Author: ziad
 */

#include "Segment.h"
#include "Segment_Cfg.h"


const Seg_ConfigType Seg_ConfigData[NO_OF_MODULES] =
{
	{
		COMMON_CATHODE, SEVEN_PINS, {3, 2, 1, 6, 5, 4, 0}
	},
	{
		COMMON_CATHODE, SEVEN_PINS, {17, 16, 15, 20, 19, 18, 14}
	},
	{
		COMMON_CATHODE, SEVEN_PINS, {10, 11, 12, 7, 8, 9, 13}
	},
	{
		COMMON_CATHODE, SEVEN_PINS, {24, 23, 22, 27, 26, 25, 21}
	}
};



