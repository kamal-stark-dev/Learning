// 155. Min Stack

#include<iostream>
#include<stack>
using namespace std;

class MinStack {
public:
    stack<int> s;
    int minVal;

    MinStack() {

    }

    void push(int val) {
        if (s.empty()) {
            s.push(val);
            minVal = val;
        }
        else if (val < minVal) {
            s.push(2 * val - minVal);
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
    MinStack* minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);

    cout << minStack->getMin() << endl; // -3
    minStack->pop();

    cout << minStack->top() << endl; // 0
    cout << minStack->getMin() << endl; // -2

    return 0;
}
/*
Each function here has time complexity of O(1). <constant time complexity>
*/