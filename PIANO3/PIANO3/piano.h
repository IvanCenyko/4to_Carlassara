#include <util/delay.h>
#include <avr/io.h>


#define C4 60
#define C4S 56

#define D4 53
#define D4S 50

#define E4 47

#define F4 45
#define F4S 42     //resultados del traspaso de onda cuadrada a pulsos

#define G4 40
#define G4S 38

#define A4 35
#define A4S 33

#define B4 32

#define C5 30

#define NOTA(OCR)    OCR0A = OCR; \
                      OCR0B = OCR/2; \
                      TCCR0A |= 1 << COM0B1     //establecer la semi interrupción
                                                     // (se mide en pulsos)


void corchea (unsigned char nota);

void blanca (unsigned char nota);

void negra (unsigned char nota);

unsigned char get_nota (void); //declaramos medicion post interrupción
