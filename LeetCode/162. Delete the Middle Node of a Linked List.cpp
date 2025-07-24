// 2095. Delete the Middle Node of a Linked List

#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int data, Node* next_ptr = nullptr) {
        val = data;
        next = next_ptr;
    }
};

void printList(Node* head) {
    Node* temp = head;
    if (!temp) cout << "List is empty.\n";
    while (temp) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "null\n";
}

Node* deleteMiddleNode_Brute(Node* head) {
    if (!head || !head->next) return nullptr;
    Node* temp = head;
    int len = 0;
    while (temp) {
        len++;
        temp = temp->next;
    }
    temp = head;
    int mid = (len + 1) / 2;
    for (int i = 0; i < mid - 1; i++) {
        temp = temp->next;
    }
    Node* middle = temp->next;
    temp->next = middle->next;
    delete middle;
    return head;
}

Node* deleteMiddleNode(Node* head) {
    if (!head || !head->next) return nullptr;

    Node *prev = nullptr, *slow = head, *fast = head;
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;
    delete slow;
    return head;
}

int main(void) {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int n = 2; // delete the 2nd node from the last -> i.e. 4

    head = deleteMiddleNode(head);
    printList(head);
}