// 25. Reverse Nodes in k-Group

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

Node* reverseKGroup(Node* head, int k) {
    if (!head || !head->next) return head;

    Node* temp = head;
    int i = 0;
    while (i < k) {
        if (!temp) return head;
        temp = temp->next;
        i++;
    }
    Node* prev = reverseKGroup(temp, k);

    temp = head;
    i = 0;
    while (i < k) {
        Node* next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
        i++;
    }
    return prev;
}

int main(void) {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int k = 2;
    cout << "Reversed K Groups are: ";
    head = reverseKGroup(head, k);
    printList(head);

    return 0;
}