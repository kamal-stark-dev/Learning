#include <stdio.h>

void print_row(int bricks, int height);

int main(void)
{
    int height;

    do
    {
        printf("Height? ");
        scanf("%d", &height);
    } while (height < 1 || height > 8);

    for (int i = 0; i < height; i++)
    {
        print_row(i + 1, height);
    }
}

void print_row(int bricks, int height)
{
    for (int i = height - bricks; i > 0; i--)
    {
        printf(" ");
    }

    for (int j = 0; j < bricks; j++)
    {
        printf("#");
    }

    printf("  ");

    for (int k = 0; k < bricks; k++)
    {
        printf("#");
    }
    printf("\n");
}
