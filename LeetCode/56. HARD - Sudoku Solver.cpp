// 37. Sodoku Solver

#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<vector<char>> board, int row, int col, char digit) {

    // check for row and col
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == digit) return false;
        if (board[i][col] == digit) return false;
    }

    // check for block
    int srow = (row / 3) * 3, scol = (col / 3) * 3;
    for (int i = srow; i < srow + 3; i++) {
        for (int j = scol; j < scol + 3; j++) {
            if (board[i][j] == digit) return false;
        }
    }

    return true;
}

bool solve(vector<vector<char>>& board, int row, int col) {
    // base case
    if (row == 9) {
        return true;
    }

    int nextR = row, nextC = col + 1;
    if (col == 9) {
        nextR = row + 1;
        nextC = 0;
    }

    if (board[row][col] != '.') return solve(board, nextR, nextC);

    for (char digit = '1'; digit <= '9'; digit++) {
        if (isSafe(board, row, col, digit)) {
            board[row][col] =  digit;
            if (solve(board, nextR, nextC)) return true;
            board[row][col] = '.';
        }
    }

    return false;
}

vector<vector<char>> solveSudoku(vector<vector<char>>& board) {
    int row = 0, col = 0;
    solve(board, row, col);
    return board;
}

int main(void) {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    solveSudoku(board);

    for (vector<char> row : board) {
        for (char n : row) {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}