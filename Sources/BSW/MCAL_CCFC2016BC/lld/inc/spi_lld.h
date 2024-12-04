/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC2016BC
* DESCRIPTION : dsp ilow level drivers code
* HISTORY     : Initial version.
* @file     spi_lld.h
* @version  1.4
* @date     2023 - 06 - 12
* @brief    Initial version.
*
*****************************************************************************/

#ifndef SPI_LLD_H_
#define SPI_LLD_H_

#include "lldconf.h"
#include "CCFC2016BC.h"
#include "typedefs.h"
#include "sys.h"
#include "edma_lld.h"
#include "intc_lld.h"

#define SPI_MASTER_MODE   TRUE
#define SPI_INT   TRUE
/**
 * @brief   Sets a pad logical state to @p PAL_HIGH.
 *
 * @param[in] port      port identifier
 * @param[in] pad       pad number within the port
 *
 * @notapi
 */
#define pal_setpad(port, pad)                                           \
  (SIU.GPDO[((port) * 16U) + (pad)].R = 1)

/**
 * @brief   Clears a pad logical state to @p PAL_LOW.
 *
 * @param[in] port      port identifier
 * @param[in] pad       pad number within the port
 *
 * @notapi
 */
#define pal_clearpad(port, pad)                                      \
  (SIU.GPDO[((port) * 16U) + (pad)].R = 0)

/**
 * @brief   Toggles a pad logical state.
 * @note    The @ref PAL provides a default software implementation of this
 *          functionality, implement this function if can optimize it by using
 *          special hardware functionalities or special coding.
 *
 * @param[in] port      port identifier
 * @param[in] pad       pad number within the port
 *
 * @notapi
 */
#define pal_togglepad(port, pad)                                      \
  (SIU.GPDO[((port) * 16U) + (pad)].R = ~SIU.GPDO[((port) * 16U) + (pad)].R)

#if SPI_DMA_MODE != SPI_DMA_NONE
#include "edma_lld.h"
#endif

#define HAS_DSPI0                      TRUE
#define DSPI0_BASE                     0xFFF90000UL

#define DSPI0_PCTL                     4
#define DSPI0_TX1_DMA_DEV_ID           1
#define DSPI0_TX2_DMA_DEV_ID           0
#define DSPI0_RX_DMA_DEV_ID            2
#define DSPI0_EOQF_HANDLER             vector75
#define DSPI0_EOQF_NUMBER              75
#define DSPI0_TFFF_HANDLER             vector76
#define DSPI0_TFFF_NUMBER              76
#define DSPI0_RFDF_HANDLER             vector78
#define DSPI0_RFDF_NUMBER              78

#define DSPI0_ENABLE_CLOCK()                                         \
  SetPeripheralClockMode(DSPI0_PCTL, SPI_DSPI0_START_PCTL)
#define DSPI0_DISABLE_CLOCK()                                         \
  SetPeripheralClockMode(DSPI0_PCTL, SPI_DSPI0_STOP_PCTL)

#define HAS_DSPI1                      TRUE
#define DSPI1_BASE                     0xFFF94000UL
#define DSPI1_PCTL                     5
#define DSPI1_TX1_DMA_DEV_ID           3
#define DSPI1_TX2_DMA_DEV_ID           0
#define DSPI1_RX_DMA_DEV_ID            4
#define DSPI1_EOQF_HANDLER             vector95
#define DSPI1_EOQF_NUMBER              95
#define DSPI1_TFFF_HANDLER             vector96
#define DSPI1_TFFF_NUMBER              96
#define DSPI1_RFDF_HANDLER             vector98
#define DSPI1_RFDF_NUMBER              98
#define DSPI1_ENABLE_CLOCK()                                          \
  SetPeripheralClockMode(DSPI1_PCTL, SPI_DSPI1_START_PCTL)
#define DSPI1_DISABLE_CLOCK()                                         \
  SetPeripheralClockMode(DSPI1_PCTL, SPI_DSPI1_STOP_PCTL)

#define HAS_DSPI2                      TRUE
#define DSPI2_BASE                     0xFFF98000UL
#define DSPI2_PCTL                     6
#define DSPI2_TX1_DMA_DEV_ID           5
#define DSPI2_TX2_DMA_DEV_ID           0
#define DSPI2_RX_DMA_DEV_ID            6
#define DSPI2_EOQF_HANDLER             vector115
#define DSPI2_EOQF_NUMBER              115
#define DSPI2_TFFF_HANDLER             vector116
#define DSPI2_TFFF_NUMBER              116
#define DSPI2_RFDF_HANDLER             vector118
#define DSPI2_RFDF_NUMBER              118
#define DSPI2_ENABLE_CLOCK()                                           \
  SetPeripheralClockMode(DSPI2_PCTL, SPI_DSPI2_START_PCTL)
#define DSPI2_DISABLE_CLOCK()                                         \
  SetPeripheralClockMode(DSPI2_PCTL, SPI_DSPI2_STOP_PCTL)

#define HAS_DSPI3                      TRUE
#define DSPI3_BASE                     0xFFF9C000UL
#define DSPI3_PCTL                     7
#define DSPI3_TX1_DMA_DEV_ID           7
#define DSPI3_TX2_DMA_DEV_ID           0
#define DSPI3_RX_DMA_DEV_ID            8
#define DSPI3_EOQF_HANDLER             vector183
#define DSPI3_EOQF_NUMBER              183
#define DSPI3_TFFF_HANDLER             vector184
#define DSPI3_TFFF_NUMBER              184
#define DSPI3_RFDF_HANDLER             vector186
#define DSPI3_RFDF_NUMBER              186
#define DSPI3_ENABLE_CLOCK()                                         \
  SetPeripheralClockMode(DSPI3_PCTL, SPI_DSPI3_START_PCTL)
#define DSPI3_DISABLE_CLOCK()                                        \
  SetPeripheralClockMode(DSPI3_PCTL, SPI_DSPI3_STOP_PCTL)

#define HAS_DSPI4                      TRUE
#define DSPI4_BASE                     0xFFFA0000UL
#define DSPI4_PCTL                     8
#define DSPI4_TX1_DMA_DEV_ID           9
#define DSPI4_TX2_DMA_DEV_ID           0
#define DSPI4_RX_DMA_DEV_ID            10
#define DSPI4_EOQF_HANDLER             vector212
#define DSPI4_EOQF_NUMBER              212
#define DSPI4_TFFF_HANDLER             vector213
#define DSPI4_TFFF_NUMBER              213
#define DSPI4_RFDF_HANDLER             vector215
#define DSPI4_RFDF_NUMBER              215
#define DSPI4_ENABLE_CLOCK()                                          \
  SetPeripheralClockMode(DSPI4_PCTL, SPI_DSPI4_START_PCTL)
#define DSPI4_DISABLE_CLOCK()                                         \
  SetPeripheralClockMode(DSPI4_PCTL, SPI_DSPI4_STOP_PCTL)

