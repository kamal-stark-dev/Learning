// 46. Permutations

#include <iostream>
#include <vector>
using namespace std;

void getPerms(vector<int>& nums, int idx, vector<vector<int>>& permutations) {
    if (idx == nums.size()) {
        permutations.push_back({nums});
        return;
    }

    // starting from idx as we are making choice for the idx'th element
    for (int i = idx; i < nums.size(); i++) {
        swap(nums[idx], nums[i]);
        getPerms(nums, idx + 1, permutations);

        swap(nums[idx], nums[i]); // re-swap to origional form (backtracking)
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> permutations;
    getPerms(nums, 0, permutations); // calling the helper function

    return permutations;
}

int main(void) {
    vector<int> nums = {1, 2, 3};
    /*
    Return all the possible permutations of this -
    123, 132, 213, 231, 312, 321 -> 6 permutations for 123

    NOTE: for a `n` elements we have `n!` permutations for the same (n = 3, n! = 3 x 2 x 1 = 6)
    */

    vector<vector<int>> permutations = permute(nums);

    for (vector<int> permutation : permutations) {
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << endl;
    }
}

/*
Time Complexity: O(n! * n) -> taking n choices for n! calls
Space Complexity: O(n!) -> we are doing inplace swaps (n! -> for permutations array storage)

NOTE: Now, can you find the permutations for a string ?

> Below is the code for the same ~
```cpp
#include<iostream>
#include<vector>
using namespace std;

void permute(string str, int idx, vector<string>& permutations) {
    if (idx == str.length()) {
        permutations.push_back(str);
        return;
    }

    for (int i = idx; i < str.length(); i++) {
        swap(str[i], str[idx]);
        permute(str, idx + 1, permutations);
        swap(str[i], str[idx]);
    }
}

vector<string> getPerms(string str) {
    vector<string> permutations;
    permute(str, 0, permutations);

    return permutations;
}

int main(void) {
    string str = "abc";

    vector<string> permutations = getPerms(str);

    for (string s : permutations) {
        cout << s << endl;
    }
}
```
*/