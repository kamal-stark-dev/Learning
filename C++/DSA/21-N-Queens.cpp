// N Queens -> You have a board of size (N x N) and you need to place N queens such that they all are safe ~

#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<string>& board, int row, int col, int n) { // O(n)
    // horizontal check
    for (int i = 0; i < n; i++) {
        if (board[row][i] == 'Q') return false;
    }

    // vertical check
    for (int i = 0; i < n; i++) {
        if (board[i][col] == 'Q') return false;
    }

    // we only need to check the upper left and right diagonals as their are no queens below

    // upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }

    // upper right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') return false;
    }

    // their is no conflict with any queen
    return true;
}

void nQueens(vector<string>& board, int row, int n, vector<vector<string>>& ans) {
    if (row == n) {
        ans.push_back({board});
        return;
    }

    for (int j = 0; j < n; j++) {
        if (isSafe(board, row, j, n)) {
            board[row][j] = 'Q';
            nQueens(board, row + 1, n, ans);
            board[row][j] = '.'; // backtrack
        }
    }
}

vector<vector<string>> solveNQueens(int rows) {
    vector<string> board(rows, string(rows, '.'));
    vector<vector<string>> ans;

    nQueens(board, 0, rows, ans);
    return ans;
}

int main(void) {
    int rows = 4;
    vector<vector<string>> allConfigurations = solveNQueens(rows);

    for (auto configuration: allConfigurations) {
        for (string row: configuration) {
            cout << row << endl;
        }
        cout << endl;
    }
}

/*
Time Complexity: O(n! * n) ==> first Q has n choices and the next has (n - 1) choices and then (n - 2), (n - 3), ..., 1 ==> n!
Space Complexity: O(n! * n^2)
*/