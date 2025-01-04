// 88. Merge Sorted Array - https://leetcode.com/problems/merge-sorted-array/

#include <iostream>
#include <vector>
using namespace std;

void mergeSortedArrays(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1;
    // int idx = nums1.size() - 1;
    int idx = m + n - 1;

    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[idx--] = nums1[i--];
        }
        else {
            nums1[idx--] = nums2[j--];
        }
    }
    // we don't need the commented out loop as this array is `nums1` itself has the elements already
    // while (i >= 0) {
    //     nums1[idx--] = nums1[i--];
    // }
    while (j >= 0) {
        nums1[idx--] = nums2[j--];
    }
}
/*
1 2 3 0 0 0
    i     k
2 5 6
    j
*/

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0}; // size -> m + n
    vector<int> nums2 = {2, 5, 6}; // size -> n
    // 1 2 2 3 5 6 -> should be stored in nums1
    int m = 3, n = 3;

    mergeSortedArrays(nums1, m, nums2, n);

    for (int n: nums1) cout << n << " ";
    cout << endl;
}

/*
Time Complexity: O(m + n)
Space Complexity: O(1)
*/