/**************************************************************************** 
 * 
 * Copyright (c) 2022  C*Core -   All Rights Reserved  
 * 
 * THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
 * INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 * 
 * PROJECT     : CCFC201XBC           
 * DESCRIPTION : CCFC201XBC she low level drivers code 
 * HISTORY     : 
 * @file     libshe.h
 * @version  3.0
 * @date     2023-04-18
 * @brief    Initial version.
 * 
 *****************************************************************************/

#ifndef LIBSHE_H_
#define LIBSHE_H_

#include "typedefs.h"

/* Exported API Functions */
extern uint32_t LIBSHE_OpenRWAuth(void);
extern uint32_t LIBSHE_SecureBootDefine(uint32_t bootImageSize, uint32_t bootImageAddress);
extern uint32_t LIBSHE_SecureBootDisable(void);

#endif /* LIBSHE_H_ */
