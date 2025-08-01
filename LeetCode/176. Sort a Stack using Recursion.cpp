// We need to sort a stack but using recurison (only)

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

void insertSorted(stack<int>& st, int element) {
    if (st.empty() || st.top() >= element) {
        st.push(element);
    }
    else {
        int temp = st.top();
        st.pop();
        insertSorted(st, element);
        st.push(temp);
    }
}

void sortStack(stack<int>& st) {
    if (!st.empty()) {
        int top = st.top();
        st.pop();
        sortStack(st);
        insertSorted(st, top);
    }
    return;
}

int main(void) {
    stack<int> st;
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(1);

    cout << "Stack: ";
    printStack(st);

    cout << "Sorted Stack: ";
    sortStack(st); // O(n ^ 2)
    printStack(st); // O(n)

    return 0;
}

/*
Time Complexity: O(n ^ 2), because each element may have to move all others to get inserted at correct position.
Space Complexity: O(n), for recursion stack.
*/