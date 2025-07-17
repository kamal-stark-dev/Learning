// 1901. Find a Peak Element II

#include <iostream>
#include <vector>
using namespace std;

vector<int> findPeakGrid_Brute(vector<vector<int>>& matrix) { // O(m * n)
    int m = matrix.size(), n = matrix[0].size();

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i > 0 && matrix[i][j] <= matrix[i - 1][j]) continue;
            if (i < m - 1 && matrix[i][j] <= matrix[i + 1][j]) continue;
            if (j > 0 && matrix[i][j] <= matrix[i][j - 1]) continue;
            if (j < m - 1 && matrix[i][j] <= matrix[i][j + 1]) continue;
            else return {i, j};
        }
    }
    return {-1, -1};
}

vector<int> findPeakGrid(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();

    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // find the max idx in mid column
        int max_row = 0;
        for (int i = 0; i < m; i++) {
            if (matrix[i][mid] > matrix[max_row][mid]) max_row = i;
        }

        // check for left and right elements
        int left_val = (mid > 0) ? matrix[max_row][mid - 1] : -1;
        int right_val = (mid < n - 1) ? matrix[max_row][mid + 1] : -1;

        if (matrix[max_row][mid] > left_val && matrix[max_row][mid] > right_val) return {mid, max_row};
        else if (matrix[max_row][mid] < right_val) left = mid + 1;
        else right = mid - 1;
    }

    return {-1, -1};
}

int main(void) {
    vector<vector<int>> matrix = {
        {1, 4},
        {3, 2}
    };

    // vector<vector<int>> matrix = {
    //     {10, 80, 82, 70, 60, 50, 40},
    //     {25, 90, 88, 85, 65, 55, 45},
    //     {20, 84, 86, 81, 68, 58, 48},
    //     {18, 50, 48, 45, 42, 40, 38},
    //     {22, 55, 45, 60, 65, 95, 92},
    //     {24, 58, 43, 62, 70, 100, 96},
    //     {28, 60, 40, 58, 68, 94, 91}
    // };

    vector<int> index = findPeakGrid(matrix);
    cout << "[" << index[0] << ", " << index[1] << "]\n";

    return 0;
}