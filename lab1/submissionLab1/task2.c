
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void char2binari(char *c, int answer[], int flag, FILE *file );
void char2binari1c(int answer[], FILE *file );
void char2binari1b(int answer[], FILE *file );

int main(int argc, char **argv)
{
    FILE *file =stdout;
    int i;
    int flag = 0;
    for(i = 1; i < argc; i++)
    {

        if(strcmp(argv[i],"-l") ==0)
        {
            flag = 1;
        }
         else if(strcmp(argv[i],"-b") ==0)
        {
            flag = 2;
        }
        else if(strcmp(argv[i],"-o")==0)
        {
            file = fopen(argv[i + 1],"w");
        }
    }

    char c;
    while((c = getchar()) != EOF)
    {
          int answer[8] = {0,0,0,0,0,0,0,0};
          if (c != 10)
          {
              if (flag == 0)
              {
                    fprintf(file, "%d", c);
                    fprintf(file, " ");
              }
              else{
                    char2binari(&c, answer, flag, file);
              }
          }
          else if(c == 10)
          {
              fprintf(file, "\n");
          }
    }
      return 0;
}


void char2binari(char *c, int answer[], int flag, FILE *file )
{
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
            char2binari1b(answer, file);
	}
	else{
            char2binari1c(answer, file);
	}
}
void char2binari1c(int answer[], FILE *file)
{
    int i;
    for( i = 7 ; i >= 0 ; i--)
    {
        fprintf(file, "%d", answer[i]);
    }
    fprintf(file, " ");
}

void char2binari1b(int answer[], FILE *file)
{
    int i;
    for( i = 0 ; i <= 7 ; i++)
    {
        fprintf(file, "%d", answer[i]);
    }
    fprintf(file, " ");
}
