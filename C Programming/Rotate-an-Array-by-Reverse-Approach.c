#include <stdio.h>
#include <ctype.h>

// Function to reverse a portion of the array
void reverseArray(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void printArray(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}

void rotateArray(int arr[], int length, int shift, char shift_type)
{
    shift %= length; // Bring shift within range of array length
    if (shift_type == 'r' || shift_type == 'R')
    {
        shift = length - shift; // Convert right rotation to left rotation equivalent
    }

    // Use reversal algorithm to perform rotation in-place
    reverseArray(arr, 0, shift - 1);
    reverseArray(arr, shift, length - 1);
    reverseArray(arr, 0, length - 1);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int length = sizeof(arr) / sizeof(arr[0]);
    int shift_value;
    char type_of_shift;

    printf("The original array is:\n");
    printArray(arr, length);

    printf("Enter the value by which you want to shift: ");
    scanf("%d", &shift_value);

    printf("Enter (l or L) for left shift and (r or R) for right shift: ");
    scanf(" %c", &type_of_shift);

    // Validate shift type input
    while (type_of_shift != 'l' && type_of_shift != 'L' && type_of_shift != 'r' && type_of_shift != 'R')
    {
        printf("Please enter a valid shift type (l or r): ");
        scanf(" %c", &type_of_shift);
    }

    rotateArray(arr, length, shift_value, type_of_shift);
    printf("\nThe array after shifting:\n");
    printArray(arr, length);

    return 0;
}

/*
SAMPLE INPUT:
The original array is:
1 2 3 4 5

Enter the value by which you want to shift: 2
Enter (l or L) for left shift and (r or R) for right shift: l

SAMPLE OUTPUT:
The array after shifting:
3 4 5 1 2

ITERATION:
array = 1 2 3 4 5
shift = 7
shift %= length: 2
shift_type = l
reverse array from index 0 to 1: 2 1 3 4 5
reverse array from index 2 to 4(length - 1): 2 1 5 4 3
reverse array from index 0 to 4(length - 1): 3 4 5 1 2
output = 3 4 5 1 2
*/