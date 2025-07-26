// Delete all occurences of a key in a double linked list

#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node *prev, *next;

    Node(int data = 0, Node* prev_ptr = nullptr, Node* next_ptr = nullptr) {
        val = data;
        prev = prev_ptr;
        next = next_ptr;
    }
};

void printList(Node* head) {
    if (!head) {
        cout << "List is empty!\n";
        return;
    }
    Node* temp = head;
    while (temp) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "null\n";
}

Node* deleteNode(Node* head, Node* nodeToDelete) {
    if (nodeToDelete == head) { // head
        head = head->next;
        if (head) head->prev = nullptr;
        delete nodeToDelete;
    }
    else if (nodeToDelete->next == nullptr) { // tail
        nodeToDelete->prev->next = nullptr;
        delete nodeToDelete;
    }
    else {
        nodeToDelete->prev->next = nodeToDelete->next;
        nodeToDelete->next->prev = nodeToDelete->prev;
        delete nodeToDelete;
    }
    return head;
}

Node* deleteAll(Node* head, int key) {
    Node* temp = head;
    while (temp) {
        Node* current = temp;
        temp = temp->next;
        if (current->val == key) head = deleteNode(head, current);
    }
    return head;
}

int main(void) {
    Node* head = new Node(1);
    Node* second = new Node(5);
    Node* third = new Node(1);
    Node* fourth = new Node(2);
    Node* fifth = new Node(1);

    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;

    fourth->next = fifth;
    fifth->prev = fourth;

    int key = 1;
    head = deleteAll(head, key);
    printList(head);

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/