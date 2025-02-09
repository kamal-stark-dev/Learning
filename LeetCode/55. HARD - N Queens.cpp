// 51. N-Queens

#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<string>& board, int row, int col, int n) {
    // horizontal
    for (int i = 0; i < n; i++) {
        if (board[row][i] == 'Q') return false;
    }

    // vertical
    for (int i = 0; i < n; i++) {
        if (board[i][col] == 'Q') return false;
    }

    // upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }

    // lower left diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') return false;
    }

    return true; // Queen is SAFE
}

void nQueens(vector<string>& board, int row, int n, vector<vector<string>>& ans) {
    // base case
    if (row == n) {
        ans.push_back({board});
        return;
    }

    for (int j = 0; j < n; j++) {
        if (isSafe(board, row, j, n)) {
            board[row][j] = 'Q';
            nQueens(board, row + 1, n, ans);
            board[row][j] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<string> board (n, string(n, '.'));
    vector<vector<string>> ans;

    nQueens(board, 0, n, ans);
    return ans;
}

int main(void) {
    int n = 4;

    vector<vector<string>> allConfigurations = solveNQueens(n);

    for (auto configuration: allConfigurations) {
        for (string row: configuration) {
            for (char item: row) cout << item << " ";
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}

/*
Time Complexity: O(n! * n)
Space Complexity: board - O(n ^ 2), call stack - O(n), Result - O(n! * n ^ 2) [worst case] ==> O(n^2 + n + n! * n^2) ==> O(n! * n^2)
*/