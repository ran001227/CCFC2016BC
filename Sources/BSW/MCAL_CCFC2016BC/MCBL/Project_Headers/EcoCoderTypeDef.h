/*************************************************************
Copyright (c) BAIC 2015-2016. All rights reserved.

File name:		EcoCoderTypeDef.h
Author:			
Version:		V0.0.1
Date:			2018-5-29
Description:
Others:
History:

	1. Date: 
	   Author: 
	   Modification:  
	2. ...
**************************************************************/

#ifndef _H_EcoCoderTypeDef_H
#define _H_EcoCoderTypeDef_H

/*************************************************************
Includes
**************************************************************/

#ifndef ECO_BOOL
	#define ECO_BOOL  unsigned char
#endif

#ifndef ECO_S08
	#define ECO_S08  signed char
#endif

#ifndef ECO_U08
	#define ECO_U08  unsigned char
#endif

#ifndef ECO_S16
	#define ECO_S16   signed short
#endif

#ifndef ECO_U16
	#define ECO_U16   unsigned short
#endif

#ifndef ECO_S32
	#define ECO_S32   signed long
#endif

#ifndef ECO_U32 
	#define ECO_U32   unsigned long
#endif

#ifndef ECO_S64
	#define ECO_S64   signed long long
#endif

#ifndef ECO_U64 
	#define ECO_U64   unsigned long long
#endif


#ifndef ECO_TRUE
    #define ECO_TRUE             (ECO_U08)1
#endif

#ifndef ECO_FALSE
    #define ECO_FALSE            (ECO_U08)0
#endif


#endif
