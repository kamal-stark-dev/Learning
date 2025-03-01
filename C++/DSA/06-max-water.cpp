#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// usnig the two pointer approach for finding the max-water
int maxWater(vector<int> nums) {
    int left = 0, right = nums.size() - 1;
    int maxArea = 0;
    int li = 0, ri = 0;

    while (left < right) {
        int width = (right - left);
        int height = min(nums[left], nums[right]);
        int area = width * height;
        if (area> maxArea) {
            li = left;
            ri = right;
        }
        maxArea = max(area, maxArea);

        if (nums[left] < nums[right]) left++;
        else right--;
    }
    cout << "from index: " << li << " to " << ri << endl;
    return maxArea;
}

/*
`~` => water
`#` => pillars
|
|              #
|              #
|           #  #
|     #     #  #
|     #~~#~~#~~#~~~~~#
|     #~~#~~#~~#~~~~~#
|  #  #~~#~~#~~#~~~~~#
|__#__#~~#~~#~~#~~0~~#__
   2  5  3  6  8  0  4
max water => from index 1 to 6 => 4 * 5 => 20
*/

int main() {
    vector<int> nums = {2, 5, 3, 6, 8, 0, 4};

    // max water
    cout << maxWater(nums) << "\n";

    return 0;
}