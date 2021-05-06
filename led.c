#include <avr/io.h>
#include <util/delay.h>

int main(void){
  DDRD  = 0x00;
  PORTD = 0x00;
  DDRB  = 0xff;      //PB0-7 as output.
  
  int pind_status;
  
  PORTB = 0xff;

  while (1){
    pind_status = PIND&(1<<PIN7);
    if(pind_status == 0x80){
	  int i;
	  for (i = 0; i<8; i++){
        PORTB = ~(1<<i);
        _delay_ms(100);
	  }
	  for (i = 7; i>=0; i--){
		PORTB = ~(1<<i);
		_delay_ms(100);
	  }
    }else{
	  PORTB = 0xff;
	}
  }
  return 0;
}
