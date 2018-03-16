#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void string_printer(char* str, void (*f) (char));
void string_reader(char* s);
void echo_printer(char c); /* task 0 from lab1
 - prints c to the standard output*/
void ascii_printer(char c); /* task 1a from lab1
 - convert a char to its ascii code and print it to the standard output*/
void binary_printer(char c); /* task 1c from lab1
 - convert a char to its ascii code in binary (most to least representation)
  and print it to the standard output*/
void char2binari1c(int answer[]);

struct fun_desc {
  char *name;
  void (*fun)(char c);
};

void string_printer(char* str, void (*f) (char)){
  int i;
  for(i = 0; i < strlen(str) ; i++)
  {
    if(str[i] != 10)
    {
        f(str[i]);
        printf(" ");
    }
  }
  printf("\n");
}

void string_reader(char* s){
   fgets(s , 10 , stdin);
}

void echo_printer(char c)
{
  if(c != 10)
  {
    printf("%c",c);
  }
}

void ascii_printer(char c)
{
  if(c != 10)
  {
    printf("%d", c);
    printf(" ");
  }
  else{
    printf("\n");
  }

}
void binary_printer(char c)
{
  int answer[8] = {0,0,0,0,0,0,0,0};
  int i;
  int newNum = c;
	for (i = 7; i >= 0 ; i--)
	{
            int temp = newNum & 1;
            answer[i] = temp;
            newNum = newNum >> 1;

	}
  char2binari1c(answer);
}

void char2binari1c(int answer[]){
	int i;
  for( i = 7 ; i >= 0 ; i--)
  {
    printf("%d", answer[i]);
  }
  printf(" ");
}



int main(int argc, char **argv){
  char s[10];
  printf("Please enter a string (0<size<=10):\n");
  string_reader(s);
  printf("Please choose printer type:\n");
  printf("0) echo printer\n");
  printf("1) ascii printer\n");
  printf("2) binary printer\n");
  printf("\n");
  char answer;
  printf("option: ");
  struct fun_desc menu[] = {{"echo", echo_printer},{"ascii", ascii_printer},{"binary", binary_printer}};
  while((answer = getchar())!= EOF)
  {
    if(answer != 10)
    {
        int i = answer - '0';

        if((i == 0)||(i == 1)||(i == 2))
        {
            string_printer(s, menu[i].fun);
        }
        else{
            printf("undefine!!\n");
        }
        printf("option:");

    }
  }
  printf("DONE\n");
    return 0;
}
