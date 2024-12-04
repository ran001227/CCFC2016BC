/******************************************************************************
Copyright (c) ECO-EV Technologies Co., Ltd. 2015-2016. All rights reserved.

File name:		Abstraction_Sys.h
Author:			ECO-EV
Version:		V1.0.1
Date:			2016-12-28
Description:
Others:
History:

	1. Date:
	   Author:
	   Modification:
	2. ...
*******************************************************************************/

#ifndef ABSTRACTION_SYS_H
#define ABSTRACTION_SYS_H

/******************************************************************************
Includes
*******************************************************************************/
#include "bsw_typedefs.h"
//#include "FS6500.h"
//#include "MC33907.h"

/******************************************************************************
Exported Function Declarations                                                                     
*******************************************************************************/
extern uint8 F_Abstr_DiagRAM();
extern uint8 F_Abstr_DiagROM();
extern uint8 F_Abstr_DiagEEPROM();
extern uint8 F_Abstr_DiagMem();
extern uint8 F_Abstr_DiagMainChip();
extern uint8 F_Abstr_DiagSlaveChip();
extern uint8 F_Abstr_DiagAll();
extern uint32 F_Abstr_GetSysTime();
extern void F_Abstr_SoftReset();
extern void F_Abstr_SoftStop();
extern void F_Abstr_SoftSetVersion(uint8 *softHLDVer,uint8 *softCLDVer,uint8 numByte);
extern void F_Abstr_MemRam2Nvm();
extern void F_Abstr_MemNvm2Ram();
extern void F_Abstr_SWT_Init(uint8 enSWT,uint32 timeOutSetMs);
extern void F_Abstr_SWT_Pause(void);
extern void F_Abstr_SWT_Resume(void);
extern void F_Abstr_SWT_Service(void);
extern void F_Abstr_BootID(uint32 *idOut);
extern void F_Abstr_HWT_Init(uint8 enHWT);
#endif


