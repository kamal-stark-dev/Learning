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

int lengthLinkedList(Node* head) {
    Node* temp = head;
    int len = 0;
    while (temp) {
        len++;
        temp = temp->next;
    }
    return len;
}

bool searchLinkedList(Node* head, int key) {
    Node* temp = head;
    while (temp) {
        if (temp->data == key) return true;
        temp = temp->next;
    }
    return false;
}

int main(void) {
    Node* head = new Node(10); // new keyword is used to dynamically allocate memory

    cout << "Memory value of head: " << head << '\n';
    cout << "Value of head node: " << head->data << '\n';

    insertNode(head, 20);
    insertNode(head, 30);
    insertNodeAtHead(head, 0);
    printLinkedList(head);

    cout << "The length of the linked list is " << lengthLinkedList(head) << ".\n";

    int key1 = 20, key2 = 50;
    cout << key1 << " is" << (searchLinkedList(head, key1) ? "": " not") << " present in the list.\n";
    cout << key2 << " is" << (searchLinkedList(head, key2) ? "": " not") << " present in the list.\n";

    return 0;
}