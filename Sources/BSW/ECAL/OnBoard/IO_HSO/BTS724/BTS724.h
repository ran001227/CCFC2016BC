/******************************************************************************
*	Copyright (c) ECO-EV Technologies Co., Ltd. 2015-2016.
*	All rights reserved.
*
*	File name:		BTS724.h
*	Author:			ECO-EV
*	Version:		V1.0.0
*	Date:			2020-12-20
*	Description:
*	Others:
*	History:
*
*	1. Date:  2020-12-20
*	   Author: liyuhang
*	   Modification: None
*	   Add: First initialization file
*	   Delete: None
*	2. ...
******************************************************************************/

#ifndef __BTS724_H__
#define __BTS724_H__

#include "bsw_typedefs.h"
#include "MCAL_GPIO.h"
#include "MCAL_SPI.h"
#include "MCAL_OPWM.h"
#include "MCAL_ADC.h"



/******************************************************************************
Public Types Definitions
*******************************************************************************/

/** \brief the enumerate of the BTS724_Mode
 */
typedef enum
{
    BTS724_01 = 0,
    BTS724_CHIPNUM_MAX,
} BTS724_ChipNum;

/** \brief Enumerate the Channels of SPI
 */
typedef enum
{
    BTS724_OUT00 = 0,
    BTS724_OUT01,
    BTS724_OUT02,
    BTS724_OUT03,
    BTS724_CHIPCHANNEL_MAX,
} BTS724_OutChannel;

/** \brief the Structure of the BTS724 Pin 
 */
typedef struct
{
	Mcal_GPIO_Pin GPIO_IN[BTS724_CHIPCHANNEL_MAX];
	Mcal_OPWM_Channel OPWM_IN[BTS724_CHIPCHANNEL_MAX];
	const Mcal_OPWM_Pin *OPWMPinPtr_IN[BTS724_CHIPCHANNEL_MAX];
	Mcal_GPIO_Pin GPIO_BTS_TS12;
	Mcal_GPIO_Pin GPIO_BTS_TS34;
} BTS724_ChipPin;


/** \brief the Structure of the MonitorChip_ChipConfig
 */
typedef struct
{
    uint16 FaultCurrent_mA[BTS724_CHIPCHANNEL_MAX];
    uint16 OpenLoadThreshold_mA[BTS724_CHIPCHANNEL_MAX];
} BTS724_Configure;

/******************************************************************************
Exported Function Declarations                                                                  
******************************************************************************/
extern void  BTS724_InitChip(BTS724_ChipNum ChipNum,BTS724_ChipPin	*ChipPin);
extern void  BTS724_ConfChip(BTS724_ChipNum ChipNum,BTS724_Configure	*ChipConf);
extern void  BTS724_EnableDiagnostic(BTS724_ChipNum ChipNum);
extern void  BTS724_DisableDiagnostic(BTS724_ChipNum ChipNum);
extern void  BTS724_InitChannel(BTS724_ChipNum ChipNum,BTS724_OutChannel OutChannel,boolean EnableOpwm);
extern void  BTS724_SwitchType_SetState(BTS724_ChipNum ChipNum,BTS724_OutChannel OutChannel,boolean State);
extern void  BTS724_OPWMType_SetParameter(BTS724_ChipNum ChipNum,BTS724_OutChannel OutChannel,uint32 Freq,uint32 Duty);
extern uint8 BTS724_ReadDTC(BTS724_ChipNum ChipNum,BTS724_OutChannel OutChannel);
extern uint16 BTS724_GetCurrent(BTS724_ChipNum ChipNum,BTS724_OutChannel OutChannel);		//mA
extern void BTS724_UpDateCurrentValue_1ms(void);


#endif
