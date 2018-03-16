#include<stdio.h>
#include<string.h>
int main(){
char strs[] = "What will be printed";
char *str1;
char *str2;
strs[5] = '\0';
str1 = strs;
strcpy(str2,str1);
printf("%s\n", str2);
return 0;
}
