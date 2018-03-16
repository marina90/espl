#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int cksum(char *s) {
int sum = 255;
while(*s) {
  sum = sum & *s;
  ++s;
  printf("%d\n", s);
  printf("%s\n", s);
}
return sum;
}


int main(){
  int ans = cksum("01234567");
  printf("%ddfasdf\n", ans);
  ans = ans & 7;
  printf("%d\n", ans);
  return 0;
}
