#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void char2binari(char * c, int answer[]);

int main(int argc, char **argv)
{
    
    char c;
    while(c != EOF)
    {
       	c = getchar();
        if (argc != 1)
        {
            if((strcmp(argv[1], "-l") == 0))
            {
                int answer[8] = {0,0,0,0,0,0,0,0};
                if(c != 10)
                {
                 char2binari(&c, answer); 
                 printf(" ");
                }
            }
        }
        
        else if (c != 10)
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


void char2binari(char *c, int answer[]){
	int i;
        int newNum = *c;
	for (i = 7; i >= 0 ; i--)
	{
            int temp = newNum & 1;
            answer[i] = temp;
            newNum = newNum >> 1;
            
	}
        for( i = 0 ; i < 8 ; i++)
        {
            printf("%d", answer[i]);
        }
	
}



