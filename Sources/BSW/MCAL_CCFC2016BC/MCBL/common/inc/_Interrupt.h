/******************************************************************************
*	Copyright (c) ECO-EV Technologies Co., Ltd. 2018-2019.
*	All rights reserved.

*	File name:		_Interrupt.h
*	Author:			ECO-EV
*	Version:		V1.0.1
*	Date:			2018-4-28
*	Description:
*	Others:
*	History:
*
*	1. Date:
*	   Author:
*	   Modification:
*	2. ...                                                       
******************************************************************************/ 
#ifndef __INTERRUPT_
#define __INTERRUPT_

#include "typedefs.h"

typedef void (*Isr_PtrType)(void);

/******************************************************************************
Exported Function Declarations
******************************************************************************/
extern void Cpu_InterruptNop(void);
extern void Cpu_EnableInterruptsISR(void);
extern void Cpu_DisableInterruptsISR(void);
extern void Cpu_EnableInterrupts(void);
extern void Cpu_DisableInterrupts(void);
extern void Cpu_SetInterruptPriority(void);

#endif
