/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC2016BC
* DESCRIPTION : common code
* HISTORY     : Initial version.
* @file     common.c
* @version  1.1
* @date     2023 - 02 - 15
* @brief    Initial version.
*
*****************************************************************************/
#include "common.h"
#include "CCFC2016BC.h"
#include "console.h"
#include "lldconf.h"

/************************************************************************
 * @brief      ARCH2D16_M1I7C2016BC check data function.
 * @param[in]  uint32_t bar, uint32_t par, uint32_t len
 * @param[out] None
 * @notapi
 *************************************************************************/
uint8_t check_data(uint32_t bar, uint32_t par, uint32_t len)
{
    uint32_t i;
    uint8_t const *pSrc = (uint8_t *)bar;
    uint8_t const *pDst = (uint8_t *)par;

    for (i = 0; i < len; i++)
    {
        if ((*pSrc) != (*pDst))
        {
            return FALSE;
        }
        pSrc++;
        pDst++;
    }

    return TRUE;
}

/************************************************************************
 * @brief      ARCH2D16_M1I7C2016BC cc_memcpy function.
 *             This function shall be copy data buffer.
 * @param[in]  uint8_t * dest, const uint8_t * src, uint32_t bytes
 * @param[out] None
 * @notapi
 *************************************************************************/
void cc_memcpy(uint8_t * dest, const uint8_t * src, uint32_t bytes)
{
    uint32_t bytes_temp;
    uint8_t * dest_temp = NULL;
    uint8_t const * src_temp = NULL;

    bytes_temp = bytes;
    dest_temp = dest;
    src_temp = src;

    while (bytes_temp > 0u)
    {
        *dest_temp = *src_temp;
        bytes_temp--;
        if (0u == bytes_temp)
        {
            break;
        }
        dest_temp++;
        src_temp++;
    }
}

/************************************************************************
 * @brief      ARCH2D16_M1I7C2016BC cc_memset_inc function.
 *             This function shall be set buffer value.
 * @param[in]  uint8_t * dest, uint8_t val, uint32_t bytes
 * @param[out] None
 * @notapi
 *************************************************************************/
void cc_memset_inc(uint8_t * dest, uint8_t val, uint32_t bytes)
{
    uint32_t bytes_temp;
    uint8_t val_temp;
    uint8_t * dest_temp;

    dest_temp = dest;
    bytes_temp = bytes;
    val_temp = val;

    while (bytes_temp > 0u)
    {
        *dest_temp = val_temp;
        val_temp++;
        bytes_temp--;
        if (0u == bytes_temp)
        {
            break;
        }
        dest_temp++;
    }
}

/************************************************************************
 * @brief      ARCH2D16_M1I7C2016BC cc_memset function.
 *             This function shall be set buffer value.
 * @param[in]  uint8_t * dest, uint8_t val, uint32_t bytes
 * @param[out] None
 * @notapi
 *************************************************************************/
void cc_memset(uint8_t * dest, uint8_t val, uint32_t bytes)
{
    uint32_t bytes_temp;
    uint8_t  * dest_temp = NULL;

    dest_temp = dest;
    bytes_temp = bytes;

    while (bytes_temp > 0u)
    {
        *dest_temp = val;
        bytes_temp--;
        if (0u == bytes_temp)
        {
            break;
        }
        dest_temp++;
    }
}

/************************************************************************
 * @brief      ARCH2D16_M1I7C2016BC check_memcpy function.
 *             This function shall be check buffer value.
 * @param[in]  uint8_t * dest, const uint8_t * src, uint32_t bytes
 * @param[out] None
 * @notapi
 *************************************************************************/
uint8_t check_memcpy(const uint8_t * dest, const uint8_t * src, uint32_t bytes)
{
    uint32_t i;
    const uint8_t * dest_temp = NULL;
    const uint8_t * src_temp = NULL;

    src_temp = src;
    dest_temp = dest;

    for (i = 0; i < bytes; i++)
    {
        if ((*src_temp) != (*dest_temp))
        {
            return FALSE;
        }
        src_temp++;
        dest_temp++;
    }

    return TRUE;
}

/************************************************************************
 * @brief      ARCH2D16_M1I7C2016BC cc_memcmp function.
 *             This function shall be compare buffer value.
 * @param[in]  const void *src1, const void *src2, uint32_t len
 * @param[out] None
 * @notapi
 *************************************************************************/
uint8_t cc_memcmp(const uint8_t *src1, const uint8_t *src2, uint32_t len)
{
    uint8_t const *p1 = NULL;
    uint8_t const *p2 = NULL;
    uint32_t len_temp = 0u;

    len_temp = len;
    p1 = src1;
    p2 = src2;

    do
    {
        if (*p1 != *p2)
        {
            return 1;
        }
        p1++;
        p2++;
        len_temp--;
    } while (len_temp != 0u);

    return 0;
}

/************************************************************************
 * @brief      ARCH2D16_M1I7C2016BC dump_hex function.
 *
 * @param[in]  uint32_t addr, uint32_t len
 * @param[out] None
 * @notapi
 *************************************************************************/
void dump_hex(uint32_t addr, uint32_t len)
{
    uint32_t i, j;
    uint8_t const *p_buf;

    j = 0;
    p_buf = (uint8_t*)addr;

    for (i = 0; i < len; i++)
    {
        (void)PSPRINTF("%02x", *p_buf);
        p_buf++;
        j++;
        j = j%32u;
        if (j == 0u)
        {
            (void)PSPRINTF("\n");
        }
        else
        {
            j = j%8u;
            if (j == 0u)
            {
                (void)PSPRINTF(" ");
            }
        }
    }
    j = j%32u;
    if (j != 0u)
    {
        (void)PSPRINTF("\n");
    }
}

/************************************************************************
 * @brief      ARCH2D16_M1I7C2016BC change_endian function.
 *             This function shall be changed the endian mode.
 * @param[in]  uint32_t data
 * @param[out] None
 * @notapi
 *************************************************************************/
uint32_t change_endian(uint32_t data)
{
    uint32_t res;

    res = (data << 24) | ((data << 8) & 0x00FF0000u) | ((data >> 8u) & 0x0000FF00u) | (data >> 24u);

    return res;
}

/************************************************************************
 * @brief
 * @param[in]  uint32_t data
 * @param[out] None
 * @notapi
 *************************************************************************/
uint32_t cc_strlen(const uint8_t * s)
{
    const uint8_t *sc;
    uint32_t temp = 0;
    for (sc = s; *sc != (uint8_t)'\0'; ++sc)
    {
    }
    temp = (uint32_t)(sc - s);
    return temp;
}
/************************************************************************
 * @brief
 * @param[in]  uint32_t data
 * @param[out] None
 * @notapi
 *************************************************************************/
uint32_t cc_strcat(uint8_t  * str1, const uint8_t * str2)
{
     uint8_t *str1_t = str1;
     uint8_t const * str2_t = str2;

     while (*str1_t != (uint8_t)'\0')
     {
        str1_t++;
     }

     while (*str2_t != (uint8_t)'\0')
     {
    *str1_t = *str2_t;
        str1_t++;
        str2_t++;
     }
     return 0;
}

void cc_strcpy(uint8_t * dest, const uint8_t *src)
{
     uint8_t *tmp_dest = NULL;
     uint8_t const *tmp_src = src;
     tmp_dest = dest;
     while (*tmp_dest != (uint8_t)'\0')
     {
         *tmp_dest = *tmp_src;
         tmp_src++;
         tmp_dest++;
     }

     *tmp_dest = *tmp_src;
}
