/*
 * MCAL_GPIO.h
 *
 *  Created on: 2018Äê3ÔÂ13ÈÕ
 *      Author: ecotrons
 */

#ifndef _GPIO_H_
#define _GPIO_H_


#include "bsw_typedefs.h"
/** \brief Enumerate the Channels of GPIO
 */
typedef enum
{

	Mcal_GPIO_Pin_NONE	= -1,

	//PORT A
	Mcal_GPIO_Pin_PA00	=0x0,		//PA[0]
	Mcal_GPIO_Pin_PA01,
	Mcal_GPIO_Pin_PA02,
	Mcal_GPIO_Pin_PA03,
	Mcal_GPIO_Pin_PA04,
	Mcal_GPIO_Pin_PA05,
	Mcal_GPIO_Pin_PA06,
	Mcal_GPIO_Pin_PA07,
	Mcal_GPIO_Pin_PA08,
	Mcal_GPIO_Pin_PA09,
	Mcal_GPIO_Pin_PA10,
	Mcal_GPIO_Pin_PA11,
	Mcal_GPIO_Pin_PA12,
	Mcal_GPIO_Pin_PA13,
	Mcal_GPIO_Pin_PA14,
	Mcal_GPIO_Pin_PA15,

	//PORT B
	Mcal_GPIO_Pin_PB00,
	Mcal_GPIO_Pin_PB01,
	Mcal_GPIO_Pin_PB02,
	Mcal_GPIO_Pin_PB03,
	Mcal_GPIO_Pin_PB04,
	Mcal_GPIO_Pin_PB05,
	Mcal_GPIO_Pin_PB06,
	Mcal_GPIO_Pin_PB07,
	Mcal_GPIO_Pin_PB08,
	Mcal_GPIO_Pin_PB09,
	Mcal_GPIO_Pin_PB10,
	Mcal_GPIO_Pin_PB11,
	Mcal_GPIO_Pin_PB12,
	Mcal_GPIO_Pin_PB13,
	Mcal_GPIO_Pin_PB14,
	Mcal_GPIO_Pin_PB15,

	//PORT C
	Mcal_GPIO_Pin_PC00,
	Mcal_GPIO_Pin_PC01,
	Mcal_GPIO_Pin_PC02,
	Mcal_GPIO_Pin_PC03,
	Mcal_GPIO_Pin_PC04,
	Mcal_GPIO_Pin_PC05,
	Mcal_GPIO_Pin_PC06,
	Mcal_GPIO_Pin_PC07,
	Mcal_GPIO_Pin_PC08,
	Mcal_GPIO_Pin_PC09,
	Mcal_GPIO_Pin_PC10,
	Mcal_GPIO_Pin_PC11,
	Mcal_GPIO_Pin_PC12,
	Mcal_GPIO_Pin_PC13,
	Mcal_GPIO_Pin_PC14,
	Mcal_GPIO_Pin_PC15,

	//PORT D
	Mcal_GPIO_Pin_PD00,
	Mcal_GPIO_Pin_PD01,
	Mcal_GPIO_Pin_PD02,
	Mcal_GPIO_Pin_PD03,
	Mcal_GPIO_Pin_PD04,
	Mcal_GPIO_Pin_PD05,
	Mcal_GPIO_Pin_PD06,
	Mcal_GPIO_Pin_PD07,
	Mcal_GPIO_Pin_PD08,
	Mcal_GPIO_Pin_PD09,
	Mcal_GPIO_Pin_PD10,
	Mcal_GPIO_Pin_PD11,
	Mcal_GPIO_Pin_PD12,
	Mcal_GPIO_Pin_PD13,
	Mcal_GPIO_Pin_PD14,
	Mcal_GPIO_Pin_PD15,

	//PORT E
	Mcal_GPIO_Pin_PE00,
	Mcal_GPIO_Pin_PE01,
	Mcal_GPIO_Pin_PE02,
	Mcal_GPIO_Pin_PE03,
	Mcal_GPIO_Pin_PE04,
	Mcal_GPIO_Pin_PE05,
	Mcal_GPIO_Pin_PE06,
	Mcal_GPIO_Pin_PE07,
	Mcal_GPIO_Pin_PE08,
	Mcal_GPIO_Pin_PE09,
	Mcal_GPIO_Pin_PE10,
	Mcal_GPIO_Pin_PE11,
	Mcal_GPIO_Pin_PE12,
	Mcal_GPIO_Pin_PE13,
	Mcal_GPIO_Pin_PE14,
	Mcal_GPIO_Pin_PE15,

	//PORT F
	Mcal_GPIO_Pin_PF00,
	Mcal_GPIO_Pin_PF01,
	Mcal_GPIO_Pin_PF02,
	Mcal_GPIO_Pin_PF03,
	Mcal_GPIO_Pin_PF04,
	Mcal_GPIO_Pin_PF05,
	Mcal_GPIO_Pin_PF06,
	Mcal_GPIO_Pin_PF07,
	Mcal_GPIO_Pin_PF08,
	Mcal_GPIO_Pin_PF09,
	Mcal_GPIO_Pin_PF10,
	Mcal_GPIO_Pin_PF11,
	Mcal_GPIO_Pin_PF12,
	Mcal_GPIO_Pin_PF13,
	Mcal_GPIO_Pin_PF14,
	Mcal_GPIO_Pin_PF15,

	//PORT G
	Mcal_GPIO_Pin_PG00,
	Mcal_GPIO_Pin_PG01,
	Mcal_GPIO_Pin_PG02,
	Mcal_GPIO_Pin_PG03,
	Mcal_GPIO_Pin_PG04,
	Mcal_GPIO_Pin_PG05,
	Mcal_GPIO_Pin_PG06,
	Mcal_GPIO_Pin_PG07,
	Mcal_GPIO_Pin_PG08,
	Mcal_GPIO_Pin_PG09,
	Mcal_GPIO_Pin_PG10,
	Mcal_GPIO_Pin_PG11,
	Mcal_GPIO_Pin_PG12,
	Mcal_GPIO_Pin_PG13,
	Mcal_GPIO_Pin_PG14,
	Mcal_GPIO_Pin_PG15,

	//PORT H
	Mcal_GPIO_Pin_PH00,
	Mcal_GPIO_Pin_PH01,
	Mcal_GPIO_Pin_PH02,
	Mcal_GPIO_Pin_PH03,
	Mcal_GPIO_Pin_PH04,
	Mcal_GPIO_Pin_PH05,
	Mcal_GPIO_Pin_PH06,
	Mcal_GPIO_Pin_PH07,
	Mcal_GPIO_Pin_PH08,
	Mcal_GPIO_Pin_PH09,
	Mcal_GPIO_Pin_PH10,
	Mcal_GPIO_Pin_PH11,
	Mcal_GPIO_Pin_PH12,
	Mcal_GPIO_Pin_PH13,
	Mcal_GPIO_Pin_PH14,
	Mcal_GPIO_Pin_PH15,

	//PORT I
	Mcal_GPIO_Pin_PI00,
	Mcal_GPIO_Pin_PI01,
	Mcal_GPIO_Pin_PI02,
	Mcal_GPIO_Pin_PI03,
	Mcal_GPIO_Pin_PI04,
	Mcal_GPIO_Pin_PI05,
	Mcal_GPIO_Pin_PI06,
	Mcal_GPIO_Pin_PI07,
	Mcal_GPIO_Pin_PI08,
	Mcal_GPIO_Pin_PI09,
	Mcal_GPIO_Pin_PI10,
	Mcal_GPIO_Pin_PI11,
	Mcal_GPIO_Pin_PI12,
	Mcal_GPIO_Pin_PI13,
	Mcal_GPIO_Pin_PI14,
	Mcal_GPIO_Pin_PI15,

	//PORT J
	Mcal_GPIO_Pin_PJ00,
	Mcal_GPIO_Pin_PJ01,
	Mcal_GPIO_Pin_PJ02,
	Mcal_GPIO_Pin_PJ03,
	Mcal_GPIO_Pin_PJ04,
	Mcal_GPIO_Pin_PJ05,
	Mcal_GPIO_Pin_PJ06,
	Mcal_GPIO_Pin_PJ07,
	Mcal_GPIO_Pin_PJ08,
	Mcal_GPIO_Pin_PJ09

} Mcal_GPIO_Pin;


