/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS, " AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* PROJECT     : CCFC2016BC
* DESCRIPTION : cache code
* HISTORY     : Initial version.
* @file     cache.h
* @version  1.4
* @date     2023 - 06 - 12
* @brief    Initial version.
*
*****************************************************************************/
#ifndef CACHE_H_
#define CACHE_H_

asm void BranchPredictionEnable(void);
asm void ICache_init(void);
asm void DCache_init(void);
asm unsigned int CheckDacheIsEnabled(void);
asm void Dcache_disable(void);
asm void Dcache_enable(void);

#endif /* CACHE_H_ */
