// Linked List Implementation

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

void insertNode(Node* head, int val) {
    Node* temp = head;
    Node* newNode = new Node(val);
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertNodeAtHead(Node*& head, int val) {
    Node* node = new Node(val);
    node->next = head;
    head = node;
}

void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main(void) {
    Node* head = new Node(10); // new keyword is used to dynamically allocate memory

    cout << "Memory value of head: " << head << '\n';
    cout << "Value of head node: " << head->data << '\n';

    insertNode(head, 20);
    insertNode(head, 30);
    insertNodeAtHead(head, 0);
    printLinkedList(head);

    return 0;
}