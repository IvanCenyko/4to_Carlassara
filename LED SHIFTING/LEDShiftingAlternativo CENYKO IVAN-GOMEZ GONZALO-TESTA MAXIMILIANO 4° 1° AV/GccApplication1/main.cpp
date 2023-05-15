#include <avr/io.h>
#include <util/delay.h>
int i = 0;

int main(void)
{
	DDRD = 255;
	DDRB = 0;
	PORTD = 255;

	while (1)
	{
		if ( PINB & ( 1 << PB0 ) ) {
		 PORTD = ~ (1 << i);
		 _delay_ms (200);
		 i = i + 1;
		 if ( i > 7 ) {
			 i = 0;
		 }
		}
		if (PINB & ( 1 << PB1 ) ) {
			i = i - 1;
			if ( i < 0 ) {
				i = 7;
			}
			PORTD = ~ ( 1 << i );
			_delay_ms (200);
		}
	}
	return 0;
}

