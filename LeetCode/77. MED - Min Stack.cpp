// 155. Min Stack

#include<iostream>
#include<stack>
using namespace std;

class MinStack_Simple { // TC: O(1), SC: O(2 * n)
private:
    stack<int> st;
    stack<int> min_st;
public:
    MinStack_Simple() {}

    void push(int val) {
        if (st.empty() || val <= min_st.top()) {
            min_st.push(val);
        }
        st.push(val);
    }

    void pop() {
        if (st.top() == min_st.top()) min_st.pop();
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return min_st.top();
    }
};

class MinStack {
private:
    stack<long long> s;
    long long minVal;
public:

    MinStack() {
        minVal = INT_MAX;
    }

    void push(int val) {
        if (s.empty()) {
            s.push(val);
            minVal = val;
        }
        else if (val < minVal) {
            s.push((long long) 2 * val - minVal);
            minVal = val;
        }
        else {
            s.push(val);
        }
    }

    void pop() {
        if (s.top() < minVal) {
            minVal = 2 * minVal - s.top();
        }
        s.pop();
    }

    int top() {
        if (s.top() < minVal) return minVal;
        return s.top();
    }

    int getMin() {
        return minVal;
    }
};

int main(void) {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);

    cout << minStack.getMin() << endl; // -3
    minStack.pop();

    cout << minStack.top() << endl; // 0
    cout << minStack.getMin() << endl; // -2

    return 0;
}
/*
Each function here has time complexity of O(1). <constant time complexity>

Time Complexity: O(1)
Space Complexity: O(n)
*/