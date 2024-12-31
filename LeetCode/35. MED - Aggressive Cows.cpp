// Aggressive Cows - https://www.youtube.com/watch?v=7wOzDqsfXy0&list=PLfqMhTWNBTe137I_EPQd34TsgV6IO55pt&index=23

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossibleMin(vector<int> nums, int totalCows, int minNeeded) {  // O(n)
    int size = nums.size();
    int cows = 1, previousStall = 0;
    for (int i = 1; i < size; i++) {
        if (nums[i] - nums[previousStall] >= minNeeded) {
            cows++;
            previousStall = i;
        }
        if (cows == totalCows) return true;
    }
    return false;
}

int aggresiveCows(vector<int> nums, int cows) {
    // sort the nums array
    sort(nums.begin(), nums.end());  // O(n log.n)

    // finding the left and right for binary search
    int size = nums.size();
    int minDist = nums[0], maxDist = nums[size - 1];
    int left = 1, right = maxDist - minDist;

    int ans = 1;
    while (left <= right) {  // O(log.R) -> R is range from min to max
        int mid = left + (right - left) / 2;

        if (isPossibleMin(nums, cows, mid)) {
            ans = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return ans;
}

int main(void) {
    vector<int> nums = {1, 2, 8, 4, 9};
    int cows = 3;

    cout << aggresiveCows(nums, cows) << endl;
    return 0;
}

/*
Time Complexity: O(n log.n) || O(n log.R) based on whichever's bigger

Note: You can see that we can use binary search logic with some checker function for `min of max` or `max of min` questions.

1. Book Allocation      ->  min possible for max pages
2. Painter's Partition  ->  min possible for max time
3. Aggressive Cows      ->  max possible for min distance
*/