// 25. Reverse Nodes in k-Group

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createLinkedList() {
    ListNode* head = new ListNode(1);
    ListNode* current = head;
    for (int i = 2; i <= 7; ++i) {
        current->next = new ListNode(i);
        current = current->next;
    }
    return head;
}

void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

// inplace reversal
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* temp = head;
    int i = 0;
    while (i < k) {
        if (temp == nullptr) {
            return head;
        }
        temp = temp->next;
        i++;
    }
    // call reverse for the rest of the nodes
    ListNode* prevNode = reverseKGroup(temp, k);

    // reverse k group
    temp = head;
    i = 0;
    while (i < k) {
        ListNode* next = temp->next;
        temp->next = prevNode;
        prevNode = temp;
        temp = next;
        i++;
    }
    return prevNode;
}

int main(void) {
    ListNode* list = createLinkedList();
    list = reverseKGroup(list, 2);
    printLinkedList(list);

    return 0;
}