#define HAS_DSPI5                      TRUE
#define DSPI5_BASE                     0xFFFA4000UL
#define DSPI5_PCTL                     9
#define DSPI5_TX1_DMA_DEV_ID           11
#define DSPI5_TX2_DMA_DEV_ID           0
#define DSPI5_RX_DMA_DEV_ID            12
#define DSPI5_EOQF_HANDLER             vector220
#define DSPI5_EOQF_NUMBER              220
#define DSPI5_TFFF_HANDLER             vector221
#define DSPI5_TFFF_NUMBER              221
#define DSPI5_RFDF_HANDLER             vector223
#define DSPI5_RFDF_NUMBER              223

#define DSPI5_ENABLE_CLOCK()                                          \
  SetPeripheralClockMode(DSPI5_PCTL, SPI_DSPI5_START_PCTL)
#define DSPI5_DISABLE_CLOCK()                                         \
  SetPeripheralClockMode(DSPI5_PCTL, SPI_DSPI5_STOP_PCTL)

#define HAS_DSPI6                      TRUE
#define DSPI6_BASE                     0xFFFA8000UL
#define DSPI6_PCTL                     10
#define DSPI6_TX1_DMA_DEV_ID           13
#define DSPI6_TX2_DMA_DEV_ID           0
#define DSPI6_RX_DMA_DEV_ID            14
#define DSPI6_EOQF_HANDLER             vector330
#define DSPI6_EOQF_NUMBER              330
#define DSPI6_TFFF_HANDLER             vector331
#define DSPI6_TFFF_NUMBER              331
#define DSPI6_RFDF_HANDLER             vector333
#define DSPI6_RFDF_NUMBER              333
#define DSPI6_ENABLE_CLOCK()                                        \
  SetPeripheralClockMode(DSPI6_PCTL, SPI_DSPI6_START_PCTL)
#define DSPI6_DISABLE_CLOCK()                                        \
  SetPeripheralClockMode(DSPI6_PCTL, SPI_DSPI6_STOP_PCTL)

#define HAS_DSPI7                      TRUE
#define DSPI7_BASE                     0xFFFAC000UL
#define DSPI7_PCTL                     11
#define DSPI7_TX1_DMA_DEV_ID           15
#define DSPI7_TX2_DMA_DEV_ID           0
#define DSPI7_RX_DMA_DEV_ID            16
#define DSPI7_EOQF_HANDLER             vector335
#define DSPI7_EOQF_NUMBER              335
#define DSPI7_TFFF_HANDLER             vector336
#define DSPI7_TFFF_NUMBER              336
#define DSPI7_RFDF_HANDLER             vector338
#define DSPI7_RFDF_NUMBER              338
#define DSPI7_ENABLE_CLOCK()                                           \
  SetPeripheralClockMode(DSPI7_PCTL, SPI_DSPI7_START_PCTL)
#define DSPI7_DISABLE_CLOCK()                                        \
  SetPeripheralClockMode(DSPI7_PCTL, SPI_DSPI7_STOP_PCTL)

#define HAS_DSPI8                      TRUE
#define DSPI8_BASE                     0xFFFE4000UL
#define DSPI8_PCTL                     12
#define DSPI8_TX1_DMA_DEV_ID           39
#define DSPI8_TX2_DMA_DEV_ID           0
#define DSPI8_RX_DMA_DEV_ID            40
#define DSPI8_EOQF_HANDLER             vector340
#define DSPI8_EOQF_NUMBER              340
#define DSPI8_TFFF_HANDLER             vector341
#define DSPI8_TFFF_NUMBER              341
#define DSPI8_TCF_HANDLER              vector342
#define DSPI8_TCF_NUMBER               342
#define DSPI8_RFDF_HANDLER             vector343
#define DSPI8_RFDF_NUMBER              343
#define DSPI8_ENABLE_CLOCK()                                           \
  SetPeripheralClockMode(DSPI8_PCTL, SPI_DSPI8_START_PCTL)
#define DSPI8_DISABLE_CLOCK()                                          \
  SetPeripheralClockMode(DSPI8_PCTL, SPI_DSPI8_STOP_PCTL)

#define EDMA_MUX_PCTL                  23
/**
 * @brief   EDMA peripheral configuration when started.
 * @note    The default configuration is 1 (always run) in run mode and
 *          2 (only halt) in low power mode.
 */
#if!defined(EDMA_MUX_START_PCTL)
#define EDMA_MUX_START_PCTL            (ME_PCTL_RUN(1) |          \
                                         ME_PCTL_LP(2))
#endif

#define DSPI5_ENABLE_CLOCK()                                         \
  SetPeripheralClockMode(DSPI5_PCTL, SPI_DSPI5_START_PCTL)
#define DSPI5_DISABLE_CLOCK()                                         \
  SetPeripheralClockMode(DSPI5_PCTL, SPI_DSPI5_STOP_PCTL)
/* ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  =*/
/* Driver constants.                                                         */
/* ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  = */

/**
 * @name    MCR register definitions
 * @{
 */
#define MCR_MSTR                       (1UL << 31)
#define MCR_CONT_SCKE                  (1UL << 30)
#define MCR_DCONF_MASK                 (3UL << 28)
#define MCR_FRZ                        (1UL << 27)
#define MCR_MTFE                       (1UL << 26)
#define MCR_PCSSE                      (1UL << 25)
#define MCR_ROOE                       (1UL << 24)
#define MCR_PCSIS7                     (1UL << 23)
#define MCR_PCSIS6                     (1UL << 22)
#define MCR_PCSIS5                     (1UL << 21)
#define MCR_PCSIS4                     (1UL << 20)
#define MCR_PCSIS3                     (1UL << 19)
#define MCR_PCSIS2                     (1UL << 18)
#define MCR_PCSIS1                     (1UL << 17)
#define MCR_PCSIS0                     (1UL << 16)
#define MCR_DOZE                       (1UL << 15)
#define MCR_MDIS                       (1UL << 14)
#define MCR_DIS_TXF                    (1UL << 13)
#define MCR_DIS_RXF                    (1UL << 12)
#define MCR_CLR_TXF                    (1UL << 11)
#define MCR_CLR_RXF                    (1UL << 10)
#define MCR_SMPL_PT_MASK               (3UL << 8)
#define MCR_SMPL_PT(n)                 ((uint32_t)(n) << 8)
#define MCR_FCPCS                      (1UL << 2)
#define MCR_PES                        (1UL << 1)
#define MCR_HALT                       (1UL << 0)
/** @} */

/**
 * @name    RSER register definitions
 * @{
 */
#define RSER_TCF_RE                    (1UL << 31)
#define RSER_DSITCF_RE                 (1UL << 29)
#define RSER_EOQF_RE                   (1UL << 28)
#define RSER_TFUF_RE                   (1UL << 27)
#define RSER_SPITCF_RE                 (1UL << 26)
#define RSER_TFFF_RE                   (1UL << 25)
#define RSER_TFFF_DIRS                 (1UL << 24)
#define RSER_DPEF_RE                   (1UL << 22)
#define RSER_SPEF_RE                   (1UL << 21)
#define RSER_DDIF_RE                   (1UL << 20)
#define RSER_RFOF_RE                   (1UL << 19)
#define RSER_RFDF_RE                   (1UL << 17)
#define RSER_RFDF_DIRS                 (1UL << 16)
/** @} */

/**
 * @name    CTAR registers definitions
 * @{
 */
