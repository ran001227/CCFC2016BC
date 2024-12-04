/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC2016BC
* DESCRIPTION : CCFC2016BC edma low level drivers code
* HISTORY     : Initial version.
* @file     edma.h
* @version  1.1
* @date     2023 - 02 - 15
* @brief    Initial version.
*
*****************************************************************************/
#ifndef EDMA_LLD_H_
#define EDMA_LLD_H_

#include "typedefs.h"
#include "CCFC2016BC.h"
#include "IntcInterrupts.h"
#include "lldconf.h"

/**
 * @name    Common constants
 * @{
 */
#if!defined(FALSE)
#define FALSE                       0U
#endif

#if!defined(TRUE)
#define TRUE                        1U
#endif

#define EDMA_HAS_MUX         TRUE
#define EDMA_NUM_OF_MUX        1

#define EDMA_ERROR          0
#define EDMA_NCHANNELS                 16U

typedef uint32_t edma_channel_t;
/**
 * @brief   DMA callback type.
 *
 * @param[in] channel   the channel number
 * @param[in] p         parameter for the registered function
 */
typedef void (*edma_callback_t)(uint32_t *p);

/**
 * @brief   DMA error callback type.
 *
 * @param[in] channel   the channel number
 * @param[in] p         parameter for the registered function
 * @param[in] esr       content of the ESR register
 */
typedef void (*edma_error_callback_t)(uint32_t *p,
                                      uint32_t esr);

/**
 * @brief   Type of an EDMA channel configuration structure.
 */
typedef struct { /* PRQA S 3630 */
  edma_channel_t        dma_channel;    /** < @brief Channel to be allocated.*/
#if (EDMA_HAS_MUX == TRUE)
  uint8_t               dma_periph;     /** < @brief Peripheral to be
                                             associated to the channel.     */
#if (EDMA_NUM_OF_MUX > 1U)
  uint8_t               dma_mux;        /** < @brief Mux associated to the
                                             peripheral.                    */
#endif /* EDMA_NUM_OF_MUX more than 1 */
#endif /* EDMA_HAS_MUX */
  uint8_t        dma_irq_prio;   /** < @brief IRQ priority level for
                                             this channel.                  */
  edma_callback_t       dma_func;       /** < @brief Channel callback,
                                             can be NULL if not required.   */
  edma_error_callback_t dma_error_func; /** < @brief Channel error callback,
                                             can be NULL if not required.   */
  uint32_t                  *dma_param;     /** < @brief Channel callback param. */
} edma_channel_config_t;

#define EDMA_ERR_FLAG_31_0_HANDLER             vector10
#define EDMA_ERR_FLAG_31_0_NUMBER              10

#define EDMA_CH0_NUMBER                      11
#define EDMA_CH1_NUMBER                      12
#define EDMA_CH2_NUMBER                      13
#define EDMA_CH3_NUMBER                      14
#define EDMA_CH4_NUMBER                      15
#define EDMA_CH5_NUMBER                      16
#define EDMA_CH6_NUMBER                      17
#define EDMA_CH7_NUMBER                      18
#define EDMA_CH8_NUMBER                      19
#define EDMA_CH9_NUMBER                      20
#define EDMA_CH10_NUMBER                      21
#define EDMA_CH11_NUMBER                      22
#define EDMA_CH12_NUMBER                      23
#define EDMA_CH13_NUMBER                      24
#define EDMA_CH14_NUMBER                      25
#define EDMA_CH15_NUMBER                      26

#define EDMA_CH0_HANDLER                     vector11
#define EDMA_CH1_HANDLER                     vector12
#define EDMA_CH2_HANDLER                     vector13
#define EDMA_CH3_HANDLER                     vector14
#define EDMA_CH4_HANDLER                     vector15
#define EDMA_CH5_HANDLER                     vector16
#define EDMA_CH6_HANDLER                     vector17
#define EDMA_CH7_HANDLER                     vector18
#define EDMA_CH8_HANDLER                     vector19
#define EDMA_CH9_HANDLER                     vector20
#define EDMA_CH10_HANDLER                     vector21
#define EDMA_CH11_HANDLER                     vector22
#define EDMA_CH12_HANDLER                     vector23
#define EDMA_CH13_HANDLER                     vector24
#define EDMA_CH14_HANDLER                     vector25
#define EDMA_CH15_HANDLER                     vector26

