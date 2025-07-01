// 493. Reverse Pairs

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums, int left, int mid, int right) {
    int i = left, j = mid + 1;
    vector<int> temp;
    while (i <= mid && j <= right) {
        if (nums[i] < nums[j])
            temp.push_back(nums[i++]);
        else
            temp.push_back(nums[j++]);
    }
    while (i <= mid) temp.push_back(nums[i++]);
    while (j <= right) temp.push_back(nums[j++]);

    int tempSize = temp.size();
    for (int k = 0; k < tempSize; k++) {
        nums[left + k] = temp[k];
    }
}

int countReverse(vector<int>& nums, int low, int mid, int high) {
    int right = mid + 1;
    int revCount = 0;
    for (int left = low; left <= mid; left++) {
        while (right <= high && (long)nums[left] > 2 * (long)nums[right]) right++;
        revCount += right - (mid + 1);
    }
    return revCount;
}

int mergeSortSpecial(vector<int>& nums, int left, int right) {
    int revCount = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        revCount += mergeSortSpecial(nums, left, mid);
        revCount += mergeSortSpecial(nums, mid + 1, right);
        revCount += countReverse(nums, left, mid, right);

        merge(nums, left, mid, right);
        return revCount;
    }
    return 0;
}

int reversePairsCount(vector<int> nums) {
    return mergeSortSpecial(nums, 0, nums.size() - 1);
}

int main(void) {
    vector<int> nums = {2, 4, 3, 5, 1};
    int revCount = reversePairsCount(nums);

    cout << "There are " << revCount << " reverse pairs in the array.\n";
    return 0;
}