/*
 * adc.h
 *
 * Created: 21.09.2017 13:37:45
 *  Author: pamarton
 */ 
#ifndef F_CPU
#define F_CPU 4915200
#endif //can be removed

#ifndef ADC_H_
#define ADC_H_

#include <util/delay.h>
#include "uart.h"
#include "adc.h"
unsigned int readADC(int channel);

#endif /* ADC_H_ */