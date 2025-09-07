// 51. N-Queens

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void backtrack(int row, int n, vector<string>& board, vector<vector<string>>& ans, unordered_set<int>& cols, unordered_set<int>& pos_diag, unordered_set<int>& neg_diag) {
    if (row == n) {
        ans.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (
            cols.find(col) == cols.end() &&
            pos_diag.find(row + col) == pos_diag.end() &&
            neg_diag.find(row - col) == neg_diag.end()
        ) {
            board[row][col] = 'Q';
            cols.insert(col);
            pos_diag.insert(row + col);
            neg_diag.insert(row - col);

            backtrack(row + 1, n, board, ans, cols, pos_diag, neg_diag);

            // backtracking
            board[row][col] = '.';
            cols.erase(col);
            pos_diag.erase(row + col);
            neg_diag.erase(row - col);
        }
    }
}

vector<vector<string>> findNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));

    unordered_set<int> cols, pos_diag, neg_diag;

    backtrack(0, n, board, ans, cols, pos_diag, neg_diag);
    return ans;
}

int main(void) {
    int n = 4;

    vector<vector<string>> res = findNQueens(n);

    cout << "Possible N-Queens are:\n";
    for (auto row: res) {
        for (string s: row) cout << s << "\n";
        cout << "\n";
    }

    return 0;
}

/*
Time Complexity: O(n!), in worst case same as typical N-Queens
Space Complexity: O(n ^ 2), O(n ^ 2) -> board, O(n) -> sets, O(n) -> recursion depth

Even more better approach would be to use arrays instead of using sets you can make array of booleans of size n for cols and size (2n - 2) for making pos_diag and neg_diag and set and unset those values while backtracking. (why 2n - 2 because largest idx value would be `(n - 1) + (n - 1)`).

NOTE: for negative diagonal (-ve indexes basically) we add (n - 1) to the difference making it positive (index = row - col + (n - 1)).
*/