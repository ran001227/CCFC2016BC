/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
* PROJECT     : CCFC2016BC           
* DESCRIPTION : CCFC2016BC EVB LED Driver H file 
* HISTORY     : Initial version.
* @file     led_hw.h
* @version  1.1
* @date     2023 - 02 - 15
* @brief    Initial version.
*
*****************************************************************************/
#ifndef LED_HW_H
#define LED_HW_H

#include "typedefs.h"
#include "siul_lld.h"

#define  LED1       0x01u
#define  LED2       0x02u
#define  LED3       0x04u

#define LED_ON      0x01u
#define LED_OFF     0x00u

/*CCFC2016BC EVB V1.0 PC[6]*/
extern void LED1_IO_Set(uint8_t val);
/*CCFC2016BC EVB V1.0 PC[7]*/
extern void LED2_IO_Set(uint8_t val);
/*CCFC2016BC EVB V1.0 PC[8]*/
extern void LED3_IO_Set(uint8_t val);

extern void LED_SIU_Init(void);
extern void LED_Set(uint8_t ledNum, uint8_t value);
extern void LED_Toggle(uint8_t ledNum);

#endif
