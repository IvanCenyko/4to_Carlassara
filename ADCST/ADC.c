#include "ADC.h"
#include <avr/io.h>


void ADC_Init (void) {
    ADMUX  =  0b11100000;
    ADCSRA =  0b10000000;
    DIDR0  =    1 << PC0;
}

int ADC_WorkRes (void) {
    ADCSRA |= 1 << ADSC;
    while (!(ADCSRA & (1 << ADIF)));
    ADCSRA |= 1 << ADIF;
    
    adc = ADCL >> 6;
    adc += (ADCH << 2);
    return adc;
}

float Temp_Mes (void) {
   return ADC_WorkRes() * 1.1 / 1023 * 100;
}