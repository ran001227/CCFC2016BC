/****************************************************************************
 *
 * Copyright (c) 2023  C*Core -   All Rights Reserved
 *
 * THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
 * INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 * PROJECT     : CCFC2016BC
 * DESCRIPTION : console driver interface
 * HISTORY     : Initial version.
 * @file     she_lld.h
 * @version  1.1
 * @date     2023 - 02 - 15
 * @brief    Initial version.
 *
 *****************************************************************************/
#ifndef SHE_LLD_H_
#define SHE_LLD_H_

#include "CCFC2016BC.h"
#include "lldconf.h"

#if defined(__cplusplus)
extern "C" {
#endif

#pragma section RX ".user_defined_section" code_mode=far_abs

#define SHE_MODULE_DEFAULT_TIMEOUT 0xFFFFFFFFU

/************************************************************************
 *    SSCM_SHE_INTERRUPT Register
 *    Configuration parameter
 ************************************************************************/
#define INTERRUPT_SIGNAL_DISABLE    0x0U /* PRQA S 1534 */
#define INTERRUPT_SIGNAL_ENABLE     0x3U
#define FUNCTON_DONE                0x0U

/************************************************************************
 *    SSCM_SHE_CAL_FLAG Register
 *    Configuration parameter
 ************************************************************************/
#define SHE_INTERRUPT_DO_NOTHING    0x00000000U /* PRQA S 1534 */
#define SHE_INTERRUPT_START_RUNNING 0xFFFFFFFFU

/************************************************************************
 *    SSCM_SHE_CAL_CSR Register
 *    Configuration parameter
 ************************************************************************/
/* ERROR CODE */
#define ERC_NO_ERROR                0x00U    /* NO Error */
#define ERC_SEQUENCE_ERROR          0x01U    /* Sequence error */
#define ERC_KEY_NOT_AVAILABLE       0x02U    /* When securt fail, key can not be used */
#define ERC_KEY_INVALID             0x03U    /* Key that is not allowed for the given operation */
#define ERC_KEY_EMPTY               0x04U    /* Key has not been initialized */
#define ERC_NO_SECURE_BOOT          0x05U    /* Secure fail */
#define ERC_KEY_WRITE_PROTECTION    0x06U    /* key is write - protected */
#define ERC_KEY_UPDATE_ERROR        0x07U    /* Fail to update key */
#define ERC_RNG_SEED                0x08U    /* Prng seed has bot been initialized */
#define ERC_NO_DEBUGGING            0x09U    /* Fail to verify debug authentication */
#define ERC_BUSY                    0x0aU    /* Busy */
#define ERC_MEMORY_FAILURE          0x0bU    /* Read memory occur error */
#define ERC_GENERAL_ERROR           0x0cU    /* Other error */

/* CAL_PARAM */
#define CMD_FUNC_FIRST              0x01U    /* first block msg */
#define CMD_FUNC_LAST               0x02U    /* last block msg */
#define AES_CMAC_MSG_PADDING        0x04U    /* cmac msg is padding with 0x80,0x00 ... */
#define AES_CMAC_MSG_NO_PADDING     0x00U    /* cmac msg is not padding */
#define AES_BIG_ENDIAN              0x08U    /* all aes params and msg is big endian */

#define TRNG_SRC0_SEED              0x00U    /* trng src0 */
#define TRNG_SRC1_SEED              0x01U    /* trng src1 */
#define TRNG_SRC2_SEED              0x02U    /* trng src2 */

#define DEBUG_SECOND_STEP           0x0U    /* Debug second step */ /* PRQA S 1534 */
#define DEBUG_FIRST_STEP            0x1U    /* Debug first step */ /* PRQA S 1534 */
#define DEBUG_DELETE_ALL_KEYS       0x2U    /* If do Debug second step, then will delete all keys */ /* PRQA S 1534 */

/* Function ID */
#define CMD_ENC_ECB                 0x00U    /* AES ECB Encrypt */
#define CMD_ENC_CBC                 0x01U    /* AES CBC Encrypt */
#define CMD_DEC_ECB                 0x02U    /* AES ECB Decrypt */
#define CMD_DEC_CBC                 0x03U    /* AES CBC Decrypt */
#define CMD_GENERATE_MAC            0x04U    /* AES CMAC */
#define CMD_VERIFY_MAC              0x05U    /* AES CMAC */
#define CMD_LOAD_KEY                0x06U    /* Memory update protocol */ /* PRQA S 1534 */
#define CMD_LOAD_PLAIN_KEY          0x07U    /* Load key to RAM_KEY as plain */
#define CMD_EXPORT_RAM_KEY          0x08U    /* Export key from ram_key */
#define CMD_INIT_RNG                0x09U    /* Prng initial */ /* PRQA S 1534 */
#define CMD_EXTEND_SEED             0x0aU    /* Prng seed exrend */ /* PRQA S 1534 */
#define CMD_RNG                     0x0bU    /* Get 16 byte prng */
#define CMD_SECURT_BOOT             0x0cU    /* Secrue boot */ /* PRQA S 1534 */
#define CMD_BOOT_FAILEURE           0x0dU    /* Secure boot fail */ /* PRQA S 1534 */
#define CMD_BOOT_OK                 0x0eU    /* Secure boot success */ /* PRQA S 1534 */
#define CMD_GET_STATUS              0x0fU    /* Get she statys */ /* PRQA S 1534 */
#define CMD_GET_ID                  0x10U    /* Get she unique id */ /* PRQA S 1534 */
#define CMD_CANCEL                  0x11U    /* NA */ /* PRQA S 1534 */
#define CMD_DEBUG                   0x12U    /* Entry debug mode */
#define CMD_RSA_ENC                 0x13U    /* RSA encrypt or sign */
#define CMD_RSA_DEC                 0x14U    /* RSA decrypt or verify */
#define CMD_COMPRESS                0x15U    /* MP compress function */
#define CMD_LOAD_RSA_KEY            0x16U    /* Load rsa key to NVM */
#define CMD_EXPORT_RSA_RAM_KEY      0x17U    /* Export rsa key from RAM_KEY */ /* PRQA S 1534 */

/**
  * @brief  When cal CMD_INIT_RNG, TRNG SRC is select:
  */
#define TRNG_SRC0                   0U
#define TRNG_SRC1                   1U
#define TRNG_SRC2                   2U

/************************************************************************
 *    SSCM_SHE_STATUS Register
 *    STATUS Define
 ************************************************************************/
#define SHE_ST_BUSY                0x01U    /* PRQA S 1534 */
#define SHE_ST_SECURE_BOOT         0x02U    /* PRQA S 1534 */
#define SHE_ST_BOOT_INIT           0x04U    /* PRQA S 1534 */
#define SHE_ST_BOOT_FINISHED       0x08U    /* PRQA S 1534 */
#define SHE_ST_BOOT_OK             0x10U    /* PRQA S 1534 */
#define SHE_ST_RNG_INIT            0x20U    /* PRQA S 1534 */
#define SHE_ST_EXT_DEBUGGER        0x40U    /* PRQA S 1534 */
#define SHE_ST_INT_DEBUGGER        0x80U    /* PRQA S 1534 */

#define WRITE_PROTECTION_ENABLE    0x01U    /* PRQA S 1534 */
#define DISABLE_KEY_BOOT_FAIL      0x02U    /* PRQA S 1534 */
#define DISABLE_KEY_DEBUGGER       0x04U    /* PRQA S 1534 */
#define KEY_WILDCARD_ENABLE        0x08U    /* PRQA S 1534 */
#define KEY_USAGE                  0x10U    /* PRQA S 1534 */
#define KEY_NOT_INITTED            0xFFFFFFFFU    /* PRQA S 1534 */

/* Represents the size of a uid in bytes */
#define SHE_UID_SIZE_IN_WORDS      (4U)    /* PRQA S 1534 */
/* Represents the size of a SHE_PRAM page in bytes */
#define SHE_PARAM_SIZE_IN_BYTES    (16U)
/* Represents the size in bytes of the M1 entry (used for key management) */
#define SHE_M1_SIZE_IN_BYTES       (16U)
/* Represents the size in bytes of the M2 entry (used for key management) */
#define SHE_M2_SIZE_IN_BYTES       (32U)
/* Represents the size in bytes of the M3 entry (used for key management) */
#define SHE_M3_SIZE_IN_BYTES       (16U)
/* Represents the size in bytes of the M4 entry (used for key management) */
#define SHE_M4_SIZE_IN_BYTES       (32U)
/* Represents the size in bytes of the M5 entry (used for key management) */
#define SHE_M5_SIZE_IN_BYTES       (16U)

#define SHA_M1M2_SIZE_IN_BYTES        (48U)    /* PRQA S 1534 */
#define SHA_M1M2M3_SIZE_IN_BYTES      (64U)    /* PRQA S 1534 */
#define SHA_M4M5_SIZE_IN_BYTES        (48U)    /* PRQA S 1534 */
#define SHA_M1M2M3M4M5_SIZE_IN_BYTES  (112U)
#define SHE_AES_KEY_SIZE_IN_BYTES     (32U)    /* PRQA S 1534 */

/**
  * @brief  SHE Status structures definition
  */
typedef enum
{
    SHE_OK = 0x00U,
    SHE_ERROR,
    SHE_BUSY,
    SHE_TIMEOUT,
    SHE_SEQUENCE_ERROR,
    SHE_KEY_NOT_AVAILABLE,
    SHE_KEY_INVALID,
    SHE_KEY_EMPTY,
    SHE_NO_SECURE_BOOT,
    SHE_KEY_WRITE_PROTECTED,
    SHE_KEY_UPDATE_ERROR,
    SHE_RNG_SEED,
    SHE_NO_DEBUGGING,
    SHE_MEMORY_FAILURE
} SHE_Status_t;

/*!
 * @brief Specify the KeyID to be used to implement the requested cryptographic
 * operation.
 *
 * Implements : she_key_id_t_Class
 */
typedef enum {
    SHE_SECRET_KEY     = 0x00U,
    SHE_MASTER_ECU_KEY = 0x01U,
    SHE_BOOT_MAC_KEY   = 0x02U,
    SHE_BOOT_MAC       = 0x03U,
    SHE_AES_KEY_1      = 0x04U,
    SHE_AES_KEY_2      = 0x05U,
    SHE_AES_KEY_3      = 0x06U,
    SHE_AES_KEY_4      = 0x07U,
    SHE_AES_KEY_5      = 0x08U,
    SHE_AES_KEY_6      = 0x09U,
    SHE_AES_KEY_7      = 0x0AU,
    SHE_AES_KEY_8      = 0x0BU,
    SHE_AES_KEY_9      = 0x0CU,
    SHE_AES_KEY_A      = 0x0DU,
    SHE_RAM_KEY        = 0x0EU,
    SHE_RSA_KEY_1      = 0x14U,
    SHE_RSA_KEY_2      = 0x15U,
    SHE_RSA_KEY_3      = 0x16U,
    SHE_RSA_KEY_4      = 0x17U
} SHE_KEY_ID_t;

/**
 * Exported Functions
 */
extern SHE_Status_t SHE_LLD_OpenRWAuth(void);
extern SHE_Status_t SHE_LLD_GetStatus(uint32_t *status);
extern SHE_Status_t SHE_LLD_GetUID(uint8_t *uid);

extern SHE_Status_t SHE_LLD_InitRNG(uint8_t trngSrc);
extern SHE_Status_t SHE_LLD_ExtendSeed(const uint8_t *entropy);
extern SHE_Status_t SHE_LLD_GenerateRNG(uint8_t *rng);

extern SHE_Status_t SHE_LLD_LoadPlainKey(const uint8_t *plainKey);
extern SHE_Status_t SHE_LLD_ExportRAMKey(uint8_t *m1, uint8_t *m2, uint8_t *m3, uint8_t *m4, uint8_t *m5);
extern SHE_Status_t SHE_LLD_LoadKey(const uint8_t *m1, const uint8_t *m2, const uint8_t *m3, uint8_t *m4, uint8_t *m5);

extern SHE_Status_t SHE_LLD_AES_EncryptECB(SHE_KEY_ID_t keyID, const uint8_t *plainText, uint32_t length, uint8_t *cipherText);
extern SHE_Status_t SHE_LLD_AES_DecryptECB(SHE_KEY_ID_t keyID, const uint8_t *cipherText, uint32_t length, uint8_t *plainText);
extern SHE_Status_t SHE_LLD_AES_EncryptCBC(SHE_KEY_ID_t keyID,
                                           const uint8_t *iv,
                                           const uint8_t *plainText,
                                           uint32_t length,
                                           uint8_t *cipherText);
extern SHE_Status_t SHE_LLD_AES_DecryptCBC(SHE_KEY_ID_t keyID,
                                           const uint8_t *iv,
                                           const uint8_t *cipherText,
                                           uint32_t length,
                                           uint8_t *plainText);
extern SHE_Status_t SHE_LLD_AES_GenerateMAC(SHE_KEY_ID_t keyID, const uint8_t *msg, uint32_t msgLen, uint8_t paddingType, uint8_t *cmac);
extern SHE_Status_t SHE_LLD_AES_GenerateMACInit(SHE_KEY_ID_t keyID, const uint8_t *msg, uint32_t msgLen);
extern SHE_Status_t SHE_LLD_AES_GenerateMACUpdate(SHE_KEY_ID_t keyID, const uint8_t *msg, uint32_t msgLen);
extern SHE_Status_t SHE_LLD_AES_GenerateMACFinal(SHE_KEY_ID_t keyID, const uint8_t *msg, uint32_t msgLen, uint8_t paddingType, uint8_t *cmac);
extern SHE_Status_t SHE_LLD_AES_VerifyCMAC(SHE_KEY_ID_t keyID,
                                           const uint8_t *msg,
                                           uint32_t msgLen,
                                           uint8_t paddingType,
                                           const uint8_t *mac,
                                           uint32_t macLen,
                                           uint8_t *verifyStatus);
extern SHE_Status_t SHE_LLD_AES_MPCompress(const uint8_t *msg, uint32_t msgLen, uint8_t *mpCompress);

extern SHE_Status_t SHE_LLD_LoadRSAKey(SHE_KEY_ID_t keyID, const uint8_t *key, uint32_t nLen, uint32_t eLen, uint32_t dLen);
extern SHE_Status_t SHE_LLD_RSA_Encrypt(SHE_KEY_ID_t keyID, const uint8_t *plainText, uint32_t length, uint8_t *cipherText);
extern SHE_Status_t SHE_LLD_RSA_Decrypt(SHE_KEY_ID_t keyID, const uint8_t *cipherText, uint32_t length, uint8_t *plainText);

extern SHE_Status_t SHE_LLD_DbgChal(uint8_t *challenge);
extern SHE_Status_t SHE_LLD_DbgAuth(const uint8_t *auth);

extern SHE_Status_t SHE_LLD_SecureBootDefine(uint32_t bootImageSize, uint32_t bootImageAddress);
extern SHE_Status_t SHE_LLD_SecureBootDisable(void);

#if defined(__cplusplus)
}
#endif

#endif /* SHE_LLD_H_ */

