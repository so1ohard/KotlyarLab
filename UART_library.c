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
	//Устанавливаем скорость 
	RADIO_UBRRH = (uint8_t)(baudRate >> 8);
	RADIO_UBRRL = (uint8_t)baudRate;
	
	RADIO_UCSRB = (1<<RADIO_RXEN) | (1<<RADIO_TXEN) | (1<<RADIO_RXCIE); //Разрешаем приём, передачу и прерывание по приёму
	//Set character size
	RADIO_UCSRC = (1<<RADIO_UCSZ1) | (1<<RADIO_UCSZ0);	//Размер данных 8 бит 
}

void USART_transmit() //Передаём данные по UART
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
	if(readFlag == 0) //Если мы прочитали данные из буфера
	{
		if(rxIndex < MAX_RX_SIZE) //И текущий индекс меньше максимального	
		{
			readyFlag = 0;		//Т.к. мы заполняем массив, то сбрасываем флаг готовности			
			rxBuffer[rxIndex] = buf;	//Помещаем полученный байт в буфер
			rxIndex++;					//Инкремент индекса буфера
			if (rxIndex == MAX_RX_SIZE) //Если достигли конца буфера
			{
				readyFlag = 1;			//Взводим флаг готовности данных
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
			//TODO: Включить нагреватель
		}
		else
		{
			//TODO: Выключить нагреватель
		}
		
		if(rxBuffer[2] == 0x01)
		{
			//TODO: Включить вентилятор
		}
		else
		{
			//TODO: Выключить нагреватель
		}
		
	}
}
