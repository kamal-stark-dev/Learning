// 138. Copy List with Random Pointer

#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node *next, *random;

    Node(int val_ = 0, Node* next_ = nullptr, Node* random_ = nullptr) {
        val = val_;
        next = next_;
        random = random_;
    }
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

Node* copyRandomList(Node* head) {
    if (!head) return nullptr;

    Node* temp = head;
    while (temp) {
        Node* next = temp->next;
        temp->next = new Node(temp->val);
        temp->next->next = next;
        temp = next;
    }

    temp = head;
    while (temp) {
        if (temp->random) {
            temp->next->random = temp->random->next;
        }
        temp = temp->next->next;
    }

    temp = head;
    Node* copyHead = head->next;
    while (temp) {
        Node* clone = temp->next;
        temp->next = clone->next;
        if (clone->next) {
            clone->next = clone->next->next;
        }
        temp = temp->next;
    }
    return copyHead;
}

int main(void) {
    Node* head = new Node(7);
    Node* second = new Node(13);
    Node* third = new Node(11);
    Node* fourth = new Node(10);
    Node* fifth = new Node(1);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    second->random = head;
    third->random = fifth;
    fourth->random = third;
    fifth->random = head;

    Node* copyHead = copyRandomList(head);
    printList(copyHead);

    cout << "Random Pointers Values:";
    while (copyHead) {
        if (!copyHead->random) cout << " null, ";
        else cout << copyHead->random->val << ", ";
        copyHead = copyHead->next;
    }
    cout << "\b\b \n";

    return 0;
}

/*
Time Complexity: O(n) -> O(3 * n) as we are traversing thrice in the list
Space Complexity: O(n), auxilary space to create deep copy of list
*/