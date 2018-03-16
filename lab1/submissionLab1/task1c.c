#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void char2binari(char *c, int answer[], int flag);
void char2binari1c(int answer[]);
void char2binari1b(int answer[]);

int main(int argc, char **argv)
{
    char c;
    while((c = getchar())!= EOF)
    {
        if (argc != 1)
        {
            int answer[8] = {0,0,0,0,0,0,0,0};
            int flag = 0;
            if (c != 10)
            {
                if((strcmp(argv[1], "-l") == 0))
                {
                    flag = 1;
                }
                if((strcmp(argv[1], "-b") == 0))
                {
                    flag = 2;
                }
                char2binari(&c, answer, flag);
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

void char2binari(char *c, int answer[], int flag){
	int i;
        int newNum = *c;
	for (i = 7; i >= 0 ; i--)
	{
            int temp = newNum & 1;
            answer[i] = temp;
            newNum = newNum >> 1;

	}
	if(flag == 1)
	{
	  char2binari1b(answer);
	}
	else{
    char2binari1c(answer);
	}
}
void char2binari1c(int answer[]){
	int i;
  for( i = 7 ; i >= 0 ; i--)
  {
    printf("%d", answer[i]);
  }
  printf(" ");

}

void char2binari1b(int answer[]){
	int i;
  for( i = 0 ; i <= 7 ; i++)
  {
    printf("%d", answer[i]);
  }
    printf(" ");

}
