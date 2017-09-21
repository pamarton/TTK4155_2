/*
 * adc.c
 *
 * Created: 21.09.2017 13:37:55
 *  Author: pamarton
 */ 
#include "adc.h"

unsigned int readADC(int channel){
	volatile char *adc_on = (char *) 0x1400;
	switch(channel){
		case 1:	adc_on[0] = 0b00010100; break; // X_axis
		case 2:	adc_on[0] = 0b00010101; break; // Y_axis
		case 3:	adc_on[0] = 0b00010110; break; // Left Slider
		case 4: adc_on[0] = 0b00010111; break; // Right Slider
		default: return 0;
	}
	//unsigned int val = (unsigned int)adc_on[0];
	_delay_us(50); //TODO, CHANGE THIS TO THE CODE BELLOW
	//while(!(PORTA |= BIT_MASK(PINA5)));
	
	//printf("Value: %i\n",val);
	return (unsigned int)adc_on[0];
}
