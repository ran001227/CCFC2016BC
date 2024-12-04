/****************************************************************************
 *
 * Copyright (c) 2023  C*Core -   All Rights Reserved
 *
 * THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
 * INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 * PROJECT     : CCFC2016BC
 * DESCRIPTION : CCFC2016BC decimator filter low level drivers code
 * HISTORY     : Initial version.
 * @file     decfilter_lld.h
 * @version  1.1
 * @date     2023 - 02 - 15
 * @brief    Initial version.
 *
 *****************************************************************************/
#ifndef DECFILTER_LLD_H_
#define DECFILTER_LLD_H_

#include "CCFC2016BC.h"
#include "lldconf.h"
#include "edma_lld.h"

/*!
 * @brief Operation Mode selection
 *
 * This define all decfilter functional mode
 *
 * Implements : decfilter_mode_t_Class
 */
typedef enum
{
    DECFILTER_MODE_STANDALONE           = 0x00U, /*!< DEFAULT: data is provided by the central processor using
                                                      the device slave-bus interface or DMA interface signals */
    DECFILTER_MODE_LOW_POWER            = 0x01U  /*!< Low power mode corresponds to the module disable mode or stop mode */
} decfilter_mode_t;

/*!
 * @brief filter type selection
 *
 * Select the filter type.
 * Bypass must not be configured in cascade mode (see field CASCD).
 *
 * Implements : decfilter_filter_type_t_Class
 */
typedef enum
{
    DECFILTER_FILTER_TYPE_BYPASS    = 0x00U, /*!< Filter Bypass  */
    DECFILTER_FILTER_TYPE_IIR       = 0x01U, /*!< IIR Filter - 1 x 4th order  */
    DECFILTER_FILTER_TYPE_FIR       = 0x02U  /*!< FIR Filter - 1 x 8th order  */
} decfilter_filter_type_t;

/*!
 * @brief filter scaling factor
 *
 * Selects the scaling factor used by the filter algorithm
 *
 * Implements : decfilter_scaling_factor_t_Class
 */
typedef enum
{
    DECFILTER_SCALING_FACTOR_1      = 0x00U, /*!< Scaling Factor = 1  */
    DECFILTER_SCALING_FACTOR_4      = 0x01U, /*!< Scaling Factor = 4  */
    DECFILTER_SCALING_FACTOR_8      = 0x02U, /*!< Scaling Factor = 8  */
    DECFILTER_SCALING_FACTOR_16     = 0x03U  /*!< Scaling Factor = 16  */
} decfilter_scaling_factor_t;

/*!
 * @brief filter io select
 *
 * Selects the source of the input data to the Decimation Filter,
 * and the destination for the filter output result.
 *
 * Implements : decfilter_io_select_t_Class
 */
typedef enum
{
    DECFILTER_IO_SEL_CFIFO_TO_RFIFO     = 0x00U,
    DECFILTER_IO_SEL_CFIFO_TO_OBUFF     = 0x01U,
    DECFILTER_IO_SEL_IBUFF_TO_OBUFF     = 0x02U,
    DECFILTER_IO_SEL_IBUFF_TO_RFIFO     = 0x03U
} decfilter_io_select_t;

/*!
 * @brief filter interrupt source
 *
 * Implements : decfilter_interrupt_source_t
 */
typedef enum
{
    DECFILTER_INPUT_DATA_INTERRUPT      = 0x00U,
    DECFILTER_OUTPUT_DATA_INTERRUPT     = 0x01U,
    DECFILTER_ERROR_INTERRUPT           = 0x02U,
    DECFILTER_INTEGRATOR_DATA_INTERRUPT = 0x03U,
    DECFILTER_INPUT_BUFFER_INTERRUPT    = 0x04U,
    DECFILTER_OUTPUT_BUFFER_INTERRUPT   = 0x05U
} decfilter_interrupt_source_t;

/*!
 * @brief Structure for config/set DMA parameters for moving data into input buffer.
 *
 * Implements : decfilter_dma_input_config_t_Class
 */
typedef struct                  /* PRQA S 3630 */
{
    uint8_t dmaChan;            /*!< DMA channel to be used */
    int16_t *sourcePtr;         /*!< Pointer to the memory address from where the commands will
                                     be copied by the DMA, if DMA transfer is enabled */
    uint32_t sourceLength;      /*!< Length (number of int16_t) of the source buffer pointed by sourcePtr */
} decfilter_dma_input_config_t;

