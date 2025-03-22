// QUEUE - FIFO (First In First Out)

#include <iostream>
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

    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (empty()) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    void dequeue() {
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

    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    q.dequeue();

    cout << q.front() << endl;

    cout << (q.empty() ? "Empty" : "Not Empty") << ".\n";

    return 0;
}
/*
Time Complexity: O(1)
Space Complexity: O(1)
*/