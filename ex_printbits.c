#include <stdio.h>

void print_bits(int num){
  int i;
  for (i = 7; i>=0; i--){
    printf("%d", (num>>i)&1);
  }
  printf("\n");
}

int main(){
  int a = 0x0;
  int b = 0xff;
  int i = 0;
  print_bits(a);
  print_bits(b);
  printf("\n");
  a = 0x1;
  b = 0xfe;
  print_bits(a);
  print_bits(b);
  printf("\n");  
  for (i = 0; i<7; i++){
    a = a<<1;
    print_bits(a);
    b = (~(~b<<1));
    print_bits(b);
    printf("\n");
  }
  return 0;
}
