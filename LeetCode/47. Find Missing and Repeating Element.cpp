// 2965. Find Missing and Repeated Values

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> findMissingAndRepeatedValues(vector<vector<int>> grid) {
    vector<int> ans;
    unordered_set<int> s;
    int n = grid.size();
    int a, b;

    int actualSum = 0, expSum = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            actualSum += grid[i][j];

            if (s.find(grid[i][j]) != s.end()) {
                a = grid[i][j];
                ans.push_back(a);
            }
            s.insert(grid[i][j]);
        }
    }
    // a -> repeated num, b -> missing num
    // expwSum + a - b = actualSum
    expSum = (n * n) * (n * n + 1) / 2;
    b = expSum + a - actualSum;
    ans.push_back(b);

    return ans;
}

int main(void) {
    vector<vector<int>> grid = {{1, 3}, {2, 2}};
    vector<int> res = findMissingAndRepeatedValues(grid);

    cout << "Repeated: " << res[0] << ", Missing: " << res[1] << endl;
    return 0;
}