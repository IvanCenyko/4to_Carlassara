#include <util/delay.h>
#include <avr/io.h>


#define C4 196
#define C4S 200

#define D4 203
#define D4S 206

#define E4 209

#define F4 211
#define F4S 214

#define G4 216
#define G4S 218

#define A4 220
#define A4S 222

#define B4 224

#define C5 226

#define NOTA(OCR)    TCNT0 = OCR;  \
                      OCR0A = OCR + (256-OCR)/2


void corchea (unsigned char nota);

void blanca (unsigned char nota);

void negra (unsigned char nota);

unsigned char get_nota (void);