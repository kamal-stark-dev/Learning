// 75. Sort Colors - https://leetcode.com/problems/sort-colors/

#include <iostream>
#include <vector>
using namespace std;

// linera time
void optimizedSort(vector<int>& nums) {
    int zeros = 0, ones = 0, twos = 0;
    for (int n: nums) {
        if (n == 0) zeros++;
        else if (n == 1) ones++;
        else twos++;
    }

    int i = 0;
    while (zeros > 0) {
        nums[i] = 0;
        i++; zeros--;
    }
    while (ones > 0) {
        nums[i] = 1;
        i++; ones--;
    }
    while (twos > 0) {
        nums[i] = 2;
        i++; twos--;
    }
}

// linear time -> single pass
void dutchNationalFlag(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[mid], nums[low]);
            mid++; low++;
        }
        else if (nums[mid] == 1) {
            mid ++;
        }
        else { // for 2
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main(void) {
    vector<int> nums = {0, 1, 2, 2, 2, 1, 0, 0, 2, 1, 0};

    dutchNationalFlag(nums);

    // display array
    for (int n: nums) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}