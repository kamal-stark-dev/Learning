#include <iostream>
#include <vector>
#include <utility>
using namespace std;

pair<int, int> linearSearch(int mat[][3], int rows, int cols, int key) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] == key) return make_pair(i, j);
        }
    }
    return make_pair(-1, -1);
}

int maxRowSum(int mat[][3], int rows, int cols) {
    int currMax = INT_MIN;

    for (int i = 0; i < rows; i++) {
        int currSum = 0;
        for (int j = 0; j < cols; j++) {
            currSum += mat[i][j];
        }
        currMax = max(currMax, currSum);
    }
    return currMax;
}

int maxColSum(int mat[][3], int rows, int cols) {
    int maxSum = INT_MIN;

    for (int i = 0; i < cols; i++) {
        int currSum = 0;
        for (int j = 0; j < rows; j++) {
            currSum += mat[j][i];
        }
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

int diagonalSum(int mat[][3], int n) {
    int dSum = 0;
    for (int i = 0; i < n; i++) {
        dSum += mat[i][i];
        if (i != n - i - 1)
            dSum += mat[n - i - 1][i];
    }
    return dSum;
}

int main() {
    // 2 Dimensional Arrays -> Matrix (rows, cols)
    int rows = 4, cols = 3;
    int matrix[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};

    // this is how indexing works
    cout << "matrix[0][2]: " << matrix[0][2] << endl;

    // changing the value at an index
    matrix[3][2] = 16;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }

    // if you want to take input of entire matrix from user you can use the same loops with `cin` this time.

    /*
    NOTE: 2D arrays are also stored linearly like 1D arrays
    array = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    There are two ways to do the same:
        1. Row Major Order ==> {1, 2, 3, 4, 5, 6, 7, 8, 9}
        2. Col Mahor Order ==> {1, 4, 7, 2, 5, 8, 3, 6, 9}
    */

    // Linear Search in 2D array
    int key = 8;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == key) {
                cout << "Key present at the index: (" << i << ", " << j << ")\n";
            }
        }
    }
    // there is a function for the same above
    pair<int, int> idxs = linearSearch(matrix, rows, cols, key);
    cout << "Key is present at the index: [" << idxs.first << "][" << idxs.second << "]\n";

    // return the "Maximum Row Sum"
    int mat[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "max-row-sum: " << maxRowSum(mat, 3, 3) << endl;

    // do the same for "Maximum Column Sum"
    cout << "max-col-sum: " << maxColSum(mat, 3, 3) << endl;

    // Diagonal Sum ==> you are given a square matrix, return the sum of both diagonals (with to repetition of same element)
    int n = 3;
    cout << "diagonal-sum: " << diagonalSum(mat, n) << endl;

    // 2D vectors
    vector<vector<int>> nums = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rows = nums.size(), cols = nums[0].size();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }

    // in 2D vectors each row can have different number of columns
    cout << "\n2D vector with different columns:\n";
    nums = {{1, 2, 3}, {4, 5, 6, 7}, {8, 9}};
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums[i].size(); j++) {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
}

// WoW that was really cool!!