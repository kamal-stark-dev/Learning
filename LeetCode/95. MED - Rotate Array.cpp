// 189. Rotate Array

#include <bits/stdc++.h>
using namespace std;

void leftRotate_Brute(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;

    vector<int> temp(k);
    for (int i = 0; i < k; i++) {
        temp[i] = nums[i];
    }
    for (int i = k; i < n; i++) {
        nums[i - k] = nums[i];
    }
    for (int i = n - k; i < n; i++) {
        nums[i] = temp[i - (n - k)];
    }
}

void rightRotate_Brute(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    k = n - k;

    vector<int> temp(k);
    for (int i = 0; i < k; i++) {
        temp[i] = nums[i];
    }
    for (int i = k; i < n; i++) {
        nums[i - k] = nums[i];
    }
    for (int i = n - k; i < n; i++) {
        nums[i] = temp[i - (n - k)];
    }
}

void rightRotate(vector<int>& nums, int k) {
    k = k % nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

void leftRotate(vector<int>& nums, int k) {
    k = k % nums.size();

    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
    reverse(nums.begin(), nums.end());
}

int main(void) {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    // rightRotate(nums, k);
    rightRotate_Brute(nums, k);

    for (int n : nums) cout << n << " ";
    cout << endl;

    return 0;
}

/*
Brute:
    Time Complexity: O(k) + O(n - k) + O(k) ==> O(n + k)
    Space Complexity: O(k)

Optimal:
    Time Complexity: O(2n) ==> O(n)
    Space Complexity: O(1)
*/