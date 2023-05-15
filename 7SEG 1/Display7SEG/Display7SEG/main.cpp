/*
 * Display7SEG.cpp
 *
 * Created: 4/7/2020 18:09:51
 * Author : iván
 */ 
#include <avr/io.h>
#include <util/delay.h>

void _7S_print (char num);

void _7S_print(char num) {
	
	switch (num) {
		case 0: PORTB = 64;
		break;
		case 1: PORTB = 121;
		break;
		case 2: PORTB = 36;
		break;
		case 3:PORTB = 48;
		break;
		case 4: PORTB = 25;
		break;
		case 5: PORTB = 18;
		break;
		case 6: PORTB = 2;
		break;
		case 7: PORTB = 120;
		break;
		case 8: PORTB = 0;
		break;
		case 9: PORTB = 16;
		break;
		
	}
}




int main(void)
{

 DDRB = 255;
 DDRD = 0;
 PORTB = 255;
  
  unsigned char dnum = 0;
  
  while (1)
  {
	  
	if ( PIND & ( 1 << PD0 ) ) {
		dnum++ ;
	}
	
	if ( PIND & ( 1 << PD1 ) ) {
		dnum-- ;		
	}

	
	if ( PIND & ( 1 << PD2 ) )  {
		dnum = 0;
	}

_7S_print (dnum);

    if ( dnum > 9 ) {
	    dnum = 9;
    }
    if ( dnum < 0 ) {
	    dnum = 0;
    }
 
   _delay_ms (200);
 }
   

return 0;
}