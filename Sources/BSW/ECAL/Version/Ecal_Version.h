/******************************************************************************
Copyright (c) ECO-EV Technologies Co., Ltd. 2015-2016. 
All rights reserved.

File name:		Flash.c
Author:			ECO-EV
Version:		V1.0.1
Date:			2016-10-24
Description:
Others:
History:

	1. Date:
	   Author:
	   Modification:
	2. ...
*******************************************************************************/
#ifndef _Hwal_Version_H_
#define _Hwal_Version_H_

#include "bsw_typedefs.h"

#define 	CCFC2016BC_EVB



//#define 	HWARDWARE_EEPROM


#ifdef	CCFC2016BC_EVB
	#include "CCFC2016BC_EVB.h"
	#define		HWARDWARE_MODEL			"CCFC2016BC_EVB"
	#define 	HWARDWARE_VERSION		{{"EV2274005310V210"}}
#endif


typedef struct{
	uint32 support_hw_list_addr;
	uint32 support_hw_count;
}Ecal_Version_SupportHWInfo_Type;


/******************************************************************************
extern Constant Declarations                                                                     
******************************************************************************/
extern const uint8 Product_HardwareModel[][16];
extern const uint8 Product_HardwareVersion[][16];


extern void   Ecal_Version_MappingPin(void);


#endif
