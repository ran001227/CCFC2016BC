/************************************************************************
Copyright (c) ECO-EV Technologies Co., Ltd. All rights reserved.

File name:     ser_mem.h
Author:        ECO-EV
Version:
Date:
Description:
Others:
History:

   1. Date:
      Author:
      Modification:
   2. ...
*************************************************************************/
#ifndef   _SER_MEM_H_
#define   _SER_MEM_H_

#include "bsw_typedefs.h"
#include "Mcal_CAN.h"

#define 	MEM_CANNODE_MAXNUM			4

/** \brief the Structure of the SPI Frame
 */
typedef struct
{
	boolean Enable;
	uint32  BaudRate;
	uint32 	SationAddress;
	boolean DTO_Extend;
	boolean CRO_Extend;
	uint32  DTO_ID;
	uint32  CRO_ID;
}CanNodeConfigure;

///** \brief the Structure of the algorithm
// */
//typedef struct
//{
//	boolean Algorithm_Enable;
//	uint32  Algorithm_Sum;
//}Algorithm;

/* brief the Structure of Calibration Data
 */
typedef struct
{

	boolean EnterLoader;			//TRUE VCU reset Enter Loader wait connect code ,if
	boolean ProgramEnd;				//main App must set TRUE
	uint32 MainAppEntryAddress;		//
	uint8 KeyWord_Verify[6];

	CanNodeConfigure ProgramNode[MEM_CANNODE_MAXNUM];
	boolean Algorithm_Enable;
}BootConfigure_new;

/* brief the Structure of Calibration Data
 */
typedef struct
{

	boolean EnterLoader;			//TRUE VCU reset Enter Loader wait connect code ,if
	boolean ProgramEnd;				//main App must set TRUE
	uint32 MainAppEntryAddress;		//
	uint8 KeyWord_Verify[6];

	CanNodeConfigure ProgramNode[MEM_CANNODE_MAXNUM];
}BootConfigure;

typedef struct
{
	BootConfigure BootConfValue;
	uint16 Crc_Check;
}BootConfpara;


#define   _BOOT_CONF_	   		__attribute__ ((section (".boot_conf")))
#define   _BOOT_SEEDKEY_CODE_	__attribute__ ((section (".boot_alg")))
//#define   _FNVM_DATA_      		__attribute__ ((section (".fnvm_data")))
//#define   _FNVM_FLAG_      		__attribute__ ((section (".fnvm_flag")))
//#define   _UFNVM_DATA_     		__attribute__ ((section (".ufnvm_data")))
//#define   _UFNVM_FLAG_     		__attribute__ ((section (".ufnvm_flag")))

#define   _CAL_DATA_ON    		__attribute__ ((section (".cal_data_on")))
#define   _CAL_DATA_OFF    		__attribute__ ((section (".cal_data_off")))
#define   _MEASURE_DATA_  	 	__attribute__ ((section (".measure_data")))

#define	  _ADDR_EPK_  	   		__attribute__ ((section (".identifier")))
/******************************************************************************
Exported Function Declarations
******************************************************************************/
extern void Ser_Mem_EEPROM_SetEnable(boolean Enable);
extern void Ser_Mem_NVM_ROM2RAM(void);
extern void Ser_Mem_NVM_RAM2ROM(void);
extern void Ser_Mem_ClearFirstFlag(void);
extern boolean Ser_Mem_UpDateNVMOKflag(void);
extern boolean Ser_Mem_IsFirstPowerOn(void);

extern boolean Ser_Mem_NVMCopyOKflag(void);
extern void Ser_Mem_OnlineProgram(void);

#endif
