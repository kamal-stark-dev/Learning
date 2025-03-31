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


```cpp
#include<bits/stdc++.h>
using namespace std;

int main(void) {
    vector<int> v; // dynamic arrays

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

    // inserting items
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
