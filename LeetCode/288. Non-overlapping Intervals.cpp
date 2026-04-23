// 435. Non-overlapping Intervals

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// O(n logn)
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) { // O(n logn)
        return a[0] < b[0];
    });

    int n = intervals.size();
    int count = 0;
    int back = intervals[0][1];

    for (int i = 1; i < n; i++) { // O(n)
        int start = intervals[i][0], end = intervals[i][1];

        if (back > start) { // not `>=` as equals are not counted as overlapping
            // ---
            back = min(back, end); // this chooses the one at the back so that there are less overlapping chances than the other one
            count++;
        }
        else {
            back = end;
        }
    }
    return count;
}

int main(void) {
    vector<vector<int>> intervals = { {1, 2}, {2, 3}, {3, 4}, {1, 3} };

    // cout << eraseOverlapIntervals(intervals) << "\n";
    cout << "Minimum number of intervals that are needed to make the rest intervals non-overlapping are: " << eraseOverlapIntervals(intervals) << "\n";

    return 0;
}

/*
Time Complexity: O(n logn)
Space Complexity: O(1)
*/