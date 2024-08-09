// pyramid pattern
//     1
//    232
//   34543
//  4567654
// 567898765

#include <stdio.h>

int height;

void print_row(int row);

int main(void)
{
    do
    {
        printf("height: ");
        scanf("%i", &height);
    } while (height < 0 || height > 5);

    for (int i = 0; i < height; i++)
    {
        print_row(i);
    }
}

void print_row(int row)
{
    int r = row;
    for (int i = row; i < height; i++)
        printf(" ");
    for (int i = 0; i < row; i++)
        printf("%d", ++r);
    printf("%d", ++r);
    for (int i = 0; i < row; i++)
        printf("%d", --r);
    printf("\n");
}