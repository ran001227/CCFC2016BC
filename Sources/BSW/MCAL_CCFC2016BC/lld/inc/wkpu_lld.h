/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC2016BC
* DESCRIPTION : CCFC2016BC wakeup low level drivers code
* HISTORY     : Initial version.
* @file     wkup_lld.h
* @version  1.1
* @date     2023 - 02 - 15
* @brief    Initial version.
*
*****************************************************************************/
#ifndef WKPU_LLD_H
#define WKPU_LLD_H
#include "CCFC2016BC.h"
#include "Mcu_lld.h"

#define WKPU0_API    0x00000001u
#define WKPU1_RTC    0x00000002u
#define WKPU2_PA1    0x00000004u   /* NMI */
#define WKPU3_PA2    0x00000008u
#define WKPU4_PB1    0x00000010u   /* CAN0RX&LIN0RX */
#define WKPU5_PC11   0x00000020u   /* CAN1RX&CAN4RX */
#define WKPU6_PE0    0x00000040u   /* CAN5RX        */
#define WKPU7_PE9    0x00000080u   /* CAN2RX&CAN3RX */
#define WKPU8_PB10   0x00000100u
#define WKPU9_PA4    0x00000200u   /* LIN5RX        */
#define WKPU10_PA15  0x00000400u
#define WKPU11_PB3   0x00000800u   /* LIN0RX        */
#define WKPU12_PC7   0x00001000u   /* LIN1RX        */
#define WKPU13_PC9   0x00002000u   /* LIN2RX        */
#define WKPU14_PE11  0x00004000u   /* LIN3RX        */
#define WKPU15_PF11  0x00008000u   /* LIN4RX        */
#define WKPU16_PF13  0x00010000u   /* LIN5RX        */
#define WKPU17_PG3   0x00020000u
#define WKPU18_PG5   0x00040000u
#define WKPU19_PA0   0x00080000u
#define WKPU20_PG7   0x00100000u   /* LIN6RX       */
#define WKPU21_PG9   0x00200000u   /* LIN7RX       */
#define WKPU22_PF9   0x00400000u   /* CAN2RX&CAN3RX */
#define WKPU23_PI3   0x00800000u   /* LIN9RX Not exist in LQFP144  */
#define WKPU24_PI9   0x01000000u   /* LIN8RX Not exist in LQFP144  */
#define WKPU25_PB8   0x02000000u
#define WKPU26_PB9   0x04000000u
#define WKPU27_PD0   0x08000000u
#define WKPU28_PD1   0x10000000u

/************************************************************************
 *    Functional declarations
 ************************************************************************/
extern void WKPU_Config(uint32_t lpmode);
extern void MC_ME_ModeSwitch(uint32_t mode_t);

#endif  /* __WKPU_LLD_H_ */
