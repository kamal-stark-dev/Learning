// print an inverted pyramid
// *******
//  *****
//   ***
//    *

#include <stdio.h>

int height;

void print_row(int row, char pattern);

int main(void)
{
    do
    {
        printf("height: ");
        scanf("%i", &height);
    } while (height < 0);

    char pattern;
    printf("pattern: ");
    scanf(" %c", &pattern);

    printf("\n");
    for (int i = 0; i < height; i++)
    {
        print_row(i, pattern);
    }
}

void print_row(int row, char pattern)
{
    for (int i = 0; i < row; i++)
        printf(" ");
    for (int i = 0; i < height - row - 1; i++)
        printf("%c", pattern);
    printf("%c", pattern);
    for (int i = 0; i < height - row - 1; i++)
        printf("%c", pattern);
    printf("\n");
}