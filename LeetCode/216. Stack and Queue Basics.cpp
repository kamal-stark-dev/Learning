// Stack and Queue

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* next = NULL;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// STACKS

class Stack {
private:
    int top_idx = -1;
    int st[10];
public:
    void push(int val) { // O(1)
        if (top_idx >= 10) {
            cerr << "Stack Overflow.\n";
            return;
        }
        top_idx++;
        st[top_idx] = val;
    }

    int top() { // O(1)
        if (top_idx == -1) {
            cerr << "Stack Underflow.\n";
            return -1;
        }
        return st[top_idx];
    }

    int pop() { // O(1)
        if (top_idx == -1) {
            cerr << "Stack Underflow.\n";
            return -1;
        }
        return st[top_idx--];
    }

    int size() { // O(1)
        return top_idx + 1;
    }
};

class StackLL {
private:
    Node* head = NULL;
    int stack_size = 0;
public:
    void push(int val) {
        Node* temp = new Node(val);
        temp->next = head;
        head = temp;
        stack_size++;
    }

    int top() {
        if (!head) {
            cerr << "Stack is empty.\n";
            return -1;
        }
        return head->data;
    }

    int pop() {
        if (!head) {
            cerr << "Stack is empty.\n";
            return -1;
        }
        int el = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        stack_size--;
        return el;
    }

    int size() {
        return stack_size;
    }
};

// QUEUES

class Queue {
private:
    static const int size_ = 10;
    int q[size_];
    int curr_size = 0, start = -1, end = -1;
public:
    void push(int val) {
        if (curr_size == size_) {
            cerr << "Queue is full.\n";
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
            cerr << "Queue is empty.\n";
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

    int front() {
        if (curr_size == 0) {
            cerr << "Queue is empty.\n";
            return -1;
        }
        return q[start];
    }

    int size() {
        return curr_size;
    }
};

class QueueLL {
private:
    Node* start = NULL;
    Node* end = NULL;
    int queue_size = 0;
public:
    void push(int val) {
        if (!start)
            start = end = new Node(val);
        else {
            end->next = new Node(val);
            end = end->next;
        }
        queue_size++;
    }

    int front() {
        if (!start) {
            cerr << "Queue is empty.\n";
            return -1;
        }
        return start->data;
    }

    int pop() {
        if (!start) {
            cerr << "Queue is empty.\n";
            return -1;
        }

        Node* temp = start;
        int el = start->data;

        start = start->next;
        if (!start) end = NULL;

        delete temp;
        queue_size--;

        return el;
    }

    int size() {
        return queue_size;
    }
};

// Stack from Queue

class StackFromQueue {
private:
    Queue q;
public:
    void push(int val) {
        int size = q.size();
        q.push(val);
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        return q.pop();
    }

    int top() {
        return q.front();
    }

    int size() {
        return q.size();
    }
};

// Queue from Stack

class QueueFromStack {
private:
    Stack s;
public:
    void push(int val) { // O(2n)
        Stack temp;
        while (s.size()) {
            temp.push(s.top());
            s.pop();
        }
        temp.push(val);
        while (temp.size()) {
            s.push(temp.top());
            temp.pop();
        }
    }

    int front() {
        return s.top();
    }

    int pop() {
        return s.pop();
    }

    int size() {
        return s.size();
    }
};

class QueueFromStack_2 { // Space -> 2 * n
private:
    Stack s1, s2;
public:
    void push(int val) { // O(1)
        s1.push(val);
    }

    int pop() { // Ocassionally -> O(n)
        if (s2.size()) {
            return s2.pop();
        }
        else {
            while (s1.size()) {
                s2.push(s1.top());
                s1.pop();
            }
            return s2.pop();
        }
    }

    int top() { // Ocassionally -> O(n)
        if (s2.size()) {
            return s2.top();
        }
        else {
            while (s1.size()) {
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }

    int size() {

    }
};

int main(void) {
    StackFromQueue s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout << "Popped Element: " << s.pop() << "\n";
    cout << "Top Element: " << s.top() << "\n";
    cout << "Size of Stack: " << s.size() << "\n\n";

    QueueFromStack q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout << "Popped Element: " << q.pop() << "\n";
    cout << "Front Element: " << q.front() << "\n";
    cout << "Size of Queue: " << q.size() << "\n";

}

// Stack -> a linear data structure that follows Last In First Out (LIFO) principle
// push(x), pop(), top(), empty()
// Benefits -> O(1) | Downside -> O(10) (not dynamic in nature)

// Queue -> a linear data structure that follows First In First Out (FIFO) principle
// push(x), pop(), top(), empty()