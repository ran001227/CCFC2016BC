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
* @file     cache.c
* @version  1.4
* @date     2023 - 06 - 12
* @brief    Initial version.
*
*****************************************************************************/
#define DCACHE_COPYBACK_MODE 0 // 1-copyback, 0-write-through

#define SPR_L1CSR1 1011
#define SPR_L1CSR0 1010

/*******************************************************************************
Function Name : BranchPredictionEnable
Engineer      : b08110
Date          : Feb-22-2010
Parameters    : 
Modifies      : r3, bucsr
Returns       : 
Notes         : turn on branch prediction and invalidate branch target buffer
Issues        : 
*******************************************************************************/
asm void BranchPredictionEnable(void)
{
    nofralloc
    
    /* turn on branch prediction and invalidate branch target buffer */
    lis   r3, 0x0
    ori   r3, r3, 0x0201
    mtbucsr r3

    blr   
}

/*******************************************************************************
Function Name : ICache_init
Engineer      : b05111
Date          : 
Parameters    : 
Modifies      : 
Returns       : 
Notes         : Invalidate and Enable
Issues        : 
*******************************************************************************/
asm void ICache_init(void)
{
    nofralloc
    
/**************************************************************************
# FUNCTION     : cfg_CACHE                                               *
# PURPOSE      : This function initializes the CACHE, using L1CSR1       *
#                register.                                                *
#                SEQUENCE:                                                *
#                - Start Cache Invalidate                                *
#                - Wait for invalidation to complete, check for Abort     *
#                  operation and restart invalidation if detected         *
#                - Enable Cache by setting CE bit                       *
#**************************************************************************/
cfg_CACHE:

    /*--------------------------------------------#
    # Invalidate - Set CINV                      #
    # bit in L1CSR1 Register                     #
    #--------------------------------------------*/
    lis   r5, 0x0000
    ori   r5, r5, 0x0002
    msync
    isync
    mtspr SPR_L1CSR1,r5

    /*-------------------------------------------#
    # Mask out CINV and CABT to see if           #
    # invalidation is complete (i.e. CINV=0,     #
    # CABT=0)                                    #
    #-------------------------------------------*/
label_CINV_check:
    /*-------------------------------------------#
    # Load Registers with Masks:                 #
    # Load CINV mask into R8                     #
    # Load CABT mask into R7                     #
    # Load CABT clear mask into R11              #
    #-------------------------------------------*/
    lis   r8, 0x0000
    ori   r8, r8, 0x0002
    lis   r7, 0x0000
    ori   r7, r7, 0x0004
    lis   r11, 0xFFFF
    ori   r11, r11, 0xFFFB
CHECK_CINV:

    /*-------------------------------------------#
    # Read SPR_L1CSR1 register, store in r9      #
    #-------------------------------------------*/
    mfspr r9, SPR_L1CSR1
    /*-------------------------------------------#
    # check for an ABORT of the cache invalidate #
    # operation                                  #
    #-------------------------------------------*/
    and.  r10, r7, r9
    beq   NO_ABORT
    /*-------------------------------------------#
    # If abort detected, clear CABT bit and      #
    # re-run invalidation                        #
    #-------------------------------------------*/
    and.  r10, r11, r9
    msync
    isync
    mtspr SPR_L1CSR1, r10
    b     cfg_CACHE

NO_ABORT:
    /*-------------------------------------------#
    # Check that invalidation has completed -    #
    # (CINV=0). Branch if invalidation not       #
    # complete.                                  #
    #-------------------------------------------*/
    and.  r10, r8, r9
    bne CHECK_CINV

    /*-------------------------------------------#
    # Enable cache by performing a               #
    # read/modify/write of the CE bit in the     #
    # SPR_L1CSR1 register                        #
    #-------------------------------------------*/
    mfspr r5, SPR_L1CSR1
    oris  r5, r5, 0x0000
    ori   r5, r5, 0x0001    /* Store SPR_L1CSR1 value to R5 (CE=1) */
    msync
    isync
    mtspr SPR_L1CSR1, r5        /* Write R5 to SPR_L1CSR1 register */

    blr
/**************************************************************************
# END OF cfg_CACHE                                                        *
#**************************************************************************/
}



