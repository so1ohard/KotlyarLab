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

#define F_CPU 10000000UL				//Частота процессора
#define MILLIS_TIMER TIMER0_COMP_vect	//Вектор прерывания таймера

#define RELAY_DDR DDRA
#define RELAY_PORT PORTA

#define FIRST_RELAY			0x01
#define SECOND_RELAY		0x02
#define THIRD_RELAY			0x03

extern uint8_t adcValue;
extern uint8_t readyFlag;

uint32_t millis(void);

void relayOn(uint8_t relay);
void relayOff(uint8_t relay);

void relay_Init();

#endif /* MAIN_H_ */