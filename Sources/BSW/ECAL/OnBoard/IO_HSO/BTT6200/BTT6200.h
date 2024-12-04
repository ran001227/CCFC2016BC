/******************************************************************************
* Copyright (C),                                                       
* File name:         BTT6200.h                                                       
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
#ifndef _BTT6200_H_
#define _BTT6200_H_

#include "bsw_typedefs.h"
#include "MCAL_GPIO.h"
#include "MCAL_SPI.h"
#include "MCAL_OPWM.h"
#include "MCAL_ADC.h"


/******************************************************************************
Public Constant Definitions
*******************************************************************************/
#define		BTT6200_CHIPNUM_MAX			(2)
#define 	BTT6200_CHIPCHANNEL_MAX		(4)

/******************************************************************************
Public Types Definitions
*******************************************************************************/

/** \brief the enumerate of the BTT6200_Mode
 */
typedef enum  
{
	BTT6200_01=0,
	BTT6200_02,	
}BTT6200_ChipNum;

/** \brief Enumerate the Channels of SPI
 */
typedef enum 
{

	BTT6200_OUT00=0,
	BTT6200_OUT01,
	BTT6200_OUT02,
	BTT6200_OUT03	
} BTT6200_OutChannel;


/** \brief the Structure of the BTT6200 Pin 
 */
typedef struct
{
	Mcal_GPIO_Pin GPIO_IN[BTT6200_CHIPCHANNEL_MAX];	
	Mcal_OPWM_Channel OPWM_IN[BTT6200_CHIPCHANNEL_MAX];
	const Mcal_OPWM_Pin* OPWMPinPtr_IN[BTT6200_CHIPCHANNEL_MAX];
	Mcal_GPIO_Pin GPIO_DEN;
	Mcal_GPIO_Pin GPIO_DSEL0;
	Mcal_GPIO_Pin GPIO_DSEL1;
	Mcal_ADC_Channel ADC_IS;
	const Mcal_ADC_Pin* ADCPinPtr_IS;
}BTT6200_ChipPin;


/** \brief the Structure of the MonitorChip_ChipConfig
 */
typedef struct
{
	uint16 FaultCurrent_mA[BTT6200_CHIPCHANNEL_MAX];
	uint16 OpenLoadThreshold_mA[BTT6200_CHIPCHANNEL_MAX];
	
}BTT6200_Configure;


/******************************************************************************
Exported Function Declarations                                                                  
******************************************************************************/
extern void  BTT6200_InitChip(BTT6200_ChipNum ChipNum,BTT6200_ChipPin	*ChipPin);
extern void  BTT6200_ConfChip(BTT6200_ChipNum ChipNum,BTT6200_Configure	*ChipConf);
extern void  BTT6200_EnableDiagnostic(BTT6200_ChipNum ChipNum);
extern void  BTT6200_DisableDiagnostic(BTT6200_ChipNum ChipNum);
extern void  BTT6200_InitChannel(BTT6200_ChipNum ChipNum,BTT6200_OutChannel OutChannel,boolean EnableOpwm);
extern void  BTT6200_SwitchType_SetState(BTT6200_ChipNum ChipNum,BTT6200_OutChannel OutChannel,boolean State);
extern void  BTT6200_OPWMType_SetParameter(BTT6200_ChipNum ChipNum,BTT6200_OutChannel OutChannel,uint32 Freq,uint32 Duty);
extern uint8 BTT6200_ReadDTC(BTT6200_ChipNum ChipNum,BTT6200_OutChannel OutChannel);
extern uint16 BTT6200_GetCurrent(BTT6200_ChipNum ChipNum,BTT6200_OutChannel OutChannel);		//mA
extern void BTT6200_UpDateCurrentValue_1ms(void);

#endif
