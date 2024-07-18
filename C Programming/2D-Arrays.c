#include <stdio.h>

#define ROWS 2
#define COLS 3

#define P 2
#define Q 3
#define R 4

void matrixMultiplication(int a[P][Q], int b[Q][R]);

int main(void)
{
    // 2D array with 2 rows and 3 columns
    int arr[ROWS][COLS] = {{1, 2, 3},
                           {4, 5, 6}};

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

    int arr2[ROWS][COLS] = {9, 8, 7, 6, 5, 4}; // this will also work the same as the compiler knows the number of rows and columns

    // taking 2d array input

    int arr3[ROWS][COLS];

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("Enter arr[%d][%d]: ", i, j);
            scanf("%d", &arr3[i][j]);
        }
    }

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%d\t", arr3[i][j]);
        }
        printf("\n");
    }

    int A[P][Q] = {1, 2, 3, 4, 5, 6};
    int B[Q][R] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    matrixMultiplication(A, B);

    return 0;
}

void matrixMultiplication(int a[P][Q], int b[Q][R])
{
    int res[P][R];

    for (int i = 0; i < P; i++)
    {
        for (int j = 0; j < R; j++)
        {
            res[i][j] = 0;
        }
    }

    for (int i = 0; i < P; i++)
    {
        for (int j = 0; j < R; j++)
        {
            for (int k = 0; k < Q; k++)
            {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    for (int i = 0; i < P; i++)
    {
        for (int j = 0; j < R; j++)
        {
            printf("C[%d][%d]: %d\t", i, j, res[i][j]);
        }
        printf("\n");
    }
}