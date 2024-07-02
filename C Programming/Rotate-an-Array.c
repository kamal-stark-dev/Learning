#include <stdio.h>
#include <ctype.h>

void printArray(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}

int *rotateArray(int arr[], int length, int shift, char shift_type)
{

    char type_of_shift = tolower(shift_type);

    // Fixed the while loop condition
    while (type_of_shift != 'l' && type_of_shift != 'r')
    {
        printf("Please enter a valid shift type: ");
        scanf(" %c", &type_of_shift); // Note the space before %c to eat the newline
        type_of_shift = tolower(type_of_shift);
    }

    shift %= length; // if shift = 7 and length = 5 then it'll make shift 2 (i.e. in range) as shifting by 2 or 7 in this case of 5 elements will be equivalent.

    int temp[length];

    for (int i = 0; i < length; i++)
    {
        if (type_of_shift == 'r')
        {
            temp[i] = arr[(i - shift + length) % length]; // for i = 0, shift = 2 and length = 5 ==> (0 + 2 + 5) % 5 = 2. so, 2nd element will be placed at 0th index
        }
        else
        {
            temp[i] = arr[(i + shift + length) % length];
        }
    }

    for (int i = 0; i < length; i++)
    {
        arr[i] = temp[i]; // copying temp array to passed array as you can't return local variables
    }

    return arr;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int length = sizeof(arr) / sizeof(arr[0]);
    int shift_value;
    char type_of_shift;

    printf("The original array is:\n");
    printArray(arr, length);

    printf("Enter the value by which you want to left shift: ");
    scanf("%d", &shift_value);

    printf("Enter (l or L) for left shift and (r or R) for right shift: ");
    scanf(" %c", &type_of_shift);

    int *rotated_array = rotateArray(arr, length, shift_value, type_of_shift);
    printf("\nThe array after shifting is:\n", shift_value);
    printArray(rotated_array, length);

    return 0;
}

/*
SAMPLE INPUT:
The original array is:
1 2 3 4 5

Enter the value by which you want to left shift: 2
Enter (l or L) for left shift and (r or R) for right shift: r

SAMPLE OUTPUT:
The array after shifting is:
4 5 1 2 3

ITERATION:
array = 1 2 3 4 5
shift = 7
shift %= length: 2
shift_type = r
temp[0] = arr[(0 - 2 + 5) % 5] = arr[3] = 4
temp[1] = arr[(1 - 2 + 5) % 5] = arr[4] = 5
temp[2] = arr[(2 - 2 + 5) % 5] = arr[0] = 1
temp[3] = arr[(3 - 2 + 5) % 5] = arr[1] = 2
temp[4] = arr[(4 - 2 + 5) % 5] = arr[2] = 3
temp = 4 5 1 2 3
output = 4 5 1 2 3
*/