#define EDMA_ERROR_IRQ_PRIO            12

#define EDMA_ERROR_HANDLER()           irqSysHalt() /* PRQA S 3472 */

/**
 * @name    EDMA CR register definitions
 * @{
 */
#define EDMA_CR_CX                  (1UL << 17)
#define EDMA_CR_ECX                 (1UL << 16)
#define EDMA_CR_GRP3PRI_MASK        (3UL << 14)
#define EDMA_CR_GRP3PRI(n)          ((uint32_t)(n) << 14)
#define EDMA_CR_GRP2PRI_MASK        (3UL << 12)
#define EDMA_CR_GRP2PRI(n)          ((uint32_t)(n) << 12)
#define EDMA_CR_GRP1PRI_MASK        (3UL << 10)
#define EDMA_CR_GRP1PRI(n)          ((uint32_t)(n) << 10)
#define EDMA_CR_GRP0PRI_MASK        (3UL << 8)
#define EDMA_CR_GRP0PRI(n)          ((uint32_t)(n) << 8)
#define EDMA_CR_EMLM                (1UL << 7)
#define EDMA_CR_CLM                 (1UL << 6)
#define EDMA_CR_HALT                (1UL << 5)
#define EDMA_CR_HOE                 (1UL << 4)
#define EDMA_CR_ERGA                (1UL << 3)
#define EDMA_CR_ERCA                (1UL << 2)
#define EDMA_CR_EDBG                (1UL << 1)
#define EDMA_CR_EBW                 (1UL << 0)
/** @} */
/**
 * @name    EDMA mode constants
 * @{
 */
#define EDMA_TCD_MODE_START         (1UL << 0)
#define EDMA_TCD_MODE_INT_END       (1UL << 1)
#define EDMA_TCD_MODE_INT_HALF      (1UL << 2)
#define EDMA_TCD_MODE_DREQ          (1UL << 3)
#define EDMA_TCD_MODE_SG            (1UL << 4)
#define EDMA_TCD_MODE_MELINK        (1UL << 5)
#define EDMA_TCD_MODE_ACTIVE        (1UL << 6)
#define EDMA_TCD_MODE_DONE          (1UL << 7)
#define EDMA_TCD_MODE_MLINKCH_MASK  (63UL << 8)
#define EDMA_TCD_MODE_MLINKCH(n)    ((uint32_t)(n) << 8) /* PRQA S 3472 */
#define EDMA_TCD_MODE_BWC_MASK      (3UL << 14)
#define EDMA_TCD_MODE_BWC(n)        ((uint32_t)(n) << 14)
/** @} */

/*
 * EDMA driver settings.
 */
#define EDMA_CR_SETTING                        (EDMA_CR_GRP1PRI(1) |           \
                                             EDMA_CR_GRP0PRI(0) |           \
                                             EDMA_CR_EMLM       |           \
                                             EDMA_CR_ERGA)
#define EDMA_GROUP0_PRIORITIES         0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15

/**
 * @brief   Type of an eDMA TCD.
 */
typedef struct {
  union {
    vuint32_t word[8];
  }; /* PRQA S 0660 */
} edma_tcd_t;
/**
 * @brief   Returns the TCD address associated to a channel.
 *
 * @param[in] channel   the channel number
 * @return              A pointer to an @p edma_tcd_t structure.
 *
 * @api
 */
#define edmaGetTCD(channel) ((edma_tcd_t *)&EDMA.TCD[channel])

/**
 * @brief   Sets the word 0 fields into a TCD.
 *
 * @param[in] tcdp      pointer to an @p edma_tcd_t structure
 * @param[in] src       the source address
 *
 * @api
 */
#define edmaTCDSetWord0(tcdp, src)                                          \
  ((tcdp)->word[0] = (uint32_t)(src))

