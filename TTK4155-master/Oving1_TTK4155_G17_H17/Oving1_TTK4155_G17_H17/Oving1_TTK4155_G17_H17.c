/*
 * Oving1_TTK4155_G17_H17.c
 *
 * Created: 04.09.2017 11:50:29
 *  Author: pamarton
 */ 
#include <stdio.h>
#define F_CPU 4915200 // clock frequency in Hz
#define BAUDRATE 9600 // Valgt verdi data sendt pr sekund
#define UBBR 32 - 1 //F_CPU/(16*BAUDRATE)-1 //USART BAUD RATE REGISTER VALUE
#include <avr/io.h>
#include <util/delay.h>
//#include <avr/interrupt.h>
#include "uart.h"
#include "i_o.h"
int readADC(int channel);

#define MAX_TRESHOLD 245
#define MIN_TRESHOLD 10
#define MID_TRESHOLD 127

void SRAM_test(void);

int main(void)
{
	init_UART(UBBR);
	
	SRAM_test();
	
	testUart();
	while (1)
	{
		printf("placeholder\n");
	}
}

int readADC(int channel){
	volatile char *adc_on = (char *) 0x1400;
	switch(channel){
		case 1:	adc_on[0] = 0b00010100; break;
		case 2:	adc_on[0] = 0b00010101; break;
		case 3:	adc_on[0] = 0b00010110; break;
		case 4: adc_on[0] = 0b00010111; break;
		default: return 0;
	}
	int val = (int)adc_on[0];
	_delay_us(50); //TODO, CHANGE THIS TO THE CODE BELLOW
	//while(!(PORTA |= BIT_MASK(PINA5)));
	//printf("Value: %i\n",val);
	return val;
}


int ADC_to_percent(int signal){
	double new_signal = signal - 128;
	new_signal = new_signal*100/128; 
	printf("%lf",new_signal);
	/*if(signal < MIN_TRESHOLD){
		signal = 0;
		printf("MIN:%i\n",signal);
	}
	else if (signal > MAX_TRESHOLD)
	{
		signal = 255;
		printf("MAX:%i\n",signal);
	}
	else if ((signal <= MID_TRESHOLD + 5) && (signal >= MID_TRESHOLD - 5)){
		signal = MID_TRESHOLD;
		printf("MID:%i\n",signal);
	}
	else{
		printf("REG:%i\n",signal);
	}*/
	
	
	return 0;
}





#include <stdlib.h>
void SRAM_test(void)
{
	BIT_ON(MCUCR,SRE);
	volatile char *ext_ram = (char *) 0x1800; // Start address for the SRAM
	
	
	while(1){
		ADC_to_percent(readADC(1));
		
		//readADC(1);
	}
	
	
	uint16_t ext_ram_size = 0x800;
	uint16_t write_errors = 0;
	uint16_t retrieval_errors = 0;
	printf("Starting SRAM test...\n");
	// rand() stores some internal state, so calling this function in a loop will
	// yield different seeds each time (unless srand() is called before this function)
	uint16_t seed = rand();
	// Write phase: Immediately check that the correct value was stored
	srand(seed);
	for (uint16_t i = 0; i < ext_ram_size; i++) {
		uint8_t some_value = rand();
		ext_ram[i] = some_value;
		uint8_t retreived_value = ext_ram[i];
		if (retreived_value != some_value) {
			printf("Write phase error: ext_ram[%4d] = %02X (should be %02X)\n", i,	retreived_value, some_value);
			write_errors++;
		}
	}
	// Retrieval phase: Check that no values were changed during or after the writephase
	srand(seed);
	// reset the PRNG to the state it had before the write phase
	for (uint16_t i = 0; i < ext_ram_size; i++) {
		uint8_t some_value = rand();
		uint8_t retreived_value = ext_ram[i];
		if (retreived_value != some_value) {
			printf("Retrieval phase error: ext_ram[%4d] = %02X (should be %02X)\n",i, retreived_value, some_value);
			retrieval_errors++;
		}
	}
	printf("SRAM test completed with\n%4d errors in write phase and\n%4d errors	in retrieval phase\n\n", write_errors, retrieval_errors);
}