#define CTAR_DBR                       (1UL << 31)
#define CTAR_FMSZ_MASK                 (15UL << 27)
#define CTAR_FMSZ(n)                   (((uint32_t)(n) - 1U) << 27)
#define CTAR_CPOL                      (1UL << 26)
#define CTAR_CPHA                      (1UL << 25)
#define CTAR_LSBFE                     (1UL << 24)
#define CTAR_PCSSCK_MASK               (3UL << 22)
#define CTAR_PCSSCK_PRE1               (0UL << 22)
#define CTAR_PCSSCK_PRE3               (1UL << 22)
#define CTAR_PCSSCK_PRE5               (2UL << 22)
#define CTAR_PCSSCK_PRE7               (3UL << 22)
#define CTAR_PASC_MASK                 (3UL << 20)
#define CTAR_PASC_PRE1                 (0UL << 20)
#define CTAR_PASC_PRE3                 (1UL << 20)
#define CTAR_PASC_PRE5                 (2UL << 20)
#define CTAR_PASC_PRE7                 (3UL << 20)
#define CTAR_PDT_MASK                  (3UL << 18)
#define CTAR_PDT_PRE1                  (0UL << 18)
#define CTAR_PDT_PRE3                  (1UL << 18)
#define CTAR_PDT_PRE5                  (2UL << 18)
#define CTAR_PDT_PRE7                  (3UL << 18)
#define CTAR_PBR_MASK                  (3UL << 16)
#define CTAR_PBR_PRE2                  (0UL << 16)
#define CTAR_PBR_PRE3                  (1UL << 16)
#define CTAR_PBR_PRE5                  (2UL << 16)
#define CTAR_PBR_PRE7                  (3UL << 16)
#define CTAR_CSSCK_MASK                (15UL << 12)
#define CTAR_CSSCK_DIV2                (0UL << 12)
#define CTAR_CSSCK_DIV4                (1UL << 12)
#define CTAR_CSSCK_DIV8                (2UL << 12)
#define CTAR_CSSCK_DIV16               (3UL << 12)
#define CTAR_CSSCK_DIV32               (4UL << 12)
#define CTAR_CSSCK_DIV64               (5UL << 12)
#define CTAR_CSSCK_DIV128              (6UL << 12)
#define CTAR_CSSCK_DIV256              (7UL << 12)
#define CTAR_CSSCK_DIV512              (8UL << 12)
#define CTAR_CSSCK_DIV1024             (9UL << 12)
#define CTAR_CSSCK_DIV2048             (10UL << 12)
#define CTAR_CSSCK_DIV4096             (11UL << 12)
#define CTAR_CSSCK_DIV8192             (12UL << 12)
#define CTAR_CSSCK_DIV16384            (13UL << 12)
#define CTAR_CSSCK_DIV32768            (14UL << 12)
#define CTAR_CSSCK_DIV65536            (15UL << 12)
#define CTAR_ASC_MASK                  (15UL << 8)
#define CTAR_ASC_DIV2                  (0UL << 8)
#define CTAR_ASC_DIV4                  (1UL << 8)
#define CTAR_ASC_DIV8                  (2UL << 8)
#define CTAR_ASC_DIV16                 (3UL << 8)
#define CTAR_ASC_DIV32                 (4UL << 8)
#define CTAR_ASC_DIV64                 (5UL << 8)
#define CTAR_ASC_DIV128                (6UL << 8)
#define CTAR_ASC_DIV256                (7UL << 8)
#define CTAR_ASC_DIV512                (8UL << 8)
#define CTAR_ASC_DIV1024               (9UL << 8)
#define CTAR_ASC_DIV2048               (10UL << 8)
#define CTAR_ASC_DIV4096               (11UL << 8)
#define CTAR_ASC_DIV8192               (12UL << 8)
#define CTAR_ASC_DIV16384              (13UL << 8)
#define CTAR_ASC_DIV32768              (14UL << 8)
#define CTAR_ASC_DIV65536              (15UL << 8)
#define CTAR_DT_MASK                   (15UL << 4)
#define CTAR_DT_DIV2                   (0UL << 4)
#define CTAR_DT_DIV4                   (1UL << 4)
#define CTAR_DT_DIV8                   (2UL << 4)
#define CTAR_DT_DIV16                  (3UL << 4)
#define CTAR_DT_DIV32                  (4UL << 4)
#define CTAR_DT_DIV64                  (5UL << 4)
#define CTAR_DT_DIV128                 (6UL << 4)
#define CTAR_DT_DIV256                 (7UL << 4)
#define CTAR_DT_DIV512                 (8UL << 4)
#define CTAR_DT_DIV1024                (9UL << 4)
#define CTAR_DT_DIV2048                (10UL << 4)
#define CTAR_DT_DIV4096                (11UL << 4)
#define CTAR_DT_DIV8192                (12UL << 4)
#define CTAR_DT_DIV16384               (13UL << 4)
#define CTAR_DT_DIV32768               (14UL << 4)
#define CTAR_DT_DIV65536               (15UL << 4)
#define CTAR_BR_MASK                   (15UL << 0)
#define CTAR_BR_DIV2                   (0UL << 0)
#define CTAR_BR_DIV4                   (1UL << 0)
#define CTAR_BR_DIV6                   (2UL << 0)
#define CTAR_BR_DIV8                   (3UL << 0)
#define CTAR_BR_DIV16                  (4UL << 0)
#define CTAR_BR_DIV32                  (5UL << 0)
#define CTAR_BR_DIV64                  (6UL << 0)
#define CTAR_BR_DIV128                 (7UL << 0)
#define CTAR_BR_DIV256                 (8UL << 0)
#define CTAR_BR_DIV512                 (9UL << 0)
#define CTAR_BR_DIV1024                (10UL << 0)
#define CTAR_BR_DIV2048                (11UL << 0)
#define CTAR_BR_DIV4096                (12UL << 0)
#define CTAR_BR_DIV8192                (13UL << 0)
#define CTAR_BR_DIV16384               (14UL << 0)
#define CTAR_BR_DIV32768               (15UL << 0)
/** @} */

/**
 * @name    PUSHR register definitions
 * @{
 */
#define PUSHR_CONT                     (1UL << 31)
#define PUSHR_CTAS_MASK                (7UL << 28)
#define PUSHR_CTAS(n)                  ((uint32_t)(n) << 28)
#define PUSHR_EOQ                      (1UL << 27)
#define PUSHR_CTCNT                    (1UL << 26)
#define PUSHR_MASC                     (1UL << 25)
#define PUSHR_MCSC                     (1UL << 24)
#define PUSHR_PCS_MASK                 (255UL << 16)
#define PUSHR_PCS(n)                   ((1UL << (n)) << 16)
#define PUSHR_TXDATA_MASK              (0xFFFFUL << 0)

/* ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  = */
/* Driver constants.                                                         */
/* ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  = */

/* ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  == */
/* Driver pre - compile time settings.                                        */
/* ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  == */

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   SPID1 driver enable switch.
 * @details If set to @p TRUE the support for DSPI0 is included.
 */
#if!defined(SPI_USE_DSPI0)
#define SPI_USE_DSPI0                  FALSE
#endif

/**
 * @brief   SPID2 driver enable switch.
 * @details If set to @p TRUE the support for DSPI1 is included.
 */
