#include <stdio.h>
#include <string.h>

int foo() {
char str1[] = "tmp";
char str2[] = "tmp";
str1[0] = 'e';
*str2 = "emp";
return strcmp(str1,str2);
}

/*int foo() {
    char *s1 = "espl121";
    char *s2 = s1;
    s1[5] = '1';
    return strcmp(s1, s2);
}*/

int main(){
  printf("%d\n", foo());
  return 0;
}
