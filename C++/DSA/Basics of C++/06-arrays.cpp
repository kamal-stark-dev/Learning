#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;  // not found
}

int sumArray(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];
    return sum;
}

void commonElements(int arr1[], int size1, int arr2[], int size2) {

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                cout << arr1[i] << " ";
            }
        }
    }
}


int main(void) {

    // Array - a linear contigous data-structure that stores homogenous data that can be indexed.

    int marks[5] = {76, 83, 93, 56, 73};

    /*
    int marks[5] = {76, 83, 93, 56, 73};
    +--------+--------+--------+--------+--------+
    |   76   |   83   |   93   |   56   |   73   |
    +--------+--------+--------+--------+--------+
    100      104      108      112      116    --> contigous memory, int is 4 bytes.

    To access a particular data element you can use indexing - which starts from 0 and goes till the total len - 1
    --------> indexes in array -> 0 to (n - 1), where n is the total elements count

    example:
        1. marks[0] will refer to the first element in the array.
        2. marks[i] will refer to the (i + 1)th element in the array.
    */

    cout << "The value at first element is: " << marks[0] << endl;

    cout << "Marks array: ";
    for (int i = 0; i < 5; i++) {
        cout << marks[i] << " ";
    }
    cout << endl;

    // you can also modify the elements through index
    cout << "marks[0]:" << marks[0] << endl;
    marks[0] = 90;
    cout << "after modifying the marks[0] value, we get\n" << "marks[0]:" << marks[0] << endl;

    // trying to access invalid indexes
    cout << endl << marks[10] << endl;    // garbage value
    cout << marks[-1] << endl;    // garbage value

    // Dynamically getting the array size
    int size = sizeof(marks) / sizeof(marks[0]);
    cout << "\nSize of the arry is: " << size << endl;

    // taking input of the array
    /*
    int arr_size;
    cout << "\nEnter the size of the array: ";
    cin >> arr_size;

    int arr[arr_size];

    for (int i = 0; i < arr_size; i++) {
        cout << "Enter the " << i + 1 << " element: ";
        cin >> arr[i];
    }

    cout << "The array is: ";
    for (int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    */

    // find the min and max in array
    int arr[10] = {43, 24, 66, -37, 12, -58, 27};

    int min = arr[0];
    int max = arr[0];

    for (int i = 0; i < 10; i++) {
        if (arr[i] < min)
            min = arr[i];
        else if (arr[i] > max)
            max = arr[i];
    }
    cout << "\nThe minimum number is: " << min << endl;
    cout << "The maximum number is: " << max << endl;

    cout << "\nLargest int: " << INT_MAX << "\nSmallest int: " << INT_MIN << endl << endl;

    /*
    You can also use min() and max() functions which are pre-built.
        minimum = min(numA, numB);
        maximum = max(numA, numB);
    */

    // Linear Search
    int values[7] = {7, 3, 5, 9, 2, 0, 1};
    size = 7;
    int key = 2; // element to search

    int indexOfKey = linearSearch(values, size, key);

    if (key != -1)
        cout << key << " found at the index " << indexOfKey << " in the array.\n";
    else
        cout << key << " is not present in the array\n";

    // sum all the elements in the array
    int sum = sumArray(values, size);
    cout << "The sum of all the elements is: " << sum << endl;

    // make a Unique array from an array having duplicates
    int duplicates[8] = {1, 2, 3, 4, 5, 4, 2, 7};
    size = sizeof(arr) / sizeof(arr[0]);
    int uniqueIndex = 0, uniqueArr[size];

    for (int i = 0; i < size; i++) {
        bool isDuplicate = false;
        for (int j = 0; j < i; j++) {
            if (duplicates[i] == duplicates[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            uniqueArr[uniqueIndex++] = duplicates[i];
        }
    }

    cout << "\nThe uniqye elements in the array are:\n";
    for (int i = 0; i < uniqueIndex; i++) {
        cout << uniqueArr[i] << " ";
    } cout << endl;


    // Intersection between two arrays
    int arr1[] = {1, 2, 3, 4, 5}, size1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {9, 8, 7, 6, 5, 4, 3}, size2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << "\nCommon elements in both are arrays are:\n";
    commonElements(arr1, size1, arr2, size2);

    return 0;
}