/*
 * sensor.h
 *
 * Created: 2020-12-10 오전 9:06:28
 *  Author: DSM
 */ 


#ifndef SENSOR_H_
#define SENSOR_H_


void ADC_set() // ADC 설정
{
	ADCSRA = (1 << ADEN); // ADC enable
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // 16Mhz/128 = 125Khz
}

uint16_t ADC_read(uint8_t channel) // channel에 해당하는 ADC값 반환
{
	ADMUX = (1 << REFS0); // ADC0, 5V에 0~1023 설정
	ADMUX |= channel; // ADC핀 설정
	
	ADCSRA |= (1 << ADSC); // ADC 변환 시작
	while(ADCSRA & (1 << ADSC)); // ADC 변환 완료
	
	return ADCW; // Return converted value
}



#endif /* SENSOR_H_ */