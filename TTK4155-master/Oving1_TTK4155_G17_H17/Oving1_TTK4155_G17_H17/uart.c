/*
 * uart.c
 *
 * Created: 11.09.2017 08:43:21
 *  Author: jonasgl
 */ 
#include "uart.h"

void send_UART(char letter){
	//send UART melding
	while( !(UCSR0A & (1<<UDRE0)) );
	UDR0 = letter;
}

void init_UART(unsigned int ubrr){
	//set baud rate
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)(ubrr);
	//enable receiver and transmitter
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	fdevopen((int(*)(char, struct __file*))&send_UART, (int(*)(struct __file*))&recieve_UART); //overrides printf("string");
}

unsigned int recieve_UART(void){
	while (!(UCSR0A & (1 << RXC0)));
	return UDR0;
}

void testUart(void){
	printf("turn off? Y/N\n");
	
	unsigned char temp = ' ';
	while(1){
		temp = recieve_UART();
		if (temp != 0){
			send_UART(temp);
		}
		if (temp == 'Y'){
			break;
		}
	};
}