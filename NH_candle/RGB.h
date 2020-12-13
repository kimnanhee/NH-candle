/*
 * RGB.h
 *
 * Created: 2020-12-13 오후 9:35:05
 *  Author: DSM
 */ 


#ifndef RGB_H_
#define RGB_H_


void pwm_init()
{
	// TCCR1n 레지스터의 설정은 OCR1A~C에 영향
	TCCR1A |= (1 << COM1A1) | (1 << COM1B1) | (1 << COM1C1) | (1 << WGM10);
	TCCR1B |= (1 << WGM12) | (1 << CS11);
	
	OCR1A = 0;
	OCR1B = 0;
	OCR1C = 100;
}

void pwm_led(int R, int G, int B)
{
	OCR1A = R;
	OCR1B = G;
	OCR1C = B;
}


#endif /* RGB_H_ */