/*
 * uart.h
 *
 * Created: 11.09.2017 08:43:48
 *  Author: jonasgl
 */ 

#ifndef UART_H_
#define UART_H_

#include "new_printf.h"
#include <avr/io.h>
#include <stdio.h>
#define F_CPU 4915200 // clock frequency in Hz
#define BAUDRATE 9600 // Valgt verdi data sendt pr sekund
#define UBBR 32 - 1 //F_CPU/(16*BAUDRATE)-1 //USART BAUD RATE REGISTER VALUE

void send_UART(char letter);
void init_UART(unsigned int ubbr);
unsigned int recieve_UART(void);
void testUart(void);

#endif /* UART_H_ */