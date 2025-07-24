// Sort a linked list of 0's, 1's and 2's

#include <iostream>
#include <vector>
#include <algorithm>
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

Node* sortList_Brute(Node* head) {
    int zeros = 0, ones = 0, twos = 0;
    Node* temp = head;
    while (temp) {
        if (temp->val == 0) zeros++;
        else if (temp->val == 1) ones++;
        else twos++;
        temp = temp->next;
    }

    temp = head;
    while (zeros) {
        temp->val = 0;
        temp = temp->next;
        zeros--;
    }
    while (ones) {
        temp->val = 1;
        temp = temp->next;
        ones--;
    }
    while (twos) {
        temp->val = 2;
        temp = temp->next;
        twos--;
    }
    return head;
}

Node* sortList(Node* head) {
    Node *zerosHead = new Node(0), *onesHead = new Node(0), *twosHead = new Node(0);
    Node *zeros = zerosHead, *ones = onesHead, *twos = twosHead, *temp = head;

    while (temp) {
        if (temp->val == 0) {
            zeros->next = temp;
            zeros = zeros->next;
        }
        else if (temp->val == 1) {
            ones->next = temp;
            ones = ones->next;
        }
        else {
            twos->next = temp;
            twos = twos->next;
        }
        temp = temp->next;
    }
    zeros->next = onesHead->next ? onesHead->next : twosHead->next;
    ones->next = twosHead->next;
    twos->next = nullptr;

    head = zerosHead->next;
    delete zerosHead;
    delete onesHead;
    delete twosHead;
    return head;
}

int main(void) {
    Node* head = new Node(1);
    head->next = new Node(0);
    head->next->next = new Node(2);
    head->next->next->next = new Node(0);
    head->next->next->next->next = new Node(1);

    head = sortList(head);
    cout << "Sorted List: ";
    printList(head);

    return 0;
}