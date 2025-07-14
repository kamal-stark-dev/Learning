// Minimize Maximum Distance between Gas Stations

#include <iostream>
#include <vector>
using namespace std;

bool validMinDistance(vector<int>& nums, int k, double max_dist) { // O(n)
    int count = 0;
    int n = nums.size();
    double dist;

    for (int i = 1; i < n; i++) {
        dist = nums[i] - nums[i - 1];
        count += (int) (dist / max_dist);
    }
    return count <= k;
}

double minimizedDistance(vector<int>& nums, int k) {
    int n = nums.size();
    double left = 0, right = 0;

    for (int i = 1; i < n; i++) { // O(n)
        right = max(right, (double) nums[i] - nums[i - 1]);
    }

    double precision = 1e-6;
    while (right - left > precision) { // O(n * log (R / e))
        double mid = (left + right) / 2.0;
        if (validMinDistance(nums, k, mid)) // O(n)
            right = mid;
        else left = mid;
    }
    return left;
}

int main(void) {
    vector<int> nums = {1, 3, 7, 14};
    int k = 4;

    cout << "The minimized maximimum distance between gas stations is " << minimizedDistance(nums, k) << " units.\n";

    return 0;
}

/*
Time Complexity: O(n * log (R / e)) + O(n), R -> 0 to maximum consecutive distance. e -> epsilon(1e-6)
*/