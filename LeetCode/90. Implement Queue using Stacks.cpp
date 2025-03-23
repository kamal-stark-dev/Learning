// 232. Implement Queue using Stacks

#include <iostream>
#include <stack>
using namespace std;

class Queue {
public:
    stack<int> s1;
    stack<int> s2;

    Queue() {}

    void push(int val) { // O(n)
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(val);
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop() { // O(1)
        int top = s1.top();
        s1.pop();
        return top;
    }

    int peek() { // O(1)
        return s1.top();
    }

    bool empty() { // O(1)
        return s1.empty();
    }
};

int main(void) {
    Queue* q = new Queue();

    q->push(1);
    q->push(2);
    q->push(3);

    cout << q->pop() << endl; // 1
    cout << q->peek() << endl; // 2
}