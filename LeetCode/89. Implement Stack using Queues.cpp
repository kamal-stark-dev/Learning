// 225. Implement Stack using Queues

#include <iostream>
#include <queue>
using namespace std;

class Stack {
public:
    queue<int> q1;
    queue<int> q2;

    Stack() {

    }

    void push(int val) {
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(val); // makes it new front
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop() {
        int top = q1.front();
        q1.pop();
        return top;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

int main(void) {
    Stack* s = new Stack();

    s->push(1);
    s->push(2);
    s->push(3);

    cout << s->pop() << endl;
    cout << s->top() << endl;

    return 0;
}