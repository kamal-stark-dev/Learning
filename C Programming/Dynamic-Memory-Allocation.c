#include <stdio.h>
#include <stdlib.h>

void printArray(int *arr, int length);
void modifyAndPrintArray(int *arr, int length);

int main()
{
    /*
    STACK VS HEAP

    Stack - ordered and all data in it has a fixed size that doesn't changes. The memory is freed when the functions return they are removed.

    Heap - Dynamically allocated memory. The size allocated can be changed.

    We create arrays with specified length from before but what if we need to allocate memory at run time??

    DMA - <requires the stdlib header file>
        1. malloc
        2. calloc
        3. realloc
        4. free
    */

    // MALLOC

    int *ptr;

    ptr = malloc(sizeof(int) * 10); // allocate space for 10 integers, we use sizeof function because the size of int can be different based on the systems

    printf("Malloc: \n");
    modifyAndPrintArray(ptr, 10);

    free(ptr); // you need to free the memory by yourself as it's not automatic like in stack

    // if we forget to free up the space then it can cause MEMORY LEAKS

    // MANUAL MEMORY MANAGEMENT - With great powers comes great responsiblities.

    // CALLOC

    int *a = calloc(10, sizeof(int));

    printf("Calloc: \n");
    modifyAndPrintArray(a, 10);

    free(a);

    // in malloc() when we free a memory the values are still there in the memory like, to prevent it you can use calloc() which assigns then to 0.

    // ex: let's say you have stored some password or sensitive information using malloc so even after freeing the memory the password will still be there.

    // REALLOC

    int *arr = calloc(10, sizeof(int)); // 40 bytes in 64-bit system

    printf("Realloc: \n");
    modifyAndPrintArray(arr, 10);

    // now if you want more space you can use realloc

    arr = realloc(arr, sizeof(int) * 15); // reallocated to 60 bytes

    for (int i = 10; i < 15; i++)
    {
        arr[i] = 69;
    }

    printArray(arr, 15);

    free(arr);

    return 0;
}

void modifyAndPrintArray(int *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        arr[i] = i + 1;
    }
    printArray(arr, length);
}

void printArray(int *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/*
GARBAGE COLLECTOR -
    Languages like Python and Java use what's called a garbage collector, which regularly checks the heap for blocks of memory that are no longer being used so it can free them.
*/