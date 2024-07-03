#include <stdio.h>

// Binary Search Funtion
int binarySearch(int arr[], int key, int length)
{
    int left = 0;
    int right = length - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (key == arr[mid])
        {
            return mid;
        }
        else if (key > arr[mid])
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

int main()
{
    // note for binary search array should be sorted
    int arr[] = {1, 2, 4, 5, 6, 8, 10};
    int length = sizeof(arr) / sizeof(arr[0]);
    int key = 8;

    int key_index = binarySearch(arr, key, length);

    if (key_index == -1)
    {
        printf("%d is not present inside the array.", key);
    }
    else
    {
        printf("The %d is present at index %d.\n", key, key_index);
    }

    return 0;
}

/*
TIME COMPLEXITY: O(log n)

INPUT 1:
key = 8
OUTPUT 1:
The 8 is present at index 5.

INPUT 2:
key = 3
OUTPUT 2:
3 is not present inside the array.

ITERATION:
arr = {1, 2, 4, 5, 6, 8, 10}

key = 8, left = 0, right = 6
mid = 0 + (6 - 0) / 2 = 3

key = key > arr[mid] = 8 > 5 = true
    left = mid + 1 = 4

low = 4, high = 6
key = key > arr[mid] = 8 > 6 = true
    left = mid + 1 = 5

low = 5, high = 6
key = (key == arr[mid]) = (8 == 8) = true
    return mid = 5

OUTPUT:
The 8 is present at index 5.
*/