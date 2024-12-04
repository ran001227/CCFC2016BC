/*
 * MCAL_EXINT.h
 *
 *  Created on: 2020Äê8ÔÂ3ÈÕ
 *      Author: LI
 */

#ifndef MCAL_EXINT_H_
#define MCAL_EXINT_H_

#include "MCAL_CAN.h"

typedef void (*EXINTCAN3Isr_PtrType)(void);

extern void Mcal_EXINT_GPIO_Init(void);
extern void Mcal_EXINT_InstallCAN3Isr(EXINTCAN3Isr_PtrType IsrPtr);


#endif /* MCAL_EXINT_H_ */
