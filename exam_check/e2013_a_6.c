#include <stdio.h>

int main()
{
  int **p;
  ((int)(p + sizeof (int*))) - (int)p;
  return 0;
}
