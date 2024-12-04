/******************************************************************************
* Copyright (C),                                                       
* File name:         BTT6030.h
*   <Author>         <Version>        <Date>                                      
*   HXL              0.1              2015-6-1                        
* Description:       
                  
* Develop pack:      CodeWarrior                                       
* Function List:          
*   1. mcu_init                                                                  
* History:                
*   1. Date:         2015-6-1                                                                  
*      Author:       fzw          
*      Ver:          0.1                                                        
*      Modification: Create                                                       
*   2. ...         
*   Standards:                                                           
******************************************************************************/ 

/******************************************************************************
Includes
******************************************************************************/
#ifndef _BTT6030_H_
#define _BTT6030_H_

#include "bsw_typedefs.h"
#include "MCAL_GPIO.h"
#include "MCAL_SPI.h"
#include "MCAL_OPWM.h"
#include "MCAL_ADC.h"


/******************************************************************************
Public Constant Definitions
*******************************************************************************/
#define		BTT6030_CHIPNUM_MAX			(2)
#define 	BTT6030_CHIPCHANNEL_MAX		(2)

/******************************************************************************
Public Types Definitions
*******************************************************************************/

/** \brief the enumerate of the BTT6030_Mode
 */
typedef enum
{
	BTT6030_01 = 0,
	BTT6030_02,
} BTT6030_ChipNum;

/** \brief Enumerate the Channels of SPI
 */
typedef enum 
{
	BTT6030_OUT00=0,
	BTT6030_OUT01
} BTT6030_OutChannel;

typedef enum
{
	BTT6030_ADC_Accuracy_10 = 10,
	BTT6030_ADC_Accuracy_12 = 12,
} BTT6030_ADC_Accuracy;

/** \brief the Structure of the BTT6030 Pin
 */
typedef struct
{
	Mcal_GPIO_Pin 			GPIO_IN[BTT6030_CHIPCHANNEL_MAX];
	Mcal_OPWM_Channel 		OPWM_IN[BTT6030_CHIPCHANNEL_MAX];
	const Mcal_OPWM_Pin* 	OPWMPinPtr_IN[BTT6030_CHIPCHANNEL_MAX];
	Mcal_GPIO_Pin 			GPIO_DEN;
	Mcal_GPIO_Pin 			GPIO_DSEL;
	Mcal_ADC_Channel 		ADC_IS;
	const Mcal_ADC_Pin* 	ADCPinPtr_IS;
}BTT6030_ChipPin;


/** \brief the Structure of the MonitorChip_ChipConfig
 */
typedef struct
{
	uint16 FaultCurrent_mA[BTT6030_CHIPCHANNEL_MAX];
	uint16 OpenLoadThreshold_mA[BTT6030_CHIPCHANNEL_MAX];
}BTT6030_Configure;


/******************************************************************************
Exported Function Declarations                                                                  
******************************************************************************/
extern void  BTT6030_InitChip(BTT6030_ChipNum ChipNum,BTT6030_ChipPin	*ChipPin);
extern void  BTT6030_ConfChip(BTT6030_ChipNum ChipNum,BTT6030_Configure	*ChipConf);
extern void  BTT6030_EnableDiagnostic(BTT6030_ChipNum ChipNum);
extern void  BTT6030_DisableDiagnostic(BTT6030_ChipNum ChipNum);
extern void  BTT6030_InitChannel(BTT6030_ChipNum ChipNum,BTT6030_OutChannel OutChannel,boolean EnableOpwm);
extern void  BTT6030_SwitchType_SetState(BTT6030_ChipNum ChipNum,BTT6030_OutChannel OutChannel,boolean State);
extern void  BTT6030_OPWMType_SetParameter(BTT6030_ChipNum ChipNum,BTT6030_OutChannel OutChannel,uint32 Freq,uint32 Duty);
extern uint8 BTT6030_ReadDTC(BTT6030_ChipNum ChipNum,BTT6030_OutChannel OutChannel);
extern uint16 BTT6030_GetCurrent(BTT6030_ChipNum ChipNum,BTT6030_OutChannel OutChannel);		//mA
extern void BTT6030_UpDateCurrentValue_1ms(void);

#endif
