# STL - Standard Template Library in C++

### How to use?

To use the STL library you'd need to include the `bits/stdc++.h` library.

```cpp
#include <bits/stdc++.h>
// rest of code
```

## Containers

Containers are objects that store data. They are implemented as template classes, allowing them to store elements of any type.

1. **Sequence Containers**: Maintain the ordering of elements (e.g., `vector`, `deque`, `list`).
2. **Associative Containers**: Store elements in a sorted order and allow fast retrieval (e.g., `set`, `map`).
3. **Unordered Containers**: Store elements in an unordered manner using hash tables (e.g., `unordered_set`, `unordered_map`).

---

### 1. Pairs

Pairs are used to store pairs of values, in this container the values are stored in a pair. It can hold all sorts of data types in it.

```cpp
#include<bits/stdc++.h>
using namespace std;

int main(void) {
    // normal pair
    pair<int, int> p = {1, 3};
    cout << p.first << " " << p.second << "\n";

    // storing nested pairs
    pair<int, pair<char, int>> p2 = {1, {'a', 2}};
    cout << p2.first << " " << p2.second.first << " " << p2.second.second << "\n";

    // array of pairs
    pair<int, int> p_arr[] = {{1, 2}, {2, 4}, {3, 5}};
    for (auto p : p_arr) {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}
```

### 2. Vectors

Vectors are like **flexible arrays** that can grow or shrink in size. They let you easily **add, remove, or copy elements** and work with tools like **iterators** for looping through items.

```cpp
#include<bits/stdc++.h>
using namespace std;

int main(void) {
    vector<int> v; // dynamic arrays (singly linked list internally)

    v.push_back(1);
    v.emplace_back(2);

    vector<pair<int, int>> vec;

    vec.push_back({1, 2});
    vec.emplace_back(1, 2); // no `{ }` and it's faster than push_back

    vector<int> v1(5); // {0, 0, 0, 0, 0} -> 5 elements
    vector<int> v2(5, 100); // {100, 100, 100, 100, 100}

    // copy vector to another vector
    vector<int> v3(v2);

    v = {1, 2, 3, 4, 5};

    // accessing items
    cout << v[0] << endl;
    cout << v.at(0) << endl;

    // iterators - points to memory
    vector<int>::iterator it = v.begin();
    it++;
    cout << *(it) << " ";

    it += 2;
    cout << *(it) << "\n";

    cout << v.back() << "\n";

    /*
        v = {1, 2, 3, 4, 5}
             a             b
        a -> *(begin) = 1
        b -> end (such that *(b - 1) = 5)

        rend -> reverse end (*(rend + 1) = 1)
        rbegin -> *(rbegin) = 5

        back -> v.back() = 5
    */

    // iterating over vector
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *(it) << " ";
    }
    cout << "\n";

    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *(it) << " ";
    }
    cout << "\n";

    // for each loop
    for (auto item : v) {
        cout << item << " ";
    }
    cout << "\n";

    // removing items
    v.erase(v.begin() + 1); // remove 2 -> 1 3 4 5

    v = {1, 2, 3, 4, 5};
    v.erase(v.begin() + 1, v.begin() + 3); // removes 2 and 3 (not 4)

    // inserting items (costly function)
    v = {10, 10};
    v.insert(v.begin(), 20); // {20, 10, 10}
    v.insert(v.begin() + 1, 2, 15); // {20, 15, 15, 10, 10}

    vector<int> copy = {69, 69};
    v.insert(v.begin(), copy.begin(), copy.end()); // {69, 69, 20, ...}

    // more features
    cout << v.size() << "\n";

    v = {1, 2, 3};
    v.pop_back(); // {1, 2} -> removes the last element

    vector<int> a = {10, 20};
    vector<int> b = {5, 15};

    a.swap(b);
    // a = {5, 15}
    // b = {10, 20}

    v.clear(); // remove all elements
    cout << v.empty() << "\n"; // 1 if empty, 0 if not

    return 0;
}
```

### 3. Lists

Lists are sequence containers that allow **non-contiguous memory allocation**. They are implemented as **doubly linked lists**, making insertion and deletion operations efficient. However, **accessing elements is slower** compared to vectors.

```cpp
#include<bits/stdc++.h>
using namespace std;

int main(void) {
    list<int> l; // doubly linked list

    l.push_back(1); // {1}
    l.emplace_back(2); // {1, 2}

    l.push_front(0); // {0, 1, 2}
    l.emplace_front(-1); // {-1, 0, 1, 2}

    // rest of the functions are same as vector
    // begin, end, clear, insert, size, swap and all

    return 0;
}
```

