#include <avr/io.h>
#include <util/delay.h>

int main(void){
  //unsigned int i = 0;
  //DDRD  = ~(1<<PD7); //PD7 as input
  //PORTD = 0x00;
  DDRB  = 0xff;      //PB0-7 as output.
  PORTB = 0xff;

  while (1){
    if(PIND & (1<<PIN7)){
      if  (PORTB == 0xff){
        PORTB = 0xfe;
        _delay_ms(100);
      }
      PORTB = ~(~PORTB<<1);
      _delay_ms(100);
    }else{
      PORTB = 0xff;
    }
  }
  return 0;
}
