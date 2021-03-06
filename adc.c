/*
 * adc.c
 *
 * Created: 17.02.2021 5:52:02
 *  Author: User
 */ 

#include "adc.h"

uint8_t adc_low = 0, adc_high = 0;
uint8_t localAdcValue[2] = {0};
uint8_t adcTrBuffer[2] = {0};
uint8_t adcReady = 0;
uint8_t adcTrFlag = 0;

ISR(ADC_vect)
{
	localAdcValue[1] = ADCL;
	localAdcValue[0] = ADCH;
	
	if(!adcTrFlag) //���� � ������ ������ ������ �� ����������
	{
		adcTrBuffer[1] = localAdcValue[1];
		adcTrBuffer[0] = localAdcValue[0];
	}
	
	//adcReady = 1;
	//adcValue = (adc_high << 8) | adc_low;
}

void ADC_Init(void)		//��� ������� � ����������� "�� ����������"
{
	ADC_CONTROL |= (1<<ADEN)	//�������� ���
				| (1<<ADSC)		//������ ��������������
				| (1<<ADFR)		//����������� ����� ������ ���
				| (1<<ADPS2) | (1<<ADPS1) | (0<<ADPS0) //���������� ������� 125 ��� - ������������ 64
				| (1<<ADIE);	 //���������� ���������� �� ���
				
	ADMUX	|= (1<<REFS1) | (1<<REFS0);/*���������� ��������, ���� ADC0 = PF0. ���� ����� �����-�� ������ �����, �� ��������� 
										*����� �������� MUX4..0
										*/	
}
