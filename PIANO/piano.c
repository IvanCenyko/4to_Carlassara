#include "piano.h"


void corchea (unsigned char nota) {
    NOTA(nota);
    _delay_ms (375);
}

void negra (unsigned char nota) {
    NOTA(nota);
    _delay_ms (750);
}

void blanca (unsigned char nota) {
    NOTA(nota);
    _delay_ms (1500);
}

unsigned char get_nota (void){
    switch (OCR0A) {
        case C4 + (256-C4)/2: return C4;
        break;
        case C4S + (256-C4S)/2: return C4S;
        break;
        case D4 + (256-D4)/2: return D4;
        break;
        case D4S + (256-D4S)/2: return D4S;
        break;
        case E4 + (256-E4)/2: return E4;
        break;
        case F4 + (256-F4)/2: return F4;
        break;
        case F4S + (256-F4S)/2: return F4S;
        break;
        case G4 + (256-G4)/2: return G4;
        break;
        case G4S + (256-G4S)/2: return G4S;
        break;
        case A4 + (256-A4)/2: return A4;
        break;
        case A4S + (256-A4S)/2: return A4S;
        break;
        case B4 + (256-B4)/2: return B4;
        break;
        case C5 + (256-C5)/2: return C5;
        break;
    }
}