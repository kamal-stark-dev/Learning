// 21. Merge Two Sorted Lists

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {
public:
    Node* head;
    Node* tail;

    List() {
        head = tail = NULL;
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    void print() {
        if (head == NULL) {
            cout << "List is empty.\n";
        }
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

Node* merge2Lists(Node* h1, Node* h2) { // recursive approach
    if (h1 == NULL || h2 == NULL) {
        return h1 == NULL ? h2 : h1;
    }
    if (h1->data <= h2->data) {
        h1->next = merge2Lists(h1->next, h2);
        return h1;
    }
    else {
        h2->next = merge2Lists(h1, h2->next);
        return h2;
    }
}

void printList(Node* pos) {
    if (pos == NULL) {
        cout << "List is empty.\n";
    }
    while (pos != NULL) {
        cout << pos->data << " -> ";
        pos = pos->next;
    }
    cout << "NULL\n";
}

int main(void) {
    List list1;
    list1.insert(1);
    list1.insert(2);
    list1.insert(4);

    cout << "List 1: ";
    list1.print();

    List list2;
    list2.insert(1);
    list2.insert(3);
    list2.insert(4);

    cout << "List 2: ";
    list2.print();

    cout << "Sorted: ";
    Node* sorted = merge2Lists(list1.head, list2.head);
    printList(sorted);

    return 0;
}
/*
Time Complexity: O(n + m)
Space Complexity: O(1) of merged list itself & O(n + m) due to recursion stack.
*/