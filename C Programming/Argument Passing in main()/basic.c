#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("\nNumber of arguments: %d\n\n", argc);

    for (int i = 0; i < argc; i++)
    {
        printf("Arg: %d = %s\n\n", i, argv[i]);
    }

    return 0;
}