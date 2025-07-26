// Find Pairs with Given Sum in Doubly Linked List

#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    Node *prev, *next;

    Node(int data) {
        val = data;
        prev = next = nullptr;
    }
};

vector<vector<int>> findPairs(Node* head, int target) {
    vector<vector<int>> pairs;

    Node *left = head, *right = head;
    while (right->next) {
        right = right->next;
    }

    // while (left && right && left != right && left->prev != right) {
    while (left->val < right->val) {
        int sum = left->val + right->val;
        if (sum == target) {
            pairs.push_back({left->val, right->val});
            // remember to update the left and right
            left = left->next;
            right = right->prev;
        }
        else if (sum > target) {
            right = right->prev;
        }
        else {
            left = left->next;
        }
    }
    return pairs;
}

int main(void) {
    Node* first = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);
    Node* sixth = new Node(6);

    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;

    fourth->next = fifth;
    fifth->prev = fourth;

    fifth->next = sixth;
    sixth->prev = fifth;

    int target = 7;
    vector<vector<int>> pairs = findPairs(first, target);
    cout << "Pairs that add up to target (" << target << "): [";
    for (auto pair: pairs) {
        cout << "[" << pair[0] << ", " << pair[1] << "], ";
    }
    cout << "\b\b]\n";

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n) -> for storing the pairs (auxiliary)
*/