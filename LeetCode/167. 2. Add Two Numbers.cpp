// 2. Add Two Numbers

#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int data = 0, Node* next_ptr = nullptr) {
        val = data;
        next = next_ptr;
    }
};

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "null\n";
}

Node* addListNums(Node* head1, Node* head2) {
    Node *node1 = head1, *node2 = head2;
    int carry = 0, sum = 0;

    Node *ans = new Node(), *ansHead = ans;
    while (node1 && node2) {
        sum = node1->val + node2->val + carry;
        ans->next = new Node(sum % 10);
        carry = sum / 10;

        ans = ans->next;
        node1 = node1->next;
        node2 = node2->next;
    }
    while (node1) {
        sum = node1->val + carry;
        ans->next = new Node(sum % 10);
        carry = sum / 10;
        ans = ans->next;
        node1 = node1->next;
    }
    while (node2) {
        sum = node2->val + carry;
        ans->next = new Node(sum % 10);
        carry = sum / 10;
        ans = ans->next;
        node2 = node2->next;
    }
    if (carry != 0) {
        ans->next = new Node(carry);
    }
    return ansHead->next;
}

Node* addListNums_Concise(Node* l1, Node* l2) {
    Node *ansHead = new Node(0), *ans = ansHead;
    int carry = 0;

    while (l1 || l2 || carry) {
        int num1 = l1 ? l1->val : 0;
        int num2 = l2 ? l2->val : 0;
        int sum = num1 + num2 + carry;

        ans->next = new Node(sum % 10);
        ans = ans->next;
        carry = sum / 10;

        l1 = l1 ? l1->next : nullptr;
        l2 = l2 ? l2->next : nullptr;
    }
    return ansHead->next;
}

int main(void) {
    Node* head1 = new Node(2);
    head1->next = new Node(4);
    head1->next->next = new Node(3);

    Node* head2 = new Node(5);
    head2->next = new Node(6);
    head2->next->next = new Node(4);

    Node* ansHead = addListNums_Concise(head1, head2);
    printList(ansHead);

    return 0;
}

/*
Time Complexity: O( max( len(num1), len(num2) ) )
*/