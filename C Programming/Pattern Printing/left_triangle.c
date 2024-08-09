// pyramid pattern

// *
// **
// ***
// ****
// *****

#include <stdio.h>

void print_row(int row, char pattern);

int main(void)
{
    int height;
    do
    {
        printf("height: ");
        scanf("%i", &height);
    } while (height < 0);

    char pattern;
    printf("pattern: ");
    scanf(" %c", &pattern);

    for (int i = 0; i < height; i++)
    {
        print_row(i, pattern);
    }
}

void print_row(int row, char pattern)
{
    for (int i = 0; i <= row; i++)
        printf("%c", pattern);
    printf("\n");
}