/*
 * NH_candle.c
 *
 * Created: 2020-12-10 오전 9:05:57
 * Author : DSM
 
 PD0 : DHT11
 
 PF0 : CDS
 PF1 : touch sensor
 
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
#include <string.h>

#include "ADC.h"
#include "DHT11.h"
#include "lcd.h"
#include "uart.h"
#include "RGB.h"

int set_R = 0, set_G = 0, set_B = 0;

int uart_finish=0, uart_i=0, uart_state=0;
char uart_buff[50];

int main(void)
{
    DDRA = 0xFF; // LCD data 핀
	DDRC = 0xFF; // LCD control 핀
	
	DDRB = 0xFF; // RGB LED
	DDRD = 0x00; // DHT
	DDRF = 0x00; // cds, sound
	
	LCD_Init();
	ADC_set();
	pwm_init();
	uart_init(BAUDRATE(9600));
	sei();
	
	int mode = 1; // 모드 저장
	char buff[50]; // LCD 출력 문자열, uart 송신 문자열 저장
	
	int cds_value; // CDS ADC값 저장
	char touch_value; // touch 센서 값 저장
	uint8_t I_RH, D_RH, I_Temp, D_Temp, CheckSum;
	
	int time_cnt=0; // 0.1초마다 cnt++, 2초마다 DHT 센서값을 읽어오기 위해서 사용
	
    while (1) 
    {
		if(uart_finish)
		{
			if(uart_buff[0] == 'S') // S[][][].(red,green,blue)
			{
				set_R = (uart_buff[1]-'0')*100 + (uart_buff[2]-'0')*10 + (uart_buff[3]-'0');
				set_G = (uart_buff[4]-'0')*100 + (uart_buff[5]-'0')*10 + (uart_buff[6]-'0');
				set_B = (uart_buff[7]-'0')*100 + (uart_buff[8]-'0')*10 + (uart_buff[9]-'0');
			}
			uart_finish = 0;
		}
		
		cds_value = ADC_read(0); // cds ADC 값 측정
		touch_value = (PINF & 0x02); // 
		
		if(touch_value == 0x02) {
			mode++;
			_delay_ms(200);
		}
		if(mode > 3) mode = 1;
		
		sprintf(buff, "mode %d", mode); // LCD에 현재 모드 출력
		LCD_setcursor(0, 0);
		LCD_wString(buff);
		
		if(time_cnt >= 200) // 2초마다 DHT센서값 측정
		{
			Request();		 //시작 펄스 신호 보냄
			Response();		 //센서로부터 응답 받음
			I_RH=Receive_data();	 //습도의 정수 부분
			D_RH=Receive_data();	 //습도의 실수 부분
			I_Temp=Receive_data();	 //온도의 정수 부분
			D_Temp=Receive_data();	 //온도의 실수 부분
			CheckSum=Receive_data(); //모든 세그먼트의 체크섬
			
			if ((I_RH + D_RH + I_Temp + D_Temp) != CheckSum) // DHT 센서값 측정 오류
			{
				I_Temp = D_Temp = I_RH = D_RH = -1;
				sprintf(buff, "error");
			}
			else
			{
				sprintf(buff, "%d.%d %d.%d %d  ", I_Temp, D_Temp, I_RH, D_RH, cds_value);
				LCD_setcursor(1, 0);
				LCD_wString(buff);
				
				sprintf(buff, "T%2d.%d H%2d.%d C%4d M%1d", I_Temp, D_Temp, I_RH, D_RH, cds_value, mode); // 온도, 습도, 조도, 모드
				uart_string(buff);
			}
			time_cnt = 0;
		}
		
		if(mode == 1) // 모드 1 RGB LED 출력
		{
			if(I_Temp > 30) pwm_led(255, 0, 0);
			else if(I_Temp > 25) pwm_led(0, 255, 0);
			else pwm_led(0, 0, 255);
		}
		else if(mode == 2) // 모드 2 RGB LED 출력
		{
			if(cds_value > 800) pwm_led(0, 0, 255);
			else if(cds_value > 600) pwm_led(0, 255, 0);
			else pwm_led(255, 0, 0);
		}
		else if(mode == 3) pwm_led(set_R, set_G, set_B); // 모드 3 RGB LED 출력
		
		_delay_ms(10); // 0.01초 딜레이
		time_cnt++;
    }
}
ISR(USART0_RX_vect)
{
	unsigned char buff = UDR0; // UDR0에 레지스터에 데이터가 저장
	
	if(buff == 0x02)
	{
		uart_state = 1; // uart로 데이터 수신 상태
		memset(uart_buff, 0, strlen(uart_buff));
		uart_i = 0;
		return;
	}
	else if(buff == 0x03)
	{
		uart_state = 0;
		uart_finish = 1; // uart로 데이터 수신 완료
	}
	
	if(uart_state)
	{
		uart_buff[uart_i++] = buff;
	}
}
