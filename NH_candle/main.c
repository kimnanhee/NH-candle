/*
 * NH_candle.c
 *
 * Created: 2020-12-10 오전 9:05:57
 * Author : DSM
 
 PD0 : DHT11
 PF0 : sound sensor
 
 PB5 : R LED
 PB6 : G LED
 PB7 : B LED
 
 PA : LCD
 PC : LCD
 */ 
#define F_CPU 16000000UL
#define BAUDRATE(x) ((F_CPU/16/x)-1)

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "ADC.h"
#include "DHT11.h"
#include "lcd.h"
#include "uart.h"

int main(void)
{
    DDRA = 0xFF; // LCD 데이터 핀
	DDRC = 0xFF; // LCD 제어 핀
	
	LCD_Init();
	ADC_set();
	uart_init(BAUDRATE(9600));
	sei();
	
    while (1) 
    {
    }
}
ISR(USART0_RX_vect)
{
	unsigned char buff = UDR0; // UDR0에 레지스터에 데이터가 저장
	
	if(buff == 0x02);
	else if(buff == 0x03);
}
