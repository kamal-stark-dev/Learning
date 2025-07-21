// 1781. Sum of Beauty of All Substrings

#include <iostream>
#include <unordered_map>
using namespace std;

int beautySum(string s) {
    int n = s.length();

    int sum = 0;
    for (int i = 0; i < n; i++) {
        unordered_map<char, int> mpp;
        for (int j = i; j < n; j++) {
            mpp[s[j]]++;
            int mini = INT_MAX, maxi = INT_MIN;
            for (auto it: mpp) {
                mini = min(mini, it.second);
                maxi = max(maxi, it.second);
            }
            sum += (maxi - mini);
        }
    }
    return sum;
}

int main(void) {
    string s = "aabcb";

    int sum = beautySum(s);
    cout << "Sum of beauty of each substring of `" << s << "` is " << sum << "\n";

    return 0;
}