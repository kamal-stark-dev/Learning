#include <iostream>
using namespace std;

void squareArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = arr[i] * arr[i];
    }
}

void reverseArray(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        // uncomment the below line to see the swap indices
        // cout << i << ", " << size - i - 1 << endl;
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

// using two pointer approach
void reverseArray2(int arr[], int size) {
    int left = 0;
    int right = size - 1;

    while (left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }
}

int main(void) {

    /*
    Pass by Reference - in this method we pass the adress of our arguments insteaf of their values.
    */

    // Arrays are non-primitive data type and they store the address of the memory (pointer).
    int arr[3] = {1, 2, 3};
    int size = 3;

    squareArray(arr, size);             // arr here is passed by reference (try printing `arr` alone without index).

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";          // will output 1 4 9 instead of 1 2 3
    } cout << endl;

    cout << "Arr: " << arr << endl;     // hexadecimal address like: 0x61fe0c

    // how to pass primitive data like int, float, double, char, bool etc. as reference.

    // Reverse an array with call by reference
    // 1 2 3 4 5 --> 5 4 3 2 1

    int values[5] = {1, 2, 3, 4, 5};
    reverseArray2(values, 5);

    for (int i = 0; i < 5; i++) {
        cout << values[i] << " ";
    }
    cout << endl;

    return 0;
}