#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& mat, int target) {
    int m = mat.size();
    int n = mat[0].size();

    int r = 0, c = n - 1;
    while (r < m && c >= 0) {
        if(target == mat[r][c]) return true;
        else if (target < mat[r][c]) c--;
        else r++;
    }
    return false;
}

int main(void) {
    vector<vector<int>> mat = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    int target = 5;

    if(searchMatrix(mat, target)) cout << target << " is present in the matrix.\n";
    else cout << target << " is not present in the matrix.\n";

    return 0;
}

/*
Time Complexity: O(n + m)
Q. How?
-> r = 0 --> m (r++)
   c = n --> 0 (c--)
in worst case `r` goes to `m` and `c` goes to `0` -> (m + n)

NOTE: O(log(m * n)) is way better/faster than O(m + n)
*/