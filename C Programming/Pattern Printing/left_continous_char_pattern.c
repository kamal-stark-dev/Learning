// character pattern
// A
// B C
// C D E
// D E F G
// E F G H I

#include <stdio.h>

int height;

void print_row(int row);

int main(void)
{
    do
    {
        printf("height: ");
        scanf("%i", &height);
    } while (height < 0);

    for (int i = 0; i < height; i++)
    {
        print_row(i);
    }
}

void print_row(int row)
{
    char c = 'A';
    for (int i = 0; i <= row; i++)
        printf("%c ", c + row + i);
    printf("\n");
}