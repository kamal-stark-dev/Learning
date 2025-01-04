// 31. Next Permutation - https://leetcode.com/problems/next-permutation/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void reverseArray(vector<int>& nums, int i, int j) {
    while (i <= j) {
        swap(nums[i], nums[j]);
        i++; j--;
    }
}

// find the next lexicographically order
void nextPermutation(vector<int>& nums) {
    int size = nums.size();
    int pivot = -1;
    for (int i = size - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            pivot = i;
            break;
        }
    }
    if (pivot == -1) { // no next permutation exists
        // according to question return the increasing order
        reverseArray(nums, 0, size - 1);
        return;
    }

    // find the rightmost smallest from pivot (i.e. newFront)
    for (int i = size - 1; i > pivot; i--) {
        if (nums[i] > nums[pivot]) {
            swap(nums[i], nums[pivot]);
            break;
        }
    }

    reverseArray(nums, pivot + 1, size - 1);
    // reverse(nums.begin() + pivot + 1, nums.end());
}

/*
1 2 3 6 5 4
find pivot => 3 as from end `3` is not following the increasing order (nums[pivot] < nums[pivot + 1])

1 2 3 6 5 4
    p
now we need to make the smallest number from the digits after pivot including itself which are -> 3 6 5 4

but we can't use the pivot as the first digit (3 can't be the first digit) -> 4356 ==> this is the next order

1 2 4 3 5 6
*/

int main() {
    vector<int> nums = {1, 2, 3, 6, 5, 4};

    nextPermutation(nums);

    for (int n: nums) cout << n;
}


/*
Below is my first attempt to just print the required -
```
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int i = size - 2;
        while (nums[i] > nums[i + 1]) {
            i--;
        }
        int pivot = i;
        int newFront = size - 1;
        cout << "The pivot element is: " << nums[pivot] << "\nThe new front is: " << newFront << endl;

        cout << "The new order is: ";
        cout << nums[pivot];
        for (int i = size - 2; i > pivot; i--) {
            cout << nums[i];
        }

        cout << "\nThe next permutation is: ";
        for (int i = 0; i < pivot; i++) cout << nums[i];
        cout << nums[newFront] << nums[pivot];
        for (int i = size - 2; i > pivot; i--) {
            cout << nums[i];
        }
    }
```

Second in space attempt:
```
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int pivot = size - 2;
        while (nums[pivot] > nums[pivot + 1]) pivot--;
        int newFront = size - 1;

        vector<int> nextPer;

        for (int i = 0; i < pivot; i++) nextPer.push_back(nums[i]);
        nextPer.push_back(nums[newFront]);
        nextPer.push_back(nums[pivot]);
        for (int i = size - 2; i > pivot; i--) nextPer.push_back(nums[i]);

        nums = nextPer;
    }
```
*/