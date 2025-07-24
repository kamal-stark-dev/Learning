// 160. Intersection of Two Linked Lists

#include <iostream>
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

Node* intersection(Node* headA, Node* headB) {
    Node *nodeA = headA, *nodeB = headB;
    while (nodeA != nodeB) {
        if (nodeA) nodeA = nodeA->next;
        else nodeA = headB;
        if (nodeB) nodeB = nodeB->next;
        else nodeB = headA;
    }
    return nodeA;
}

int main(void) {
    Node* headA = new Node(4);
    headA->next = new Node(1);
    headA->next->next = new Node(8);
    headA->next->next->next = new Node(4);
    headA->next->next->next->next = new Node(5);

    Node* headB = new Node(5);
    headB->next = new Node(6);
    headB->next->next = new Node(1);
    headB->next->next->next = headA->next->next; // intersection

    /*
           4, 1 ->
                  -> 8, 4, 5
        5, 6, 1 ->
    */
    cout << "There is an intersection at node: " << intersection(headA, headB)->val << "\n";

    return 0;
}