// 138. Copy List with Random Pointer

#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* random;

    Node (int val) {
        data = val;
        next = nullptr;
        random = nullptr;
    }
};

Node* createList() {
    Node* node1 = new Node(7);
    Node* node2 = new Node(13);
    Node* node3 = new Node(11);
    Node* node4 = new Node(10);
    Node* node5 = new Node(1);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    // node5->next = nullptr; -> is already nullptr

    node1->random = nullptr;
    node2->random = node1;
    node3->random = node5;
    node4->random = node3;
    node5->random = node1;

    return node1;
}

void printList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    Node* current = head;
    while (current) {
        cout << "Value: " << current->data << "\t";
        if (current->random) {
            cout << "Random: " << current->random->data;
        } else {
            cout << "Random: nullptr";
        }
        cout << endl;
        current = current->next;
    }
}

Node* copyList(Node* head) {
    unordered_map<Node*, Node*> map;

    Node* newHead = new Node(head->data); // copying the head
    map[head] = newHead;

    Node* oldTemp = head->next;
    Node* newTemp = newHead;

    while (oldTemp != nullptr) {
        Node* copyNode = new Node(oldTemp->data);
        map[oldTemp] = copyNode;

        newTemp->next = copyNode;
        newTemp = newTemp->next;
        oldTemp = oldTemp->next;
    }

    oldTemp = head;
    newTemp = newHead;

    while (oldTemp != nullptr) {
        newTemp->random = map[oldTemp->random];
        oldTemp = oldTemp->next;
        newTemp = newTemp->next;
    }

    return newHead;
}

int main() {
    cout << "      ~ Original List ~\n";
    Node* head = createList();
    printList(head);

    cout << "\n      ~ Copied List ~\n";
    Node* copyHead = copyList(head);
    printList(copyHead);

    return 0;
}
/*
Time Complexity: O(n) if we ignore the worst case of unordered_map. <Practically it's O(n)>
*/