#if!defined(SPI_USE_DSPI1)
#define SPI_USE_DSPI1                  FALSE
#endif

/**
 * @brief   SPID3 driver enable switch.
 * @details If set to @p TRUE the support for DSPI2 is included.
 */
#if!defined(SPI_USE_DSPI2)
#define SPI_USE_DSPI2                  FALSE
#endif

/**
 * @brief   SPID4 driver enable switch.
 * @details If set to @p TRUE the support for DSPI3 is included.
 */
#if!defined(SPI_USE_DSPI3)
#define SPI_USE_DSPI3                  FALSE
#endif

/**
 * @brief   SPID5 driver enable switch.
 * @details If set to @p TRUE the support for DSPI4 is included.
 */
#if!defined(SPI_USE_DSPI4)
#define SPI_USE_DSPI4                  FALSE
#endif

/**
 * @brief   SPID6 driver enable switch.
 * @details If set to @p TRUE the support for DSPI5 is included.
 */
#if!defined(SPI_USE_DSPI5)
#define SPI_USE_DSPI5                  FALSE
#endif

/**
 * @brief   Selects the DMA mode for the SPI driver.
 * @details The driver is able to work using three distinct DMA modes:
 *          - SPI_DMA_RX_AND_TX, 3 DMA channels are used for both RX
 *            and TX. Note, the transmission size is limited to 512 frames
 *            in this mode because EDMA limitations.
 *          - SPI_DMA_RX_ONLY, 1 DMA channels is used for RX only. TX
 *            is handled using interrupts.
 *          - SPI_DMA_NONE, the DMA is not used at all, the drivers
 *            works in a fully interrupt - driven way.
 *          .
 * @note    DMA modes are only possible on those platforms where a DMA
 *          controllers is present.
 */
#if!defined(SPI_DMA_MODE)
#define SPI_DMA_MODE                   SPI_DMA_NONE
#endif

/**
 * @brief   DSPI0 MCR PCS defaults.
 */
#if!defined(SPI_DSPI0_MCR)
#define SPI_DSPI0_MCR                  (MCR_PCSIS0 |              \
                                             MCR_PCSIS1 |              \
                                             MCR_PCSIS2 |              \
                                             MCR_PCSIS3 |              \
                                             MCR_PCSIS4 |              \
                                             MCR_PCSIS5 |              \
                                             MCR_PCSIS6 |              \
                                             MCR_PCSIS7)
#endif

/**
 * @brief   DSPI1 MCR PCS defaults.
 */
#if!defined(SPI_DSPI1_MCR)
#define SPI_DSPI1_MCR                  (MCR_PCSIS0 |              \
                                             MCR_PCSIS1 |              \
                                             MCR_PCSIS2 |              \
                                             MCR_PCSIS3 |              \
                                             MCR_PCSIS4 |              \
                                             MCR_PCSIS5 |              \
                                             MCR_PCSIS6 |              \
                                             MCR_PCSIS7)
#endif

/**
 * @brief   DSP2 MCR PCS defaults.
 */
#if!defined(SPI_DSPI2_MCR)
#define SPI_DSPI2_MCR                  (MCR_PCSIS0 |              \
                                             MCR_PCSIS1 |              \
                                             MCR_PCSIS2 |              \
                                             MCR_PCSIS3 |              \
                                             MCR_PCSIS4 |              \
                                             MCR_PCSIS5 |              \
                                             MCR_PCSIS6 |              \
                                             MCR_PCSIS7)
#endif

/**
 * @brief   DSPI3 MCR PCS defaults.
 */
#if!defined(SPI_DSPI3_MCR)
#define SPI_DSPI3_MCR                  (MCR_PCSIS0 |              \
                                             MCR_PCSIS1 |              \
                                             MCR_PCSIS2 |              \
                                             MCR_PCSIS3 |              \
                                             MCR_PCSIS4 |              \
                                             MCR_PCSIS5 |              \
                                             MCR_PCSIS6 |              \
                                             MCR_PCSIS7)
#endif

/**
 * @brief   DSPI4 MCR PCS defaults.
 */
#if!defined(SPI_DSPI4_MCR)
#define SPI_DSPI4_MCR                  (MCR_PCSIS0 |              \
                                             MCR_PCSIS1 |              \
                                             MCR_PCSIS2 |              \
                                             MCR_PCSIS3 |              \
                                             MCR_PCSIS4 |              \
                                             MCR_PCSIS5 |              \
                                             MCR_PCSIS6 |              \
                                             MCR_PCSIS7)
#endif

/**
 * @brief   DSPI5 MCR PCS defaults.
 */
#if!defined(SPI_DSPI5_MCR)
#define SPI_DSPI5_MCR                  (MCR_PCSIS0 |              \
                                             MCR_PCSIS1 |              \
                                             MCR_PCSIS2 |              \
                                             MCR_PCSIS3 |              \
                                             MCR_PCSIS4 |              \
                                             MCR_PCSIS5 |              \
                                             MCR_PCSIS6 |              \
                                             MCR_PCSIS7)
#endif

/**
 * @brief   DSPI0 DMA IRQ priority.
 */
#if!defined(SPI_DSPI0_DMA_IRQ_PRIO)
#define SPI_DSPI0_DMA_IRQ_PRIO         10
#endif

/**
 * @brief   DSPI1 DMA IRQ priority.
 */
#if!defined(SPI_DSPI1_DMA_IRQ_PRIO)
#define SPI_DSPI1_DMA_IRQ_PRIO         10
#endif

/**
 * @brief   DSPI2 DMA IRQ priority.
 */
#if!defined(SPI_DSPI2_DMA_IRQ_PRIO)
#define SPI_DSPI2_DMA_IRQ_PRIO         10
#endif

/**
 * @brief   DSPI3 DMA IRQ priority.
 */
#if!defined(SPI_DSPI3_DMA_IRQ_PRIO)
#define SPI_DSPI3_DMA_IRQ_PRIO         10
#endif

/**
 * @brief   DSPI4 DMA IRQ priority.
 */
#if!defined(SPI_DSPI4_DMA_IRQ_PRIO)
#define SPI_DSPI4_DMA_IRQ_PRIO         10
#endif

/**
 * @brief   DSPI5 DMA IRQ priority.
 */
#if!defined(SPI_DSPI5_DMA_IRQ_PRIO)
#define SPI_DSPI5_DMA_IRQ_PRIO         10
#endif

/**
 * @brief   SPI DMA error hook.
 */
#if!defined(SPI_DMA_ERROR_HOOK)
#define SPI_DMA_ERROR_HOOK(spip)       irqSysHalt()
#endif

/**
 * @brief   DSPI0 IRQ priority.
 */
#if!defined(SPI_DSPI0_IRQ_PRIO)
#define SPI_DSPI0_IRQ_PRIO             10
#endif

/**
 * @brief   DSPI1 IRQ priority.
 */
#if!defined(SPI_DSPI1_IRQ_PRIO)
#define SPI_DSPI1_IRQ_PRIO             10
#endif

/**
 * @brief   DSPI2 IRQ priority.
 */
#if!defined(SPI_DSPI2_IRQ_PRIO)
#define SPI_DSPI2_IRQ_PRIO             10
#endif

/**
 * @brief   DSPI3 IRQ priority.
 */
