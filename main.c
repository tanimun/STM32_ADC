#include "stm32f10x.h"                  // Device header
#include<stdio.h>

void USART2_write(int ch);

void delayMs(int delay);
int main(void)
{
	int analogValue;
	
	RCC->APB2ENR |= 0x0204;
	RCC->APB1ENR= 0x20000;
	GPIOA-> CRL = 0x00004A00;
	RCC->CFGR = 0x8000;
	USART2->CR1=0x200C;
	USART2->BRR = 0x0EA6;
	
	ADC1->SMPR2 = 0x0038;
	ADC1->SQR3 = 0x0001;
	ADC1->CR2 = 0x0003;
	ADC1->CR2 = 0x0003;
	ADC1->CR2 = 0x0007;
	ADC1->CR2 = 0x4000000;
	while(1)
	{
		ADC1->CR2|=0x00400000;
		while(!(ADC1->SR&2)){}
	
		analogValue = ADC1->DR;
		printf("Analog Value is:%d", analogValue);
		printf("\r\n");
		delayMs(50);
		}
	}


void USART2_write(int ch){

	while(!(USART2 ->SR & 0x0080)){}
		USART2 ->DR = (ch & 0xFF);

}

void delayMs(int delay)
{
	int i;
	for(; delay>0;delay--)
	{
		for(i = 0; i<3195; i++);
	}
}
