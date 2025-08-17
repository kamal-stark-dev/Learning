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

// void insertAtBottom(stack<int>& st, int element) {
//     stack<int> temp;

//     while(!st.empty()) {
//         temp.push(st.top());
//         st.pop();
//     }
//     st.push(element);
//     while(!temp.empty()) {
//         st.push(temp.top());
//         temp.pop();
//     }
// }

void insertAtBottom(stack<int>& st, int element) {
    if (st.empty()) {
        st.push(element);
        return;
    }
    int elem = st.top();
    st.pop();
    insertAtBottom(st, element);
    st.push(elem);
}

void reverseStack(stack<int>& st) {
    if (st.empty()) return;

    int temp = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, temp);
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
Time Complexity: O(n * n)
Space Complexity: O(n)
*/