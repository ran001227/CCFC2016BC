/******************************************************************************
*  Copyright (c) ECO-EV Technologies Co., Ltd. 2015-2016.
*  All rights reserved.

*  File name:     Mcal_Flash.h
*  Author:        ECO-EV
*  Version:    V1.0.1
*  Date:       2017-6-23
*  Description:
*  Others:
*  History:
*
*  1. Date:
*     Author:
*     Modification:
*  2. ...
******************************************************************************/
#ifndef _Mcal_FLASH_H_
#define _Mcal_FLASH_H_

#include "bsw_typedefs.h"
#include "flash_lld.h"


/** \brief Enumerate the Sector of Flash
 */
typedef enum
{   
	Mcal_FlashSector_None = 0,
	
    Mcal_FlashSector_DF_Low0,
    Mcal_FlashSector_DF_Low1,
    Mcal_FlashSector_DF_Low2,
    Mcal_FlashSector_DF_Low3,
    
    Mcal_FlashSector_PF_Low0,
    Mcal_FlashSector_PF_Low1,
    Mcal_FlashSector_PF_Low2,
    Mcal_FlashSector_PF_Low3,
    Mcal_FlashSector_PF_Low4,
    Mcal_FlashSector_PF_Low5,
    Mcal_FlashSector_PF_Mid0,
    Mcal_FlashSector_PF_Mid1,
    Mcal_FlashSector_PF_High0,
    Mcal_FlashSector_PF_High1,
    Mcal_FlashSector_PF_High2,
    Mcal_FlashSector_PF_High3,
    Mcal_FlashSector_PF_High4,
    Mcal_FlashSector_PF_High5,
    Mcal_FlashSector_PF_High6,
    Mcal_FlashSector_PF_High7,
    Mcal_FlashSector_PF_High8,
    Mcal_FlashSector_PF_High9,
    Mcal_FlashSector_PF_High10,
    Mcal_FlashSector_PF_High11,
    Mcal_FlashSector_PF_High12,
    Mcal_FlashSector_PF_High13,
    Mcal_FlashSector_PF_High14,
    Mcal_FlashSector_PF_High15,
    Mcal_FlashSector_PF_Max,
} Mcal_Flash_FlashSector;


enum
{
	Mcal_FlashSector_DF_Low,
	Mcal_FlashSector_PF_Low,
	Mcal_FlashSector_PF_Mid,
	Mcal_FlashSector_PF_High,
};

/** \brief contains start and end address of sectors
*/
typedef struct
{
    uint32    Start;  /**< \brief start address of sector */
    uint32    End;    /**< \brief end address of sector */
} Mcal_Flash_FlashSectorStruct;


/******************************************************************************
public symbol Definitions
******************************************************************************/
#define  MCAL_FLASH_PAGESIZE       (PGM_SIZE)      //bytes
#define  MCAL_FLASH_SECTOR_NUM            (Mcal_FlashSector_PF_Max)
#define  OTP_SECTION_START_ADDRESS             0x00401000
#define  OTP_SECTION_END_ADDRESS               0x00403FFF
/******************************************************************************
Exported Function Declarations
******************************************************************************/
extern void Mcal_Flash_Init(void);
extern uint8 Mcal_Flash_EraseOneSector(Mcal_Flash_FlashSector FlashSector);
extern uint8 Mcal_Flash_WriteFlash_OnePage(uint32 PageAddr,uint32 DataAddr);
extern uint8 Mcal_Flash_EraseFlash(uint32 Address,uint32 Length);
extern uint8 Mcal_Flash_ProgramFlash(uint32 DestAddr,uint32 SourceAddr,uint32 Size);

/*  The default value of the LOCK bits is locked. */
extern void Mcal_Flash_LockOneSector(Mcal_Flash_FlashSector FlashSector);  //lock the sector from program/erase
extern void Mcal_Flash_LockAllSector(void);
extern void Mcal_Flash_LockSector(uint32 Address,uint32 Length);
extern void Mcal_Flash_UnlockOneSector(Mcal_Flash_FlashSector FlashSector);//unlock the sector from program/erase
extern void Mcal_Flash_UnlockAllSector(void);
extern void Mcal_Flash_UnlockSector(uint32 Address,uint32 Length);
extern void Mcal_Flash_SetLockForSector(Mcal_Flash_FlashSector FlashSector,boolean LockState);
extern boolean Mcal_Flash_GetLockState(Mcal_Flash_FlashSector FlashSector);

extern Mcal_Flash_FlashSector Mcal_Flash_GetSectorNum(uint32 Address);
extern uint8 Mcal_Flash_GetSectorInfo(Mcal_Flash_FlashSector FlashSector,uint32* StartAddress,uint32* EndAddress,uint16* Size);
extern void Mcal_FlashNVMCopyOKFlag(boolean NVMCopyFlag);
extern void Mcal_FlashError_Handler(void);

#endif
