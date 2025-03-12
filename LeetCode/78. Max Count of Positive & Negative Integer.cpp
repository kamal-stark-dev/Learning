// 2529. Maximum Count of Positive Integer and Negative Integer

#include <iostream>
#include <vector>
using namespace std;

// NOTE: `0` is neither positive nor negative

/*
It can be done with a single for loop easily with linear time complexity.

And as it's sorted we can apply binary search for logarithmic time complexity.
> try dry running the binary search to make more sense out of it :)
*/
int maximumCount(vector<int> nums) {
    int left = 0, right = nums.size() - 1;

    // find positive
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > 0) right = mid - 1;
        else left = mid + 1;
    }
    int positive = nums.size() - left;

    // find negative
    left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] < 0) left = mid + 1;
        else right = mid - 1;
    }
    int negative = right + 1;

    return max(positive, negative);
}

int main(void) {
    vector<int> nums = {-3, -2, -1, 0, 0, 1, 2};
    int maxCount = maximumCount(nums);

    cout << maxCount << endl;
    return 0;
}
/*
Time Complexity: O(log.n)
Space Complexity: O(1)
*/