#include <iostream>
#include <vector>
#include <list>
#include <deque>
using namespace std;

/*
Sequential Containers
*/

int main() {
    /*
    List
    */
    list<int> lis; // implemented by doubly linked list

    lis.push_back(1);
    lis.emplace_back(2);
    lis.push_front(0);
    lis.emplace_front(-1);

    cout << "List: ";
    for (int val: lis) {
        cout << val << " "; // -1 0 1 2
    } cout << endl;

    lis.pop_front(); // -1
    lis.pop_back(); // 2

    cout << "Modified List: ";
    for (auto it = lis.begin(); it != lis.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    lis = {1, 2, 3, 4, 5};

    // cout << lis[1] << endl; --> this is not valid as the list is double ended linked list

    // size, erase, clear, begin, end, rbegin, rend, insert, front, back --> all are present in list too

    /*
    DEQUE - Double Ended Queue
    */
    deque<int> d = {1, 2, 3};

    cout << "\nDeque: ";
    for (int i = 0; i < 3; i++) {
        cout << d[i] << " ";
    }
    cout << endl;

    // it has all the features that we saw in lists and vectors
    // The difference is that `deque` is implimented using dynamic arrays just like vectors and can be indexed

    /*
    Pair
    */
    pair<int, char> p = {1, 'a'};

    cout << "\nPair: " << p.first << " " << p.second << endl;

    // nested pairs
    pair<int, pair<int, int>> p2 = {1, {2, 3}};
    cout << "Pair 2: " << p2.first << " " << p2.second.first << " " << p2.second.second << endl;

    // vector of pairs
    vector<pair<int, int>> coords = {{0, 5}, {5, 10}, {10, 0}};

    cout << "Coords (vector of pairs):\n\t";
    for (pair<int, int> p: coords) { // you can also use `for (auto p: coords)`
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    coords.push_back({-5, 0});
    coords.emplace_back(-10, 5); // in-place object create - little faster than push_back

    cout << "Coords:\n\t";
    for (pair<int, int> p: coords) { // you can also use `for (auto p: coords)`
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << "\n";
}