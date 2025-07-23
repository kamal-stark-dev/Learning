// Doubly Linked List

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = prev = nullptr;
    }

    Node(int val, Node* n, Node* p) {
        data = val;
        next = n;
        prev = p;
    }
};

class DoublyList {
private:
    Node* head;
    Node* tail;
public:
    DoublyList() {
        head = tail = nullptr;
    }

    void insertAtTail(int val) {
        Node* node = new Node(val);
        if (!tail) {
            head = tail = node;
            return;
        }
        tail->next = node;
        node->prev = tail;
        tail = node;
    }

    void insertAtHead(int val) {
        Node* node = new Node(val);
        if (!head) {
            head = tail = node;
            return;
        }
        node->next = head;
        head->prev = node;
        head = node;
    }

    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "null\n";
    }

    void printReverseList() {
        cout << "null";
        Node* temp = tail;
        while (temp) {
            cout << " <- " << temp->data;
            temp = temp->prev;
        }
        cout << "\n";
    }

    void deleteNode(int val) {
        if (!head) return;
        Node* temp = head;

        if (temp->data == val) {
            head = temp->next;
            if (!head) {
                head->prev = nullptr;
                head = tail = nullptr;
                return;
            }
            delete temp;
            return;
        }

        while (temp && temp->data != val) {
            temp = temp->next;
        }
        if (!temp) return;
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }
        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        }
        delete temp; // remove the temp node
    }

    void reverseList() {
        if (!head || !head->next) return;
        Node* curr = head;
        Node* previous = nullptr;

        while (curr) {
            previous = curr->prev;
            curr->prev = curr->next;
            curr->next = previous;
            curr = curr->prev; // as the next node is now prev node
        }
        if (previous) {
            head = previous->prev;
            tail = head;
            while (tail && tail->next) {
                tail = tail->next;
            }
        }
    }
};

int main(void) {
    DoublyList dll;
    dll.insertAtHead(10);
    dll.insertAtTail(20);
    dll.insertAtTail(30);
    dll.printList();
    dll.reverseList();
    dll.printList();
    // dll.printReverseList();

    return 0;
}