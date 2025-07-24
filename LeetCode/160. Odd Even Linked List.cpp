// 328. Odd Even linked List

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

Node* oddEvenList(Node* head) {
    if (!head || !head->next) return head;

    Node *odd = head, *even = head->next, *evenHead = even;
    while (even && even->next) {
        odd->next = even->next;
        odd = odd->next;

        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

Node* oddEvenList_MyLogic(Node* head) {
    if (!head || !head->next) return head;

    Node *odd = head, *prev = head->next;
    while (prev && prev->next) {
        Node* temp = prev->next;
        prev->next = temp->next;
        temp->next = odd->next;
        odd->next = temp;
        odd = odd->next;
        prev = prev->next;
    }
    return head;
}

int main(void) {
    // 2,1,3,5,6,4,7
    Node* head = new Node(2);
    head->next = new Node(1);
    head->next->next = new Node(3);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(6);
    head->next->next->next->next->next = new Node(4);
    head->next->next->next->next->next->next = new Node(7);

    head = oddEvenList_MyLogic(head);

    cout << "Odd Even List: ";
    Node* curr = head;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}