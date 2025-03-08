// Stacks go brrr...

#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

class Stack_V {
private:
    vector<int> v;
public:
    void push(int val) { // O(1)
        v.push_back(val);
    }

    int top() { // O(1)
        if (empty()) {
            cout << "Stack is empty.\n";
            return -1;
        }
        return v[v.size() - 1];
    }

    void pop() { // O(1)
        if (empty()) {
            cout << "Stack is empty.\n";
            return;
        }
        v.pop_back();
    }

    bool empty() {
        return v.size() == 0 ? true : false;
    }
};

class Stack_LL {
private:
    list<int> ll;
public:
    void push(int val) {
        ll.push_front(val);
    }

    int top() {
        if (ll.size() == 0) {
            cout << "List is empty.\n";
            return -1;
        }
        return ll.front();
    }

    void pop() {
        if (ll.size() == 0) {
            cout << "List is empty.\n";
            return;
        }
        ll.pop_front();
    }

    bool empty() {
        return ll.size() == 0 ? true : false;
    }
};

int main(void) {
    // LIFO - Last In First Out Structure
    // Stack_V s;
    // Stack_LL s;
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    s.top();
    s.pop();
}

/*
Applications -> Call stack in memory
*/