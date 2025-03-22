// QUEUE - FIFO (First In First Out)

#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Queue {
public:
    Node* head;
    Node* tail;

    Queue() {
        head = tail = nullptr;
    }

    void push(int val) {
        Node* newNode = new Node(val);
        if (empty()) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    void pop() {
        if (empty()) {
            cout << "Queue is Empty.\n";
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }
        Node* newHead = head->next;
        delete head;
        head = newHead;
    }

    int front() {
        if (empty()) {
            cout << "Queue is empty.\n";
            return -1;
        }
        return head->data;
    }

    bool empty() {
        return head == nullptr;
    }
};

int main(void) {
    /*
    All takes O(1) time complexity:
        push -> from rear (enqueue)
        pop -> from front (dequeue)
        front -> look at front
    */

    // Queue q;
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);

    q.pop();

    cout << q.front() << endl;

    cout << (q.empty() ? "Empty" : "Not Empty") << ".\n";

    return 0;
}
/*
Time Complexity: O(1)
Space Complexity: O(1)
*/