// Generate Binary Strings Without Consecutive 1s

#include <iostream>
#include <vector>
using namespace std;

/*
    n = 3
    0
    00
    > 000
    > 001
    01
    > 010
    011 X

    1
    10
    > 100
    > 101
    11 X

    ['000', '001', '010', '100', '101']
*/

void recursive(vector<string>& ans, string& s, int i, int n) {
    if (i == n) {
        ans.push_back(s);
        return;
    }
    s += "0";
    recursive(ans, s, i + 1, n);
    s.pop_back();

    // Only add '1' if the previous character is not '1'
    if (i == 0 || s[i - 1] != '1') {
        s += "1";
        recursive(ans, s, i + 1, n);
        s.pop_back();
    }
}

vector<string> generateBinaries(int n) {
    vector<string> ans;
    int i = 0;
    string s = "";
    recursive(ans, s, i, n);
    return ans;
}

int main(void) {
    int n = 3;

    vector<string> binaryStrs = generateBinaries(n);
    cout << "All binary strings of size " << n << " and no consecutive ones are:\n[";
    for (string binary: binaryStrs) {
        cout << binary << ", ";
    }
    cout << "\b\b]\n";

    return 0;
}