#if!defined(SPI_DSPI3_IRQ_PRIO)
#define SPI_DSPI3_IRQ_PRIO             10
#endif

/**
 * @brief   DSPI4 IRQ priority.
 */
#if!defined(SPI_DSPI4_IRQ_PRIO)
#define SPI_DSPI4_IRQ_PRIO             10
#endif

/**
 * @brief   DSPI5 IRQ priority.
 */
#if!defined(SPI_DSPI5_IRQ_PRIO)
#define SPI_DSPI5_IRQ_PRIO             10
#endif

/**
 * @brief   DSPI0 peripheral configuration when started.
 * @note    The default configuration is 1 (always run) in run mode and
 *          2 (only halt) in low power mode.
 */
#if!defined(SPI_DSPI0_START_PCTL)
#define SPI_DSPI0_START_PCTL           (ME_PCTL_RUN(1) |          \
                                             ME_PCTL_LP(2))
#endif

/**
 * @brief   DSPI0 peripheral configuration when stopped.
 * @note    The default configuration is 0 (never run) in run mode and
 *          0 (never run) in low power mode.
 */
#if!defined(SPI_DSPI0_STOP_PCTL)
#define SPI_DSPI0_STOP_PCTL            (ME_PCTL_RUN(0) |          \
                                             ME_PCTL_LP(0))
#endif

/**
 * @brief   DSPI1 peripheral configuration when started.
 * @note    The default configuration is 1 (always run) in run mode and
 *          2 (only halt) in low power mode.
 */
#if!defined(SPI_DSPI1_START_PCTL)
#define SPI_DSPI1_START_PCTL           (ME_PCTL_RUN(1) |          \
                                             ME_PCTL_LP(2))
#endif

/**
 * @brief   DSPI1 peripheral configuration when stopped.
 * @note    The default configuration is 0 (never run) in run mode and
 *          0 (never run) in low power mode.
 */
#if!defined(SPI_DSPI1_STOP_PCTL)
#define SPI_DSPI1_STOP_PCTL            (ME_PCTL_RUN(0) |          \
                                             ME_PCTL_LP(0))
#endif

/**
 * @brief   DSPI2 peripheral configuration when started.
 * @note    The default configuration is 1 (always run) in run mode and
 *          2 (only halt) in low power mode.
 */
#if!defined(SPI_DSPI2_START_PCTL)
#define SPI_DSPI2_START_PCTL           (ME_PCTL_RUN(1) |          \
                                             ME_PCTL_LP(2))
#endif

/**
 * @brief   DSPI2 peripheral configuration when stopped.
 * @note    The default configuration is 0 (never run) in run mode and
 *          0 (never run) in low power mode.
 */
#if!defined(SPI_DSPI2_STOP_PCTL)
#define SPI_DSPI2_STOP_PCTL            (ME_PCTL_RUN(0) |          \
                                             ME_PCTL_LP(0))
#endif

/**
 * @brief   DSPI3 peripheral configuration when started.
 * @note    The default configuration is 1 (always run) in run mode and
 *          2 (only halt) in low power mode.
 */
#if!defined(SPI_DSPI3_START_PCTL)
#define SPI_DSPI3_START_PCTL           (ME_PCTL_RUN(1) |          \
                                             ME_PCTL_LP(2))
#endif

/**
 * @brief   DSPI3 peripheral configuration when stopped.
 * @note    The default configuration is 0 (never run) in run mode and
 *          0 (never run) in low power mode.
 */
#if!defined(SPI_DSPI3_STOP_PCTL)
#define SPI_DSPI3_STOP_PCTL            (ME_PCTL_RUN(0) |          \
                                             ME_PCTL_LP(0))
#endif

/**
 * @brief   DSPI4 peripheral configuration when started.
 * @note    The default configuration is 1 (always run) in run mode and
 *          2 (only halt) in low power mode.
 */
#if!defined(SPI_DSPI4_START_PCTL)
#define SPI_DSPI4_START_PCTL           (ME_PCTL_RUN(1) |          \
                                             ME_PCTL_LP(2))
#endif

/**
 * @brief   DSPI4 peripheral configuration when stopped.
 * @note    The default configuration is 0 (never run) in run mode and
 *          0 (never run) in low power mode.
 */
#if!defined(SPI_DSPI4_STOP_PCTL)
#define SPI_DSPI4_STOP_PCTL            (ME_PCTL_RUN(0) |          \
                                             ME_PCTL_LP(0))
#endif

/**
 * @brief   DSPI5 peripheral configuration when started.
 * @note    The default configuration is 1 (always run) in run mode and
 *          2 (only halt) in low power mode.
 */
#if!defined(SPI_DSPI5_START_PCTL)
#define SPI_DSPI5_START_PCTL           (ME_PCTL_RUN(1) |          \
                                             ME_PCTL_LP(2))
#endif

/**
 * @brief   DSPI5 peripheral configuration when stopped.
 * @note    The default configuration is 0 (never run) in run mode and
 *          0 (never run) in low power mode.
 */
#if!defined(SPI_DSPI5_STOP_PCTL)
#define SPI_DSPI5_STOP_PCTL            (ME_PCTL_RUN(0) |          \
                                             ME_PCTL_LP(0))
#endif

#if!defined(EDMA_MUX_START_PCTL)
#define EDMA_MUX_START_PCTL            (ME_PCTL_RUN(1) |          \
                                             ME_PCTL_LP(2))
#endif

/* ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  = */
/* Derived constants and error checks.                                       */
/* ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  == */

#if!(SPI_DMA_MODE == SPI_DMA_NONE) &&                                \
        !(SPI_DMA_MODE == SPI_DMA_RX_ONLY) &&                         \
        !(SPI_DMA_MODE == SPI_DMA_RX_AND_TX)
#error "invalid SPI_DMA_MODE selected"
#endif

#if (HAS_EDMA == FALSE) && (SPI_DMA_MODE != SPI_DMA_NONE)
#error "SPI with DMA modes are not supported on this device, no DMA found"
#endif

#if (SPI_USE_DSPI0 == TRUE) && (HAS_DSPI0 == FALSE)
#error "DSPI0 not present in the selected device"
#endif

#if (SPI_USE_DSPI1 == TRUE) && (HAS_DSPI1 == FALSE)
#error "DSPI1 not present in the selected device"
#endif

#if (SPI_USE_DSPI2 == TRUE) && (HAS_DSPI2 == FALSE)
#error "DSPI2 not present in the selected device"
#endif

#if (SPI_USE_DSPI3 == TRUE) && (HAS_DSPI3 == FALSE)
#error "DSPI3 not present in the selected device"
#endif

#if (SPI_USE_DSPI4 == TRUE) && (HAS_DSPI4 == FALSE)
#error "DSPI4 not present in the selected device"
#endif

#if (SPI_USE_DSPI5 == TRUE) && (HAS_DSPI5 == FALSE)
#error "DSPI5 not present in the selected device"
#endif

#if (SPI_USE_DSPI0 == FALSE) && (SPI_USE_DSPI1 == FALSE) &&       \
    (SPI_USE_DSPI2 == FALSE) && (SPI_USE_DSPI3 == FALSE) &&       \
    (SPI_USE_DSPI4 == FALSE) && (SPI_USE_DSPI5 == FALSE)