/** \brief GPIO input / output mode definition.
 */
typedef enum
{
    Mcal_GPIO_Pin_Mode_PushPullGeneral  = 0,  /**< \brief Push-pull, General-purpose output */
    Mcal_GPIO_Pin_Mode_OpenDrainGeneral = 1,  /**< \brief Open-drain, General-purpose output. */
    Mcal_GPIO_Pin_Mode_NoPullDevice     = 2,      /**< \brief Input, No pull device connected. */
    Mcal_GPIO_Pin_Mode_PullDown         = 3,     /**< \brief Input, pull-down device connected. */
    Mcal_GPIO_Pin_Mode_PullUp           = 4,  /**< \brief Input, pull-up device connected. */
    Mcal_GPIO_Pin_Mode_MultiResistance  = 5,
    Mcal_GPIO_Pin_Mode_IIC              = 6
} Mcal_GPIO_Pin_Mode;


/******************************************************************************
public symbol Definitions
******************************************************************************/
#define LEVEL_HIGH   TRUE
#define LEVEL_LOW    FALSE

/******************************************************************************
Exported Function Declarations
******************************************************************************/
extern void 	Mcal_GPIO_SetPinMode(Mcal_GPIO_Pin Pin,Mcal_GPIO_Pin_Mode Mode);
extern boolean 	Mcal_GPIO_GetState(Mcal_GPIO_Pin Pin);
extern void 	Mcal_GPIO_SetState(Mcal_GPIO_Pin Pin,boolean State);

#endif
