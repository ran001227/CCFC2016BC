/**************************************************************************** 
* 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* PROJECT     : CCFC2016BC           
* DESCRIPTION : This file contains the application entry point __startup. 
* HISTORY     : Initial version.
* @file     CCFC2016BC_Startup.c
* @version  1.1
* @date     2023 - 02 - 15
* @brief    Initial version.
*
*****************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

__declspec(section ".init") extern void __startup(int argc, char **argv, char **envp);
/* primary entry point */
extern void __start(register int argc, register char **argv, register char **envp);

#ifdef __cplusplus
}
#endif

asm void __startup(register int argc, register char **argv, register char **envp)
{
	nofralloc							/* explicitly no stack */
	// call standard application initialization
	bl __start
}
