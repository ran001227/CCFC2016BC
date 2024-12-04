/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC2016BC
* DESCRIPTION : console h file
* HISTORY     : Initial version.
* @file     console.h
* @version  1.1
* @date     2023 - 02 - 15
* @brief    Initial version.
*
*****************************************************************************/
#ifndef CONSOLE_H_
#define CONSOLE_H_

#include "CCFC2016BC.h"

#define UART_BAUDRATE   115200U
#define SYS_CLOCK        160000000U

#define DISABLE         0U         /*Bit - Field Is Disabled */
#define ENABLE          1U         /*Bit - Field Is Enabled  */

#define UART_DISABLE_PARITY     0U
#define UART_ODD_PARITY         1U
#define UART_EVEN_PARITY        2U

struct Private_Param
{
    uint8_t tx_buf[4];
    uint8_t rx_buf[4];

    uint8_t tx_buflen;
    uint8_t rx_buflen;

    uint8_t tx_flag;
    uint8_t rx_flag;

    uint32_t tx_count;
    uint32_t rx_count;

    struct Lin_Device *std_uart;
};

struct Lin_Device /* PRQA S 3630 */
{
    volatile struct LINFLEXD0_tag *lin_num;
    struct Private_Param param_num;
    uint8_t MSid;
};

extern void Console_Init(void);
extern uint8_t UART_RX(struct Lin_Device const *dev);
extern void Uart_Send_Char(uint8_t TXData);
void PSPRINTF(const char *fmt, ...);
#endif  /* CONSOLE_H_ */
