/******************************************************************************
*	Copyright (c) ECO-EV Technologies Co., Ltd. 2015-2016. 
*	All rights reserved.

*	File name:		MCAL_SWT.h
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
#ifndef _Mcal_SWT_H_
#define _Mcal_SWT_H_

#include "bsw_typedefs.h"

/******************************************************************************
Exported Function Declarations                                                                     
******************************************************************************/
extern void Mcal_SWT_InitWatchDog(boolean EnWdg,uint16 CycleTime_ms);
extern void Mcal_SWT_DisableWatchDog(void);
extern void Mcal_SWT_EnableWatchDog(void);
extern void Mcal_SWT_PauseWatchDog(void);
extern void Mcal_SWT_ResumeWatchDog(void);
extern void Mcal_SWT_ServiceWatchDog(void);

#endif
