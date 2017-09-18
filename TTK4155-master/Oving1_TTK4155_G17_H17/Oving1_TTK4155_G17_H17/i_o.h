/*
 * i_o.h
 *
 * Created: 11.09.2017 12:17:20
 *  Author: jonasgl
 */ 


#ifndef I_O_H_
#define I_O_H_

#define INPUT 0
#define OUTPUT 1
#define OFF 0
#define ON 1

#include <avr/io.h>

#define BIT_MASK(b)  (0x01 << (b))
#define BIT_ON(p,b)  ((p) |= BIT_MASK(b))
#define BIT_OFF(p,b) ((p) &= ~BIT_MASK(b))
#define BIT_SET(p,b,v) (v ? BIT_ON(p,b) : BIT_OFF(p,b))

#define BIT_ON_A(b) BIT_ON(PORTA,b)
#define BIT_OFF_A(b) BIT_OFF(PORTA, b)
#define BIT_SET_A(b,v) BIT_SET(PORTA, b)

#define BIT_ON_B(b) BIT_ON(PORTB,b)
#define BIT_OFF_B(b) BIT_OFF(PORTB, b)
#define BIT_SET_B(b,v) BIT_SET(PORTB, b)

#define BIT_ON_C(b) BIT_ON(PORTC,b)
#define BIT_OFF_C(b) BIT_OFF(PORTC, b)
#define BIT_SET_C(b,v) BIT_SET(PORTC, b)

#define BIT_ON_D(b) BIT_ON(PORTD,b)
#define BIT_OFF_D(b) BIT_OFF(PORTD, b)
#define BIT_SET_D(b,v) BIT_SET(PORTD, b)

#define WAIT_UNTIL_SET(r,b)	while(r |= BIT_MASK(b))

#endif /* I_O_H_ */