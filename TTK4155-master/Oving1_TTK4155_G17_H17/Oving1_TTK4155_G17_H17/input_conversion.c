/*
 * input_conversion.c
 *
 * Created: 21.09.2017 15:42:26
 *  Author: pamarton
 */ 
#include "input_conversion.h"
#define CALIBRATE_READINGS 100
volatile int calibrate_x = 0;
volatile int calibrate_y = 0;
volatile int ref_X = 0;
volatile int ref_Y = 0;
volatile int ref_L = 0;
volatile int ref_R = 0;




void initialize_control_input(void){
	calibrate_joystick();
	ref_X = read_control_input('X');
	ref_Y = read_control_input('Y');
	ref_L = read_control_input('L');
	ref_R = read_control_input('R');
	printf("Calibration values: \tcal_X: %i\tcal_Y:%i\n",calibrate_x,calibrate_y);
	printf("Reference Values: \tX %i\tY %i\tL %i\tR %i\t\n",ref_X,ref_Y,ref_L,ref_R);
}

void calibrate_joystick(void){
	for (int i = 0; i < CALIBRATE_READINGS; i++){
		calibrate_x += 127 - readADC(1);
		calibrate_y += 127 - readADC(2);
	}
	calibrate_x /= CALIBRATE_READINGS;
	calibrate_y /= CALIBRATE_READINGS;
}

int read_control_input(char channel){
	switch(channel){
		case 'X': 
			ref_X = signal_to_range(readADC(1), 0, 255, -100, 100, calibrate_x, ref_X, 10); 
			return ref_X;
		case 'Y': 
			ref_Y = signal_to_range(readADC(2), 0, 255, -100, 100, calibrate_y, ref_Y, 10);
			return ref_Y;
		case 'L':
		ref_L = signal_to_range(readADC(3), 0, 255, 0, 100, 0, ref_L, 10);
		return ref_L;
		case 'R': 
			ref_R = signal_to_range(readADC(4), 0, 255, 0, 100, 0, ref_R, 10);
			return ref_R;
	}
	return 0;
}


int signal_to_range(int signal, int signal_min, int signal_max, int output_min, int output_max, int calibrate, int referance, int step){
	
	int new_signal = (int)((double)output_min + (double)(signal + calibrate - signal_min)*(double)(output_max-output_min)/(double)(signal_max-signal_min));
	
		
	if (new_signal >= output_max - step){
		referance = output_max;
	}else if(new_signal <= output_min + step){
		referance = output_min;
	}else{
		while (!(((new_signal < referance + step) && (new_signal > referance - step)))){
			if((new_signal >= referance + step/2)){
				referance += step;
			}
			else if (new_signal <= referance - step/2){
				referance -= step;
			}
			 
		}
	}
	//printf("VALUE: \t%i\t%i\t%i\n",signal,new_signal, referance);
	return referance;
}

