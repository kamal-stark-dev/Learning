// Remove Duplicates from Sorted Doubly Linked List

#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node *prev, *next;

    Node(int data = 0, Node* prev_ptr = nullptr, Node* next_ptr = nullptr) {
        val = data;
        prev = prev_ptr;
        next = next_ptr;
    }
};

void printList(Node* head) {
    if (!head) {
        cout << "List is empty!\n";
        return;
    }
    Node* temp = head;
    while (temp) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "null\n";
}

void removeDuplicates(Node* head) {
    Node* current = head;
    while (current && current->next) {
        if (current->val == current->next->val) {
            Node* duplicate = current->next;
            if (duplicate->next) {
                duplicate->next->prev = duplicate->prev;
            }
            current->next = duplicate->next;

        }
        else {
            current = current->next;
        }
    }
}

int main(void) {
    Node* head = new Node(1);
    Node* second = new Node(1);
    Node* third = new Node(2);
    Node* fourth = new Node(3);
    Node* fifth = new Node(3);

    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;

    fourth->next = fifth;
    fifth->prev = fourth;

    removeDuplicates(head);
    printList(head);

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/