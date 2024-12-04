/*************************************************************
Copyright (c) ECO-EV Technologies Co., Ltd. 2015-2016. All rights reserved.

File name:		Abstraction_MCU.h
Author:			ECO-EV
Version:		V1.0.1
Date:			2017-6-8
Description:
Others:
History:

	1. Date:
	   Author:
	   Modification:
	2. ...
**************************************************************/

#ifndef ABSTRACTION_MCU_H
#define ABSTRACTION_MCU_H

/*************************************************************
Includes
**************************************************************/
#include "bsw_typedefs.h"

/******************************************************************************
type define
******************************************************************************/


/*************************************************************
Exported Function Declarations                                                                     
**************************************************************/
extern void F_Abstr_MCU_Init(void);

extern void F_Abstr_MCU_INTC_DIS(void);

extern void F_Abstr_MCU_INTC_EN(void);


#endif



