// 148. Sort List

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

Node* sortList(Node* head) {
    Node* temp = head;
    vector<int> nums;
    while (temp) {
        nums.push_back(temp->val);
        temp = temp->next;
    }

    temp = head;
    sort(nums.begin(), nums.end());
    for (int num: nums) {
        temp->val = num;
        temp = temp->next;
    }
    return head;
}

int main(void) {
    Node* head = new Node(4);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(3);

    head = sortList(head);
    cout << "Sorted List: ";
    printList(head);

    return 0;
}