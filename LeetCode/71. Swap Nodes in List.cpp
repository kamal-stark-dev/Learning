// 24. Swap Nodes in Pairs

#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;

    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node* next) : val(x), next(next) {}
};

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* swapNodes(Node* head) {
    if (!head || !head->next) return head;

    Node* first = head;
    Node* second = head->next;
    Node* prev = nullptr;

    while (first && second) {
        Node* third = second->next;
        first->next = third;
        second->next = first;
        if (prev) {
            prev->next = second;
        }
        else {
            head = second;
        }

        prev = first;
        first = third;
        if (third) {
            second = third->next;
        }
        else second = nullptr;
    }
    return head;
}

int main(void) {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    // list => 1 2 3 4 X

    printList(head);

    head = swapNodes(head);
    printList(head);

    return 0;
}