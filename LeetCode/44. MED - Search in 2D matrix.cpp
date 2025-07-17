#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& mat, int target) { // O(log(rows * cols))
    int rows = mat.size(), cols = mat[0].size();
    int left = 0, right = rows - 1, mid = -1;

    while(left <= right) { // O(log.rows)
        int mid = left + (right - left) / 2;
        if (mat[mid][0] <= target && target <= mat[mid][cols - 1]) {
            // sub binary search in row
            int start = 0, end = cols - 1;
            while (left <= right) { // O(log.cols)
                int sub_mid = (start + end) / 2;
                if (target == mat[mid][sub_mid]) return true;
                else if (target > mat[mid][sub_mid]) left = mid + 1;
                else right = mid - 1;
            }
            return false;
        }
        else if (target >= mat[mid][cols - 1]) left = mid + 1;
        else if (target <= mat[mid][0]) right = mid - 1;
    }
    return false;
}

bool searchMatrix_Easier(vector<vector<int>>& mat, int target) {
    int m = mat.size(), n = mat[0].size();
    int left = 0, right = (m * n) - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int row = mid / m, col = mid % m;
        if (mat[row][col] == target) return true;
        else if (mat[row][col] < target) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}

int main(void) {
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 11;

    if(searchMatrix_Easier(matrix, target)) cout << target << " is present in the matrix.\n";
    else cout << target << " is not present in the matrix.\n";

    return 0;
}

/*
Time Complexity: O(logm + logn) ==> O(log (m * n))
*/