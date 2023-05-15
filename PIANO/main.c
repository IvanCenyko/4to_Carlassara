#define F_CPU 1000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "piano.h"



int main (void) {
    
    TCCR0A = 0x83;
    TCCR0B = 0X03;
    TIMSK0 = 0X01;

    sei ();

    while (1) {
        
    negra (C4);
    OCR0A = 0;
    _delay_ms (50);
    negra (C4);
    OCR0A = 0;
    _delay_ms (50);
    negra (G4);
    OCR0A = 0;
    _delay_ms (50);
    negra (G4);
    OCR0A = 0;
    _delay_ms (50);
    negra (A4);
    OCR0A = 0;
    _delay_ms (50);
    negra (A4);
    OCR0A = 0;
    _delay_ms (50);
    blanca (G4); 
    OCR0A = 0;
    _delay_ms (50); 
    negra (F4);
    OCR0A = 0;
    _delay_ms (50);
    negra (F4);
    OCR0A = 0;
    _delay_ms (50);
    negra (E4);
    OCR0A = 0;
    _delay_ms (50);         
    negra (E4);
    OCR0A = 0;
    _delay_ms (50);        
    negra (D4);
    OCR0A = 0;
    _delay_ms (50);
    negra (D4);
    OCR0A = 0;
    _delay_ms (50);
    blanca (C4); 
    OCR0A = 0;
    _delay_ms (50); 
    negra (D4);
    OCR0A = 0;
    _delay_ms (50);    


    }

    return 0;

}


ISR (TIMER0_OVF_vect) {

    switch (get_nota()) {
        case C4: NOTA(C4);
        break;
        case C4S: NOTA(C4S);
        break;
        case D4: NOTA(D4);
        break;
        case D4S: NOTA(D4S);
        break;
        case E4: NOTA(E4);
        break;
        case F4: NOTA(F4);
        break;
        case F4S: NOTA(F4S);
        break;
        case G4: NOTA(G4);
        break;
        case G4S: NOTA(G4S);
        break;
        case A4: NOTA(A4);
        break;
        case A4S: NOTA(A4S);
        break;
        case B4: NOTA(B4);
        break;
        case C5: NOTA(C5);
        break;
    }   

}