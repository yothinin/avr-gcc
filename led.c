#include <avr/io.h>
#include <util/delay.h>

int main(void){
  DDRD  = 0x00;
  PORTD = 0x00;
  DDRB  = 0xff;      //PB0-7 as output.
  
  int pind_status;
  

  while (1){
    pind_status = PIND&(1<<PIN7);
    if(pind_status == 0x80){ 
      if (PORTB == 0xff){
        PORTB = (PORTB<<1);
        _delay_ms(100);
      }
      //PORTB = ~(~PORTB<<1);
      //PORTB = (PORTB<<1)+1;
      PORTB = (PORTB<<1)|0x01;
      _delay_ms(100);
    }else{
      PORTB = 0xff;
    }
  }
  return 0;
}