#error "SPI driver activated but no DSPI peripheral assigned"
#endif

#if (HAS_EDMA == TRUE) && (SPI_USE_DSPI0 == TRUE)
#if ((SPI_DMA_MODE == SPI_DMA_RX_ONLY) &&                         \
     (!defined(SPI_DSPI0_RX_DMA_CH_ID))) ||                            \
    ((SPI_DMA_MODE == SPI_DMA_RX_AND_TX) &&                       \
     (!defined(SPI_DSPI0_TX1_DMA_CH_ID) ||                             \
     !defined(SPI_DSPI0_TX2_DMA_CH_ID) ||                             \
     !defined(SPI_DSPI0_RX_DMA_CH_ID)))
#error "DMA channels not defined for DSPI0"
#endif
#endif

#if (HAS_EDMA == TRUE) && (SPI_USE_DSPI1 == TRUE)
#if ((SPI_DMA_MODE == SPI_DMA_RX_ONLY) &&                         \
     (!defined(SPI_DSPI1_RX_DMA_CH_ID))) ||                            \
    ((SPI_DMA_MODE == SPI_DMA_RX_AND_TX) &&                       \
     (!defined(SPI_DSPI1_TX1_DMA_CH_ID) ||                             \
     !defined(SPI_DSPI1_TX2_DMA_CH_ID) ||                             \
     !defined(SPI_DSPI1_RX_DMA_CH_ID)))
#error "DMA channels not defined for DSPI1"
#endif
#endif

#if (HAS_EDMA == TRUE) && (SPI_USE_DSPI2 == TRUE)
#if ((SPI_DMA_MODE == SPI_DMA_RX_ONLY) &&                         \
     (!defined(SPI_DSPI2_RX_DMA_CH_ID))) ||                            \
    ((SPI_DMA_MODE == SPI_DMA_RX_AND_TX) &&                       \
     (!defined(SPI_DSPI2_TX1_DMA_CH_ID) ||                             \
     !defined(SPI_DSPI2_TX2_DMA_CH_ID) ||                             \
     !defined(SPI_DSPI2_RX_DMA_CH_ID)))
#error "DMA channels not defined for DSPI2"
#endif
#endif

#if (HAS_EDMA == TRUE) && (SPI_USE_DSPI3 == TRUE)
#if ((SPI_DMA_MODE == SPI_DMA_RX_ONLY) &&                         \
     (!defined(SPI_DSPI3_RX_DMA_CH_ID))) ||                            \
    ((SPI_DMA_MODE == SPI_DMA_RX_AND_TX) &&                       \
     (!defined(SPI_DSPI3_TX1_DMA_CH_ID) ||                             \
     !defined(SPI_DSPI3_TX2_DMA_CH_ID) ||                             \
     !defined(SPI_DSPI3_RX_DMA_CH_ID)))
#error "DMA channels not defined for DSPI3"
#endif
#endif

#if (HAS_EDMA == TRUE) && (SPI_USE_DSPI4 == TRUE)
#if ((SPI_DMA_MODE == SPI_DMA_RX_ONLY) &&                         \
     (!defined(SPI_DSPI4_RX_DMA_CH_ID))) ||                            \
    ((SPI_DMA_MODE == SPI_DMA_RX_AND_TX) &&                       \
     (!defined(SPI_DSPI4_TX1_DMA_CH_ID) ||                             \
     !defined(SPI_DSPI4_TX2_DMA_CH_ID) ||                             \
     !defined(SPI_DSPI4_RX_DMA_CH_ID)))
#error "DMA channels not defined for DSPI4"
#endif
#endif

#if (HAS_EDMA == TRUE) && (SPI_USE_DSPI5 == TRUE)
#if ((SPI_DMA_MODE == SPI_DMA_RX_ONLY) &&                         \
     (!defined(SPI_DSPI5_RX_DMA_CH_ID))) ||                            \
    ((SPI_DMA_MODE == SPI_DMA_RX_AND_TX) &&                       \
     (!defined(SPI_DSPI5_TX1_DMA_CH_ID) ||                             \
     !defined(SPI_DSPI5_TX2_DMA_CH_ID) ||                             \
     !defined(SPI_DSPI5_RX_DMA_CH_ID)))
#error "DMA channels not defined for DSPI5"
#endif
#endif

/* ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  = */
/* Driver data structures and types.                                         */
/* ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  = */

/**
 * @brief SPI mode type.
 */
typedef enum {
    DSPI0 = 0U,
    DSPI1 = 1U,
    DSPI2 = 2U,
    DSPI3 = 3U,
    DSPI4 = 4U,
    DSPI5 = 5U,
    DSPI6 = 6U,
    DSPI7 = 7U,
    DSPI8 = 8U //slian-20230731
} spi_controller_t;

/*
 * @brief Type of a structure representing an SPI driver.
 *
 */
typedef struct SPIDriver SPIDriver;

/*!
 * @brief Defines the mode of the DSPI (master or slave)
 *
 * Select if the device is used as master or slave.
 *
 */
typedef enum
{
    SPI_SLAVE  = 0U,
    SPI_MASTER = 1U
} spi_functional_mode_t;

/*!
 * @brief Defines the polarity for data signal of DSPI
 *
 * This enum is used to define data polarity
 *
 * Implements : dspi_polarity_t_Class
 */
typedef enum
{
    SPI_ACTIVE_LOW = 0U,
    SPI_ACTIVE_HIGH = 1U
} spi_clock_polarity_t;

typedef enum
{
    SPI_INACTIVE_LOW = 0U,
    SPI_INACTIVE_HIGH = 1U
} spi_pcs_polarity_t;
/*!
 * @brief Defines shift and capture edges for SPI transfer
 *
 * This enum is used to define the edges used for shifting and captureing
 *
 * Implements : dspi_clock_phase_t_Class
 */
typedef enum
{
    SPI_CLOCK_PHASE_1ST_EDGE = 0U, /*! < Data captured on SCK 1st edge, changed on 2nd. */
    SPI_CLOCK_PHASE_2ND_EDGE = 1U  /*! < Data changed on SCK 1st edge, captured on 2nd. */
} spi_clock_phase_t;

/*!
 * @brief Defines how are handle the RX/TX buffers
 *
 * This typedef defines the available methods to handle RX and TX buffers
 *
 * Implements : dspi_transfer_type_t_Class
 */
typedef enum
{
    SPI_USING_POLLING = 0U,
    SPI_USING_INTERRUPTS = 1U
} spi_transfer_type_t;

/*!
 * @brief Defines how are handle the RX/TX data
 *
 * This typedef defines the available methods to handle RX and TX data
 *
 * Implements : spi_dma_type_t_Class
 */
typedef enum
{
    DSPI_DMA_NONE = 0U,
    DSPI_DMA_RX_ONLY = 1U,
    DSPI_DMA_RX_AND_TX = 2
} spi_dma_type_t;

typedef uint32_t size_t; /*PRQA S 4605*/
/**
 * @brief   SPI notification callback type.
 *
 * @param[in] spip      pointer to the @p SPIDriver object triggering the
 *                      callback
 */
typedef void (*spicallback_t)(SPIDriver *spip);


