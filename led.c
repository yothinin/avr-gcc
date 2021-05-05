#include <avr/io.h>
#include <util/delay.h>

int main(void){
  //DDRD  = ~(1<<PD7); //PD7 as input
  DDRB  = 0xff;      //PB0-7 as output.

  while (1){
    if(PIND & (1<<PIN7)){
      if  (PORTB == 0xff){
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