/**
 * @brief   Sets the word 1 fields into a TCD.
 *
 * @param[in] tcdp      pointer to an @p edma_tcd_t structure
 * @param[in] ssize     the source width
 * @param[in] dsize     the destination width
 * @param[in] soff      the source increment value
 *
 * @api
 */
#define edmaTCDSetWord1(tcdp, ssize, dsize, soff)                           \
  ((tcdp)->word[1] = (((uint32_t)(ssize) << 24) |                           \
                      ((uint32_t)(dsize) << 16) |                           \
                      ((uint32_t)(soff) << 0)))

/**
 * @brief   Sets the word 2 fields into a TCD.
 *
 * @param[in] tcdp      pointer to an @p edma_tcd_t structure
 * @param[in] nbytes    the inner counter value
 *
 * @api
 */
#define edmaTCDSetWord2(tcdp, nbytes)                                       \
  ((tcdp)->word[2] = (uint32_t)(nbytes))

/**
 * @brief   Sets the word 3 fields into a TCD.
 *
 * @param[in] tcdp      pointer to an @p edma_tcd_t structure
 * @param[in] slast      the adjustment value
 *
 * @api
 */
#define edmaTCDSetWord3(tcdp, slast)                                        \
  ((tcdp)->word[3] = (int32_t)(slast))

/**
 * @brief   Sets the word 4 fields into a TCD.
 *
 * @param[in] tcdp      pointer to an @p edma_tcd_t structure
 * @param[in] dst       the destination address
 *
 * @api
 */
#define edmaTCDSetWord4(tcdp, dst)                                          \
  ((tcdp)->word[4] = (uint32_t)(dst))

/**
 * @brief   Sets the word 5 fields into a TCD.
 *
 * @param[in] tcdp      pointer to an @p edma_tcd_t structure
 * @param[in] citer     the current outer counter value
 * @param[in] doff      the destination increment value
 *
 * @api
 */
#define edmaTCDSetWord5(tcdp, citer, doff)                                  \
  ((tcdp)->word[5] = (((uint32_t)(citer) << 16) |                           \
                      ((uint32_t)(doff) << 0)))

/**
 * @brief   Sets the word 5 fields into a TCD.
 * @note    Transfers are limited to 512 operations using this modality
 *          (citer parameter).
 *
 * @param[in] tcdp      pointer to an @p edma_tcd_t structure
 * @param[in] linkch    channel linked on minor loop counter
 * @param[in] citer     the current outer counter value
 * @param[in] doff      the destination increment value
 *
 * @api
 */
#define edmaTCDSetWord5Linked(tcdp, linkch, citer, doff)                    \
  ((tcdp)->word[5] = (((uint32_t)0x80000000U) |                             \
                      ((uint32_t)(linkch) << 25) |                          \
                      ((uint32_t)(citer) << 16) |                           \
                      ((uint32_t)(doff) << 0)))

/**
 * @brief   Sets the word 6 fields into a TCD.
 *
 * @param[in] tcdp      pointer to an @p edma_tcd_t structure
 * @param[in] dlast     the adjustment value
 *
 * @api
 */
#define edmaTCDSetWord6(tcdp, dlast)                                        \
  ((tcdp)->word[6] = (int32_t)(dlast))

/**
 * @brief   Sets the word 7 fields into a TCD.
 *
 * @param[in] tcdp      pointer to an @p edma_tcd_t structure
 * @param[in] biter     the base outer counter value
 * @param[in] mode      the mode value
 *
 * @api
 */
#define edmaTCDSetWord7(tcdp, biter, mode)                                  \
  ((tcdp)->word[7] = (((uint32_t)(biter) << 16) |                           \
                      ((uint32_t)(mode) << 0)))

/**
 * @brief   Sets the word 7 fields into a TCD.
 * @note    Transfers are limited to 512 operations using this modality
 *          (biter parameter).
 *
 * @param[in] tcdp      pointer to an @p edma_tcd_t structure
 * @param[in] linkch    channel linked on minor loop counter
 * @param[in] biter     the base outer counter value
 * @param[in] mode      the mode value
 *
 * @api
 */
