#include <stdio.h>
#include <stdlib.h> // atoi function - ASCII to integer

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <start> <end>\n", argv[0]);
        exit(1);
    }

    int start, end;

    start = atoi(argv[1]);
    end = atoi(argv[2]);

    for (int i = start; i <= end; i++)
    {
        printf("%d\n", i);
    }

    return 0;
}