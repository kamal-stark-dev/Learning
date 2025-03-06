// 234. Palindrome Linked List
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> vals;
        ListNode* current = head;
        while (current != NULL) {
            vals.push_back(current->val);
            current = current->next;
        }
        int left = 0, right = vals.size() - 1;
        while (left < right) {
            if (vals[left] != vals[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    bool isPalindromeOptimal(ListNode* head) {
        if (!head || !head->next) return true; // Edge case: empty or single element

        ListNode* fast = head;
        ListNode* slow = head;

        // find middle (slow)
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // reverse second half of the list
        ListNode* reversedHead = reverseList(slow);

        // compare the first and second half
        ListNode* left = head;
        ListNode* right = reversedHead;
        bool isPalin = true;

        while (right) {
            if (left->val != right->val) {
                isPalin = false;
                break;
            }
            left = left->next;
            right = right->next;
        }

        // restore the reversed list (optional)
        reverseList(reversedHead);

        return isPalin;
    }
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev; // new head of reversed list
    }
};

int main() {
    // Example usage:
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    Solution solution;
    cout << (solution.isPalindromeOptimal(head) ? "True" : "False") << endl;

    return 0;
}

