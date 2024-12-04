/******************************************************************************
* Copyright (C),                                                       
* File name:         TJA1044T.h                                                       
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
#ifndef _TJA1044T_H_
#define _TJA1044T_H_

#include "MCAL_GPIO.h"

/** \brief the enumerate of the TJA1044T_Mode
 */
typedef enum  
{
	TJA1044T_ChipNum_1=0,
	TJA1044T_ChipNum_2,

}TJA1044T_ChipNum;

/* Enum  the Mode of TJA1044T */
typedef enum  
{
	TJA1044T_Mode_Normal=0,
	TJA1044T_Mode_Standby
}TJA1044T_Mode;


/** \brief the Structure of the MonitorChip_ChipConfig
 */
typedef struct
{

	Mcal_GPIO_Pin  GPIO_STB;

}TJA1044T_ChipPin;


/******************************************************************************
Public Constant Definitions
*******************************************************************************/
#define		TJA1044T_CHIPNUM_MAX			(2)

/******************************************************************************
Exported Function Declarations                                                                  
******************************************************************************/
extern void TJA1044T_InitChipPin(TJA1044T_ChipNum ChipNum,TJA1044T_ChipPin *ChipPin_Ptr);
extern void TJA1044T_ChangeMode(TJA1044T_ChipNum ChipNum,TJA1044T_Mode Mode);




#endif
