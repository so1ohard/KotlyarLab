/*
 * main.h
 *
 * Created: 15.02.2021 19:50:48
 *  Author: User
 */ 


#ifndef MAIN_H_
#define MAIN_H_

#include "stdint.h"
#include "avr/interrupt.h"
//#include "avr/iom128.h"

#define F_CPU 8000000UL					//Частота процессора
#define MILLIS_TIMER TIMER0_COMP_vect	//Вектор прерывания таймера по 

extern uint8_t adcValue;
extern uint8_t readyFlag;

uint32_t millis(void);

#endif /* MAIN_H_ */