// 57. Insert Interval

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// O(n)
vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    vector<vector<int>> output = { intervals[0] };
    int n = intervals.size();
    // no sorting needed for intervals (as it's already sorted by first values in this case)

    for (int i = 1; i < n; i++) {
        int lastEnd = output.back()[1];
        int start = intervals[i][0], end = intervals[i][1];

        if (lastEnd >= start) {
            // merge
            output.back()[1] = max(end, lastEnd);
        }
        else {
            output.push_back(intervals[i]);
        }
    }
    return output;
}

// O(n(i-shifting) + n(inserting) + n(merging)) => O(n)
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    // insert the `newInterval` at correct position
    int i = 0, n = intervals.size();
    while (i < n) {
        if (newInterval[0] <= intervals[i][0]) break;
        i++;
    }
    intervals.insert(intervals.begin() + i, newInterval); // O(n)

    // now, merge the intervals
    return mergeIntervals(intervals);
}

int main(void) {
    vector<vector<int>> intervals = {{1, 3}, {6, 9}};
    vector<int> newInterval = {2, 5};

    cout << "New Intervals: [";
    intervals = insert(intervals, newInterval);
    for (auto interval: intervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "], ";
    }
    cout << "\b\b]";

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/