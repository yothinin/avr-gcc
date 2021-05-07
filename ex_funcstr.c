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
    char dest[9] = "";
	printf("bits = %s\n", print_bits(dest, 0xfe));
	
	return 0;
}
