#include <cs50.h>
#include <stdio.h>

void print_row(int bricks, int height);

int main(void)
{
    int height;

    do
    {
        height = get_int("Height? ");
    } while (height < 1 || height > 8);

    for (int i = 1; i <= height; i++)
    {
        print_row(i, height);
    }
}

void print_row(int bricks, int height)
{
    for (int i = height - bricks; i > 0; i--)
    {
        printf(" ");
    }

    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
    printf("\n");
}