#define edmaTCDSetWord7Linked(tcdp, linkch, biter, mode)                    \
  ((tcdp)->word[7] = (((uint32_t)0x80000000U) |                             \
                      ((uint32_t)(linkch) << 25) |                          \
                      ((uint32_t)(biter) << 16) |                           \
                      ((uint32_t)(mode) << 0)))

/**
 * @brief   EDMA channel setup.
 *
 * @param[in] channel   eDMA channel number
 * @param[in] src       source address
 * @param[in] dst       destination address
 * @param[in] soff      source address offset
 * @param[in] doff      destination address offset
 * @param[in] ssize     source transfer size
 * @param[in] dsize     destination transfer size
 * @param[in] nbytes    minor loop count
 * @param[in] iter      major loop count
 * @param[in] dlast     last destination address adjustment
 * @param[in] slast     last source address adjustment
 * @param[in] mode      LSW of TCD register 7
 *
 * @api
 */
#define EdmaChannelSetup(channel, src, dst, soff, doff, ssize, dsize, nbytes, iter, slast, dlast, mode) {/* PRQA S 3472 */ \
  volatile edma_tcd_t *tcdp = edmaGetTCD(channel);                          \
  edmaTCDSetWord0(tcdp, src);                                               \
  edmaTCDSetWord1(tcdp, ssize, dsize, soff);                                \
  edmaTCDSetWord2(tcdp, nbytes);                                            \
  edmaTCDSetWord3(tcdp, slast);                                             \
  edmaTCDSetWord4(tcdp, dst);                                               \
  edmaTCDSetWord5(tcdp, iter, doff);                                        \
  edmaTCDSetWord6(tcdp, dlast);                                             \
  edmaTCDSetWord7(tcdp, iter, mode);                                        \
}

/**
 * @brief   EDMA channel setup with linked channel on both minor and major
 *          loop counters.
 * @note    Transfers are limited to 512 operations using this modality
 *          (iter parameter).
 *
 * @param[in] channel   eDMA channel number
 * @param[in] linkch    channel linked on minor loop counter
 * @param[in] src       source address
 * @param[in] dst       destination address
 * @param[in] soff      source address offset
 * @param[in] doff      destination address offset
 * @param[in] ssize     source transfer size
 * @param[in] dsize     destination transfer size
 * @param[in] nbytes    minor loop count
 * @param[in] iter      major loop count
 * @param[in] dlast     last destination address adjustment
 * @param[in] slast     last source address adjustment
 * @param[in] mode      LSW of TCD register 7
 *
 * @api
 */
#define EdmaChannelSetupLinked(channel, linkch, src, dst, soff, doff, ssize, dsize, nbytes, iter, slast, dlast, mode) {  /* PRQA S 3472 */ \
  edma_tcd_t *tcdp = edmaGetTCD(channel);                                   \
  edmaTCDSetWord0(tcdp, src);                                               \
  edmaTCDSetWord1(tcdp, ssize, dsize, soff);                                \
  edmaTCDSetWord2(tcdp, nbytes);                                            \
  edmaTCDSetWord3(tcdp, slast);                                             \
  edmaTCDSetWord4(tcdp, dst);                                               \
  edmaTCDSetWord5Linked(tcdp, linkch, iter, doff);                          \
  edmaTCDSetWord6(tcdp, dlast);                                             \
  edmaTCDSetWord7Linked(tcdp, linkch, iter, (mode) |                        \
                                            EDMA_TCD_MODE_MELINK |          \
                                            EDMA_TCD_MODE_MLINKCH(linkch)); \
}

/**
 * @brief   Enables the request signal related to the specified channel.
 *
 * @param[in] channel   the channel number
 *
 * @api
 */
#define edmaEnableRequest(channel) (EDMA.SERQR.R = (uint8_t)(channel))

/**
 * @brief   Disables the request signal related to the specified channel.
 *
 * @param[in] channel   the channel number
 *
 * @api
 */
