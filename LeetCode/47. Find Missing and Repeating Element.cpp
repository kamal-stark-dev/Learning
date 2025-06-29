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

vector<int> findMissingAndRepeatedValuesNums(vector<int> nums) {
    int n = nums.size();
    long long sn = (n * (n + 1)) / 2;
    long long s2n = (n * (n + 1) * (2 * n + 1)) / 6;
    int missing = -1, repeating = -1;

    long long s = 0, s2 = 0;
    for (int n: nums) {
        s += n;
        s2 += n * n;
    }

    int xmy = s - sn;
    int xpy = (s2 - s2n) / xmy;

    repeating = (xpy + xmy) / 2;
    missing = xpy - repeating;
    return {repeating, missing};
}

int main(void) {
    // vector<vector<int>> grid = {{1, 3}, {2, 2}};
    // vector<int> res = findMissingAndRepeatedValues(grid);

    vector<int> nums = {1, 2, 1, 4, 5};
    vector<int> res = findMissingAndRepeatedValuesNums(nums);

    cout << "Repeated: " << res[0] << ", Missing: " << res[1] << endl;
    return 0;
}