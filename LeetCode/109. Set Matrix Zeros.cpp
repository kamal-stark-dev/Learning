#include <iostream>
#include <vector>
using namespace std;

void setRowColZeros(vector<vector<int>>& mat, int row, int col) {
    int m = mat.size(), n = mat[0].size();

    for (int i = 0; i < m; i++) mat[i][col] = -1;
    for (int i = 0; i < n; i++) mat[row][i] = -1;
}

void setMatrixZeros_Brute(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0) {
                setRowColZeros(mat, i, j);
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == -1) {
                mat[i][j] = 0;
            }
        }
    }
}

void setMatrixZeros_Better(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    vector<bool> rows(m, false);
    vector<bool> cols(n, false);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0) {
                rows[i] = true;
                cols[j] = true;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (rows[i] || cols[j]) {
                mat[i][j] = 0;
            }
        }
    }
    return;
}

void setMatrixZeros(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    int col0 = 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0) {
                mat[i][0] = 0;
                if (j != 0) mat[0][j] = 0;
                else col0 = 0;
            }
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (mat[i][0] == 0 || mat[0][j] == 0) {
                mat[i][j] = 0;
            }
        }
    }

    if (mat[0][0] == 0) {
        for (int i = 0; i < m; i++) {
            mat[i][0] = 0;
        }
    }

    if (col0 == 0) {
        for (int i = 0; i < n; i++) {
            mat[0][i] = 0;
        }
    }
    return;
}

int main(void) {
    vector<vector<int>> mat = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    setMatrixZeros(mat);

    for (auto row: mat) {
        for (int n: row) {
            cout << n << " ";
        }
        cout << '\n';
    }

    return 0;
}