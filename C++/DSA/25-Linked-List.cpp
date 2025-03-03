// Linked List - Linear Data Structure (Dynamic)

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() {}

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {
private:
    Node* head;
    Node* tail;
public:
    List() {
        head = tail = NULL;
    }

    ~List() {
        Node* temp = head;
        while (temp != NULL) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        head = tail = NULL;
    }

    void push_front(int val) { // O(1)
        Node* newNode = new Node(val); // dynamic
        /*
        Node newNode(val); // will do the same job but it's static
        So, it'll be removed when the function ends & we don't want that
        */
        if (head == NULL) { // list is empty
            head = tail = newNode;
        }
        else { // when list is not empty
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val) { // O(1) and O(n) without tail
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front() { // O(1)
        if (head == NULL){
            cout << "List is Empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;

        if (head == NULL) { // if list become empty
            tail = NULL;
        }
    }

    void pop_back() { // O(n)
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        if (head == tail) { // only one element remains
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next != tail) { // if you don't have "tail" then use `tail->next->next != tail)`
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail; // delete keyword deletes it's heap memory not the variable
        tail = temp;
    }

    void insert(int val, int pos) { // O(n)
        if (pos < 0) {
            cout << "Invalid Position.\n";
            return;
        }
        if (pos == 0) { // inserting at the first position
            push_front(val);
            return;
        }

        Node* temp = head;
        for (int i = 0; i < pos - 1; i++) {
            if (temp == NULL) {
                cout << "Invalid Position.\n";
                return;
            }
            if (temp->next == NULL) {
                break;
            }
            temp = temp->next;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    int search(int val) { // O(n)
        Node* temp = head;
        int i = 0;
        while (temp != NULL) {
            if (temp->data == val) {
                cout << val << " found at index " << i << endl;
                return i;
            }
            temp = temp->next;
            i++;
        }
        cout << val << " is not present in the list.\n";
        return -1;
    }

    void print_list() { // O(n)
        if (head == NULL) {
            cout << "List is Empty.\n";
            return;
        }

        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    List my_list;

    // push_front
    my_list.push_front(1);
    my_list.push_front(2);
    my_list.push_front(3);

    // push_back
    my_list.push_back(2);
    my_list.push_back(3);

    // print_list
    my_list.print_list();

    // pop_front
    my_list.pop_front();

    // pop_back
    my_list.pop_back();

    // insert
    my_list.insert(10, 4);

    // search
    int idx = my_list.search(10);

    my_list.print_list();
}

// Reference: https://www.programiz.com/dsa/linked-list