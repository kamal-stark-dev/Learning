// Circular Linked List

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

class CircularList {
    Node* head;
    Node* tail;

public:
    CircularList() {
        head = tail = nullptr;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
            tail->next = head;
            return;
        }
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
            tail->next = head;
            return;
        }
        tail->next = newNode;
        newNode->next = head;
        tail = newNode;
    }

    void pop_front() {
        if (head == nullptr) {
            cout << "Circular list is empty.\n";
            return;
        }
        if (head == tail) { // only one element
            delete head;
            head = tail = nullptr;
            return;
        }
        Node* temp = head;
        head = head->next;
        tail->next = head;
        temp->next = nullptr;
        delete temp;
    }

    void pop_back() {
        if (head == nullptr) {
            cout << "Circlar list is empty.\n";
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        tail->next = nullptr;
        delete tail;
        temp->next = head;
        tail = temp;
    }

    void show() {
        if (head == nullptr) {
            cout << "Circular list is empty.\n";
            return;
        }
        Node* temp = tail->next;
        do { // found a place where using do while is ideal to use :)
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << "\b> " << temp->data << "\n"; // circle
    }
};

int main() {
    CircularList cll;

    cll.push_front(2);
    cll.push_front(1);
    cll.push_back(3);
    cll.push_front(4);

    cll.pop_front();
    cll.pop_back();

    cll.show();
}