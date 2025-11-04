// Prefix, Infix and Postfix Conversions

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

bool isalnum(char c) { // O(1)
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) return true;
    return false;
}

int getPriority(char c) { // O(1)
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

string specialReverse(string s) { // O(n)
    // reverses the string and replaces `(` with `)` and vice-versa
    reverse(s.begin(), s.end());
    for (char &c: s) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }
    return s;
}

string infixToPostfix(string infix) { // O(n)
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

string infixToPrefix(string infix) { // O(n)
    // steps: reverse the infix, infix to postfix, reverse the postfix
    infix = specialReverse(infix);
    string prefix;
    stack<char> st;

    for (char c: infix) {
        if (isalnum(c)) prefix += c;
        else if (c == '(') st.push(c);
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                prefix += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();
        }
        else {
            while (!st.empty() &&
            ((c == '^' && getPriority(c) <= getPriority(st.top())) ||
            (c != '^' && getPriority(c) < getPriority(st.top())))) {
                prefix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        prefix += st.top();
        st.pop();
    }

    reverse(prefix.begin(), prefix.end());
    return prefix;

    // detailed time complexity: O(n){1st reverse} + O(2 * n){postfix conversion} + O(n / 2){last reverse}
}

string postfixToInfix(string postfix) { // O(n + n{string concatenation})
    stack<string> st;

    for (char c: postfix) {
        if (isalnum(c)) st.push(string(1, c));
        else {
            string operand2 = st.top();
            st.pop();
            string operand1 = st.top();
            st.pop();
            st.push("(" + operand1 + string(1, c) + operand2 + ")"); // in worst case can go upto: O(n)
        }
    }
    return st.top();
}

int main(void) {
    string infix = "a+b*(c^d-e)";
    cout << "Postfix of `" << infix << "` is: `" << infixToPostfix(infix) << "`.\n";

    infix = "(A+B)*C-D+E";
    cout << "Prefix of `" << infix << "` is: `" << infixToPrefix(infix) << "`.\n";

    string postfix = "AB-CD+E*/";
    cout << "Infix of `" << postfix << "` is: `" << postfixToInfix(postfix) << "`.\n";


    return 0;
}

/*
Infix to Postfix:
    Time Complexity: O(n) -> O(n{characters} + n{operators (worst case)})
    Space Complexity: O(n) -> O(n{stack (worst case)} + n{ans})
*/