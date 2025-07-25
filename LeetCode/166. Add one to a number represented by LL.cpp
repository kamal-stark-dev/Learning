// Add one to a number represented by LL

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

Node* addOne_Brute(Node* head) {
    int num = 0;
    Node* temp = head;

    // fetch the number
    while (temp) {
        int currDigit = temp->val;
        num *= 10;
        num += currDigit;
        temp = temp->next;
    }
    // delete the previous nodes in the number
    temp = head;
    while (temp) {
        Node* del = temp;
        temp = temp->next;
        delete del;
    }
    head = nullptr;
    num++;

    // create nodes for new number
    while (num != 0) {
        int digit = num % 10;
        num /= 10;
        Node* node = new Node(digit, head);
        head = node;
    }
    return head;
}


Node* reverse(Node* head) { // O(n)
    Node *prev = nullptr, *curr = head;
    while (curr) {
        Node* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

Node* addOne(Node* head) { // O(n)
    head = reverse(head);

    Node* temp = head;
    int sum = 0, carry = 1;
    while (temp) {
        sum = temp->val + carry;
        temp->val = sum % 10;
        carry = sum / 10;

        if (carry == 0) break;

        if (temp->next == nullptr && carry != 0) {
            temp->next = new Node(carry);
            carry = 0;
            break;
        }
        temp = temp->next;
    }

    head = reverse(head);
    return head;
}

int main(void) {
    Node* head = new Node(6);
    head->next = new Node(8);

    head = addOne(head);
    printList(head);

    return 0;
}