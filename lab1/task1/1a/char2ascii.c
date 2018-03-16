#include <stdio.h>

int main()
{
    char c;
    while(c != EOF)
    {
       	c = getchar();
        if(c != 10)
        {   
            printf("%d", c);
            printf(" ");	
        }
        if(c == 10)
        {
            printf("\n");
        }
            
    }
      return 0;
}




