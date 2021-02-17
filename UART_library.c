/*
 * UART_library.c
 *
 * Created: 15.02.2021 17:11:26
 *  Author: User
 */ 

#include "main.h"
#include "UART_library.h"

uint32_t lastDataTransmit = 0;
uint8_t anyVal;
uint8_t readFlag = 0;

uint8_t rxBuffer[3] = {0};
uint8_t rxIndex = 0;
uint8_t readyFlag = 0;

void USART_Init(unsigned int baudRate)
{
	//������������� �������� 
	RADIO_UBRRH = (uint8_t)(baudRate >> 8);
	RADIO_UBRRL = (uint8_t)baudRate;
	
	RADIO_UCSRB = (1<<RADIO_RXEN) | (1<<RADIO_TXEN) | (1<<RADIO_RXCIE); //��������� ����, �������� � ���������� �� �����
	//Set character size
	RADIO_UCSRC = (1<<RADIO_UCSZ1) | (1<<RADIO_UCSZ0);	//������ ������ 8 ��� 
}

void USART_transmit() //������� ������ �� UART
{
	if((millis() - lastDataTransmit) > TRANSMIT_INTERVAL)	
	{
		if(adcReady)
		{
			//TODO:
			if(RADIO_UCSRA & (1<<RADIO_UDRE))
			{
				RADIO_UDR = adcValue;
			}
	}
}

ISR(RADIO_RX_vect)
{
	uint8_t buf = RADIO_UDR;
	if(buf == 0xEE)
	{
		rxIndex = 0;
	}
	if(readFlag == 0) //���� �� ��������� ������ �� ������
	{
		if(rxIndex < MAX_RX_SIZE) //� ������� ������ ������ �������������	
		{
			readyFlag = 0;		//�.�. �� ��������� ������, �� ���������� ���� ����������			
			rxBuffer[rxIndex] = buf;	//�������� ���������� ���� � �����
			rxIndex++;					//��������� ������� ������
			if (rxIndex == MAX_RX_SIZE) //���� �������� ����� ������
			{
				readyFlag = 1;			//������� ���� ���������� ������
			}
		}
	}
}

void USART_receive()
{
	cli();
	if(readyFlag == 1)
	{
		readFlag = 1;
		readyFlag = 0;
	}
	sei();
	
	if(readFlag == 1)
	{
		if(rxBuffer[1] == 0x01)
		{
			//TODO: �������� �����������
		}
		else
		{
			//TODO: ��������� �����������
		}
		
		if(rxBuffer[2] == 0x01)
		{
			//TODO: �������� ����������
		}
		else
		{
			//TODO: ��������� �����������
		}
		
	}
}
