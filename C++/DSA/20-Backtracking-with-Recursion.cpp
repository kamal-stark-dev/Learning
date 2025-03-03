// Backtracking

#include <iostream>
#include <vector>
using namespace std;

void printSubsets(vector<int>& arr, vector<int>& ans, int i) {
    if (i == arr.size()) {
        for (int n: ans) cout << n << " ";
        cout << "\n";
        return;
    }
    // include
    ans.push_back(arr[i]);
    printSubsets(arr, ans, i + 1);

    // exclude
    ans.pop_back();
    printSubsets(arr, ans, i + 1);
}

int main(void) {
    // subsets -> for `n` elements there are `2 ^ n` subsets
    vector<int> arr = {1, 2, 3};
    vector<int> ans; // store the subsets

    printSubsets(arr, ans, 0);

    return 0;
}