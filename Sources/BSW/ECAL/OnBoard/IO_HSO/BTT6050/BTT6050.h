/******************************************************************************
* Copyright (C),                                                       
* File name:         BTT6050.h                                                       
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
#ifndef _BTT6050_H_
#define _BTT6050_H_

#include "bsw_typedefs.h"
#include "MCAL_GPIO.h"
#include "MCAL_SPI.h"
#include "MCAL_OPWM.h"
#include "MCAL_ADC.h"


/******************************************************************************
Public Constant Definitions
*******************************************************************************/
#define		BTT6050_CHIPNUM_MAX			(6)
#define 	   BTT6050_CHIPCHANNEL_MAX		(2)

/******************************************************************************
Public Types Definitions
*******************************************************************************/

/** \brief the enumerate of the BTT6050_Mode
 */
typedef enum  
{
	BTT6050_01=0,	
	BTT6050_02=1,
	BTT6050_03=2,
	BTT6050_04=3,
	BTT6050_05=4,
	BTT6050_06=5
}BTT6050_ChipNum;

/** \brief Enumerate the Channels of SPI
 */
typedef enum 
{

	BTT6050_OUT00=0,
	BTT6050_OUT01	
} BTT6050_OutChannel;


/** \brief the Structure of the BTT6050 Pin 
 */
typedef struct
{
	Mcal_GPIO_Pin GPIO_IN[BTT6050_CHIPCHANNEL_MAX];	
	Mcal_OPWM_Channel OPWM_IN[BTT6050_CHIPCHANNEL_MAX];
	const Mcal_OPWM_Pin* OPWMPinPtr_IN[BTT6050_CHIPCHANNEL_MAX];
	Mcal_GPIO_Pin GPIO_DEN;
	Mcal_GPIO_Pin GPIO_DEN_1;
	Mcal_GPIO_Pin GPIO_DSEL;
	Mcal_ADC_Channel ADC_IS;
	const Mcal_ADC_Pin* ADCPinPtr_IS;
}BTT6050_ChipPin;


/** \brief the Structure of the MonitorChip_ChipConfig
 */
typedef struct
{
	uint16 FaultCurrent_mA[BTT6050_CHIPCHANNEL_MAX];
	uint16 OpenLoadThreshold_mA[BTT6050_CHIPCHANNEL_MAX];
	
}BTT6050_Configure;


/******************************************************************************
Exported Function Declarations                                                                  
******************************************************************************/
extern void  BTT6050_InitChip(BTT6050_ChipNum ChipNum,BTT6050_ChipPin	*ChipPin);
extern void  BTT6050_ConfChip(BTT6050_ChipNum ChipNum,BTT6050_Configure	*ChipConf);
extern void  BTT6050_EnableDiagnostic(BTT6050_ChipNum ChipNum);
extern void  BTT6050_DisableDiagnostic(BTT6050_ChipNum ChipNum);
extern void  BTT6050_InitChannel(BTT6050_ChipNum ChipNum,BTT6050_OutChannel OutChannel,boolean EnableOpwm);
extern void  BTT6050_SwitchType_SetState(BTT6050_ChipNum ChipNum,BTT6050_OutChannel OutChannel,boolean State);
extern void  BTT6050_OPWMType_SetParameter(BTT6050_ChipNum ChipNum,BTT6050_OutChannel OutChannel,uint32 Freq,uint32 Duty);
extern uint8 BTT6050_ReadDTC(BTT6050_ChipNum ChipNum,BTT6050_OutChannel OutChannel);
extern uint16 BTT6050_GetCurrent(BTT6050_ChipNum ChipNum,BTT6050_OutChannel OutChannel);		//mA
extern void BTT6050_UpDateCurrentValue_1ms(void);

#endif
