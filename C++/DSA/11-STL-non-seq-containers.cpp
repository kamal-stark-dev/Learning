#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
using namespace std;

/*
Non-Sequential Containers
*/

int main() {
    /*
    Stack - LIFO
        -> push, emplace, top, pop, size, empty, swap
    */
    stack<int> s;

    s.push(1);
    s.push(3);
    s.emplace(5);
    s.push(7);

    cout << "Top of Stack: " << s.top() << endl;
    cout << "Size of Stack: " << s.size() << endl;

    cout << "\nStack: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";

    stack<char> s1, s2;
    s1.push('a');
    s1.push('b');
    s1.push('c');

    cout << "\nSize of s1: " << s1.size() << endl;
    cout << "Size of s2: " << s2.size() << endl;
    s2.swap(s1);
    cout << "\nAfter swapping s1 and s2:\n";
    cout << "Size of s1: " << s1.size() << endl;
    cout << "Size of s2: " << s2.size() << endl;

    /*
    Queue - FIFO
        -> elements are inserted from back (rear) and removed from the front
        -> push, emplace, front, pop, size, empty, swap
    */
    queue<int> q;

    q.push(-1);
    q.push(0);
    q.push(1);
    q.push(2);

    cout << "\nQueue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";

    /*
    Priority Queue
        -> implemented using max/min heaps which are complete binary trees
        -> top - O(1)
        -> push, emplace, pop - O(log.n) [as they are implemented in trees form]
    */

    priority_queue<int, vector<int>, greater<int>> pq; // for min-heap

    pq.push(6);
    pq.push(2);
    pq.push(7);
    pq.push(4);

    // 7 6 4 2 --> internally it's in tree form

    cout << "Priority Queue: ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "\n\n";

    /*
    Map - used to store key-value pairs (all keys are unique)
    It's like dictionary in python.
    */
    map<string, int> m;
    m["TV"] = 100;
    m["Laptop"] = 120;
    m["Phone"] = 100;

    m.insert({"Watch", 50});
    m.erase("TV");

    for (pair<string, int> p: m) {
        cout << p.first << " : " << p.second << endl; // will be printed in `lexographical` order in ascending order for keys
    }

    // find() -> returns the `iterator` of the key if its found else `map.end()`
    string key = "Phone";
    if(m.find(key) != m.end()) {
        cout << key << " is present in the map & it has the value: " << m[key] << endl;
    }
    else {
        cout << key << " is not present in the map.\n\n";
    }

    /*
    Other maps -
        1. Multimap -> you can have multiple keys
        2. Unordered Map -> keeps the data unordered (random order), used quite frequently
    */
    multimap<string, int> mm;

    mm.insert({"TV", 100});
    mm.emplace("Radio", 20);
    mm.insert({"TV", 120});
    mm.emplace("Radio", 40);

    for (auto val: mm) {
        cout << val.first << " " << val.second << "\n\n";
    }

    // Unordered Map
    unordered_map<char, int> um;

    um.emplace('a', 1);
    um.emplace('c', 3);
    um.emplace('d', 4);
    um.emplace('b', 2);

    cout << "Unordered Map:\n";
    for (auto val: um) {
        cout << val.first << " " << val.second << "\n\n";
    }

    /*
        unordered maps functions have lesser time complexity than map ones in majority cases
        [insert, erase and count takes `log.n` time whereas unordered ones takes constant time complexity in most of the times]
    */

    /*
    Set - contains unique values in a sorted order

    A `set` also uses `tree` internally -> insert, erase and count takes `log.n` time
    */
    set<int> set_;

    set_.insert(1);
    set_.insert(2);
    set_.insert(3);
    set_.insert(4);
    set_.insert(5);

    set_.insert(1); // won't add duplicates

    cout << "Set: ";
    for (auto val: set_) cout << val << " ";
    cout << endl;

    // lower_bound(num) -> gives iterator of lower bound, returns `set.end()` if no value >= lower bound
    cout << "Lower Bound: " << *(set_.lower_bound(4)) << endl;

    // upper_bound(num) -> gives iterator of upper bound (non-inclusive), value > upper bound
    cout << "Upper Bound: " << *(set_.upper_bound(4)) << endl;

    /*
    Multi Set and Unordered Set

    1. Multi Set - Can store duplicate elements -> time complexity is `O(log.n)`
    2. Unordered Set - Stores in a random order not sorted -> time comeplexity is `O(1)`
    */

    return 0;
}

// wow that was really cool!!