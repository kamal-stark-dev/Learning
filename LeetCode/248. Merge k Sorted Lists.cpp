// 23. Merge k Sorted Lists

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
};

ListNode* merge(ListNode* list1, ListNode* list2) { // TC: O(n), SC: O(1)
    ListNode dummy;
    ListNode* curr = &dummy;

    while (list1 && list2) {
        if (list1->val < list2->val) {
            curr->next = list1;
            list1 = list1->next;
        }
        else {
            curr->next = list2;
            list2 = list2->next;
        }
        curr = curr->next;
    }
    curr->next = list1 ? list1 : list2;
    return dummy.next;
}

ListNode* mergeKLists_Brute(vector<ListNode*> lists) { // TC: O(n * k), SC: O(1)
    if (lists.size() == 0) return nullptr;

    while (lists.size() > 1) {
        int n = lists.size();
        lists[0] = merge(lists[0], lists[n - 1]);
        lists.pop_back();
    }
    return lists[0];
}

ListNode* mergeKLists_Optimal(vector<ListNode*> lists) { // TC: O(n logk), SC: O(k)
    if (lists.size() == 0) return nullptr;

    while (lists.size() > 1) {
        vector<ListNode*> mergedLists = {};
        int n = lists.size();
        for (int i = 0; i < n; i += 2) {
            ListNode* list1 = lists[i];
            ListNode* list2 = (i + 1 < n) ? lists[i + 1] : nullptr;
            mergedLists.push_back(merge(list1, list2));
        }
        lists = mergedLists;
    }
    return lists[0];
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
    ListNode* root1 = new ListNode(1);
    root1->next = new ListNode(4);
    root1->next->next = new ListNode(5);

    ListNode* root2 = new ListNode(1);
    root2->next = new ListNode(3);
    root2->next->next = new ListNode(4);

    ListNode* root3 = new ListNode(2);
    root3->next = new ListNode(6);

    vector<ListNode*> lists = {root1, root2, root3};

    ListNode* mergedSortedList = mergeKLists_Optimal(lists);
    display(mergedSortedList);

    return 0;
}

/*
k -> size of lists
n -> total number of nodes

Time Complexity: O(n logk)
Space Complexity: O(k)
*/