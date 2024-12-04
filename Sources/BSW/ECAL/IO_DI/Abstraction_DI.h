/*************************************************************
Copyright (c) ECO-EV Technologies Co., Ltd. 2015-2016. All rights reserved.

File name:		Abstraction_DI.h
Author:			ECO-EV
Version:		V1.0.1
Date:			2017-6-6
Description:
Others:
History:

	1. Date:
	   Author:
	   Modification:
	2. ...
**************************************************************/

#ifndef ABSTRACTION_DI_H
#define ABSTRACTION_DI_H

/*************************************************************
Includes
**************************************************************/
#include "bsw_typedefs.h"
#include "MCAL_GPIO.h"


/** \brief the enumerate of the DI channel
 */
typedef enum
{
	ABS_DI_CANINH,

	ABS_DI_KEYON,
	ABS_DI_NUM
} ABS_DI_Channel_t;

enum
{
	DI_VAILD_LEVEL_HIGH = 0,
	DI_VAILD_LEVEL_LOW,
};


/*************************************************************
Exported Function Declarations                                                                     
**************************************************************/
extern void F_Abstr_DI_BuildChannel(ABS_DI_Channel_t channel,Mcal_GPIO_Pin GPIO_Pin);
extern void F_Abstr_DI_InitChannel(ABS_DI_Channel_t channel);
extern void F_Abstr_DI_SetInputLevelPolarity(ABS_DI_Channel_t channel, uint8 level);

extern boolean F_Abstr_DI_GetValue(ABS_DI_Channel_t channel);


#endif


