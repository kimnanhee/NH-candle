/*
 * NH_candle.c
 *
 * Created: 2020-12-10 오전 9:05:57
 * Author : DSM
 
 PD0 : DHT11
 
 PF0 : CDS
 PF1 : sound sensor
 
 PB5 : R LED
 PB6 : G LED
 PB7 : B LED
 
 PA : LCD data pins
 PC : LCD control pins
 
 mode 1 : 온도에 따라 LED 조절
 mode 2 : 조도에 따라 LED 조절
 mode 3 : 사용자 설정에 따른 LED 조절
 */  
#define F_CPU 16000000UL
#define BAUDRATE(x) ((F_CPU/16/x)-1)

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>

#include "ADC.h"
#include "DHT11.h"
#include "lcd.h"
#include "uart.h"

int main(void)
{
    DDRA = 0xFF; // LCD data 핀
	DDRC = 0xFF; // LCD control 핀
	
	DDRB = 0xFF; // RGB LED
	DDRD = 0x00; // DHT
	DDRF = 0x00; // cds, sound
	
	LCD_Init();
	ADC_set();
	uart_init(BAUDRATE(9600));
	sei();
	
	int mode = 1;
	char buff[50];
	
	int cds_value; // CDS ADC값 저장
	char sound_value; 
	uint8_t I_RH, D_RH, I_Temp, D_Temp, CheckSum;
	
    while (1) 
    {
		cds_value = ADC_read(0);
		sound_value = (PINF & 0x02);
		
		if(sound_value == 0x00) mode++;
		if(mode > 3) mode = 1;
		
		Request();		 //시작 펄스 신호 보냄
		Response();		 //센서로부터 응답 받음
		I_RH=Receive_data();	 //습도의 정수 부분
		D_RH=Receive_data();	 //습도의 실수 부분
		I_Temp=Receive_data();	 //온도의 정수 부분
		D_Temp=Receive_data();	 //온도의 실수 부분
		CheckSum=Receive_data(); //모든 세그먼트의 체크섬
		
		if ((I_RH + D_RH + I_Temp + D_Temp) != CheckSum) sprintf(buff, "error");
		else
		{
			sprintf("T%2d.%d H%2d.%d C%4d M%1d", I_Temp, D_Temp, I_RH, D_RH, cds_value, mode);
			uart_string(buff);
		}
		_delay_ms(3000); // 2초 이상 쉬어야 센서에서 맞는 값을 읽어올 수 있다
    }
}
ISR(USART0_RX_vect)
{
	unsigned char buff = UDR0; // UDR0에 레지스터에 데이터가 저장
	
	if(buff == 0x02);
	else if(buff == 0x03);
}
