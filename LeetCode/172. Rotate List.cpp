// 61. Rotate List

#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int data = 0, Node* next_ptr = nullptr) : val(data), next(next_ptr) {}
};

void printList(Node* head) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    while (temp) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "null\n";
}

Node* rotateList_MyApproach(Node* head, int k) {
    if (!head || !head->next || k == 0) return head;

    int len = 1;
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
        len++;
    }
    k = k % len;
    if (k == 0) return head;
    int skip = len - k;

    Node *prev = nullptr, *tail = temp;
    temp = head;
    while (skip) {
        prev = temp;
        temp = temp->next;
        skip--;
    }
    prev->next = nullptr;
    Node* prevHead = head;

    head = temp;
    tail->next = prevHead;

    return head;
}

Node* rotateList_CycleApproach(Node* head, int k) {
    if (!head || !head->next || !k) return head;

    Node* tail = head;
    int len = 1;
    while (tail->next) {
        tail = tail->next;
        len++;
    }

    k = k % len;
    if (!k) return head;

    tail->next = head; // make the list circular
    int skip = len - (k % len);
    while (skip) {
        tail = tail->next;
        skip--;
    }
    head = tail->next;
    tail->next = nullptr;
    return head;
}

int main(void) {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int k = 3;
    head = rotateList_CycleApproach(head, k);
    printList(head);

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/