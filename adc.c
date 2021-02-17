/*
 * adc.c
 *
 * Created: 17.02.2021 5:52:02
 *  Author: User
 */ 

#include "adc.h"

uint8_t adc_low = 0, adc_high = 0;
uint8_t adcValue[2] = {0};
uint8_t adcReady = 0;

ISR(ADC_vect)
{
	adcValue[1] = ADCL;
	adcValue[0] = ADCH;
	adcReady = 1;
	//adcValue = (adc_high << 8) | adc_low;
}

void ADC_Init(void)		//АЦП включён и срабатывает "по требованию"
{
	ADC_CONTROL |= (1<<ADEN)	//Включаем АЦП
				//| (1<<ADSC)		//Запуск преобразования
				//| (1<<ADFR)		//Непрерывный режим работы АЦП
				| (1<<ADPS2) | (1<<ADPS1) | (0<<ADPS0) //Выставляем частоту 125 кГц - предделитель 64
				| (1<<ADIE);	 //Разрешение прерывания от АЦП
				
	ADMUX	|= (1<<REFS1) | (1<<REFS0);/*Внутренний источник, вход ADC0 = PF0. Если нужен какой-то другой канал, то указываем 
										*Через значения MUX4..0
										*/	
}