### 4. Deque (Double Ended Queue)

A deque (Double Ended Queue) is a data structure that allows you to **add or remove elements from both the front and the back efficiently**. It is flexible and can be **used like both a stack and a queue**.

```cpp
#include<bits/stdc++.h>
using namespace std;

int main(void) {
    deque<int> dq;

    dq.push_back(1); // {1}
    dq.emplace_back(2); // {1, 2}

    dq.push_front(3); // {3, 1, 2}
    dq.emplace_front(4); // {4, 3, 1, 2}

    dq.pop_back(); // {4, 3, 1}
    dq.pop_front(); // {3, 1}

    // rest are same as vectors

    return 0;
}
```

### 5. Stack

A stack is a container that follows the **Last In, First Out (LIFO)** principle. You can only add (`push`) or remove (`pop`) elements from the top of the stack, making it useful for tasks like reversing data or managing function calls.

```cpp
#include<bits/stdc++.h>
using namespace std;

int main(void) {
    stack<int> s; // note: no indexing & all operations are O(1)

    s.push(1); // {1}
    s.push(2); // {2, 1}
    s.push(3); // {3, 2, 1}
    s.emplace(4); // {4, 3, 2, 1}

    cout << s.top() << endl; // 4

    s.pop(); // {3, 2, 1}

    cout << s.top() << endl; // 3

    cout << s.size() << endl; // 3
    cout << s.empty() << endl; // 0

    // s1.swap(s2);

    return 0;
}
```

### 6. Queue

**Queue**: A queue is a container that follows the **First In, First Out (FIFO)** principle. Elements are **added at the back and removed from the front**, making it useful for tasks like scheduling or managing resources.

```cpp
#include<bits/stdc++.h>
using namespace std;

int main(void) {
    queue<int> q; // FIFO

    q.push(1); // {1}
    q.push(2); // {1, 2}
    q.emplace(3); // {1, 2, 3}

    q.back() += 5; // 3 += 5 => 8

    cout << q.front() << endl; // 1

    q.pop(); // {2, 8}

    cout << q.front() << endl; // 2

    // size, swap and empty same as stack

    return 0;
}
```

### 7. Priority Queue

A **priority queue** is a special type of queue where elements are arranged based on their `priority`. The highest (or lowest) priority element is always at the front and is processed first. It is commonly used in tasks like **scheduling or pathfinding** algorithms.

```cpp
#include<bits/stdc++.h>
using namespace std;

// push, pop => O(log n)
// top => O(1)

int main(void) {
    priority_queue<int> pq; // Non-Linear - Tree (Internally)

    // max heap
    pq.push(5); // {5}
    pq.push(2); // {5, 2}
    pq.emplace(10); // {10, 5, 2}

    cout << pq.top() << endl; // 10

    pq.pop(); // {5, 2}

    cout << pq.top() << endl; // 5

    // min heap
    priority_queue<int, vector<int>, greater<int>> pq2;

    pq2.push(5); // {5}
    pq2.push(2); // {2, 5}
    pq2.emplace(10); // {2, 5, 10}

    cout << pq2.top() << endl; // 2

    return 0;
}
```

### 8. Set

A set in C++ is a container that stores **unique elements** in a **sorted order**. It is useful when you need to ensure no duplicates and perform operations like **_searching, union, or intersection_** efficiently.

```cpp
#include <bits/stdc++.h>
using namespace std;

// every function takes `O(log n)` time complexity.

int main(void) {
    set<int> s; // Tree (internally)

    s.insert(1); // {1}
    s.emplace(2); // {1, 2}
    s.insert(1); // {1, 2}
    s.insert(4); // {1, 2, 4}
    s.insert(3); // {1, 2, 3, 4}

    auto it = s.find(3); // iterator of 3

    it = s.find(10); // s.end() => when el is not there

    s.erase(4); // {1, 2, 3}
    // s.erase(s.find(4)); // using iterators

    int count = s.count(1); // can be only 0 or 1

    auto it1 = s.find(2);
    auto it2 = s.find(3);
    s.erase(it1, it2); // {1}

    // multiset
    multiset<int> ms;

    ms.insert(1); // {1}
    ms.insert(1); // {1, 1}
    ms.insert(1); // {1, 1, 1}

    // ms.erase(1); // will erase all ones

    int count = ms.count(1);
    cout << count << endl;

    ms.erase(ms.find(1)); // will remove the first one (iterater passed)

    // rest all are same as set

    return 0;
}
```
