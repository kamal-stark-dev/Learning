// Find the row with maximum number of 1's

#include <iostream>
#include <vector>
using namespace std;

int maxOnesRow_Better(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    int maxOnes = 0, rowIdx = -1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 1) {
                if (n - mat[i][j] > maxOnes) {
                    maxOnes = n - mat[i][j];
                    rowIdx = i;
                }
                break;
            }
        }
    }
    return rowIdx;
}

int firstIndexOf(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int idx = nums.size();

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target) {
            if (nums[mid] == target) idx = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }
    return idx;
}

int maxOnesRow(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    int onesCnt = 0, idx = -1;

    for (int i = 0; i < m; i++) {
        int count = n - firstIndexOf(mat[i], 1);
        if (count > onesCnt) {
            onesCnt = count;
            idx = i;
        }
    }
    return idx;
}

int main(void) {
    vector<vector<int>> mat = {
        {1, 1, 1},
        {0, 0, 1},
        {0, 0, 0}
    };

    // we need to find the index of the first row with maximum ones
    cout << "The row with maximum ones is at index: " << maxOnesRow(mat) << ".\n";

    return 0;
}

/*
Time Complexity: O(m * logn), m -> rows, n -> cols
*/