#define edmaDisableRequest(channel) (EDMA.CERQR.R = (uint8_t)(channel))

/**
 * @brief   Clears Done bit related to the specified channel.
 *
 * @param[in] channel   the channel number
 *
 * @api
 */
#define edmaClearDone(channel) (EDMA.CDSBR.R = (uint8_t)(channel))
/**
 * @brief   Sets Start bit in TCD for a specified channel.
 *
 * @param[in] channel   the channel number
 *
 * @api
 */
#define EdmaSetStart(channel) (EDMA.SSBR.R = (uint8_t)(channel))

/**
 * @brief   Starts a specified channel.
 *
 * @param[in] channel   the channel number
 *
 * @api
 */
#define EdmaChannelStart(channel) edmaEnableRequest(channel) /* PRQA S 3472 */
/**
 * @brief   Stops a specified channel.
 *
 * @param[in] channel   the channel number
 *
 * @api
 */
#define EdmaChannelStop(channel) {edmaDisableRequest(channel); edmaClearDone(channel); }/* PRQA S 3472 */

#if defined(NULL)
#undef NULL /* PRQA S 4600, 0841*/
#endif
#if defined(__cplusplus)
#define NULL 0 /* PRQA S 4600 */
#else
#define NULL ((void *)0) /* PRQA S 4600 */
#endif

/*! @brief eDMA modulo configuration
 * Implements : edma_modulo_t_Class
 */
typedef enum {
    EDMA_MODULO_OFF = 0U,
    EDMA_MODULO_2B,
    EDMA_MODULO_4B,
    EDMA_MODULO_8B,
    EDMA_MODULO_16B,
    EDMA_MODULO_32B,
    EDMA_MODULO_64B,
    EDMA_MODULO_128B,
    EDMA_MODULO_256B,
    EDMA_MODULO_512B,
    EDMA_MODULO_1KB,
    EDMA_MODULO_2KB,
    EDMA_MODULO_4KB,
    EDMA_MODULO_8KB,
    EDMA_MODULO_16KB,
    EDMA_MODULO_32KB,
    EDMA_MODULO_64KB,
    EDMA_MODULO_128KB,
    EDMA_MODULO_256KB,
    EDMA_MODULO_512KB,
    EDMA_MODULO_1MB,
    EDMA_MODULO_2MB,
    EDMA_MODULO_4MB,
    EDMA_MODULO_8MB,
    EDMA_MODULO_16MB,
    EDMA_MODULO_32MB,
    EDMA_MODULO_64MB,
    EDMA_MODULO_128MB,
    EDMA_MODULO_256MB,
    EDMA_MODULO_512MB,
    EDMA_MODULO_1GB,
    EDMA_MODULO_2GB
} edma_modulo_t;

/*! @brief eDMA transfer configuration
 * Implements : edma_transfer_size_t_Class
 */
typedef enum {
    EDMA_TRANSFER_SIZE_1B  = 0x0U,
    EDMA_TRANSFER_SIZE_2B  = 0x1U,
    EDMA_TRANSFER_SIZE_4B  = 0x2U,
    EDMA_TRANSFER_SIZE_8B  = 0x3U,
    EDMA_TRANSFER_SIZE_32B = 0x4U,
    EDMA_TRANSFER_SIZE_64B = 0x5U
} edma_transfer_size_t;

/*!
 * @brief eDMA loop transfer configuration.
 *
 * This structure configures the basic minor/major loop attributes.
 * Implements : edma_loop_transfer_config_t_Class
 */
typedef struct { /* PRQA S 3630 */
    uint32_t majorLoopIterationCount;       /* Number of major loop iterations. */
    uint8_t srcOffsetEnable;                /* Selects whether the minor loop offset is applied to the
                                                 source address upon minor loop completion. */
    uint8_t dstOffsetEnable;                /* Selects whether the minor loop offset is applied to the
                                                 destination address upon minor loop completion. */
    int32_t minorLoopOffset;                /* Sign - extended offset applied to the source or destination address
                                                 to form the next - state value after the minor loop completes. */
    uint8_t minorLoopChnLinkEnable;         /* Enables channel - to - channel linking on minor loop complete. */
    uint8_t minorLoopChnLinkNumber;         /* The number of the next channel to be started by DMA
                                                 engine when minor loop completes. */
    uint8_t majorLoopChnLinkEnable;         /* Enables channel - to - channel linking on major loop complete. */
    uint8_t majorLoopChnLinkNumber;         /* The number of the next channel to be started by DMA
                                                 engine when major loop completes. */
} edma_loop_transfer_config_t;

