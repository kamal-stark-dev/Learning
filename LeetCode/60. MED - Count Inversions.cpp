// Count Inversions : https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

#include <iostream>
#include <vector>
using namespace std;

int countInversions_brute(vector<int> nums) { // O(n ^ 2)
    int size = nums.size();
    int count = 0;

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (nums[i] > nums[j]) count ++;
        }
    }
    return count;
}

int merge(vector<int>& nums, int start, int mid, int end) {
    int i = start, j = mid + 1;
    vector<int> temp;
    int invCount = 0;

    while (i <= mid && j <= end) {
        if (nums[i] <= nums[j]) {
            temp.push_back(nums[i++]);
        }
        else { // when nums[i] > nums[j]
            invCount += (mid - i + 1);
            temp.push_back(nums[j++]);
        }
    }
    while (i <= mid) {
        temp.push_back(nums[i++]);
    }
    while (j <= end) {
        temp.push_back(nums[j++]);
    }

    for (int i = 0; i < temp.size(); i++) {
        nums[start + i] = temp[i];
    }
    return invCount;
}

int countInversions_mergeSort(vector<int>& nums, int start, int end) { // TC: O(n logn) | SC: O(n)
    int invCount = 0;
    if (start < end) {
        int mid = start + (end - start) / 2;

        invCount += countInversions_mergeSort(nums, start, mid);
        invCount += countInversions_mergeSort(nums, mid + 1, end);

        invCount += merge(nums, start, mid, end);

        return invCount;
    }
    return 0;
}

int main(void) {
    vector<int> nums = {6, 3, 5, 2, 7};
    // vector<int> nums = {10, 10, 10};
    /*
    We need to count the number of inversions in the array, inversions are the pairs of (arr[i], arr[j]) that follow -
        1. i < j
        2. arr[i] > arr[j]
    */

    int count = countInversions_mergeSort(nums, 0, nums.size() - 1);
    cout << "There are `" << count << "` inversions for the array.\n";

    return 0;
}