// Hollow Star Pyramid

//     *
//    * *
//   *   *
//  *     *
// *********

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

    for (int i = 0; i < height - 1; i++)
        print_row(i, pattern);

    for (int i = 0; i < height * 2 - 1; i++)
        printf("%c", pattern);
}

void print_row(int row, char pattern)
{
    // print space
    for (int i = row; i < height - 1; i++)
        printf(" ");

    // print pattern
    for (int i = 0; i <= row * 2; i++)
    {
        if (i == 0 || i == row * 2)
            printf("%c", pattern);
        else
            printf(" ");
    }
    // print new line
    printf("\n");
}