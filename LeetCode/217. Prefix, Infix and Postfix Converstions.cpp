// Prefix, Infix and Postfix Conversions

#include <iostream>
#include <stack>
using namespace std;

bool isalnum(char c) {
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) return true;
    return false;
}

int getPriority(char c) {
    switch(c) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return -1;
    }
}

string infixToPostfix(string infix) {
    string postfix;
    stack<char> st;

    for (char c: infix) {
        // if it's operand add to result
        if (isalnum(c)) postfix += c;

        else if (c == '(') st.push('(');
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            while (!st.empty() && getPriority(c) <= getPriority(st.top())) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

int main(void) {
    string infix = "a+b*(c^d-e)";
    string postfix = infixToPostfix(infix);

    cout << "Postfix of `" << infix << "` is: `" << postfix << "`.\n";

    return 0;
}

/*
Infix to Postfix:
    Time Complexity: O(n) -> O(n{characters} + n{operators (worst case)})
    Space Complexity: O(n) -> O(n{stack (worst case)} + n{ans})
*/