/*!
 * @brief Structure for config/set DMA parameters for moving output data from a result buffer into system memory.
 *
 * Implements : decfilter_dma_output_config_t_Class
 */
typedef struct                   /* PRQA S 3630 */
{
    uint8_t dmaChan;             /*!< DMA channel to be used */
    int16_t *destPtr;            /*!< Pointer to the memory address where the decfilter output will be copied
                                      by the DMA, if DMA transfer is enabled */
    uint32_t destLength;         /*!< Length (num of int16_t) of the destination buffer pointed by destPtr */
} decfilter_dma_output_config_t;

/*!
 * @brief DECFILT configuration structure.
 * Implements : DECFILT_Config_t_Class
 */
typedef struct
{
    decfilter_mode_t mode;                       /*!< configuration register provides configuration control bits
                                                      for the Decimation Filter internal logic */
    decfilter_filter_type_t filterType;          /*!< select the filter type */
    decfilter_scaling_factor_t scalFactor;       /*!< field selects the scaling factor used by the filter algorithm */
    decfilter_io_select_t ioSelect;              /*!< input data source and output result destination selection*/

    uint8_t inputDataInterruptEnable;            /*!< enables the Decimation Filter to generate interrupt requests on all new input data
                                                      written to the Interface Input Buffer register or Input/Output Buffers register */
    uint8_t outputDataInterruptEnable;           /*!< enables the Decimation Filter to generate interrupt requests on all new data
                                                      written to the filter Output buffer. It is independent of how ISEL is set. */
    uint8_t errorInterruptEnable;                /*!< enables the Decimation Filter to generate interrupt requests based on the
                                                      assertion of the DECFILTER_MSR register error flags OVF, DIVR, SVR, OVR, or IVR */
    uint8_t integratorDataInterruptEnable;       /*!< enables output buffer interrupts due to integrator data result being ready */
    uint8_t inputBufferInterruptRequestEnable;   /*!< enables the Decimation Filter to generate interrupt requests */
    uint8_t outputBufferInterruptRequestEnable;  /*!< enables the Decimation Filter interrupt requests when outputs are directed
                                                      to the device slave-bus and DMA is not selected(DSEL = 0). */

    decfilter_dma_input_config_t *dmaConfigInputBuffer;   /*!< dma config for Decimation Filter X Input Buffer (fill) */
    decfilter_dma_output_config_t *dmaConfigOutputBuffer; /*!< dma config for Decimation Filter X Output
                                                               Buffer or Integrator(drain/integrator) */

    uint8_t saturationEnable;                    /*!< enables the saturation of the filter output */
    uint8_t decimationRateSelection;             /*!< The decimation rate defines the number of data samples from the master block that is
                                                      required to generate one decimated result in the Decimation Filter output. */

    uint32_t coefficients[DECFILTER_COEF_COUNT]; /*!< fields are the digital filter coefficients registers. The coefficients are
                                                      fractional signed values in 2s complement format, in the range */
} DECFILTER_Config_t;

/**
  * @brief  DECFITL Driver Structure definition
  */
typedef struct
{
    struct DECFIL_tag *instance;  /*!< DECFILT registers base address */
} DECFILTER_Driver;

/**
 * Exported Functions
 */
extern uint8_t DECFILTER_LLD_Init(DECFILTER_Driver *decfilter, const DECFILTER_Config_t *config);
extern uint8_t DECFILTER_LLD_WriteInputData(const DECFILTER_Driver *decfilter, const uint32_t data);
extern uint16_t DECFILTER_LLD_ReadOutputData(const DECFILTER_Driver *decfilter);
extern void DECFILTER_LLD_StartTransfer_DMA(const DECFILTER_Config_t *config);
extern void DECFILTER_LLD_WaitDone_DMA(const DECFILTER_Config_t *config);
extern void DECFILTER_LLD_EnableInterrupts(const DECFILTER_Driver *decfilter, decfilter_interrupt_source_t source);
extern void DECFILTER_LLD_DisableInterrupts(const DECFILTER_Driver *decfilter, decfilter_interrupt_source_t source);
extern uint32_t DECFILTER_LLD_GetFilterTap(const DECFILTER_Driver *decfilter, const uint8_t index);
extern uint32_t DECFILTER_LLD_GetFinalValue(const DECFILTER_Driver *decfilter);

#endif /* DECFILT_LLD_H_ */

