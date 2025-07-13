// Aggressive Cows

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool validStalls(vector<int>& stalls, int k, int dist) { // O(n)
    int n = stalls.size();
    int cows = 1;
    int last = stalls[0];

    for (int i = 1; i < n; i++) {
        if(stalls[i] - last >= dist) {
            cows++;
            last = stalls[i];
        }
        if (cows >= k) return true;
    }
    return false;
}

int aggressiveCows(vector<int>& stalls, int k) {
    sort(stalls.begin(), stalls.end()); // O(n * logn)

    int n = stalls.size();
    int left = 1, right = stalls[n - 1] - stalls[0]; // range -> [1, max(stall) - min(stall)]

    while (left <= right) { // O(log range)
        int mid = left + (right - left) / 2;

        if (validStalls(stalls, k, mid)) { // O(n)
            left = mid + 1;
        }
        else right = mid - 1;
    }
    return right; // right will contain the maximum-minimum dist
}

int main(void) {
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int k = 4;

    cout << "The maximum possible minimum distance between any two cows will be " << aggressiveCows(stalls, k) << " when " << k << " cows are placed.\n";

    return 0;
}

/*
Time Complexity: O(n * logn) + O(n * log(max_stall - min_stall))
Space Complexity: O(1)
*/