typedef struct
{
	spi_controller_t WhichSpiController;	/*!< Select which DSPI controller is used */
    uint8_t CTARx;						    /*!< Select which DSICTARs(0~7) is used */	
    uint32_t bitsPerSec;                  	/*!< Baud rate in bits per second*/
    spi_pcs_polarity_t pcsPolarity;         /*!< PCS polarity for all available PCS*/
    uint16_t bitcount;                   	/*!< Number of bits/frame, minimum is 4-bits , maximum = 16-bits*/
    spi_clock_phase_t clkPhase;         	/*!< Selects which phase of clock to capture data */
    spi_clock_polarity_t clkPolarity;       /*!< Selects clock polarity */
    uint8_t isClkContinuous;                /*!< Enable/disable continuous clock */
    uint8_t lsbFirst;                       /*!< Option to transmit LSB first */
    spi_transfer_type_t transferType;   	/*!< Type of DSPI transfer */
    spi_dma_type_t  dmaType;				/*!< Type of handing DSPI TX/RX data */
    spicallback_t callback;             	/*!< User callback function. Note that this function will be
                                          	  *  called from the interrupt service routine, so its
                                          	  *  execution time should be as small as possible. It can be
                                          	  *  NULL if it is not needed */
    uint8_t continuousPCS;                  /*!< Enable/disable continuous CS */
    uint8_t whichPCS;                    	/*!< Select which CS(PCSIS0~PCSIS5) is used */
} spi_config_t;


/*!
 * @brief Defines the configuration for DSPI DSI/CSI master/slave mode.
 *
 * Implements : dcsi_config_t_Class
 */

typedef struct
{    
    uint8_t Dconf;							/*!< DSPI Configuration: 0b00 - SPI, 0b01 - DSI, 0b10 - CSI */   
    uint8_t TSBC;							/*!< Timed Serial Bus Configuration 0 - disable, 1 - enable*/
    uint8_t DsiDataSource;			     	/*!< 0 - DSPI_SDR, 1 - DSPI_ASDR */   
    uint8_t isCID;							/*!< DSI transfer 0 - continuous, 1 - Change in Data */
    uint8_t Dcont;       					/*!< Enable/disable DSI continuous CS  */
    uint8_t DSICTAx;						/*!< Select which DSICTARs(0~7) is used */	
    uint8_t whichDSIPCS;                    /*!< Select which DSI CS(DPCS0~DPCS5) is used */
    
    uint8_t TSBCNT;							/*!< Timed Serial Bus operation Count */
    uint8_t SDR1En;							/*!< SDR1 1-enable 0-disnable */
    uint8_t DataSelect0En;					/*!< Zero bit is inserted at the middle of the data frame */
    uint8_t DataSelect1En;					/*!< Zero bit is inserted at the beginning of the data frame */
    uint8_t whichTSBPCS;                    /*!< Select which the Second receiver CS(DPCS1_0~DPCS1_7) is used */
    
} dcsi_config_t;

/**
 * @brief   Structure representing an SPI driver.
 * @note    Implementations may extend this structure to contain more,
 *          architecture dependent, fields.
 */
struct SPIDriver {
  /**
   * @brief   Current configuration data.
   */
  const spi_config_t    *config;
  /**
   * @brief   Waiting flag.
   */
  vuint8_t           ready;
  /**
   * @brief   Pointer to the DSPI registers block.
   */
  volatile struct DSPI_tag    *dspi;
  
  volatile struct DSPIMSC_tag    *dspi8;

  /**
   * @brief   EDMA channel used for receive.
   */
  edma_channel_t            rx_channel;
  /**
   * @brief   Memory pointer for RX operations.
   */
  union {
    void                    *rx_ptr;
    uint8_t                 *rx_ptr8;
    uint16_t                *rx_ptr16;
  }rx;

  /*
   * @brief   Remaining frames to be received.
   */
  size_t                    rx_cnt;
  /**
   * @brief   EDMA channel used for data memory to memory copy.
   */
  edma_channel_t            tx1_channel;
  /**
   * @brief   EDMA channel used for transmit.
   */
  edma_channel_t            tx2_channel;
  /**
   * @brief   Command for the ongoing TX operation.
   */
  uint32_t                  tx_cmd;
  /**
   * @brief   Last frame of a transmission sequence.
   */
  uint32_t                  tx_last;
  /**
   * @brief   Memory pointer for TX operations.
   */
  union {
     void              *tx_ptr;
     uint8_t           *tx_ptr8;
     uint16_t          *tx_ptr16;
  }tx;

  /*
   * @brief   Remaining frames to be transmitted.
   */
  size_t                    tx_cnt;
};
/*------------------------------------------------------------------------ - */

/**
 * @brief   SPI TX/RX status.
 */
#define SPI_TXRX_READY                 0U
#define SPI_TXRX_BUSY                  1U

#if (SPI_USE_WAIT == TRUE)
/**
 * @brief   Sets ready flag.
 * @details This function sets the ready flag when a TX/RX transfer starts.
 *
 * @param[in] spip      pointer to the @p SPI Driver object
 *
 * @notapi
 */
#define SPI_TXRX_IN_PROGRESS(spip)                                        \
  (spip)->ready = SPI_TXRX_BUSY;

/**
 * @brief   Clears ready flag.
 * @details This function clears the ready flag when a TX/RX transfer is
 *          completed.
 *
 * @param[in] spip      pointer to the @p SPI Driver object
 *
 * @notapi
 */
#define SPI_TXRX_DONE(spip)                                               \
  (spip)->ready = SPI_TXRX_READY;

#ifdef __ghs__
#pragma ghs ZO
#endif
/**
 * @brief   Waits for TX/RX completion.
 * @details This function waits till the current TX/RX transfer is completed.
 *
 * @param[in] spip      pointer to the @p SPI Driver object
 *
 * @notapi
 */
#define SPI_WAIT_FOR_TXRX_COMPLETION(spip)                                \
    while ((spip)->ready == SPI_TXRX_BUSY)                                \
    {}
#ifdef __ghs__
#pragma ghs O
#endif
#else /*!SPI_USE_WAIT */
#define SPI_TXRX_IN_PROGRESS(spip)
#define SPI_TXRX_DONE(spip)
#define SPI_WAIT_FOR_TXRX_COMPLETION(spip)
#endif

/* ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  = */
/* IRQ Handlers                                                              */
/* ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  = */

IRQ_HANDLER(DSPI0_RFDF_HANDLER);
IRQ_HANDLER(DSPI0_EOQF_HANDLER);
IRQ_HANDLER(DSPI0_TFFF_HANDLER);
/* SPI_USE_DSPI0 */

IRQ_HANDLER(DSPI1_RFDF_HANDLER);
IRQ_HANDLER(DSPI1_EOQF_HANDLER);
IRQ_HANDLER(DSPI1_TFFF_HANDLER);
/* SPI_USE_DSPI1 */

IRQ_HANDLER(DSPI2_RFDF_HANDLER);
IRQ_HANDLER(DSPI2_EOQF_HANDLER);
IRQ_HANDLER(DSPI2_TFFF_HANDLER);
/* SPI_USE_DSPI2 */

IRQ_HANDLER(DSPI3_RFDF_HANDLER);
IRQ_HANDLER(DSPI3_EOQF_HANDLER);
IRQ_HANDLER(DSPI3_TFFF_HANDLER);
/* SPI_USE_DSPI3 */

