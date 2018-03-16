#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	int iarray[3];
	char carray[3];
	int i;
	for(i=0;i<3;i++)
	{
		 printf("- iarray: %p\n",&iarray[i]);
   		 printf("- carray: %p\n",&carray[i]);	
	}
        printf("- iarray: %p\n",&iarray);
        printf("- iarray: %p\n",&iarray+1);
        printf("- carray: %p\n",&carray);
        printf("- carray: %p\n",&carray+1);
	return 0;
}