// Union of Two Sorted Arrays

#include <bits/stdc++.h>
using namespace std;

vector<int> findUnion(vector<int> a, vector<int> b) {
    int n = a.size(), m = b.size();
    int i = 0, j = 0;
    vector<int> unionArr;

    while (i < n && j < m) {
        if (a[i] <= b[j]) {
            if (unionArr.size() == 0 || unionArr.back() != a[i]) {
                unionArr.push_back(a[i]);
            }
            i++;
        }
        else {
            if (unionArr.size() == 0 || unionArr.back() != b[j]) {
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }

    while (i < n) {
        if (unionArr.size() == 0 || unionArr.back() != a[i]) {
            unionArr.push_back(a[i]);
        }
        i++;
    }

    while (j < m) {
        if (unionArr.size() == 0 || unionArr.back() != b[j]) {
            unionArr.push_back(b[j]);
        }
        j++;
    }

    return unionArr;
}

int main(void) {
    vector<int> a = {1, 1, 2, 3, 4, 5};
    vector<int> b = {2, 3, 4, 4, 5, 6};

    vector<int> unionArr = findUnion(a, b);

    for (int n : unionArr) cout << n << " ";
    return 0;
}

/*
Time Complexity: O(n + m)
Space Complexity: O(1) -> computing & O(n + m) -> storing union
*/