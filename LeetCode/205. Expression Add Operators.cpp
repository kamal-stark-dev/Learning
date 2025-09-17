// 282. Expression Add Operators

#include <iostream>
#include <vector>
using namespace std;

 void solve(int idx, long currRes, long lastFactor, string path, string num, int target, vector<string>& ans) {
    if (idx == num.size()) {
        if (currRes == target) ans.push_back(path);
        return;
    }

    long currNum = 0;

    for (int i = idx; i < num.size(); i++) {
        if (i > idx && num[idx] == '0') break; // stop further processing

        currNum = currNum * 10 + (num[i] - '0');
        string currStr = num.substr(idx, i - idx + 1);

        if (idx == 0) {
            solve(i + 1, currNum, currNum, currStr, num, target, ans);
        }
        else {
            // idx, currRes, lastFactor, path, num, target, ans
            solve(i + 1, currRes + currNum, currNum, path + "+" + to_string(currNum), num, target, ans);
            solve(i + 1, currRes - currNum, -currNum, path + "-" + to_string(currNum), num, target, ans);
            solve(i + 1, currRes - lastFactor + lastFactor * currNum, lastFactor * currNum, path + "*" + currStr, num, target, ans);
        }
    }
}

vector<string> addOperators(string num, int target) {
    vector<string> ans;
    if (num.empty()) return ans;
    solve(0, 0, 0, "", num, target, ans);
    return ans;
}

int main(void) {
    string num = "232";
    int target = 8;

    vector<string> res = addOperators(num, target);

    for (const string s: res) {
        cout << s << "\n";
    }

    return 0;
}

/*
Time Complexity: O()
Space Complexity: O()
*/