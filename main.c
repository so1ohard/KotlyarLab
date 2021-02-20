/*
 * KotlyarLab.c
 *
 * Created: 15.02.2021 17:10:14
 * Author : User
 */ 

#include <avr/io.h>
#include "UART_library.h"
#include "adc.h"
#include "main.h"

uint8_t _millis = 0;
//uint8_t dataReady = 0;



int main(void)
{
	ADC_Init();
	USART_Init(115200);
    /* Replace with your application code */
    while (1) 
    {
		USART_receive();
		USART_transmit();
    }
}

void systemTimerInitAtmega128() //������ ��� �������� �����������. ����������� ������ �� ������������ ������ ������������
{
	TCCR0 = (1<<WGM01) | (0<<WGM00) | (0<<COM01) | (0<<COM00)|	//����� CTC, OC0 ��������
	(1<<CS02) | (0<<CS01) | (0<<CS00);							//������������ 64 
	TCNT0 = 0x00;												//���������� ������� ����� 
	OCR0 = ((F_CPU/64)/1000) - 1;								//����� �� �������� �������
	TIMSK |= (1<<OCIE0);	
}

ISR(MILLIS_TIMER)  //����������� ������ ������������
{
	_millis++;
}

uint32_t millis(void)	//�������, ������������ ���������� �����������
{
	return _millis;
}

void relay_Init()	//����������� ���� ����� �� �����
{
	RELAY_DDR |= ((1<<FIRST_RELAY) | (1<<SECOND_RELAY) | (1<<THIRD_RELAY));
}

void relayOn(uint8_t relay) //����� �� ���� ������� ���� 1
{
	RELAY_PORT |= (1<<relay)
}

void relayOff(uint8_t relay) //����� �� ���� ������� ���� 0
{
	RELAY_PORT &= ~(1<<relay);
}