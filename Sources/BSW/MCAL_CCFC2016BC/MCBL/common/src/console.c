/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC2016BC
* DESCRIPTION : console c file
* HISTORY     : Initial version.
* @file     console.c
* @version  1.0
* @date     2023 - 02 - 15
* @brief    Initial version.
*
*****************************************************************************/
#include "CCFC2016BC.h"
#include "console.h"
#include <stdarg.h> /*PRQA S 5130*/
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include "common.h"

static struct Lin_Device STD_DEV;


static void STDIO_OUT_INIT(struct Lin_Device  *dev);
extern void UART_CLEAR(const struct Lin_Device *dev); /* PRQA S 3219 */
extern void Uart00_Rx_Handler(void);
extern void Uart00_Tx_Handler(void);

/*******************************************************************************
 * @brief   UART_Siu_Conf
 *
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
static void UART_Siu_Conf(const struct Lin_Device *dev)
{
    volatile struct LINFLEXD0_tag const *LINFLEX_PTR = dev->lin_num;

    if (LINFLEX_PTR == &LINFLEX_0)
    {
        SIU.PCR[18].R = 0x0600U;    /* PB[2] LINFlex_0.TxDA */
        SIU.PCR[19].R = 0x0100U;    /* PB[3] LINFlex_0.RxDA */
    }
}
/*******************************************************************************
 * @brief   UART_CLEAR
 *
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
void UART_CLEAR(const struct Lin_Device *dev) /* PRQA S 3219 */
{
    volatile struct LINFLEXD0_tag *LINFLEX_PTR;

    LINFLEX_PTR = dev->lin_num;
    LINFLEX_PTR->LINCR1.R &= 1U;
    LINFLEX_PTR->UARTCR.R = 0U;
}
/*******************************************************************************
 * @brief   UART_Set_Baudrate
 *
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
static void UART_Set_Baudrate(struct Lin_Device const *dev, long32_t sys_clock, long32_t baudrate)
{
    volatile struct LINFLEXD0_tag *LINFLEX_PTR;
    uint32_t rate, rate_f, rate_m;

    LINFLEX_PTR = dev->lin_num;

    LINFLEX_PTR->LINCR1.B.SLEEP  = DISABLE;
    LINFLEX_PTR->LINCR1.B.BF     = DISABLE;

    LINFLEX_PTR->UARTCR.B.UART   = 1U;
    LINFLEX_PTR->UARTCR.B.RXEN   = ENABLE;
    LINFLEX_PTR->UARTCR.B.TXEN   = ENABLE;

    rate = (uint32_t)sys_clock/(uint32_t)baudrate;
    rate_f = rate % 16u;
    rate_m = rate/16u;

    LINFLEX_PTR->LINFBRR.B.DIV_F = rate_f;
    LINFLEX_PTR->LINIBRR.B.DIV_M = rate_m;

    LINFLEX_PTR->UARTSR.B.DRFRFE = 1U;
    LINFLEX_PTR->UARTSR.B.DTFTFF = 1U;
}
/*******************************************************************************
 * @brief   UART_Set_Param
 *
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
static void UART_Set_Param(struct Lin_Device const *dev, uint8_t parity, uint8_t bit_len, uint8_t tfc, uint8_t rfc)
{
    volatile struct LINFLEXD0_tag *LINFLEX_PTR;

    LINFLEX_PTR = dev->lin_num;
    LINFLEX_PTR->LINCR1.B.LBKM = 0U;

    switch (parity)
    {
        case 0:
            LINFLEX_PTR->UARTCR.B.PCE = DISABLE;
            break;
        case UART_ODD_PARITY:
            LINFLEX_PTR->UARTCR.B.PCE = ENABLE;
            LINFLEX_PTR->UARTCR.B.PC0 = 1U; /*Parity sent is odd*/
            break;
        case UART_EVEN_PARITY:
            LINFLEX_PTR->UARTCR.B.PCE = ENABLE;
            LINFLEX_PTR->UARTCR.B.PC0 = 0U; /*Parity sent is even*/
            break;
        default:
            LINFLEX_PTR->UARTCR.B.PCE = DISABLE;
            break;
    }

    switch (bit_len)
    {
        case 7:
            LINFLEX_PTR->UARTCR.B.WL0 = 0U;
            break;
        case 8:
            LINFLEX_PTR->UARTCR.B.WL0 = 1U;
            break;
        default:
            LINFLEX_PTR->UARTCR.B.WL0 = 1U;
            break;
    }

    LINFLEX_PTR->UARTCR.B.TDFLTFC = tfc;   /* Tx FIFO counter*/
    LINFLEX_PTR->UARTCR.B.RDFLRFC = rfc;   /* Rx FIFO counter*/
}
/*******************************************************************************
 * @brief   UART_INT_DIS
 *
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
static void UART_INT_DIS(struct Lin_Device const *dev)
{
    volatile struct LINFLEXD0_tag *LINFLEX_PTR;
    LINFLEX_PTR = dev->lin_num;
    LINFLEX_PTR->LINIER.R = 0U;
}
/*******************************************************************************
 * @brief   UART_TX
 *
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
static void UART_TX(struct Lin_Device const *dev, uint8_t data)
{
    volatile struct LINFLEXD0_tag *LINFLEX_PTR = dev->lin_num;

    LINFLEX_PTR->UARTSR.B.DTFTFF = 1U;

    LINFLEX_PTR->BDRL.B.DATA0 = data;

    while (LINFLEX_PTR->UARTSR.B.DTFTFF == 0U)
    {
        ;
    }
}
/*******************************************************************************
 * @brief   UART_RX
 *
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
uint8_t UART_RX(struct Lin_Device const *dev)
{
    uint8_t datain;
    volatile struct LINFLEXD0_tag *LINFLEX_PTR = dev->lin_num;

    while (LINFLEX_PTR->UARTSR.B.DRFRFE == 0U)
    {
    }

    datain = (uint8_t)(LINFLEX_PTR->BDRM.B.DATA4);
    LINFLEX_PTR->UARTSR.B.DRFRFE = 1U;

    return datain;
}
/*******************************************************************************
 * @brief   UartComm_Rx_Handler
 *
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
static void UartComm_Rx_Handler(struct Lin_Device *dev)
{
    volatile struct LINFLEXD0_tag *LINFLEX_PTR = dev->lin_num;

    if (dev->param_num.rx_buflen == 0U)
    {
        return;
    }
    else
    {
        dev->param_num.rx_buf[0] = (uint8_t)(LINFLEX_PTR->BDRM.B.DATA4);

        if (dev->param_num.rx_buflen > 1U)
        {
            dev->param_num.rx_buf[1] = (uint8_t)(LINFLEX_PTR->BDRM.B.DATA5);
        }
        if (dev->param_num.rx_buflen > 2U)
        {
            dev->param_num.rx_buf[2] = (uint8_t)(LINFLEX_PTR->BDRM.B.DATA6);
        }
        if (dev->param_num.rx_buflen > 3U)
        {
            dev->param_num.rx_buf[3] = (uint8_t)(LINFLEX_PTR->BDRM.B.DATA7);
        }
    }

    dev->param_num.rx_flag = 1U;
    dev->param_num.rx_count++;

    LINFLEX_PTR->UARTSR.B.DRFRFE = 1U;
}
/*******************************************************************************
 * @brief   UartComm_Tx_Handler
 *
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
static void UartComm_Tx_Handler(struct Lin_Device *dev)
{
    volatile struct LINFLEXD0_tag *LINFLEX_PTR = dev->lin_num;

    LINFLEX_PTR->UARTSR.B.DTFTFF = 1U;

    dev->param_num.tx_flag = 1U;
    dev->param_num.tx_count++;
}
/*******************************************************************************
 * @brief   Uart00_Rx_Handler
 *
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
void Uart00_Rx_Handler(void)
{
    UartComm_Rx_Handler(&(STD_DEV));
}
/*******************************************************************************
 * @brief   Uart00_Tx_Handler
 *
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
void Uart00_Tx_Handler(void)
{
    UartComm_Tx_Handler(&(STD_DEV));
}
/*******************************************************************************
 * @brief   Std_Dev_Register
 *
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
static void Std_Dev_Register(struct Lin_Device *lin_dev, uint32_t index)
{
    if (index == 0U)
    {
        lin_dev->lin_num = &LINFLEX_0;
    }

    return;
}
/*******************************************************************************
 * @brief   LINFLEX_Start_Config
 *
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
static void LINFLEX_Start_Config(struct Lin_Device const *dev)
{
    volatile struct LINFLEXD0_tag *LINFLEX_PTR;
    LINFLEX_PTR = dev->lin_num;
    LINFLEX_PTR->LINCR1.B.INIT = ENABLE;
}

static void LINFLEX_Complete_Config(struct Lin_Device const *dev)
{
    volatile struct LINFLEXD0_tag *LINFLEX_PTR;
    LINFLEX_PTR = dev->lin_num;
    LINFLEX_PTR->LINCR1.B.INIT   = DISABLE;
}
/*******************************************************************************
 * @brief   Uart_Send_Char
 *
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
void Uart_Send_Char(uint8_t TXData)
{
    if (TXData == (uint8_t)'\n')
    {
        UART_TX(STD_DEV.param_num.std_uart, (uint8_t)'\r');
    }
    UART_TX(STD_DEV.param_num.std_uart, TXData);
}
/*******************************************************************************
 * @brief   STDIO_OUT_INIT
 *
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
static void STDIO_OUT_INIT(struct Lin_Device *dev) /* PRQA S 1505 */
{
    struct Private_Param *Param;
    Param = &dev->param_num;
    Param->std_uart = dev;

    LINFLEX_Start_Config(dev);
    UART_Siu_Conf(dev);
    UART_Set_Baudrate(dev, (long32_t)SYS_CLOCK, (long32_t)UART_BAUDRATE);
    UART_Set_Param(dev, UART_EVEN_PARITY, 8U, 0U, 0U);
    UART_INT_DIS(dev);
    LINFLEX_Complete_Config(dev);
}
/*******************************************************************************
 * @brief   myitoa
 *
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
static uint8_t *myitoa(int32_t value, uint8_t *string, int32_t radix)
{
    uint8_t tmp[33];
    uint8_t *tp = tmp;
    int32_t i;
    int32_t v;
    uint8_t sign;
    uint8_t *sp;

    if ((radix > 36) || (radix <= 1))
    {
        return (uint8_t*)0;
    }
    sign = (uint8_t)((radix == 10) && (value < 0)); /* PRQA S 4304  */
    if (sign == 1u)
    {
        v = - value;
    }
    else
    {
        v = value;
    }
    while ((v > 0)|| (tp == tmp))
    {
        i = v % radix;
        v = v / radix;
        if (i < 10)
        {
            *tp = (uint8_t)(i) + (uint8_t)'0';
            tp++;
        }
        else
        {
            *tp = (uint8_t)(i) + (uint8_t)'a' - 10u;
            tp++;
        }
    }
    sp = string;

    if (sign == 1u)
    {
        *sp = (uint8_t)'-';
        sp++;
    }
    while (tp > tmp)
    {
        tp--;
        *sp = *tp;
        sp++;
    }
    *sp = 0;
    return string;
}

