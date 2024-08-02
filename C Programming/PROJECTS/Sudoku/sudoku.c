#include <stdio.h>

int sudoku[9][9] = {
    {1, 2, 3, 4, 5, 6, 7, 8, 9},
    {1, 2, 3, 4, 5, 6, 7, 8, 9},
    {1, 2, 3, 4, 5, 6, 7, 8, 9},
    {1, 2, 3, 4, 5, 6, 7, 8, 9},
    {1, 2, 3, 4, 5, 6, 7, 8, 9},
    {1, 2, 3, 4, 5, 6, 7, 8, 9},
    {1, 2, 3, 4, 5, 6, 7, 8, 9},
    {1, 2, 3, 4, 5, 6, 7, 8, 9},
    {1, 2, 3, 4, 5, 6, 7, 8, 9}};

void input(int *n, char name);
int block_check(int b);
void find_block_data(int block_number);

int arr[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

int main()
{

    int a = 0, b = 0;
    int block = 0;

    // take user inputs
    input(&a, 'a');
    input(&b, 'b');

    // find block number
    if (a == 1 || a == 2 || a == 3)
        block = block_check(b);
    else if (a == 4 || a == 5 || a == 6)
        block = block_check(b) + 3;
    else
        block = block_check(b) + 6;

    printf("BLOCK: %d\n", block);

    // find the data in the block
    find_block_data(block);

    return 0;
}

// takes user's input till it's an integer between 1 and 9 inclusive
void input(int *n, char name)
{
    do
    {
        printf("%c (1-9): ", name);
        scanf("%d", n);
    } while (*n > 9 || *n < 1);
}

// used in block number finding
int block_check(int b)
{
    if (b == 1 || b == 2 || b == 3)
        return 1;
    else if (b == 4 || b == 5 || b == 6)
        return 2;
    else
        return 3;
    return -1;
}

// currently prints the block information
void find_block_data(int block_number)
{
    int d[3];
    switch (block_number)
    {
    case 1:
    case 4:
    case 7:
        d[0] = 0, d[1] = 1, d[2] = 2;
        break;
    case 2:
    case 5:
    case 8:
        d[0] = 3, d[1] = 4, d[2] = 5;
        break;
    case 3:
    case 6:
    case 9:
        d[0] = 6, d[1] = 7, d[2] = 8;
        break;
    }

    int e[3] = {0, 0, 0};
    switch (block_number)
    {
    case 1:
    case 2:
    case 3:
        e[0] = 0, d[1] = 1, d[2] = 2;
        break;
    case 4:
    case 5:
    case 6:
        e[0] = 3, d[1] = 4, d[2] = 5;
        break;
    case 7:
    case 8:
    case 9:
        e[0] = 6, d[1] = 7, d[2] = 8;
        break;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", sudoku[e[i]][d[j]]);
        }
        printf("\n");
    }

    /*
    1, 2, 3 -> 123
    1 - 123
    2 - 456
    3 - 789

    4, 5, 6 -> 456
    4 - 123
    5 - 456
    6 - 789

    7, 8, 9 -> 789
    7 - 123
    8 - 456
    9 - 789
    */
}
