// 79. Word Search

#include <iostream>
#include <vector>
using namespace std;

bool check(int row, int col, int idx, vector<vector<char>>& board, string word) {
    if (idx >= word.size()) return true;
    if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[idx]) return false;

    char temp = board[row][col];

    board[row][col] = '$';
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool found = false;
    for (auto [dr, dc]: directions) {
        found = found || check(row + dr, col + dc, idx + 1, board, word);
    }
    /*
    bool found = (
        check(row + 1, col, idx + 1, board, word) ||
        check(row - 1, col, idx + 1, board, word) ||
        check(row, col + 1, idx + 1, board, word) ||
        check(row, col - 1, idx + 1, board, word)
    );
    */
    board[row][col] = temp; // backtrack -> or `board[row][col] = word[idx]`

    return found;
}

// a little more optimized approach

bool exists(vector<vector<char>>& board, string word) {
    int m = board.size(), n = board[0].size();

    bool answer = false;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (check(i, j, 0, board, word))
                return true;
        }
    }
    return false;
}

int main(void) {
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    string word = "ABCCED";

    cout << (exists(board, word) ? "True": "False") << "\n";

    return 0;
}

/*
Time Complexity: O(m * n * (4 ^ L)), L -> length of the word and as we will be checking all four directions we have 4 choices
    - check: O(4 ^ L)
Space Complexity: O(L), the maximum recursion depth is L
*/