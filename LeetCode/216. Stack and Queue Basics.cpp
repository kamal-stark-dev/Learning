// Stack and Queue

#include <iostream>
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

    int top() {
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

    int top() {
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

int main(void) {
    StackLL s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout << "Popped Element: " << s.pop() << "\n";
    cout << "Top Element: " << s.top() << "\n";
    cout << "Size of Stack: " << s.size() << "\n\n";

    QueueLL q;
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