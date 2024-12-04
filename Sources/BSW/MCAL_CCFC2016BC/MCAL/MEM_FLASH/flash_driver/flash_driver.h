/******************************************************************************
*  Copyright (c) ECO-EV Technologies Co., Ltd. 2015-2016.
*  All rights reserved.

*  File name:     flash_driver.h
*  Author:        ECO-EV
*  Version:    V1.0.1
*  Date:       2017-6-23
*  Description:
*  Others:
*  History:
*
*  1. Date:
*     Author:
*     Modification:
*  2. ...
******************************************************************************/
#ifndef _FLASH_DRIVER_H_
#define _FLASH_DRIVER_H_

#include "bsw_typedefs.h"


/*************************************************************************/
/*                   SSD Configuration Structure                         */
/*************************************************************************/

/* Block information for an address space */
typedef struct _c55_block_info
{
    uint32 n16KBlockNum;         /* Number of 16K blocks */
    uint32 n32KBlockNum;         /* Number of 32K blocks */
    uint32 n64KBlockNum;         /* Number of 64K blocks */
} BLOCK_INFO, *PBLOCK_INFO;

/* SSD Configuration Structure */
typedef struct _c55_ssd_config
{
    uint32 c55RegBase;           /* C55 control register base */
    uint32 mainArrayBase;        /* base of main array */
    BLOCK_INFO lowBlockInfo;     /* blocks info of low address space */
    BLOCK_INFO midBlockInfo;     /* blocks info of mid address space */
    BLOCK_INFO highBlockInfo;    /* blocks info of high address space */
    uint32 n256KBlockNum;        /* number of blocks in 256K address space */
    uint32 uTestArrayBase;       /* base of UTEST array */
    boolean mainInterfaceFlag;      /* interface flag indicate main or alternate interface */
    uint32 programmableSize;     /* programmable size */
    boolean BDMEnable;              /* debug mode selection */
} SSD_CONFIG, *PSSD_CONFIG;

/* MISR structure */
typedef struct _c55_misr
{
    uint32 W0;
    uint32 W1;
    uint32 W2;
    uint32 W3;
    uint32 W4;
    uint32 W5;
    uint32 W6;
    uint32 W7;
    uint32 W8;
    uint32 W9;
} MISR, *PMISR;

/* Structure data for the context values */
typedef struct _c55_context_data
{
    uint32 dest;
    uint32 size;
    uint32 source;
    uint32 *pFailedAddress;
    uint32 *pFailedData;
    uint32 *pFailedSource;
    uint32 *pSum;
    PMISR pMisr;
    void* pReqCompletionFn;
    uint32 operationOpt;
} CONTEXT_DATA, *PCONTEXT_DATA;

/* Block select structure for 256K address space */
typedef struct _c55_n256k_block_sel
{
    uint32 first256KBlockSelect;
    uint32 second256KBlockSelect;
} N256K_BLOCK_SEL, *PN256K_BLOCK_SEL;

/* Start address of memory regions */
typedef struct _c55_mem_region
{
    uint32 n16KLowEvenPartBase;
    uint32 n16KLowOddPartBase;
    uint32 n32KLowEvenPartBase;
    uint32 n32KLowOddPartBase;
    uint32 n64KLowEvenPartBase;
    uint32 n64KLowOddPartBase;
    uint32 n16KMidEvenPartBase;
    uint32 n16KMidOddPartBase;
    uint32 n32KMidEvenPartBase;
    uint32 n32KMidOddPartBase;
    uint32 n64KMidEvenPartBase;
    uint32 n64KMidOddPartBase;
    uint32 n16KHighEvenPartBase;
    uint32 n16KHighOddPartBase;
    uint32 n32KHighEvenPartBase;
    uint32 n32KHighOddPartBase;
    uint32 n64KHighEvenPartBase;
    uint32 n64KHighOddPartBase;
    uint32 n256KBase;
} MEM_REGION_INFO, *PMEM_REGION_INFO;

/* Struct of ADR register */
typedef union
{
    uint32 R;
    struct
    {
        uint32 SAD         :1U;                /* bit 31 is Utest NVM address*/
        uint32 aMEM        :1U;                /* bit 30 is memory space */
        uint32 aH          :1U;                /* bit 29 is High address space */
        uint32 aM          :1U;                /* bit 28 is Mid address space */
        uint32 aL          :1U;                /* bit 27 is Low address space */
        uint32 a256K       :1U;                /* bit 26 is 256K address space */
        uint32 a64K        :1U;                /* bit 25 is 64K address space */
        uint32 a32K        :1U;                /* bit 24 is 32K address space */
        uint32 a16K        :1U;                /* bit 23 is 16K address space */
        uint32 ADDR        :20U;               /* bit 3 -> 22 are internal address */
        uint32 reserved    :3U;                /* bit 0, 1, 2 are reserved */
    } B;
}INTERNAL_FLASH_ADDR;

