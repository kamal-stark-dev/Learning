// 1011. Capacity To Ship Packages Within D Days

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

bool validShipment(vector<int>& weights, int days, int max_limit) {
    int i = 0, n = weights.size();
    int count = 0;

    while (i < n) {
        int limit = max_limit;
        if (weights[i] > limit) return false;
        while (i < n && weights[i] <= limit) {
            limit -= weights[i];
            i++;
        }
        count++;
    }
    return count <= days;
}

int minShipCapacity(vector<int>& weights, int days) {
    int left = *max(weights.begin(), weights.end()), right = accumulate(weights.begin(),  weights.end(), 0);
    // int left = 1, right = accumulate(weights.begin(),  weights.end(), 0);

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (validShipment(weights, days, mid)) right = mid;
        else left = mid + 1;
    }
    return right;
}

int main(void) {
    // vector<int> weights = {3, 2, 2, 4, 1, 4};
    // int days = 3;
    vector<int> weights = {1, 2, 3, 1, 1};
    int days = 4;

    cout << "Ship capacity of " << minShipCapacity(weights, days)  << " is minimum to ship all the packages in " << days << " days.\n";

    return 0;
}