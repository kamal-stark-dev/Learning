#include <stdio.h>

// Linear Search Function
int linearSearch(int arr[], int key, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length = sizeof(arr) / sizeof(arr[0]);

    int key = 4;

    int key_index = linearSearch(arr, key, length);

    if (key_index == -1)
    {
        printf("%d is not present in the array.", key);
    }
    else
    {
        printf("Element %d is present at the index %d.", key, key_index);
    }
}

/*
TIME COMPLEXITY: O(n)

INPUT 1:
key = 4
OUTPUT 1:
Element 4 is present at the index 3.

INPUT 2:
key = 10
OUTPUT 2:
10 is not present in the array.

ITERATION:
i = 0, arr[0] = 1, key != 1
i = 1, arr[1] = 2, key != 2
i = 2, arr[2] = 3, key != 3
i = 3, arr[3] = 4, key == 4
Element 4 is present at the index 3.
*/