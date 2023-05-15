#include <avr/io.h>
#include "LCD.h"
#include "ADC.h"
#include <util/delay.h>



int main (void) {
    
    ADC_Init ();
    LCD_Init ();

    while (1) {

        LCD_Clear ();
        _delay_ms (2);
        LCD_WriteFloat (Temp_Mes());

    }
    return 0;
}