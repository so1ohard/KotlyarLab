/*
 * UART_library.h
 *
 * Created: 15.02.2021 17:11:46
 *  Author: User
 */ 

#include "main.h"
#include "avr/io.h"

#ifndef UART_LIBRARY_H_
#define UART_LIBRARY_H_


//#if defined(__AVR_ATmega2560__)

#define RADIO_UCSRA		UCSR1A						//������� �������� � ������� UART
#define RADIO_UCSRB		UCSR1B						//-//-
#define RADIO_UCSRC		UCSR1C						//-//-
#define RADIO_UDR		UDR1						//������� ������ ������
#define RADIO_UDRIE		UDRIE1						//���������\��������� ���������� �� ����� UDRE
#define RADIO_RXCIE		RXCIE1						//���������� �� ��������� �����
#define RADIO_RXEN		RXEN1						//������� UART ������
#define RADIO_TXEN		TXEN1						//���������� UART ������
#define RADIO_UDRE		UDRE1						//���� ���������� �������� UDR
#define RADIO_UCSZ0		UCSZ10						//����� ����� ������������ ���
#define RADIO_UCSZ1		UCSZ11						//-//-
#define RADIO_UBRRL		UBRR1L						//������� ��� ������� �������� UART
#define RADIO_UBRRH		UBRR1H
#define RADIO_SPEED		(F_CPU/(RADIO_BAUD*16))-1	//������ �������� UART

//#elif defined(__AVR_ATmega128__)
//
//#define RADIO_UCSRA		UCSR1A						//������� �������� � ������� UART
//#define RADIO_UCSRB		UCSR1B						//-//-
//#define RADIO_UCSRC		UCSR1C						//-//-
//#define RADIO_UDR		UDR1						//������� ������ ������
//#define RADIO_UDRIE		UDRIE1						//���������\��������� ���������� �� ����� UDRE
//#define RADIO_RXCIE		RXCIE1						//���������� �� ��������� �����
//#define RADIO_RXEN		RXEN1						//������� UART ������
//#define RADIO_TXEN		TXEN1						//���������� UART ������
//#define RADIO_UDRE		UDRE1						//���� ���������� �������� UDR
//#define RADIO_UCSZ0		UCSZ10						//����� ����� ������������ ���
//#define RADIO_UCSZ1		UCSZ11						//-//-
//#define RADIO_UBRR		UBRR1						//������� ��� ������� �������� UART
//#define RADIO_SPEED		(F_CPU/(RADIO_BAUD*16))-1;	//������ �������� UART
//
//#else
//#error "This MCU not supported"
//#endif

#define RADIO_RX_vect		USART1_RX_vect			//���������� �� �����
#define RADIO_UDRE_vect		USART1_UDRE_vect		//���������� �� ������������ �������
#define RADIO_BAUD			115200					//�������� UART

#define MAX_RX_SIZE			3
#define PACKET_HEADER		0xEE
#define TRANSMIT_INTERVAL	1000					//1 second

extern uint8_t adcReady;

void USART_Init(unsigned int baudRate);
#endif /* UART_LIBRARY_H_ */