/***************************************************************************************/
/*                   eraseOption for FlashErase                                    */
/***************************************************************************************/

/*      flash dependent configuration   */
#define C55_REG_BASE                    0xFFFE0000
#define MAIN_ARRAY_BASE                 0x00800000
#define UTEST_ARRAY_BASE                0x00400000
#define UTEST_ARRAY_SIZE                0x00004000

#define C55_PROGRAMMABLE_SIZE           0x80

/* Checking mode used in FlashCheckStatus */
#define C55_MODE_OP_PROGRAM                  0x00U
#define C55_MODE_OP_ERASE                    0x01U
#define C55_MODE_OP_PROGRAM_VERIFY           0x02U
#define C55_MODE_OP_BLANK_CHECK              0x03U
#define C55_MODE_OP_CHECK_SUM                0x04U
#define C55_MODE_OP_USER_TEST_CHECK          0x05U
#define C55_MODE_OP_EXPRESS_PROGRAM          0x06U

/* below macros are not used in FlashErase anymore. However, still keep them here because user may already use it*/
#define C55_ERASE_MAIN              0x00U   /* Perform normal erase on main array */
#define C55_ERASE_MAIN_FERS         0x01U   /* Perform factory erase on main array */
#define C55_ERASE_UTEST             0x02U   /* Perform erase on UTest array */
#define C55_ERASE_UTEST_FERS        0x03U   /* Perform factory erase on UTest array */


/***************************************************************************************/
/*                   Return Codes for SSD functions                                    */
/***************************************************************************************/

#define C55_OK                      0x00000000U
#define C55_ERROR_ALIGNMENT         0x00000001U   /* Alignment error */
#define C55_ERROR_ENABLE            0x00000002U   /* it's impossible to enable an operation */
#define C55_ERROR_BUSY              0x00000004U   /* New program/erase cannot be preformed while previous high voltage operation in progress */
#define C55_ERROR_PGOOD             0x00000008U   /* The program operation is unsuccessful */
#define C55_ERROR_EGOOD             0x00000010U   /* The erase operation is unsuccessful */
#define C55_ERROR_NOT_BLANK         0x00000020U   /* There is non-blank location in the checked flash memory */
#define C55_ERROR_VERIFY            0x00000040U   /* There is a mismatch between the source data and content in the checked flash memory */
#define C55_ERROR_BLOCK_INDICATOR   0x00000080U   /* Invalid block indicator */
#define C55_ERROR_ALTERNATE         0x00000100U   /* The operation is unsupported via alternate interface */
#define C55_ERROR_FACTORY_OP        0x00000200U   /* Factory erase/program cannot be performed */
#define C55_ERROR_MISMATCH          0x00000400U   /* The MISR generated by the AIC hardware doesnot match the MISR passed by the user */
#define C55_ERROR_NO_BLOCK          0x00000800U   /* No blocks have been enabled for Array Integrity check */
#define C55_ERROR_ADDR_SEQ          0x00001000U   /* Invalid address sequence */
#define C55_ERROR_MARGIN_LEVEL      0x00002000U   /* Invalid margin level */
#define C55_ERROR_ERASE_OPTION      0x00004000U   /* Invalid erase option */
#define C55_ERROR_MODE_OP           0x00008000U   /* Invalid mode op */
#define C55_ERROR_SET_LOCK          0x00040000U   /* Invalid set lock value */
#define C55_ERROR_RESUME            0x00080000U   /* This master can't resume the P/E operation */
#define C55_ERROR_SUSPEND           0x00100000U   /* This master can't suspend the P/E operation */

#define C55_ERROR_ABORT_RESERVATION 0x00200000U
#define C55_ERROR_ECC_NO_DWORD_SEL  0x00400000U     /* there is no double word selected for ECC checking */
#define C55_ERROR_ECC_NOTCHECK      0x00800000U   /* don't check ECC logic for this case */
#define C55_ERROR_ECC_LOGIC         0x01000000U
#define C55_ERROR_ADDR_NOT_INVERTED 0x02000000U
#define C55_ERROR_ADDR_ENCODE       0x04000000U


#define C55_ERROR_PEP              0x08000000U
#define C55_ERROR_PES              0x10000000U

#define C55_DONE                    0x00010000U   /* Done status */
#define C55_INPROGRESS              0x00020000U   /* InProgress status */


