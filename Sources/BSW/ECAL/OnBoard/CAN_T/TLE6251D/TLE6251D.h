/******************************************************************************
* Copyright (C),                                                       
* File name:         TLE6251D.h
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
#ifndef _TLE6251D_H_
#define _TLE6251D_H_

#include "MCAL_GPIO.h"

/** \brief the enumerate of the TLE6251D_Mode
 */
typedef enum  
{
	TLE6251D_ChipNum_1=0,
	TLE6251D_ChipNum_2=1,
	TLE6251D_ChipNum_3=2

}TLE6251D_ChipNum;

/* Enum  the Mode of TLE6251D */
typedef enum  
{
	TLE6251D_Mode_Normal=0,
	TLE6251D_Mode_Standby
}TLE6251D_Mode;


/** \brief the Structure of the MonitorChip_ChipConfig
 */
typedef struct
{

	Mcal_GPIO_Pin  GPIO_STB;

}TLE6251D_ChipPin;


/******************************************************************************
Public Constant Definitions
*******************************************************************************/
#define		TLE6251D_CHIPNUM_MAX			(3)

/******************************************************************************
Exported Function Declarations                                                                  
******************************************************************************/
extern void TLE6251D_InitChipPin(TLE6251D_ChipNum ChipNum,TLE6251D_ChipPin *ChipPin_Ptr);
extern void TLE6251D_ChangeMode(TLE6251D_ChipNum ChipNum,TLE6251D_Mode Mode);




#endif