IRQ_HANDLER(DSPI4_RFDF_HANDLER);
IRQ_HANDLER(DSPI4_EOQF_HANDLER);
IRQ_HANDLER(DSPI4_TFFF_HANDLER);
/* SPI_USE_DSPI4 */

IRQ_HANDLER(DSPI5_RFDF_HANDLER);
IRQ_HANDLER(DSPI5_EOQF_HANDLER);
IRQ_HANDLER(DSPI5_TFFF_HANDLER);
/* SPI_USE_DSPI5 */

IRQ_HANDLER(DSPI6_RFDF_HANDLER);
IRQ_HANDLER(DSPI6_EOQF_HANDLER);
IRQ_HANDLER(DSPI6_TFFF_HANDLER);
/* SPI_USE_DSPI6 */

IRQ_HANDLER(DSPI7_RFDF_HANDLER);
IRQ_HANDLER(DSPI7_EOQF_HANDLER);
IRQ_HANDLER(DSPI7_TFFF_HANDLER);
/* SPI_USE_DSPI7 */

IRQ_HANDLER(DSPI8_RFDF_HANDLER);
IRQ_HANDLER(DSPI8_EOQF_HANDLER);
IRQ_HANDLER(DSPI8_TFFF_HANDLER);
/* SPI_USE_DSPI8 */

/* ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  = */
/* External declarations.                                                    */
/* ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  ==  = */
extern SPIDriver SPID1;
extern SPIDriver SPID2;
extern SPIDriver SPID3;
extern SPIDriver SPID4;
extern SPIDriver SPID5;
extern SPIDriver SPID6;
extern SPIDriver SPID7;
extern SPIDriver SPID8;
extern SPIDriver SPID9;

#ifdef __cplusplus
extern "C" {
#endif

extern uint32_t SPI_LLD_SetbaudRate(const SPIDriver *spip, uint32_t bitsPerSec, uint32_t sourceClockInHz);
extern void SPI_LLD_Gpio_Init(uint8_t dspix, uint8_t spi_mode);
extern void SPI_LLD_Install_INT(SPIDriver *spip);
extern void SPI_LLD_Init(SPIDriver *spip, const spi_config_t *config, spi_functional_mode_t spi_mode);
extern void SPI_LLD_DeInit(const SPIDriver *spip);

extern void SPI_LLD_Exchange(SPIDriver *spip, size_t n, uint8_t *txbuf, uint8_t *rxbuf);
extern void SPI_LLD_Exchange_DMA(SPIDriver *spip, size_t n, uint8_t *txbuf, uint8_t *rxbuf);
extern void SPI_LLD_Exchange_DMA_Rx(SPIDriver *spip, size_t n, uint8_t *txbuf, uint8_t *rxbuf);
extern void SPI_LLD_Send(SPIDriver *spip, size_t n,  uint8_t *txbuf);
extern void SPI_LLD_Send_DMA(SPIDriver *spip, size_t n,  uint8_t *txbuf);
extern void SPI_LLD_Master_Receive(SPIDriver *spip, size_t n, uint8_t *rxbuf);
extern void SPI_LLD_Slave_Receive(SPIDriver *spip, size_t n, uint8_t *rxbuf);
extern void SPI_LLD_Receive_DMA(SPIDriver *spip, size_t n, uint8_t *rxbuf);

extern uint16_t SPI_LLD_Polled_Exchange_Frame(const SPIDriver *spip, uint16_t frame, uint8_t last_frame);
extern void SPI_LLD_Polled_Exchange(SPIDriver *spip , size_t n, uint8_t *txbuf, uint8_t *rxbuf);
extern void SPI_LLD_Polled_Send_Frame(const SPIDriver *spip, uint16_t frame, uint8_t last_frame);
extern void SPI_LLD_Polled_Send(SPIDriver *spip, size_t n, uint8_t *txbuf);
extern void SPI_LLD_Slave_Polled_Receive(SPIDriver *spip, size_t n, uint8_t *rxbuf);
extern void SPI_LLD_SetCATR0_NoFmsz(const SPIDriver *spip, uint32_t catr0_reg);

void spi_set_disable_fifo(const SPIDriver *spip);

extern uint32_t SPI8_LLD_SetbaudRate(const SPIDriver *spip, uint32_t bitsPerSec, uint32_t sourceClockInHz);
extern void SPI8_LLD_Gpio_Init(uint8_t dspix, uint8_t spi_mode,uint8_t lvds);
extern void SPI8_LLD_Install_INT(SPIDriver *spip);
extern void SPI8_LLD_Init(SPIDriver *spip, const spi_config_t *config,const dcsi_config_t *config1,spi_functional_mode_t spi_mode,uint8_t lvds); 
extern void SPI8_LLD_DeInit(const SPIDriver *spip);

extern void SPI8_LLD_Exchange(SPIDriver *spip, size_t n, uint8_t *txbuf, uint8_t *rxbuf);
extern void SPI8_LLD_Exchange_DMA(SPIDriver *spip, size_t n, uint8_t *txbuf, uint8_t *rxbuf);
extern void SPI8_LLD_Exchange_DMA_Rx(SPIDriver *spip, size_t n, uint8_t *txbuf, uint8_t *rxbuf);
extern void SPI8_LLD_Send(SPIDriver *spip, size_t n,  uint8_t *txbuf);
extern void SPI8_LLD_Send_DMA(SPIDriver *spip, size_t n,  uint8_t *txbuf);
extern void SPI8_LLD_Master_Receive(SPIDriver *spip, size_t n, uint8_t *rxbuf);
extern void SPI8_LLD_Slave_Receive(SPIDriver *spip, size_t n, uint8_t *rxbuf);
extern void SPI8_LLD_Receive_DMA(SPIDriver *spip, size_t n, uint8_t *rxbuf);

extern uint16_t SPI8_LLD_Polled_Exchange_Frame(const SPIDriver *spip, uint16_t frame, uint8_t last_frame);
extern void SPI8_LLD_Polled_Send_Frame(const SPIDriver *spip, uint16_t frame, uint8_t last_frame);
extern void SPI8_LLD_Polled_Send(SPIDriver *spip, size_t n, uint8_t *txbuf);
extern void SPI8_LLD_Slave_Polled_Receive(SPIDriver *spip, size_t n, uint8_t *rxbuf);
extern void SPI8_LLD_SetCATR0_NoFmsz(const SPIDriver *spip, uint32_t catr0_reg);
extern void SPI8_LLD_Polled_Exchange_8bit(SPIDriver *spip, uint32_t n, uint8_t *txbuf, uint8_t *rxbuf);
extern void SPI_LLD_Polled_Exchange_16bit(SPIDriver *spip, uint32_t n, uint8_t *txbuf, uint8_t *rxbuf);

void spi_set_disable_fifo(const SPIDriver *spip);

void edmaChannelRelease(const edma_channel_config_t *ccfg);
static void edmaSetMuxSlot(const edma_channel_config_t *ccfg);
edma_channel_t EdmaChannelAllocate(const edma_channel_config_t *ccfg);

#ifdef __cplusplus
}
#endif

#endif /* LLD_USE_SPI */
