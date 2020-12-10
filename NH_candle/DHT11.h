/*
 * DHT11.h
 *
 * Created: 2020-12-10 오전 9:09:58
 *  Author: DSM
 */ 


#ifndef DHT11_H_
#define DHT11_H_


#define DHT11_PIN 0
uint8_t c=0, I_RH, D_RH, I_Temp, D_Temp, CheckSum;
void Request()				// ATMega128로 스타트 펄스 전달 & 응답 과정
{
	DDRD |= (1<<DHT11_PIN);
	PORTD &= ~(1<<DHT11_PIN);	// PD6 LOW
	_delay_ms(20);
	PORTD |= (1<<DHT11_PIN);	// PD6 HIGH
}
void Response()				// 온습도 센서로부터 응답
{
	DDRD &= ~(1<<DHT11_PIN); // PD4 LOW
	while(PIND & (1<<DHT11_PIN));
	while((PIND & (1<<DHT11_PIN))==0);
	while(PIND & (1<<DHT11_PIN));
}

uint8_t Receive_data()
{
	for (int q=0; q<8; q++)
	{
		while((PIND & (1<<DHT11_PIN)) == 0); //비트가 0인지 1인지 체크
		_delay_us(30);
		if(PIND & (1<<DHT11_PIN)) //HIGH가 30ms보다 크면
		c = (c<<1)|(0x01);	 //HIGH 상태
		else
		c = (c<<1); //LOW 상태
		while(PIND & (1<<DHT11_PIN));
	}
	return c;
}


#endif /* DHT11_H_ */