#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int *arr, int length);

int main()
{
    int *arr = malloc(100 * sizeof(int));

    printf("Malloc Initially: \n");
    printArray(arr, 100);

    for (int i = 0; i < 100; i++)
    {
        arr[i] = 69;
    }
    printf("Malloc After Assignment: \n");
    printArray(arr, 100);

    free(arr);

    int *arr2 = malloc(100 * sizeof(int));

    printf("New Malloc After Freeing Previous One: \n");
    printArray(arr2, 100); // you'll see that the data is still there

    free(arr2);

    int *arr3 = calloc(100, sizeof(int));

    printf("New Calloc: \n");
    printArray(arr3, 100); // all will be 0 now

    free(arr3);

    printf("Comparision between malloc and calloc: \n");

    clock_t tic, toc;
    int *array;

    // test malloc
    tic = clock();
    array = malloc(1000 * sizeof(int));
    toc = clock();
    printf("malloc: %lfs\n", (double)(toc - tic) / CLOCKS_PER_SEC);
    free(array);

    // test calloc
    tic = clock();
    array = calloc(1000, sizeof(int));
    toc = clock();
    printf("calloc: %lfs\n", (double)(toc - tic) / CLOCKS_PER_SEC);
    free(array);

    /*
    Comparision between malloc and calloc:
    malloc: 0.000013s
    calloc: 0.000098s

    calloc is slower as it assigns the values to zero as well
    */

    return 0;
}

void printArray(int *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}