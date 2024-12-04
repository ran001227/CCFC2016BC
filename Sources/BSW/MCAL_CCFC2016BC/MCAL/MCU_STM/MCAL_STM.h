/******************************************************************************
*	Copyright (c) ECO-EV Technologies Co., Ltd. 2015-2016.
*	All rights reserved.

*	File name:		SCU.h
*	Author:			ECO-EV
*	Version:		V1.0.1
*	Date:			2017-6-23
*	Description:
*	Others:
*	History:
*
*	1. Date:
*	   Author:
*	   Modification:
*	2. ...
******************************************************************************/
#ifndef _MCAL_SCU_H_
#define _MCAL_SCU_H_

#include "bsw_typedefs.h"


/******************************************************************************
public symbol Definitions
******************************************************************************/
#define     MCAL_STM_DIVIDE_US       (5)

/******************************************************************************
Exported Function Declarations
******************************************************************************/
extern uint32 	Mcal_SCU_ReadFreeTimer(void);
extern uint32   Mcal_SCU_GetFreq(void);			//Hz
extern void 	Mcal_SCU_Wait_us (uint16 Count_us);
extern void 	Mcal_SCU_Wait_ms (uint16 Count_ms);


#endif

