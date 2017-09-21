/*
 * button_interrupts.h
 *
 * Created: 21.09.2017 18:11:11
 *  Author: pamarton
 */ 


#ifndef BUTTON_INTERRUPTS_H_
#define BUTTON_INTERRUPTS_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include "uart.h"
#include "i_o.h"
#include "input_conversion.h"//REMOVE THIS AND THE PRINTF IN THE button_interrupts.c FILE

void initalize_interrupts(void);
ISR(INT0_vect);//interrupt button Right
ISR(INT1_vect);//interrupt button Left



#endif /* BUTTON_INTERRUPTS_H_ */