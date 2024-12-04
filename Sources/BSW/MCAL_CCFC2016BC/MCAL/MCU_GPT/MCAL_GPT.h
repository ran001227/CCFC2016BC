/******************************************************************************
*	Copyright (c) ECO-EV Technologies Co., Ltd. 2015-2016.
*	All rights reserved.

*	File name:		GPT.h
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
#ifndef _Mcal_GPT_H_
#define _Mcal_GPT_H_

#include "bsw_typedefs.h"

/******************************************************************************
Public Type Definition
******************************************************************************/

/** \brief Enumerate the Timer interrupt
 */
typedef enum
{
	Mcal_GPT_PIT0=0,
	Mcal_GPT_PIT1,
	Mcal_GPT_PIT2,
	Mcal_GPT_PIT3,
	Mcal_GPT_STM0,
	Mcal_GPT_STM1,
	Mcal_GPT_STM2,
	Mcal_GPT_STM3,

} Mcal_GPT_Timer;


/** \brief the Structure of the timer configure
 */
typedef struct
{
	uint32 Cycle_us;
	uint8 EnInterrupt;
	uint8 EnableTimer;
}Mcal_GPT_TimerConfigure;

typedef void (*Mcal_GTPIsr_PtrType)(void);

/******************************************************************************
Exported Function Declarations
******************************************************************************/
extern void Mcal_GPT_Configure(Mcal_GPT_Timer Timer,Mcal_GPT_TimerConfigure *TimerConfigure);
extern void Mcal_GPT_SetCycle(Mcal_GPT_Timer Timer,uint32 Cycle_us);
extern void Mcal_GPT_EnableInterrupt(Mcal_GPT_Timer Timer);
extern void Mcal_GPT_DisableInterrupt(Mcal_GPT_Timer Timer);
extern void Mcal_GPT_SetEnInterrupt(Mcal_GPT_Timer Timer,boolean Enable);
extern void Mcal_GPT_EnableTimer(Mcal_GPT_Timer Timer);
extern void Mcal_GPT_DisableTimer(Mcal_GPT_Timer Timer);
extern void Mcal_GPT_SetEnable(Mcal_GPT_Timer Timer,boolean Enable);
extern uint32 Mcal_GPT_ReadCurrentValue(Mcal_GPT_Timer Timer);
extern void Mcal_GPT_InstallIsr(Mcal_GPT_Timer Timer,Mcal_GTPIsr_PtrType Isr_Ptr);
extern void Mcal_GPT_UninstallIsr(Mcal_GPT_Timer Timer);
extern void Mcal_GPT_PIT0_Isr(void);
extern void Mcal_GPT_PIT1_Isr(void);
extern void Mcal_GPT_PIT2_Isr(void);
extern void Mcal_GPT_PIT3_Isr(void);

#endif
