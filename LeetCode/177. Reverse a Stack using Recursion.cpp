// Reverse a Stack using Recursion

#include <iostream>
#include <stack>
using namespace std;

void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << '\n';
}

void insert(stack<int>& st, int element) {
    stack<int> temp;

    while(!st.empty()) {
        temp.push(st.top());
        st.pop();
    }
    st.push(element);
    while(!temp.empty()) {
        st.push(temp.top());
        temp.pop();
    }
}

void reverseStack(stack<int>& st) {
    if (st.empty()) return;

    int temp = st.top();
    st.pop();
    reverseStack(st);
    insert(st, temp);
}

int main(void) {
    stack<int> st;
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);

    cout << "Stack: ";
    printStack(st);

    cout << "Reversed Stack: ";
    reverseStack(st);
    printStack(st);
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/