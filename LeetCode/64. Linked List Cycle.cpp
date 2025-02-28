// 141. Linked List Cycle

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    // below is a constructor
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) { // loop exists
                return true;
            }
        }
        return false; // no loop exists
    }
};

// Example usage
int main() {
    // Create a linked list with a cycle for testing
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2; // Creates a cycle

    Solution solution;
    bool result = solution.hasCycle(node1);
    std::cout << "Cycle detected: " << (result ? "Yes" : "No") << std::endl;

    // Clean up memory (not necessary in this example due to the cycle)
    node4->next = NULL; // break the loop to delete the nodes
    delete node1;
    delete node2;
    delete node3;
    delete node4;

    return 0;
}