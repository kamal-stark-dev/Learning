// 48. Rotate Image

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotateImage_brute(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> rotatedImage(n, vector<int> (n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rotatedImage[j][(n - 1) - i] = matrix[i][j]; // found via dry run
        }
    }
    matrix = rotatedImage;
    return;
}

void rotateImage_optimal(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // transpose the matrix
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j ++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // reverse each row
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
    return;
}

int main(void) {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    rotateImage_optimal(matrix);

    for (auto row: matrix) {
        for (int n: row) cout << n << " ";
        cout << "\n";
    }

    return 0;
}

/*
Time Complexity:
    Brute: O(n ^ 2)
    Optimal: O(n ^ 2)

Space Complexity:
    Brute: O(n ^ 2)
    Optimal: O(1), inplace -> transpose and reverse rows
*/