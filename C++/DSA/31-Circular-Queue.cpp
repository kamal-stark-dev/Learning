// Circular Queue

#include <iostream>
using namespace std;

// has a fixed capacity

class CircularQueue {
public:
    int currSize, cap, front_, rear;
    int *cq;

    CircularQueue(int capacity) {
        cap = capacity;
        currSize = 0;
        cq = new int[capacity];
        front_ = 0;
        rear = -1;
    }

    bool empty() {
        return currSize == 0;
    }

    void push(int val) {
        if (currSize == cap) {
            cout << "Queue is full.\n";
            return;
        }
        rear = (rear + 1) % cap;
        cq[rear] = val;
        currSize++;
    }

    void pop() {
        if (empty()) {
            cout << "Queue is empty.\n";
        }
        front_ = (front_ + 1) % cap;
        currSize--;
    }

    int front() {
        if (empty()) {
            cout << "Queue is empty.\n";
            return -1;
        }
        return cq[front_];
    }

    void printArray() {
        for (int i = 0; i < cap; i++) cout << cq[i] << " ";
        cout << endl;
    }

    void printQueue() {
        int f = front_;
        int i = f;
        do {
            cout << cq[i] << " ";
            i = (i + 1) % cap;
        }
        while (i != f);
    }
};

int main(void) {
    CircularQueue cq(3);

    cq.push(1);
    cq.push(2);
    cq.push(3);

    cq.push(4); // full

    cq.pop(); // _ 2 3

    cq.push(4);

    cq.printArray(); // 4 2 3
    cq.printQueue(); // 2 3 4

    return 0;
}