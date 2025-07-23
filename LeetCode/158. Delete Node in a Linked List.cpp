// 237. Delete Node in a Linked List

#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int data) {
        val = data;
        next = nullptr;
    }
};

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "null\n";
}

void deleteNode(Node* node) {
    Node* temp = node->next;
    node->val = temp->val;
    node->next = temp->next;
    delete temp;
}

int main(void) {
    Node* head = new Node(4);
    head->next = new Node(5);
    head->next->next = new Node(1);
    head->next->next->next = new Node(9);

    // we are given that the provided node is not the tail node
    deleteNode(head->next->next); // 1
    printList(head);


    return 0;
}