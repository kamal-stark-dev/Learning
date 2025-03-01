#include <iostream>
#include <vector>
using namespace std;

/*
Sorting means to order data elements in an ascending or descending order.
    ex: {3, 4, 2, 1} -> {1, 2, 3, 4} or {4, 3, 2, 1}
*/

void swap (int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void printArray(vector<int>& nums, int size) {
    for (int i = 0; i < size; i++) {
        cout << nums[i] << " ";
    } cout << endl;
}

// Bubble Sort - O(n^2)
void bubbleSort(vector<int>& nums, int n, char order = 'a') {
    for (int i = 0; i < n - 1; i++) {
        bool isSwap = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (nums[j] > nums[j + 1] && order == 'a') { // ascending
                isSwap = true;
                swap(nums[j], nums[j + 1]);
            }
            else if (nums[j] < nums[j + 1] && order == 'd') { // descending
                isSwap = true;
                swap(nums[j], nums[j + 1]);
            }
        }
        if (!isSwap) return;  // the array is sorted as no swaps were done
    }
}

// Selection Sort - O(n^2)
void selectionSort(vector<int>& nums, int n, char order = 'a') {
    for (int i = 0; i < n - 1; i ++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (nums[j] < nums[minIdx] && order == 'a') minIdx = j;
            else if (nums[j] > nums[minIdx] && order == 'd') minIdx = j;
        }
        swap(nums[i], nums[minIdx]);
    }
}

// Insertion Sort - O(n^2)
void insertionSort(vector<int>& nums, int n, char order = 'a') {
    for (int i = 1; i < n; i++) {
        int curr = nums[i], prev = i - 1;
        if (order == 'a') {
            while (prev >= 0 && nums[prev] > curr) {
                nums[prev + 1] = nums[prev]; // keep shifting to right until we reach the right position
                prev--;
            }
            nums[prev + 1] = curr; // placing ith element to its correct position
        }
        else if (order == 'd') {
            while (prev >= 0 && nums[prev] < curr) {
                nums[prev + 1] = nums[prev];
                prev--;
            }
            nums[prev + 1] = curr;
        }
    }
}

int main() {
    vector<int> nums = {3, 4, 2, 1, 5};
    int size = nums.size();

    insertionSort(nums, size , 'd');

    cout << "The array is: ";
    printArray(nums, size);
}