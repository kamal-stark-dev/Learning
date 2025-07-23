// 206. Reverse Linked List

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() {
        data = 0;
        next = NULL;
    }
    Node(int x) {
        data = x;
        next = NULL;
    }
    Node(int x, Node* n) {
        data = x;
        next = n;
    }
};

class List {
private:
    Node* head;
public:
    List() {
        head = NULL;
    }

    void insert(int x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
    }

    void print_list() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void reverse_list() {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    Node* recursive_reverse(Node* head) {
        if (!head || !head->next) {
            return head;
        }

        Node* newHead = recursive_reverse(head->next);

        // backtracking part
        Node* front = head->next;
        front->next = head;
        head->next = nullptr;

        return newHead;
    }

    void reverse_list_recursion() {
        head = recursive_reverse(head);
    }
};

int main(void) {
    List myList;
    myList.insert(1);
    myList.insert(2);
    myList.insert(3);
    myList.insert(4);
    myList.insert(5);

    cout << "Original List: ";
    myList.print_list();

    // myList.reverse_list();
    myList.reverse_list_recursion();

    cout << "Reversed List: ";
    myList.print_list();

    return 0;
}