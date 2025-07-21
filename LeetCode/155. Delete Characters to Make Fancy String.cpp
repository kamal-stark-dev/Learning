// 1957. Delete Characters to Make Fancy String

#include <iostream>
using namespace std;

string fancify(string s) {
    string res = "";
    for (char c: s) {
        int res_size = res.size();
        if (res_size < 2 || res[res_size - 1] != c || res[res_size - 2] != c) {
            res += c;
        }
    }
    return res;
}

string fancify_slightlyBetter(string s) {
    int idx = 0;
    for (char c: s) {
        if (idx < 2 || s[idx - 1] != s[idx - 2] || s[idx - 1] != c) {
            s[idx++] = c;
        }
    }
    return s.substr(0, idx);
}

int main(void) {
    string s = "kamalveeer";
    string fancy = fancify(s);

    cout << "Fancy string is `" << fancy << "`.\n";

    return 0;
}