#include <stdlib.h>
#include <stdio.h>
void mallocAndInit(int *ip){
ip = (int *)malloc (sizeof (int));
*ip = 3;
}
int main (){
int *ip ;
int a = 3;
mallocAndInit (ip);
printf ("%d", *ip);
return 0;
}
