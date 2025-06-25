#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotateImage_Brute(vector<vector<int>>& mat) { // O(n ^ 2) & O(n ^ 2) space
    int n = mat.size();
    vector<vector<int>> rotated(n, vector<int> (n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rotated[j][n - i - 1] = mat[i][j];
        }
    }
    mat = rotated;
    return;
}

void rotateImage(vector<vector<int>>& mat) { // O(2 * (n ^ 2)) -> O(n ^ 2)
    int n = mat.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }

    for (int i = 0; i < n; i++) {
        reverse(mat[i].begin(), mat[i].end());
    }
}

int main(void) {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    rotateImage_Brute(mat);

    for (auto row: mat) {
        for (int n: row) {
            cout << n << " ";
        }
        cout << '\n';
    }

    return 0;
}