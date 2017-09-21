/*
 * input_conversion.h
 *
 * Created: 21.09.2017 15:42:44
 *  Author: pamarton
 */ 


#ifndef INPUT_CONVERSION_H_
#define INPUT_CONVERSION_H_
#include "uart.h"
#include "adc.h"

int signal_to_range(int signal, int signal_min, int signal_max, int output_min, int output_max, int calibrate, int referance, int step);
void calibrate_joystick(void);
void initialize_control_input(void);
int read_control_input(char channel);
#endif /* INPUT_CONVERSION_H_ */