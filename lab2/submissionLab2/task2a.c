#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void string_printer(char* str, void (*f) (char));
void string_reader(char* s);
void echo_printer(char c); /* task 0 from lab1 - prints c to the standard output*/
void ascii_printer(char c); /* task 1a from lab1 - convert a char to its ascii code and print it to the standard output*/
void binary_printer(char c); /* task 1c from lab1 - convert a char to its ascii code in binary (most to least representation) and print it to the standard output*/
void char2binari1c(int answer[]);


void string_printer(char* str, void (*f) (char)){
  /* TODO: Complete during task 2.b */
}

void string_reader(char* s){
  /* TODO: Complete during task 2.c*/
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
  printf("task2a:\n");
  char a[1] = {"a"};
  echo_printer(a[0]);
  ascii_printer(a[0]);
  binary_printer(a[0]);
  return 0;
}
