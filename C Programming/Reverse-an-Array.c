#include <stdio.h>

void printArray(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int *reverseArray(int arr[], int length)
{
    for (int i = 0; i < length / 2; i++)
    {
        swap(&arr[i], &arr[length - 1 - i]);
    }
    return arr;
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int length = sizeof(array) / sizeof(array[0]);

    printf("Orignal array: \n");
    printArray(array, length);

    int *rev_arr = reverseArray(array, length);
    printf("Array after reversing: \n");
    printArray(rev_arr, length);

    return 0;
}