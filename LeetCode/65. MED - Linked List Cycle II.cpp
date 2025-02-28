// 142. Linked List Cycle II

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    // below is a constructor
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool hasCycle = false;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) { // loop exists
                hasCycle = true;
                break;
            }
        }
        if (!hasCycle) {
            return NULL;
        }

        slow = head;
        ListNode* prev = NULL;
        while (slow != fast) {
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }
        prev->next = NULL; // to break the loop

        return slow;
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
    ListNode* result = solution.hasCycle(node1);
    cout << "The cycle starts from " << result->val << endl;

    // Clean up memory (not necessary in this example due to the cycle)
    node4->next = NULL; // break the loop to delete the nodes
    delete node1;
    delete node2;
    delete node3;
    delete node4;

    return 0;
}