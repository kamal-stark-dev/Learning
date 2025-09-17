// 36. Valid Sudoku

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool checkBoard(vector<vector<char>>& board) {
    int n = board.size(), m = board[0].size(); // both are 9 x 9 but to make it flexible

    vector<unordered_set<char>> rows(n);
    vector<unordered_set<char>> cols(n);
    vector<unordered_set<char>> boxes(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char val = board[i][j];
            int b = (i / 3) * 3 + (j / 3);

            if (val != '.') {
                if (rows[i].find(val) != rows[i].end()
                || cols[j].find(val) != cols[j].end()
                || boxes[b].find(val) != boxes[b].end()) {
                    return false;
                }

                rows[i].insert(val);
                cols[j].insert(val);
                boxes[b].insert(val);
            }
        }
    }
    return true;
}

bool checkBoard_2(vector<vector<char>>& board) {
    bool rows[9][9] = {false};
    bool cols[9][9] = {false};
    bool boxes[9][9] = {false};

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.') {
                int num = board[i][j] - '1'; // '1' -> 0
                int boxIdx = (i / 3) * 3 + (j / 3);

                if (rows[i][num] || cols[num][j] || boxes[boxIdx][num]) return false;
                rows[i][num] = cols[num][j] = boxes[boxIdx][num] = true;
            }
        }
    }
    return true;
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

    cout << (checkBoard_2(board) ? "True": "False") << "\n";

    return 0;
}

/*
Time Complexity: O(1), because we have taken constant size 9 for our sudoku grid. [O(m * n) for varying values]
Space Complexity: O(1) or O(m * n) depending on constant or varying sizes.
*/