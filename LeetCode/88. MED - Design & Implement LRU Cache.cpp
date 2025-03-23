// 146. LRU Cache

#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int key, val;
    Node *prev;
    Node *next;

    Node(int k, int v) {
        key = k;
        val = v;
        prev = next = nullptr;
    }
};

class LRUCache {
public:
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    unordered_map<int, Node*> m;

    int limit;

    void addNode(Node* newNode) { // O(1)
        Node* oldNext = head->next;
        head->next = newNode;
        oldNext->prev = newNode;

        newNode->next = oldNext;
        newNode->prev = head;
    }

    void deleteNode(Node* oldNode) { // O(1)
        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;

        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;

        // delete oldNode;
    }

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (m.find(key) == m.end()) return -1;

        Node* ansNode = m[key];
        int ans = ansNode->val;

        m.erase(key);
        deleteNode(ansNode);
        addNode(ansNode);
        m[key] = ansNode;

        return ans;
    }

    void put(int key, int value) { // O(1)
        // update already present key
        if (m.find(key) != m.end()) {
            Node* oldNode = m[key];
            deleteNode(oldNode);
            m.erase(key);
        }
        // when capacity reached
        if (m.size() == limit) {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        Node* newNode = new Node(key, value);
        addNode(newNode);
        m[key] = newNode;
    }
};

int main(void) {
    LRUCache lruCache(2); // capacity 2

    lruCache.put(1, 1); // Add key=1, value=1
    lruCache.put(2, 2);

    cout << lruCache.get(1) << endl;

    lruCache.put(3, 3); // Evicts key=2, adds key=3, value=3

    cout << lruCache.get(2) << endl; // Returns -1 (not found)

    lruCache.put(4, 4); // Evicts key=1, adds key=4, value=4

    cout << lruCache.get(1) << endl; // -1
    cout << lruCache.get(3) << endl; // 3
    cout << lruCache.get(4) << endl; // 4

    return 0;
}