static char *myftoa(double32_t number, int32_t ndigit, int8_t *buf)/* PRQA S 1505 */
{
    long32_t int_part;
    double32_t float_part1;
    double32_t float_part2;
    uint8_t str_int[32];
    uint8_t str_float[32];
    int32_t loop = 0;
    uint8_t i;
    double32_t number_temp = number ;
    (void)cc_memset(str_int, 0u, 32u);
    (void)cc_memset(str_float, 0u, 32u);
    int_part = (long32_t)number_temp;
    float_part1 = (double32_t)(number - (double32_t)int_part);
    //  Integer parnumber - int_parttial processing
    (void)myitoa(int_part, str_int, 10);
    i = (uint8_t)cc_strlen(str_int);
    str_int[i] = (uint8_t)'.';
    //  Fractional processing
    if (ndigit > 0)
    {
        for (; loop < ndigit; loop++)
        {
            float_part2 = (double32_t)10*float_part1;
            float_part1 = float_part2;
            (void)myitoa((long32_t)float_part2, str_float, 10);
            (void)strcat(str_int, str_float); /* PRQA S 3335*/
            float_part1 = (double32_t)(float_part1 - (long32_t)float_part2);/* PRQA S 1800 */
        }
    }
    (void)strcpy(buf, str_int); /* PRQA S 3335*/
    return (char *)buf;
}

