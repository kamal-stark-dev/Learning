// 19. Remove Nth Node From End of List

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

Node* deleteFromLast_Brute(Node* head, int n) {
    int len = 0;
    Node* temp = head;
    while (temp) {
        len++;
        temp = temp->next;
    }

    int pos = len - n - 1;
    if (pos < 0) return head->next; // head needs to be removed

    temp = head;
    while (temp && pos > 0) {
        pos--;
        temp = temp->next;
    }
    if (temp->next) {
        temp->next = temp->next->next;
    }
    return head;
}

Node* deleteFromLast_Optimal(Node* head, int n) {
    Node* newHead = new Node(0, head);
    Node *slow = newHead, *fast = newHead;
    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }
    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return newHead->next;
}

int main(void) {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int n = 2; // delete the 2nd node from the last -> i.e. 4

    head = deleteFromLast_Optimal(head, n);
    printList(head);
}