// Deque - Double Ended Queue

#include <iostream>
#include <deque>
using namespace std;

// can be implemented by doubly linked list

int main(void) {
    deque<int> dq;

    dq.push_front(1);
    dq.push_back(2);
    dq.push_back(3);
    dq.push_front(0);

    // 0 1 2 3

    dq.pop_back(); // 0 1 2
    dq.pop_front(); // 1 2

    cout << "Front: " << dq.front() << endl; // 1
    cout << "Back : " << dq.back() << endl; // 2

    return 0;
}