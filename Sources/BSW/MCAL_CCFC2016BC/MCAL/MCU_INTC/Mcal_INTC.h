/*
 * Mcal_INTC.h
 *
 *  Created on: 2019Äê3ÔÂ12ÈÕ
 *      Author: yang
 */

#ifndef BSW_MCAL_5744P_MCAL_INTC_MCAL_INTC_H_
#define BSW_MCAL_5744P_MCAL_INTC_MCAL_INTC_H_


typedef enum{
	INTC_SoftSetable_Interrupt_0=0,
	INTC_SoftSetable_Interrupt_1,
	INTC_SoftSetable_Interrupt_2,
	INTC_SoftSetable_Interrupt_3,
	INTC_SoftSetable_Interrupt_4,
	INTC_SoftSetable_Interrupt_5,
	INTC_SoftSetable_Interrupt_6,
	INTC_SoftSetable_Interrupt_7,
	INTC_SoftSetable_Interrupt_Num
}Mcal_INTC_SS_Source;

typedef void (*SoftSetable_ISR)(uint8 source);

extern void Mcal_INTC_SS_Install(uint8 en, Mcal_INTC_SS_Source source, SoftSetable_ISR isr_handler);
extern void Mcal_INTC_CANFD_Install(uint8 en, Mcal_INTC_SS_Source source, SoftSetable_ISR isr_handler);
extern void Mcal_INTC_SS_TriggerEvent(Mcal_INTC_SS_Source source);
extern void Mcal_INTC_CANFD_TriggerEvent(Mcal_INTC_SS_Source source);
#endif /* BSW_MCAL_5744P_MCAL_INTC_MCAL_INTC_H_ */
