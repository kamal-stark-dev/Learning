#include <stdio.h>
#include "library.h"

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int length = sizeof(arr) / sizeof(arr[0]);

    printf("Array: \n");
    printArray(arr, length);

    swap(&arr[0], &arr[1]);

    printf("Array after swapping index 0 and index 1: \n");
    printArray(arr, length);
}

// use the following command to compile the program:
// gcc -o file_name main.c library.c

/*
OUTPUT:
Array:
1 2 3 4 5 6 7 8 9 10
Array after swapping index 0 and index 1:
2 1 3 4 5 6 7 8 9 10
*/