// Move Zeroes To End - https://www.naukri.com/code360/problems/interview-shuriken-41-move-zeroes-to-end_240143

#include <bits/stdc++.h>
using namespace std;

void moveZerosToEnd_brute(vector<int>& nums) {
    int n = nums.size();

    vector<int> temp;
    for (int n: nums) {
        if (n != 0) temp.push_back(n);
    }

    int num_of_zeros = n - temp.size();
    if (num_of_zeros == 0) return;

    int idx = 0;
    for (int n: temp) {
        nums[idx++] = n;
    }
    for (int i = 0; i < num_of_zeros; i++) {
        nums[idx++] = 0;
    }
}

void moveZerosToEnd_better(vector<int>& nums) {
    int n = nums.size();
    int idx = 0;
    for (int j = 0; j < n; j++) {
        if (nums[j] != 0) {
            nums[idx++] = nums[j];
        }
    }

    int num_of_zeros = n - idx;
    if (num_of_zeros == 0) return;
    for (int i = 0; i < num_of_zeros; i++) {
        nums[i + idx] = 0;
    }
}

void moveZerosToEnd_optimal(vector<int>& nums) {
    int n = nums.size();

    int j = -1;
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            j = i;
            break;
        }
    }

    if (j == -1) return;
    for (int i = j + 1; i < n; i++) {
        if (nums[i] != 0) {
            swap(nums[i], nums[j++]);
        }
    }
}

int main(void) {
    vector<int> nums = {1, 0, 3, 2, 4, 0, 0, 5, 4, 1};

    moveZerosToEnd_optimal(nums);

    for (int n: nums) cout << n << " ";
    return 0;
}
/*
k = num_of_zeros

Time Complexity:
    Brute: O(n) + O(n - k) + O(k) => O(2n)
    Better: O(n) + O(k) => O(n + k)
    Optimal: O(n)

Space Complexity:
    Brute: O(k)
    Better: O(1)
    Optimal: O(1)
*/