#include <avr/io.h>
#include <util/delay.h>

int main(void){
  DDRD  = 0x00;
  PORTD = 0x00;
  
  DDRB  = 0xff;      //PB0-7 as output.  
  PORTB = 0xff;

  while (1){
    if((PIND&(1<<PIN7)) == (1<<PIN7)){
      PORTB = (PORTB == 0xff)?(PORTB <<1):(PORTB<<1)|1;          
      _delay_ms(50);        
    }else{
      PORTB = 0xff;
    }
  }
  
  return 0;
}


