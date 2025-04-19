// 73. Set Matrix Zeroes

#include <vector>
#include <iostream>
using namespace std;

void setZeros(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<int> rows(n), cols(m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                rows[i] = 1;
                cols[j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (rows[i] || cols[j]) {
                matrix[i][j] = 0;
            }
        }
    }
    return;
}

int main(void) {
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    setZeros(matrix);

    for (auto row : matrix) {
        for (int n : row) {
            cout << n << " ";
        }
        cout << "\n";
    }

    return 0;
}

/*
Time Complexity: O(2 * m * n)
Space Complexity: O(n) + O(m)

You can't lower down the time complexity further, but the space complexity can be optimized (making the rows and cols inplace in matrix)
*/