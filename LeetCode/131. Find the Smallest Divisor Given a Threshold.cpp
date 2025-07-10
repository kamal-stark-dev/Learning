// Find the Smallest Divisor Given a Threshold

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool validDivisor(vector<int>& nums, int limit, int divisor) {
    int sum = 0;
    for (int n: nums) {
        sum += n / divisor + ((n % divisor == 0) ? 0 : 1);
    }
    return sum <= limit;
}

int smallestDivisor(vector<int>& nums, int limit) {
    int left = 1, right = *max_element(nums.begin(), nums.end());
    int minDivisor = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (validDivisor(nums, limit, mid)) {
            minDivisor = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }
    return minDivisor;
}

int optimal_solution(vector<int>& nums, int limit) {
    int left = 1, right = *max_element(nums.begin(), nums.end());
    int mid, sum;
    while (left < right) {
        mid = left + (right - left) / 2, sum = 0;
        for (int n: nums) {
            sum += ceil(1.0 * n / mid);
        }
        if (sum <= limit) right = mid;
        else left = mid + 1;
    }
    return right;
}

int main(void) {
    vector<int> nums = {1, 2, 3, 4, 5};
    int limit = 8;

    cout << "Smallest number that divides all elements making their sum less than or equal to " << limit << " is " << smallestDivisor(nums, limit) << ".\n";
    // cout << "Smallest number that divides all elements making their sum less than or equal to " << limit << " is " << optimal_solution(nums, limit) << ".\n";

    return 0;
}