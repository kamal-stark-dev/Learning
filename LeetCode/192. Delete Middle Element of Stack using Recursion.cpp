// Delete Middle Element of Stack using Recusrion

#include <iostream>
#include <stack>
using namespace std;

int findLength(stack<int> st) {
    int len = 0;
    while (!st.empty()) {
        st.pop();
        len++;
    }
    return len;
}

void deleteMiddle(stack<int>& st, int len, int i = 0) {
    if (i == len / 2) {
        st.pop();
        return;
    }

    int elem = st.top();
    st.pop();
    deleteMiddle(st, len, i + 1);
    st.push(elem);
}

int main(void) {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);

    int stackLength = findLength(st);
    deleteMiddle(st, stackLength);

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << "\n";

    return 0;
}

/*
Time Complexity: O(n), 1.5 * n -> to find the length and remove middle element
Space Complexity: O(n), 0.5 * n -> recursion stack
*/