/******************************************************************************/
/*                        Exported Function Declarations                      */
/******************************************************************************/
/******************************************************************************
SSD Function Pointer Types
******************************************************************************/
typedef uint32 (*PFLASHINIT) ( PSSD_CONFIG pSSDConfig );

typedef uint32 (*PFLASHERASE) ( PSSD_CONFIG pSSDConfig,
                    uint8 eraseOption,
                    uint32 lowBlockSelect,
                    uint32 midBlockSelect,
                    uint32 highBlockSelect,
                    N256K_BLOCK_SEL n256KBlockSelect
                    );

typedef uint32 (*PFLASHERASEALTERNATE) ( PSSD_CONFIG pSSDConfig,
                    uint32 interlockAddress
                    );

typedef uint32 (*PBLANKCHECK) ( PSSD_CONFIG pSSDConfig,
                    uint32 dest,
                    uint32 size,
                    uint32 *pFailedAddress,
                    uint32 *pFailedData,
                    PCONTEXT_DATA pCtxData
                    );

typedef uint32 (*PFLASHPROGRAM) ( PSSD_CONFIG pSSDConfig,
                    boolean factoryPgmFlag,
                    uint32 dest,
                    uint32 size,
                    uint32 source,
                    PCONTEXT_DATA pCtxData
                    );

typedef uint32 (*PPROGRAMVERIFY) ( PSSD_CONFIG pSSDConfig,
                    uint32 dest,
                    uint32 size,
                    uint32 source,
                    uint32 *pFailedAddress,
                    uint32 *pFailedData,
                    uint32 *pFailedSource,
                    PCONTEXT_DATA pCtxData
                    );

typedef uint32 (*PFLASHCHECKSTATUS) ( PSSD_CONFIG pSSDConfig,
                    uint8 modeOp,
                    uint32 *opResult,
                    PCONTEXT_DATA pCtxData
                    );

typedef uint32 (*PGETLOCK) ( PSSD_CONFIG pSSDConfig,
                    uint8 blkLockIndicator,
                    uint32 *blkLockState
                    );

typedef uint32 (*PSETLOCK) ( PSSD_CONFIG pSSDConfig,
                    uint8 blkLockIndicator,
                    uint32 blkLockState
                    );

typedef uint32 (*POVERPGMPROTGETSTATUS) ( PSSD_CONFIG pSSDConfig,
                    uint8 blkProtIndicator,
                    uint32* blkProtState
                    );

typedef uint32 (*PCHECKSUM) ( PSSD_CONFIG pSSDConfig,
                    uint32 dest,
                    uint32 size,
                    uint32 *pSum,
                    PCONTEXT_DATA pCtxData
                    );

typedef uint32 (*PFLASHSUSPEND) ( PSSD_CONFIG pSSDConfig,
                    uint8 *suspendState
                    );

typedef uint32 (*PFLASHRESUME) ( PSSD_CONFIG pSSDConfig,
                    uint8 *resumeState
                    );

typedef uint32 (*PFLASHABORT) ( PSSD_CONFIG pSSDConfig, uint8 abortOption );

typedef uint32 (*PFLASHARRAYINTEGRITYCHECK) ( PSSD_CONFIG pSSDConfig,
                    uint32 lowEnabledBlocks,
                    uint32 midEnabledBlocks,
                    uint32 highEnabledBlocks,
                    N256K_BLOCK_SEL n256KEnabledBlocks,
                    uint8 breakOption,
                    uint8 addrSeq,
                    PMISR pMisrValue,
                    PCONTEXT_DATA pCtxData
                    );

typedef uint32 (*PFLASHARRAYINTEGRITYSUSPEND) ( PSSD_CONFIG pSSDConfig,
                    uint8 *suspendState
                    );

typedef uint32 (*PFLASHARRAYINTEGRITYRESUME) ( PSSD_CONFIG pSSDConfig,
                    uint8 *resumeState
                    );

typedef uint32 (*PUSERMARGINREADCHECK) ( PSSD_CONFIG pSSDConfig,
                    uint32 lowEnabledBlocks,
                    uint32 midEnabledBlocks,
                    uint32 highEnabledBlocks,
                    N256K_BLOCK_SEL n256KEnabledBlocks,
                    uint8 breakOption,
                    uint8 marginLevel,
                    PMISR pMisrValue,
                    PCONTEXT_DATA pCtxData
                    );
typedef uint32 (*PFLASHECCLOGICCHECK) ( PSSD_CONFIG pSSDConfig,
                            PMEM_REGION_INFO pMemRegionInfo,
                            uint32* dataVal,
                            uint32* errBits,
                            uint8 eccValue,
                            uint8 errECCBits,
                            uint8 dWordSel);
