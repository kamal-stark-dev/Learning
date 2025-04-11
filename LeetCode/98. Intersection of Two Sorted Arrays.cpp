#include <bits/stdc++.h>
using namespace std;

vector<int> findIntersection(vector<int> a, vector<int> b) {
    int n = a.size(), m = b.size();
    int i = 0, j = 0;
    vector<int> common;

    while (i < n && j < m) {
        if (a[i] == b[j]) {
            common.push_back(a[i]);
            i++; j++;
        }
        else if (a[i] < b[j]) i++;
        else j++;
    }
    return common;
}

int main(void) {
    vector<int> a = {1, 1, 2, 3, 4, 5};
    vector<int> b = {2, 3, 4, 4, 5, 6};

    vector<int> unionArr = findIntersection(a, b);

    for (int n : unionArr) cout << n << " ";
    return 0;
}
/*
Time Complexity:
    Average Case -> min(n, m)
    Worst Case -> O(n + m) -> no common element
Space Complexity:
    Computation: O(1)
    Storing: O(min(n, m))
*/