/*******************************************************************************
Function Name : DCache_init
Engineer      : b05111
Date          : 
Parameters    : 
Modifies      : 
Returns       : 
Notes         : Invalidate and Enable
Issues        : 
*******************************************************************************/
asm void DCache_init(void)
{
    nofralloc
    
/**************************************************************************
# FUNCTION     : cfg_CACHE                                                *
# PURPOSE      : This function initializes the CACHE, using L1CSR1        *
#                register.                                                *
#                SEQUENCE:                                                *
#                - Start Cache Invalidate                                 *
#                - Wait for invalidation to complete, check for Abort     *
#                  operation and restart invalidation if detected         *
#                - Enable Cache by setting CE bit                         *
#**************************************************************************/
cfg_DCACHE:

    /*--------------------------------------------#
    # Invalidate - Set CINV                      #
    # bit in L1CSR0 Register                     #
    #--------------------------------------------*/
    lis   r5, 0x0000
    ori   r5, r5, 0x0002
    msync
    isync
    mtspr SPR_L1CSR0,r5

    /*-------------------------------------------#
    # Mask out CINV and CABT to see if           #
    # invalidation is complete (i.e. CINV=0,     #
    # CABT=0)                                    #
    #-------------------------------------------*/
label_DCINV_check:
    /*-------------------------------------------#
    # Load Registers with Masks:                 #
    # Load CINV mask into R8                     #
    # Load CABT mask into R7                     #
    # Load CABT clear mask into R11              #
    #-------------------------------------------*/
    lis   r8, 0x0000
    ori   r8, r8, 0x0002
    lis   r7, 0x0000
    ori   r7, r7, 0x0004
    lis   r11, 0xFFFF
    ori   r11, r11, 0xFFFB
CHECK_DCINV:

    /*-------------------------------------------#
    # Read SPR_L1CSR0 register, store in r9      #
    #-------------------------------------------*/
    mfspr r9, SPR_L1CSR0
    /*-------------------------------------------#
    # check for an ABORT of the cache invalidate #
    # operation                                  #
    #-------------------------------------------*/
    and.  r10, r7, r9
    beq   D_NO_ABORT
    /*-------------------------------------------#
    # If abort detected, clear CABT bit and      #
    # re-run invalidation                        #
    #-------------------------------------------*/
    and.  r10, r11, r9
    msync
    isync
    mtspr SPR_L1CSR0, r10
    b     cfg_DCACHE

D_NO_ABORT:
    /*-------------------------------------------#
    # Check that invalidation has completed -    #
    # (CINV=0). Branch if invalidation not       #
    # complete.                                  #
    #-------------------------------------------*/
    and.  r10, r8, r9
    bne CHECK_DCINV

    /*-------------------------------------------#
    # Enable cache by performing a               #
    # read/modify/write of the CE bit in the     #
    # SPR_L1CSR0 register                        #
    #-------------------------------------------*/
    mfspr r5, SPR_L1CSR0
    oris  r5, r5, 0x0000
    ori   r5, r5, 0x0001    /* Store SPR_L1CSR0 value to R5 (CE=1) */
    msync
    isync
    mtspr SPR_L1CSR0, r5        /* Write R5 to SPR_L1CSR0 register */

    blr
/**************************************************************************
# END OF cfg_CACHE                                                        *
#**************************************************************************/
}


/*******************************************************************************
Function Name : Enable_DCache_Copyback
Engineer      : b05111
Date          : 
Parameters    : 
Modifies      : 
Returns       : 
Notes         : Invalidate and Enable
Issues        : 
*******************************************************************************/
#ifdef DCACHE_COPYBACK_MODE
asm void Enable_DCache_Copyback(void)
{
    /*-------------------------------------------#
    # Enable cache by performing a               #
    # read/modify/write of the DCWM bit in the   #
    # SPR_L1CSR0 register                        #
    #-------------------------------------------*/
    mfspr r5, SPR_L1CSR0
    oris  r5, r5, 0x0010
    ori   r5, r5, 0x0000    /* Store SPR_L1CSR0 value to R5 (DCWM=1) */
    msync
    isync
    mtspr SPR_L1CSR0, r5        /* Write R5 to SPR_L1CSR0 register */

    blr
}
#endif


#if 0

* GreenHills compiler asm syntax */

 

__asmleaf void flush_inv_cache_line(unsigned int flushed_way, unsigned int flushed_set) {

%reg flushed_way %reg flushed_set

mfspr r3, l1finv0

insrwi r3, flushed_way, 5, 3

insrwi r3, flushed_set, 7, 20

li r4, 2

rlwimi r3, r4, 0, 30, 31

msync

mtspr l1finv0, r3

    }

 

void flush_inv_cache(void) {

    unsigned int i;

    unsigned int j;

    for (i = 0u; i < 8u; i++)

    {

        for (j = 0u; j < 128u; j++)

        {

            flush_inv_cache_line(i, j);

        }

    }

}

#endif

/*******************************************************************************
Function Name : ICache_init
Engineer      : b05111
Date          : 
Parameters    : 
Modifies      : 
Returns       : 
Notes         : Invalidate and Enable
Issues        : 
*******************************************************************************/
asm void Dcache_disable(void)
{
	msync 
	isync
	
	lis r3, 0x0000 
	ori r3, r3, 0x0002 
	msync 
	isync
	mtspr l1csr0, r3 	
}

asm void Dcache_enable(void) 
{
WaitForInvalidationComplete1: 
	mfspr r3, l1csr0 
	li r4, 0x0002
	and r3, r3, r4 
	cmpli r3, 0x0002 
	beq WaitForInvalidationComplete1

InvalidateCache:
	msync   
	isync
	mtspr l1csr0, r4 

WaitForInvalidationComplete2:
	mfspr r3, l1csr0 
	and r3, r3, r4 
	cmpli r3, 0x0002 
	beq WaitForInvalidationComplete2

	mfspr r3, l1csr0 
	li r4, 0x0004 
	and r3, r3, r4 
	cmpli r3, 0x0004 
	beq InvalidateCache 

	lis r3, 0x0008 
	ori r3, r3, 0x0009 // cofigure D cache L1CRS0
	msync 
	isync
	mtspr l1csr0, r3 
	
	mfspr r3, l1csr0 
	
	mfspr r3, l1csr1 
}

asm unsigned int CheckDacheIsEnabled(void)
{		
	mfspr r3, l1csr0
	
	blr
}