typedef uint32 (*PFLASHEDCAFTERECCLOGICCHECK) ( PSSD_CONFIG pSSDConfig,
                                    PMEM_REGION_INFO pMemRegionInfo,
                                    uint32*    dataValue,
                                    uint32*    errBits,
                                    uint8    eccValue,
                                    uint8    errECCBits,
                                    uint8 dWordSel);
typedef uint32 (*PFLASHEXPRESSPROGRAM) ( PSSD_CONFIG pSSDConfig,
                    PMEM_REGION_INFO pMemRegionInfo,
                    uint32 dest,
                    uint32 size,
                    uint32 source,
                    PCONTEXT_DATA pCtxData);

typedef uint32 (*PFLASHADDRESSENCODELOGICCHECK) ( PSSD_CONFIG pSSDConfig,
        PMEM_REGION_INFO pMemRegionInfo,
        uint32*   invertBits   );

/******************************************************************************
Public Functions Definitions
******************************************************************************/
extern unsigned long FlashInit_C[];
extern unsigned long FlashErase_C[];
extern unsigned long FlashEraseAlternate_C[];
extern unsigned long BlankCheck_C[];
extern unsigned long FlashProgram_C[];
extern unsigned long ProgramVerify_C[];
extern unsigned long FlashCheckStatus_C[];
extern unsigned long GetLock_C[];
extern unsigned long SetLock_C[];
extern unsigned long OverPgmProtGetStatus_C[];
extern unsigned long CheckSum_C[];
extern unsigned long FlashSuspend_C[];
extern unsigned long FlashResume_C[];
extern unsigned long FlashAbort_C[];
extern unsigned long FlashArrayIntegrityCheck_C[];
extern unsigned long FlashArrayIntegritySuspend_C[];
extern unsigned long FlashArrayIntegrityResume_C[];
extern unsigned long UserMarginReadCheck_C[];
extern unsigned long FlashECCLogicCheck_C[];
extern unsigned long FlashEDCAfterECCLogicCheck_C[];
extern unsigned long FlashExpressProgram_C[];
extern unsigned long FlashAddressEncodeLogicCheck_C[];

/******************************************************************************
Public Functions Definitions
******************************************************************************/

#define FlashInit                      ((PFLASHINIT)FlashInit_C)
#define FlashErase                     ((PFLASHERASE)FlashErase_C)
#define FlashEraseAlternate            ((PFLASHERASEALTERNATE)FlashEraseAlternate_C)
#define BlankCheck                     ((PBLANKCHECK)BlankCheck_C)
#define FlashProgram                   ((PFLASHPROGRAM)FlashProgram_C)
#define ProgramVerify                  ((PPROGRAMVERIFY)ProgramVerify_C)
#define FlashCheckStatus               ((PFLASHCHECKSTATUS)FlashCheckStatus_C)
#define GetLock                        ((PGETLOCK)GetLock_C)
#define SetLock                        ((PSETLOCK)SetLock_C)
#define OverPgmProtGetStatus           ((POVERPGMPROTGETSTATUS)OverPgmProtGetStatus_C)
#define CheckSum                       ((PCHECKSUM)CheckSum_C)
#define FlashSuspend                   ((PFLASHSUSPEND)FlashSuspend_C)
#define FlashResume                    ((PFLASHRESUME)FlashResume_C)
#define FlashAbort                     ((PFLASHABORT)FlashAbort_C)
#define FlashArrayIntegrityCheck       ((PFLASHARRAYINTEGRITYCHECK)FlashArrayIntegrityCheck_C);
#define FlashArrayIntegritySuspend     ((PFLASHARRAYINTEGRITYSUSPEND)FlashArrayIntegritySuspend_C);
#define FlashArrayIntegrityResume      ((PFLASHARRAYINTEGRITYRESUME)FlashArrayIntegrityResume_C);
#define UserMarginReadCheck            ((PUSERMARGINREADCHECK)UserMarginReadCheck_C);
#define FlashECCLogicCheck             ((PFLASHECCLOGICCHECK)FlashECCLogicCheck_C);
#define FlashEDCAfterECCLogicCheck     ((PFLASHEDCAFTERECCLOGICCHECK)FlashEDCAfterECCLogicCheck_C);
#define FlashExpressProgram            ((PFLASHEXPRESSPROGRAM)FlashExpressProgram_C);
#define FlashAddressEncodeLogicCheck   ((PFLASHADDRESSENCODELOGICCHECK)FlashAddressEncodeLogicCheck_C);




#endif
