#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

int main(void){
  DDRD  = 0x00;
  PORTD = 0x00;
  DDRB  = 0xff;      //PB0-7 as output.  
  PORTB = 0xff;

  while (1){
    if((PIND&(1<<PIN7)) == (1<<PIN7)){
	  if (PORTB == 0xff)
        PORTB = 0xfe;
        
      _delay_ms(50);        
      PORTB = (PORTB << 1)|0x01;
	  /*
	  int i;
	  for (i = 0; i<8; i++){
        PORTB = ~(1<<i);
		printf("%8x\n", PORTB);
        fflush(stdout);
        _delay_ms(100);
	  }
	  for (i = 7; i>=0; i--){
		PORTB = ~(1<<i);
		_delay_ms(100);
	  }
	  */
    }else{
	  PORTB = 0xff;
	}
  }
  return 0;
}
