#define F_CPU 8000000UL			/* Define frequency here its 8MHz */
#include <avr/io.h>
#include <util/delay.h>

int main(){
  DDRB  = 0xff; 	//Set all DDRB to output.
  PORTB = 0xff;		//Set all PORTB to HIGH, LED's off.
  DDRD  = 0Xfe;		//Set PIND7 to input

  while(1){
    if (PIND & (1<<PD7)){
      PORTB &= ~(1<<PB0);	//11111111 & 11111110 = 11111110 -> On
				//or PORTB = 0xfe;
    }else{
      PORTB |= (1<<PB0);	//11111110 | 00000001 = 11111111 -> Off
    				//or PORTB = 0xff;
    }
  }
}