/*******************************************************************************
 * @brief   PSPRINTF
 *
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
void PSPRINTF(const char *fmt, ...) /* PRQA S 1337 */
{
    char *s; /* PRQA S 3678 */
    char const *fmt_t = fmt;
    int32_t d;
    double32_t f;
    char buf[16];
    va_list ap;
    va_start(ap, fmt_t);   /* PRQA S 3417,3432,3335,3110,5140 */
    while ((uint8_t)(*fmt_t) > 0u)
    {
        if (*fmt_t != '%')
        {
            Uart_Send_Char((uint8_t)*fmt_t);
            fmt_t++;
            continue;
        }
        ++fmt_t;
        switch (*fmt_t)
        {
            case 's':
                s = (char *)va_arg(ap, const char *);/* PRQA S 5140 */
                for (; *s; s++) /* PRQA S 3344 */
                {
                    Uart_Send_Char((uint8_t)*s);
                }
                break;
            case 'd':
                d = va_arg(ap, int32_t);/* PRQA S 5140 */
                (void)myitoa(d, (uint8_t *)buf, 10);
                for (s = buf; *s; s++) /* PRQA S 3344 */
                {
                    Uart_Send_Char((uint8_t)*s);
                }
                break;

            case 'x':
            case 'X':
                d = va_arg(ap, int32_t);/* PRQA S 5140 */
                (void)myitoa(d, (uint8_t *)buf, 16);
                for (s = buf; *s; s++) /* PRQA S 3344 */
                {
                    Uart_Send_Char((uint8_t)*s);
                }
                break;
            /* Add other specifiers here... */
            case 'f':
                f = (double32_t)va_arg(ap, double32_t);/* PRQA S 5140 */
                (void)myftoa(f, 6, (int8_t *)buf);
                for (s = buf; *s; s++)/* PRQA S 3344 */
                {
                    Uart_Send_Char((uint8_t)*s);
                }
                break;
            default:
                Uart_Send_Char((uint8_t)*fmt_t);
                break;
        }
        fmt_t++;
    }
    va_end(ap);/* PRQA S 5140,3119 */
}
/*******************************************************************************
 * @brief      Console_Init
 *
 * @param[in]  None
 * @param[out] None
 * @retval     None
 * @notapi
 *******************************************************************************/
void Console_Init(void)
{
    Std_Dev_Register(&STD_DEV, 0);
    STDIO_OUT_INIT(&STD_DEV);
    PSPRINTF("\n CCFC2016BC Console Init \n");
}
