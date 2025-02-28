// 876. Middle of the Linked List

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

    void middle_brute() {
        int len = 0;
        Node* temp = head;
        while (temp != NULL) {
            len++;
            temp = temp->next;
        }
        int mid = len / 2;
        temp = head;
        for(int i = 0; i < mid; i++) {
            temp = temp->next;
        }
        cout << "The middle of list is: " << temp->data << "\n";
    }

    void middle_slowFast() { // single loop
        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next; // +1
            fast = fast->next->next; // +2
        }
        cout << "The middle of list is: " << slow->data << "\n";
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

    myList.middle_brute();
    myList.middle_slowFast();

    return 0;
}
/*
Time Complexity: O(n)
Space Complexity: O(1)
*/