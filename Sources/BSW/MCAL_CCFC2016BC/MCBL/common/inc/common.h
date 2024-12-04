/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC2016BC
* DESCRIPTION : common h file
* HISTORY     : Initial version.
* @file     common.h
* @version  1.1
* @date     2023 - 02 - 15
* @brief    Initial version.
*
*****************************************************************************/
#ifndef COMMON_H
#define COMMON_H
#include "typedefs.h"

extern uint8_t check_data(uint32_t bar,  uint32_t par, uint32_t len);
extern void cc_memcpy(uint8_t * dest, const uint8_t * src, uint32_t bytes);
extern void cc_memset(uint8_t * dest, uint8_t val, uint32_t bytes);
extern uint8_t cc_memcmp(const uint8_t *src1, const uint8_t *src2, uint32_t len);
extern void cc_memset_inc(uint8_t * dest, uint8_t val, uint32_t bytes);
extern uint32_t change_endian(uint32_t data);
extern void dump_hex(uint32_t addr, uint32_t len);
extern uint8_t check_memcpy(const uint8_t * dest, const uint8_t * src, uint32_t bytes);
extern uint32_t cc_strlen(const uint8_t * s);
extern uint32_t cc_strcat(uint8_t * str1, const uint8_t * str2);
extern void cc_strcpy(uint8_t * dest, const uint8_t *src);

/* ########################## Chip Selection ############################## */
/**
  * @brief This is a list of CCFC2016BC chip packages.
  */
#define CCFC2016BC_70L7_LQFP176
#if 0U
#define CCFC2016BC_70L5_LQFP144
#define CCFC2016BC_70L3_LQFP100
#define CCFC2016BC_80L7_LQFP176
#define CCFC2016BC_80L5_LQFP64
#endif
#endif
