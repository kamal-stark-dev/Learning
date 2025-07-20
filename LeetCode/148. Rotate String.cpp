// 796. Rotate String

#include <iostream>
using namespace std;

bool validRotateString(string s, string goal) {
    int n = s.size();
    if (s.length() != goal.length()) return false;

    for (int i = 0; i < n; i++) {
        if (goal == s.substr(i) + s.substr(0, i)) return true;
    }
    return false;
}

bool validRotateString_2(string s, string goal) {
    if (s.length() != goal.length()) return false;
    return (s + s).find(goal) != string::npos;
}

int main(void) {
    string s = "abcde", goal = "cdeab";
    cout << "Strings `" << s << "` and `" << goal << "` are" << (validRotateString_2(s, goal) ? "": " not") << " valid rotate strings.\n";

    return 0;
}