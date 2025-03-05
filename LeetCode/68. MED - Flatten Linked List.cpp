// 430. Flatten a Multilevel Doubly Linked List

#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int _val) {
        val = _val;
        prev = nullptr;
        next = nullptr;
        child = nullptr;
    }
};

class MultilevelDoublyLinkedList {
public:
    Node* head;

    MultilevelDoublyLinkedList() {
        head = nullptr;
    }

    void append(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            Node* curr = head;
            while (curr->next) {
                curr = curr->next;
            }
            curr->next = newNode;
            newNode->prev = curr;
        }
    }

    void addChild(Node* parent, int value) {
        Node* childNode = new Node(value);
        parent->child = childNode;
    }

    void printList(Node* node) {
        while (node) {
            cout << node->val << " ";
            node = node->next;
        }
        cout << endl;
    }

    // main function
    Node* flatten(Node* head) {
        if (!head) return head;
        Node* curr = head;
        while (curr) {
            if (curr->child) {
                // flatten child nodes
                Node* next = curr->next;
                curr->next = flatten(curr->child);
                curr->next->prev = curr;
                curr->child = nullptr;
                // find tail
                while(curr->next) {
                    curr = curr->next;
                }
                // attatch tail with next pointer
                if (next) {
                    curr->next = next;
                    next->prev = curr;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};

int main() {
    MultilevelDoublyLinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);

    list.addChild(list.head->next, 7); // Adding a child to the second node (value 2)
    list.addChild(list.head->next->child, 8); // Adding a child to the child node (value 7)

    list.printList(list.head);

    Node* flatten_head = list.flatten(list.head);
    list.printList(flatten_head);

    return 0;
}
/*
Time Complexity: O(n) for n nodes.
*/