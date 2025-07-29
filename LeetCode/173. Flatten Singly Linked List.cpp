// Flatten a Singly Linked List Sorted

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:
    int val;
    Node *next, *child;

    Node(int data = 0, Node* next_ = nullptr, Node* child_ = nullptr) {
        val = data;
        next = next_;
        child = child_;
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
        temp = temp->child;
    }
    cout << "null\n";
}

Node* flattenList_Brute(Node* head) { // O(n), n -> total number of nodes
    Node* temp = head;
    Node* newHead = new Node(0);
    Node* nhead = newHead;
    while (temp) {
        nhead->next = new Node(temp->val);
        nhead = nhead->next;
        Node* ttemp = temp->child;
        while (ttemp) {
            nhead->next = new Node(ttemp->val);
            nhead = nhead->next;
            ttemp = ttemp->child;
        }
        temp = temp->next;
    }
    return newHead->next;
}

Node* sortList(Node* head) { // O(n logn)
    vector<int> nums;
    Node* temp = head;
    while (temp) {
        nums.push_back(temp->val);
        temp = temp->next;
    }
    sort(nums.begin(), nums.end());
    temp = head;
    for (int num: nums) {
        temp->val = num;
        temp = temp->next;
    }
    return head;
}

Node* mergeLists(Node* list1, Node* list2) {
    Node* dummy = new Node(-1);
    Node* res = dummy;

    while (list1 && list2) {
        if (list1->val < list2->val) {
            res->child = list1;
            res = list1;
            list1 = list1->child;
        }
        else {
            res->child = list2;
            res = list2;
            list2 = list2->child;
        }
    }
    if (list1) res->child = list1;
    else res->child = list2;

    if (dummy->child) dummy->child->next = nullptr;
    return dummy->child;
}

Node* flattenList(Node* head) {
    if (!head || !head->next) {
        return head;
    }

    Node* mergedHead = flattenList(head->next);
    head = mergeLists(head, mergedHead);
    return head;
}

int main(void) {
    Node* head = new Node(4);
    head->child = new Node(10);

    Node* second = new Node(2);
    head->next = second;
    second->child = new Node(5);
    second->child->child = new Node(20);

    Node* third = new Node(12);
    second->next = third;
    third->child = new Node(13);
    third->child->child = new Node(16);
    third->child->child->child = new Node(17);

    head = flattenList(head);
    head = sortList(head);
    printList(head);

    return 0;
}

/*
Optimal:
    Time Complexity: O(n * 2m) -> n is the nodes of main linked list, m is number of children we are merging
    Space Complexity: O(1), but recursive stack uses O(n) auxilary space
*/