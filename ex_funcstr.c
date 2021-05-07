#include <stdio.h>
#include <string.h>

char *print_bits(char *dest, int num){
  int i;
  char t[2];
  
  for (i = 7; i>=0; i--){
    sprintf(t, "%d", (num>>i)&1);
    strcat(dest, t);
  }

  return dest;
}

int main(){
  int i, num = 0xff;
  
  for (i = 0; i<8; i++){
    num = (num == 0xff)?num<<1:num<<1|1;
    char dest[9] = "";
	printf("%s\n", print_bits(dest, num));
  }
  
  return 0;
}

