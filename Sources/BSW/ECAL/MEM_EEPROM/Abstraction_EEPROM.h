/*************************************************************
Copyright (c) ECO-EV Technologies Co., Ltd. 2015-2016. All rights reserved.

File name:		Abstraction_DI.h
Author:			ECO-EV
Version:		V1.0.1
Date:			2017-6-6
Description:
Others:
History:

	1. Date:
	   Author:
	   Modification:
	2. ...
**************************************************************/

#ifndef ABSTRACTION_EEPROM_H
#define ABSTRACTION_EEPROM_H

/*************************************************************
Includes
**************************************************************/
#include "bsw_typedefs.h"
#include "MCAL_GPIO.h"


/** \brief Enumerate the type of EEPROM
 */
typedef enum
{
   Abstr_EEPROM_ChipType_BL24C512A = 0
} Abstr_EEPROM_ChipType;

/** \brief Enumerate the Error of EEPROM
 */
typedef enum
{
   EEPROM_Error_None = 0,
   EEPROM_Error_WriteInProcess,
   EEPROM_Error_OutOfRange,
   EEPROM_Error_ErrorType
} Abstr_EEPROM_Error;

/*************************************************************
Exported Function Declarations                                                                     
**************************************************************/
extern void F_Abstr_EEPROM_Build(Abstr_EEPROM_ChipType ChipType);
extern void F_Abstr_EEPROM_Enable(void);
extern void F_Abstr_EEPROM_Disable(void);
extern uint8 F_Abstr_EEPROM_ReadData(uint32 RomAddr,uint32 RamAddr,uint32 Size);
extern uint8 F_Abstr_EEPROM_WriteData(uint32 RomAddr,uint32 RamAddr,uint32 Size);


#endif


