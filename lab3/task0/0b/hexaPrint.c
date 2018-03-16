#include <stdio.h>
#include <stdlib.h>


PrintHex(char *buffer, int length)
{
    int i;
    for (i = 0 ; i < length && buffer[i] != NULL ; i++)
    {
         printf("%02X ",buffer[i]);
    }
    printf("\n");
    return 0;
}

int main(int argc, char **argv)
{
    FILE *file;
    char buffer[100];
    file = fopen(argv[0], "r");
    fread(buffer, sizeof(char), 100 ,file);
    PrintHex(buffer, 100);
    return 0;
    fclose(file);
}
