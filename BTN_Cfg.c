/*
 * BTN_Cfg.c
 *
 *  Created on: Nov 11, 2018
 *      Author: ziad
 */

#ifndef BTN_CFG_C_
#define BTN_CFG_C_

#include "BTN.h"
#include "BTN_Cfg.h"


const BtnConfigType BtnConfigData[NUM_OF_BTNS] =
{
	{28, ACTIVE_HIGH},
    {29, ACTIVE_HIGH},
	{30, ACTIVE_HIGH},
	{31, ACTIVE_HIGH}
};



#endif /* BTN_CFG_C_ */
