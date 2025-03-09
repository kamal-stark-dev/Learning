// 20. Valid Parentheses

#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '{' || c == '(' || c == '[')
            st.push(c);
        else {
            if (st.empty()) return false;
            if ((c == ')' && st.top() == '(') ||
                (c == '}' && st.top() == '{') ||
                (c == ']' && st.top() == '[')) {
                    st.pop();
            }
            else return false;
        }
    }
    return st.size() == 0;
}

int main(void) {
    string s = "[({}){}]"; // make sure no spaces or other chracters are their

    cout << (isValid(s) ? "True" : "False") << endl;
    return 0;
}
/*
Time Complexity: O(n)
Space Complexity: O(n)
*/