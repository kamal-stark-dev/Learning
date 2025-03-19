// 3191. Minimum Operations to Make Binary Array Elements Equal to One I

#include <iostream>
#include <vector>
using namespace std;

int minOperations(vector<int> nums) {
    int minCount = 0, size = nums.size();

    for (int i = 0; i <= size - 3; i++) {
        if (nums[i] == 0) {
            nums[i] ^= 1;
            nums[i + 1] ^= 1;
            nums[i + 2] ^= 1;
            minCount++;
        }
    }
    for (int n : nums) {
        if (n == 0) return -1;
    }
    return minCount;
}

int main(void) {
    vector<int> nums = {0, 1, 1, 1, 0, 0};

    int minCount = minOperations(nums);
    cout << "Min Count: " << minCount << endl;

    return 0;
}