/*!
 * @brief eDMA transfer size configuration.
 *
 * This structure configures the basic source/destination transfer attribute.
 * Implements : edma_transfer_config_t_Class
 */
typedef struct { /* PRQA S 3630 */
    uint32_t srcAddr;                                 /* Memory address pointing to the source data. */
    uint32_t destAddr;                                /* Memory address pointing to the destination data. */
    edma_transfer_size_t srcTransferSize;             /* Source data transfer size. */
    edma_transfer_size_t destTransferSize;            /* Destination data transfer size. */
    int16_t srcOffset;                                /* Sign - extended offset applied to the current source address
                                                           to form the next - state value as each source read/write
                                                           is completed. */
    int16_t destOffset;                               /* Sign - extended offset applied to the current destination
                                                           address to form the next - state value as each source
                                                           read/write is completed. */
    int32_t srcLastAddrAdjust;                        /* Last source address adjustment. */
    int32_t destLastAddrAdjust;                       /* Last destination address adjustment. Note here it is only
                                                           valid when scatter/gather feature is not enabled. */
    edma_modulo_t srcModulo;                          /* Source address modulo. */
    edma_modulo_t destModulo;                         /* Destination address modulo. */
    uint32_t minorByteTransferCount;                  /* Number of bytes to be transferred in each service request
                                                           of the channel. */
    uint8_t scatterGatherEnable;                      /* Enable scatter gather feature. */
    uint32_t scatterGatherNextDescAddr;               /* The address of the next descriptor to be used, when
                                                           scatter/gather feature is enabled.
                                                           Note: this value is not used when scatter/gather
                                                                 feature is disabled. */
    uint8_t interruptEnable;                          /* Enable the interrupt request when the major loop
                                                           count completes. */
    uint8_t hardwareRequestDisable;                   /* Disable hardware request. If this flag is set, the eDMA hardware
                                                           automatically clears the corresponding EDMA_ERQH or EDMA_ERQL bit
                                                           when the current major iteration count reaches zero. */

    edma_loop_transfer_config_t *loopTransferConfig;  /* Pointer to loop transfer configuration structure
                                                           (defines minor/major loop attributes)
                                                           Note: this field is only used when minor loop mapping is
                                                                 enabled from DMA configuration. */
} edma_transfer_config_t;

#ifdef __cplusplus
extern "C" {
#endif
extern void EdmaInit(void);
extern void EdmaChannelSetup_C(
        edma_channel_t n,  /* channel.                 */
        vuint32_t src,      /* src.                     */
        vuint32_t dst,      /* dst.                     */
        vuint16_t soff,     /* soff, do not advance.    */
        vuint16_t doff,     /* doff, do not advance.    */
        uint8_t ssize,      /* ssize, 8 bits transfers. */
        uint8_t dsize,      /* dsize, 8 bits transfers. */
        uint32_t nbytes,    /* nbytes, always one.      */
        uint16_t iter,      /* iter.                    */
        int32_t slast,     /* slast.                   */
        int32_t dlast,     /* dlast.                   */
        uint16_t mode);
extern void DMAMUX_ChConfigEn(uint8_t ChNum, uint8_t ChSource);

/* ADD LLD DRIVER APIs */
extern void EDMA_LLD_ConfigLoopTransfer(uint8_t channel, const edma_transfer_config_t *transferConfig);
extern void EDMA_LLD_StartChannel(uint8_t channel);
extern void EDMA_LLD_WaitDone(uint8_t channel);

#ifdef __cplusplus
}
#endif

#endif/* EDMA_H_ */
