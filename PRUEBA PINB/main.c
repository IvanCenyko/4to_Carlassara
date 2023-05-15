#include <avr/io.h>
#include "LCD.h"
#include <util/delay.h>

int main (void) {

    LCD_Init ();
    DDRB = 0;


    while (1) {

        LCD_Clear ();
        _delay_ms (2);
        LCD_WriteFloat (PINB);

    }    
}