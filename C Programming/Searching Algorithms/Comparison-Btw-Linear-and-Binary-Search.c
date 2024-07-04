#include <stdio.h>

void printArray(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// defining a srtucture for index and steps count
typedef struct
{
    int index;
    int steps;
} resInfo;

void linearSearch(int arr[], int target, int length, resInfo *res)
{
    int steps = 0;
    res->index = -1;

    for (int i = 0; i < length; i++)
    {
        steps++;
        res->steps = steps;
        if (arr[i] == target)
        {
            res->index = i;
            break;
        }
    }
}

resInfo binarySearch(int arr[], int target, int length, resInfo res)
{
    int low = 0, high = length - 1;
    int steps = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        steps++;

        if (target == arr[mid])
        {
            res.steps = steps;
            res.index = mid;
            return res;
        }
        else if (target < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    res.index = -1;
    res.steps = steps;
    return res;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Array: \n");
    printArray(arr, length);

    printf("Select the element you want to search: \n");
    scanf("%d", &target);

    resInfo result = {-1, -1};
    result = binarySearch(arr, target, length, result);

    printf("\nBINARY SEARCH:\n");

    if (result.index == -1)
    {
        printf("%d is not present in the array.\n", target);
    }
    else
    {
        printf("Element %d is present at the index %d.\n", target, result.index);
    }
    printf("Steps taken: %d", result.steps);

    // using call by reference in linearSearch
    linearSearch(arr, target, length, &result);

    printf("\n\nLINEAR SEARCH:\n");

    if (result.index == -1)
    {
        printf("%d is not present in the array.\n", target);
    }
    else
    {
        printf("Element %d is present at the index %d.\n", target, result.index);
    }
    printf("Steps taken: %d", result.steps);
}

/*
TIME COMPLEXITY:
    Binary Search: O(log n)
    Linear Search: O(n)

Input1:
    Array:
    1 2 3 4 5 6 7 8 9
    Select the element you want to search:
    5

Output1:
    BINARY SEARCH:
    Element 5 is present at the index 4.
    Steps taken: 2

    LINEAR SEARCH:
    Element 5 is present at the index 4.
    Steps taken: 5


Input2:
    Array:
    1 2 3 4 5 6 7 8 9
    Select the element you want to search:
    10

Output2:
    BINARY SEARCH:
    10 is not present in the array.
    Steps taken: 4

    LINEAR SEARCH:
    10 is not present in the array.
    Steps taken: 9

ITERATION STEPS:
array = {1, 2, 3, 4, 5, 6, 7, 8, 9}
target = 5, length = 9
    Binary Search:
        1. low = 0, high = 8, mid = 4, steps = 1
        arr[mid] = 5 == target
        steps = 1

    Linear Search:
        1. i = 0, steps = 1
        2. i = 1, steps = 2
        3. i = 2, steps = 3
        4. i = 3, steps = 4
        5. i = 4, steps = 5
        steps = 5
*/