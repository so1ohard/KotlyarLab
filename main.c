/*
 * KotlyarLab.c
 *
 * Created: 15.02.2021 17:10:14
 * Author : User
 */ 

#include <avr/io.h>
#include "UART_library.h"
#include "main.h"

uint8_t _millis = 0;
//uint8_t dataReady = 0;



int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
    }
}

void systemTimerInitAtmega128() //Таймер для подсчёта миллисекунд. Настраиваем таймер на срабатывание каждую миллисекунду
{
	TCCR0 = (1<<WGM01) | (0<<WGM00) | (0<<COM01) | (0<<COM00)|	//Режим CTC, OC0 отключен
	(0<<CS02) | (1<<CS01) | (1<<CS00);							//Предделитель 32 
	TCNT0 = 0x00;												//Сбрасываем регистр счёта 
	OCR0 = ((F_CPU/32)/1000) - 1;								//Число до которого считаем
	TIMSK |= (1<<OCIE0);	
}

ISR(MILLIS_TIMER)  //Срабатывает каждую миллисекунду
{
	_millis++;
}

uint32_t millis(void)	//Функция, возвращающая количество миллисекунд
{
	return _millis;
}