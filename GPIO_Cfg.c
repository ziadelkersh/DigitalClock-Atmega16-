/*
 * GPIO_Cfg.c
 *
 *  Created on: Nov 12, 2018
 *      Author: ziad
 */
#include "GPIO.h"
#include "GPIO_Cfg.h"

const GPIO_CfgType GPIO_ConfigParam[GPIO_GROUPS_NUMBER] =
{
	{
		0x03, 0x01, 0xFF
	},
	{
		0x03, 0x02, 0xFF
	},
	{
		0x03, 0x04, 0xFF
	},
	{
		0x03, 0x08, 0xFF
	},
	{
		0x03, 0x10, 0xFF
	},
	{
		0x03, 0x20, 0xFF
	},
	{
		0x03, 0x40, 0xFF
	},

	{
		0x02, 0x01, 0xFF
	},
	{
		0x02, 0x02, 0xFF
	},
	{
		0x02, 0x04, 0xFF
	},
	{
		0x02, 0x08, 0xFF
	},
	{
		0x02, 0x10, 0xFF
	},
	{
		0x02, 0x20, 0xFF
	},
	{
		0x02, 0x40, 0xFF
	},

	{
		0x01, 0x01, 0xFF
	},
	{
		0x01, 0x02, 0xFF
	},
	{
		0x01, 0x04, 0xFF
	},
	{
		0x01, 0x08, 0xFF
	},
	{
		0x01, 0x10, 0xFF
	},
	{
		0x01, 0x20, 0xFF
	},
	{
		0x01, 0x40, 0xFF
	},

	{
		0x00, 0x01, 0xFF
	},
	{
		0x00, 0x02, 0xFF
	},
	{
		0x00, 0x04, 0xFF
	},
	{
		0x00, 0x08, 0xFF
	},
	{
		0x00, 0x10, 0xFF
	},
	{
		0x00, 0x20, 0xFF
	},
	{
		0x00, 0x40, 0xFF
	},
	/* ON-OFF Timer Mode */
	{
		0x00, 0x80, 0x00
	},
	/* Increment Digit */
	{
		0x01, 0x80, 0x00
	},
	/* Field Selector */
	{
		0x02, 0x80, 0x00
	},
	/* Decrement Digit */
	{
		0x03, 0x80, 0x00
	}
};



