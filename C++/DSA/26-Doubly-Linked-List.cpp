// Doubly Linked List
/*
Types of Linked List:
    1. Singly Linked List
    2. Doubly Linked List
    3. Circular Linked List

Doubly Linked List Structure -> Data | Next | Prev, making each node point to it's next and previous nodes.
*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        prev = next = nullptr;
    }
};

class DoublyList {
private:
    Node* head;
    Node* tail;
public:
    DoublyList() {
        head = tail = nullptr;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void show() {
        if (head == nullptr) {
            cout << "Doubly list is empty.\n";
            return;
        }
        Node* temp = head;
        while(temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void pop_front() {
        if (head == nullptr) {
            cout << "Doubly list is empty.\n";
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = tail = nullptr;
            return;
        }
        Node* temp = head;
        head = head->next;
        head->prev = nullptr;
        temp->next = nullptr;
        delete temp;
    }

    void pop_back() {
        if (head == nullptr) {
            cout << "Doubly list is empty.\n";
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = tail = nullptr;
            return;
        }

        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        temp->prev = nullptr;
        delete temp;
    }
};

#include <iostream>
using namespace std;

int main() {
    DoublyList dll;

    dll.push_back(1);
    dll.push_back(2);
    dll.push_back(3);

    dll.pop_back();
    dll.pop_back();
    dll.pop_back();

    dll.show();

    return 0;
}