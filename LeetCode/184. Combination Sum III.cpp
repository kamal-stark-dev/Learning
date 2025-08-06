// 216. Combination Sum III

#include <iostream>
#include <vector>
using namespace std;

void recursive(int num, int sum, int k, int target,vector<int>& curr, vector<vector<int>>& ans) {
    if (sum == target && curr.size() == k) {
        ans.push_back(curr);
        return;
    }

    // base-case
    if (num == 10 || sum > target || curr.size() > k) return;

    // include
    curr.push_back(num);
    recursive(num + 1, sum + num, k, target, curr, ans);

    // not-include
    curr.pop_back();
    recursive(num + 1, sum, k, target, curr, ans);
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> combinations;
    vector<int> curr;
    recursive(1, 0, k, n, curr, combinations);
    return combinations;
}

int main(void) {
    int k = 3, n = 9;

    vector<vector<int>> combinations = combinationSum3(k, n);

    for (auto row: combinations) {
        for (int num: row) cout << num << " ";
        cout << "\n";
    }

    return 0;
}

/*
Time Complexity: O(C(9, k)), combination of (9, k) -> since we explore all combinations of size k out of 9
Space Complexity: O(k), for recursion stack and current combination [Note: Auxilary Space would be O(k * C(9, k))]
*/

/*
The above recursive function can also be written like this -

```cpp
void recursive(int num, int sum, int k, int target, vector<int>& curr, vector<vector<int>>& ans) {
    if (sum == target && curr.size() == k) {
        ans.push_back(curr);
        return;
    }

    // base-case
    if (sum > target || curr.size() > k) return;

    for (int i = num; i < 10; i++) {
        curr.push_back(i);
        recursive(i + 1, sum + i, k, target, curr, ans);
        curr.pop_back();
    }
}
```
*/