// 417. Pacific Atlantic Water Flow

#include <iostream>
#include <set>
#include <vector>
using namespace std;

void dfs(int row, int col, vector<vector<bool>>& visit, const vector<vector<int>>& heights) {
    int ROWS = heights.size(), COLS = heights[0].size();
    vector<int> dirs = {-1, 0, 1, 0, -1};

    visit[row][col] = 1; // set as visited
    for (int i = 0; i < 4; i++) {
        int newRow = row + dirs[i];
        int newCol = col + dirs[i + 1];
        if (newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS && !visit[newRow][newCol] && heights[newRow][newCol] >= heights[row][col]) {
            dfs(newRow, newCol, visit, heights);
        }
    }
}

vector<vector<int>> pacificAtlantic(const vector<vector<int>>& heights) {
    int rows = heights.size(), cols = heights[0].size();
    if (rows == 0 || cols == 0) return {};

    vector<vector<bool>> pac(rows, vector<bool>(cols, false)), atl(rows, vector<bool>(cols, false));

    for (int c = 0; c < cols; c++) {
        dfs(0, c, pac, heights);
        dfs(rows - 1, c, atl, heights);
    }

    for (int r = 0; r < rows; r++) {
        dfs(r, 0, pac, heights);
        dfs(r, cols - 1, atl, heights);
    }

    vector<vector<int>> res;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (pac[r][c] == 1 && atl[r][c] == 1) {
                res.push_back({r, c});
            }
        }
    }
    return res;
}

int main(void) {
    vector<vector<int>> heights = {
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4}
    };

    vector<vector<int>> canReachBoth = pacificAtlantic(heights);
    cout << "[";
    for (auto cell: canReachBoth) {
        cout  << "[" << cell[0] << ", " << cell[1] << "], ";
    }
    cout << "\b\b]\n";

    return 0;
}

// at first I used sets for pac and atl visited structures but making a boolean matrix works faster

/*
Time Complexity: O(m * n)
Space Complexity: O(m * n), pac and atl arrays
*/

// below is the BFS approach for the same (better because it's iterative - prevents recursion depth issues)

/*
class Solution {
private:
    void bfs(queue<pair<int, int>>& q, vector<vector<bool>>& visit, vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        static int dirs[5] = {-1, 0, 1, 0, -1};

        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dirs[i];
                int nc = c + dirs[i + 1];
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !visit[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                    visit[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        if (rows == 0 || cols == 0) return {};

        vector<vector<bool>> pac(rows, vector<bool>(cols, false)),
                            atl(rows, vector<bool>(cols, false));
        queue<pair<int, int>> qPac, qAtl;

        // pacific left and top
        for (int r = 0; r < rows; r++) {
            qPac.push({r, 0});
            pac[r][0] = true;
        }
        for (int c = 0; c < cols; c++) {
            qPac.push({0, c});
            pac[0][c] = true;
        }

        // atlantic right and bottom
        for (int r = 0; r < rows; r++) {
            qAtl.push({r, cols - 1});
            atl[r][cols - 1] = true;
        }
        for (int c = 0; c < cols; c++) {
            qAtl.push({rows - 1, c});
            atl[rows - 1][c] = true;
        }

        // BFS for each ocean
        bfs(qPac, pac, heights);
        bfs(qAtl, atl, heights);

        vector<vector<int>> res;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (pac[r][c] && atl[r][c]) res.push_back({r, c});
            }
        }
        return res;
    }
};
*/