// Median of Row Wise Sorted Matrix

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countLessOrEqual(vector<vector<int>>& matrix, int m, int n, int target) { // O(m * logn)
    int count = 0;
    for (int i = 0; i < m; i++) {
        // you can also implement your own upper-bound function
        count += upper_bound(matrix[i].begin(), matrix[i].end(), target) - matrix[i].begin();
    }
    return count;
}

int median(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    int left = INT_MAX, right = INT_MIN;

    for (int i = 0; i < m; i++) { // O(m)
        left = min(left, matrix[i][0]);
        right = max(right, matrix[i][n - 1]);
    }

    int required = (m * n) / 2;
    while (left <= right) { // O(log R * m * logn), R is range from min_val to max_val in matrix
        int mid = left + (right - left) / 2;
        int count = countLessOrEqual(matrix, m, n, mid); // O(m * logn)
        if (count <= required) left = mid + 1;
        else right = mid - 1;
    }
    return left;
}

int main(void) {
    vector<vector<int>> matrix = {
        {1, 4, 9},
        {2, 5, 6},
        {3, 8, 7}
    };

    cout << "The median of the row wise sorted matrix is " << median(matrix) << "\n";

    return 0;
}

/*
Time Complexity: O(log R * m * logn), R in worst case would be (10^9) if nums are in range [1 - 10^9]
*/