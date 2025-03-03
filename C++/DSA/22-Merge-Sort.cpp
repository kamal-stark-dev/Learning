// Merge Sort - Divide & Conquer

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums, int start, int mid, int end) { // O(n)
    vector<int> temp;
    int i = start, j = mid + 1;
    while (i <= mid && j <= end) {
        if (nums[i] < nums[j]) {
            temp.push_back(nums[i]); i++;
        }
        else {
            temp.push_back(nums[j]); j++;
        }
    }
    while (i <= mid) {
        temp.push_back(nums[i]); i++;
    }
    while (j <= end) {
        temp.push_back(nums[j]); j++;
    }

    for (int idx = 0; idx < temp.size(); idx++) {
        nums[start + idx] = temp[idx];
    }
}

void mergeSort(vector<int>& nums, int start, int end) { // O(log.n)
    if (start < end) {
        int mid = start + (end - start) / 2;

        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1, end);

        merge(nums, start, mid, end);
    }
}

void printArr(vector<int> nums) {
    for (int n: nums) cout << n << " ";
    cout << endl;
}

int main(void) {
    vector<int> nums = {12, 31, 35, 8, 32, 17};

    mergeSort(nums, 0, nums.size() - 1);
    printArr(nums);

    return 0;
}
/*
Time Complexity: O(n log.n)
Space Complexity: O(n) -> temp
*/