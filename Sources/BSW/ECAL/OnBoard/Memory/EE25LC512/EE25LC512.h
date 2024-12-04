/*******************************************************************************
Copyright (c) ECO-EV Technologies Co., Ltd. 2015-2016. All rights reserved.

File name:		25LC512.h
Author:			ECO-EV
Version:		V1.0.1
Date:			2018-2-25
Description:
Others:
History:

	1. Date:
	   Author:
	   Modification:
	2. ...
********************************************************************************/

#ifndef _EE25LC512_H
#define _EE25LC512_H

/******************************************************************************
Includes
*******************************************************************************/

#include "Mcal_Spi.h"
#include "Mcal_GPIO.h"


typedef enum
{
	EE25LC512_ChipNum_U01
}EE25LC512_ChipNum;


/** \brief the Structure of the 25LC512 Chip Configure
 */
typedef struct
{
	Mcal_Spi_Channel 	SPI_Channel;
	Mcal_Spi_CS   		SPI_CS;
	Mcal_Spi_MasterPin  SPI_MasterPin;
	Mcal_GPIO_Pin 		GPIO_NWP;
}EE25LC512_ChipConfigureStruct;


/** \List the write protection area of the EEPROM
 */
typedef enum
{
	EE25LC512_WriteProtectLength_None=0,
	EE25LC512_WriteProtectLength_HighQuarter,
	EE25LC512_WriteProtectLength_HighHalf,
	EE25LC512_WriteProtectLength_All
} EE25LC512_WriteProtectLength;

/** \List the error enum of the EEPROM
 */
typedef enum
{
	EE25LC512_Error_None=0,
	EE25LC512_Error_WriteInProcess=1,
	EE25LC512_Error_OutOfRange=2,

} EE25LC512_ErrorState;


#define		EE25LC512_CHIPNUM_MAX			(1)
#define		EE25LC512_BYTELENGTH_MAX		(64*1024)
#define 	EE25LC512_BYTE_PAGESIZE			(128)

/******************************************************************************
Exported Function Declarations
******************************************************************************/
extern void  EE25LC512_ConfigureChip(EE25LC512_ChipNum ChipNum,EE25LC512_ChipConfigureStruct *EE25LC512_ChipConfigure);
extern uint8  EE25LC512_WriteNByte(EE25LC512_ChipNum ChipNum,uint16 Address,uint8 *WriteData,uint16 Length);
extern uint8  EE25LC512_ReadNByte(EE25LC512_ChipNum ChipNum,uint16 Address,uint8 *ReadData,uint16 Length);
extern void  EE25LC512_WriteProtect(EE25LC512_ChipNum ChipNum,EE25LC512_WriteProtectLength WriteProtectLength);
extern void	EE25LC512_StatusProtect(EE25LC512_ChipNum ChipNum,boolean StatusProtect);
extern uint8  EE25LC512_NPageErase(EE25LC512_ChipNum ChipNum,uint16 Address,uint8 Pages);
extern void  EE25LC512_SectorErase(EE25LC512_ChipNum ChipNum,uint16 Address);
extern void  EE25LC512_ChipErase(EE25LC512_ChipNum ChipNum);
extern void  EE25LC512_DeepPowerDown(EE25LC512_ChipNum ChipNum);
extern uint8  EE25LC512_ReleaseAndReadSignature(EE25LC512_ChipNum ChipNum,uint8 *ReadData);

extern uint8  EE25LC512_WriteOneByte(EE25LC512_ChipNum ChipNum,uint16 Address,uint8 *WriteData);
extern uint8  EE25LC512_ReadOneByte(EE25LC512_ChipNum ChipNum,uint16 Address,uint8 *ReadData);

#endif
