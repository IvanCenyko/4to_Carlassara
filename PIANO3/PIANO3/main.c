#define F_CPU 1000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "piano.h"

int main (void) {
    
    TCCR0A = 0x23; //interruptor
    TCCR0B = 0x0B;
    DDRD |= 1 << PD5;
   //TIMSK0 = 0x01;

    sei ();

    PCICR = 0b00000011;   // PCINT0 activada (Interrupciones en todo el Puerto B)
    PCMSK0 = 0xFF;  // interrupcion en PB0
    PCMSK1 = 0b00011111;  // "" PC0
    while (1) {      
        
    }

    return 0;

}

ISR (PCINT0_vect) { //interrupción en PB
    switch (PINB) {
        case 0b00000001: NOTA(C4);
        break;
        case 0b00000010: NOTA(C4S);
        break;
        case 0b00000100: NOTA(D4);
        break;
        case 0b00001000: NOTA(D4S);
        break;
        case 0b00010000: NOTA(E4);
        break;
        case 0b00100000: NOTA(F4);
        break;
        case 0b01000000: NOTA(F4S);
        break;  
        case 0b10000000: NOTA(G4);
        break;
        default: TCCR0A &= ~(1 << COM0B1);
        break;
    }

}

ISR (PCINT1_vect) { //interrupción en PC
    switch (PINC) {
        case 0b01000001: NOTA(G4S);
        break;
        case 0b01000010: NOTA(A4);
        break;
        case 0b01000100: NOTA(A4S);
        break;
        case 0b01001000: NOTA(B4);
        break;
        default: NOTA(0);
        break;
    }

}


/* ISR (TIMER0_OVF_vect) { //interrupción general

    switch (get_nota()) { //reubicar la nota después de la interrupción
    
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
} */