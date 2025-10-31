// Stack and Queue

#include <iostream>
using namespace std;

class Stack {
private:
    int top_idx = -1;
    int st[10];
public:
    void push(int val) { // O(1)
        if (top_idx >= 10) {
            cout << "Stack Overflow.\n";
            return;
        }
        top_idx++;
        st[top_idx] = val;
    }

    int top() { // O(1)
        if (top_idx == -1) {
            cout << "Stack Underflow.\n";
            return -1;
        }
        return st[top_idx];
    }

    int pop() { // O(1)
        if (top_idx == -1) {
            cout << "Stack Underflow.\n";
            return -1;
        }
        return st[top_idx--];
    }

    int size() { // O(1)
        return top_idx + 1;
    }
};

class Queue {
private:
    static const int size_ = 10;
    int q[size_];
    int curr_size = 0, start = -1, end = -1;
public:
    void push(int val) {
        if (curr_size == size_) {
            cout << "Queue is full.\n";
            return;
        }
        if (curr_size == 0)
            start = end = 0;
        else
            end = (end + 1) % size_;
        q[end] = val;
        curr_size++;
    }

    int pop() {
        if (curr_size == 0) {
            cout << "Queue is empty.\n";
            return -1;
        }
        int el = q[start];
        if (curr_size == 1)
            start = end = -1;
        else
            start = (start + 1) % size_;
        curr_size--;
        return el;
    }

    int top() {
        if (curr_size == 0) {
            cout << "Queue is empty.\n";
            return -1;
        }
        return q[start];
    }

    int size() {
        return curr_size;
    }
};

int main(void) {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout << "Popped Element: " << s.pop() << "\n";
    cout << "Top Element: " << s.top() << "\n";
    cout << "Size of Stack: " << s.size() << "\n\n";

    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout << "Popped Element: " << q.pop() << "\n";
    cout << "Front Element: " << q.top() << "\n";
    cout << "Size of Queue: " << q.size() << "\n";

}

// Stack -> a linear data structure that follows Last In First Out (LIFO) principle
// push(x), pop(), top(), size()
// Benefits -> O(1) | Downside -> O(10) (not dynamic in nature)

// Queue -> a linear data structure that follows First In First Out (FIFO) principle
// push(x), pop(), top(), size()