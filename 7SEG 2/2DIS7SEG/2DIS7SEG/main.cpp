
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

unsigned char dnum = 0;
unsigned char lnum = 0;


int main(void)
{

DDRB = 255;
DDRD = 255;
PORTB = 64;
PORTD = 64;

TCNT1 = 49911;
TCCR1B = 0X03;
TIMSK1 = 0X01;

sei();

while (1)
{
switch (dnum) {
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



switch (lnum) {
	case 0: PORTD = 64;
	break;
	case 1: PORTD = 121;
	break;
	case 2: PORTD = 36;
	break;
	case 3:PORTD = 48;
	break;
	case 4: PORTD = 25;
	break;
	case 5: PORTD = 18;
	break;
	case 6: PORTD = 2;
	break;

}
}


return 0;
} 


ISR (TIMER1_OVF_vect) {
	TCNT1 = 49911;
	
    dnum++;
	
	 if ( dnum > 9 ) {
		 dnum = 0;
		 lnum++;
	 }
	 
	 if ( lnum > 5 ) {
		 lnum = 0;
		 dnum = 0;
	 }

	                                                                                                                                                                                                                                                                                                                                                                                                                                    }