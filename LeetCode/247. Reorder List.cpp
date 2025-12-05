// 143. Reorder List

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void reorderList(ListNode* head) {
    // find the middle node
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* curr = slow->next;
    slow->next = nullptr; // set first list end node next to nullptr

    // reverse the list
    ListNode *prev = nullptr, *temp = nullptr;
    while (curr) {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    // merge the two lists
    ListNode *first = head, *second = prev;
    ListNode *temp1 = nullptr, *temp2 = nullptr;
    while (second) {
        temp1 = first->next;
        temp2 = second->next;
        first->next = second;
        second->next = temp1;
        first = temp1;
        second = temp2;
    }
}

void display(ListNode* head) {
    ListNode* curr = head;
    while (curr) {
        cout << curr->val << "->";
        curr = curr->next;
    }
    cout << "NULL\n";
}

int main(void) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    display(head);
    reorderList(head);
    display(head);

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/