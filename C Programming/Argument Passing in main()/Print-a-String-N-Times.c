#include <stdio.h>
#include <stdlib.h>

int main(int agrc, char *argv[])
{
    if (agrc != 3)
    {
        printf("\nInvalid number of arguments!!\n");
        printf("\nUsage: <file-name.exe> <string> <length>\nExample: ./a ABC 5\n\n");
        return 1;
    }

    int len = atoi(argv[2]);

    for (int i = 0; i < len; i++)
    {
        printf("%s\n", argv[1]);
    }

    return 0;
}