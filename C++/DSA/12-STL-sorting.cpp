#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool comparator(pair<int, int> p1, pair<int, int> p2) {
    if (p2.second > p1.second) return true;
    if (p2.second < p1.second) return false;
    if (p1.first < p2.first) return true;
    else return false;
}

// bool comparator(pair<int, int> p1, pair<int, int> p2) {
//     if (abs(p1.second - p1.first) < abs(p2.second - p2.first)) return true;
//     else return false;
// }

int main() {
    /*
    sort()
    */

    // for arrays
    int arr[5] = {3, 5, 1, 8, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + size);

    cout << "Array Sorted: ";
    for (int val: arr) {
        cout << val << " ";
    }
    cout << endl;

    // for vectors
    vector<int> vec = {3, 5, 1, 8, 2};

    sort(vec.begin(), vec.end());

    cout << "Vector Sorted: ";
    for (int val: vec) cout << val << " ";
    cout << "\n";

    // if you want to sort in descending order then we use a comparator/functor
    sort(arr, arr + size, greater<int>());

    cout << "Sorted Descending: ";
    for (int val: arr) {
        cout << val << " ";
    }
    cout << endl;

    // what about pairs
    vector<pair<int, int>> pairs = {{2, 1}, {5, 2}, {6, 2}, {7, 1}};

    sort(pairs.begin(), pairs.end()); // this will sort your pairs in `pairs.first` values

    cout << "\nPairs Sorted: ";
    for (auto pair: pairs) {
        cout << "{" << pair.first << ", " << pair.second << "}, ";
    }
    cout << "\b\b \n";

    // what if you want to make custom logic for sorting
    sort(pairs.begin(), pairs.end(), comparator); // this will sort your pairs in `pairs.first` values

    cout << "Pairs Custom Sorted: ";
    for (auto pair: pairs) {
        cout << "{" << pair.first << ", " << pair.second << "}, ";
    }
    cout << "\b\b \n";

    /*
    reverse()
    */

    vec = {1, 3, 5, 7, 9};

    reverse(vec.begin(), vec.end());

    cout << "\nVector Reversed: ";
    for (int val: vec) cout << val << " ";
    cout << "\n";

    // reversing from index 1 to 3
    vec = {1, 3, 5, 7, 9};

    reverse(vec.begin() + 1, vec.begin() + 4);

    cout << "Vector Reversed: ";
    for (int val: vec) cout << val << " ";
    cout << "\n";

    /*
    next_permutation()
    */
    vec = {1, 2, 3};

    next_permutation(vec.begin(), vec.end());

    cout << "\nNext Permutation of `1 2 3`: ";
    for (int val: vec) cout << val << " ";
    cout << "\n";

    string str = "abc";
    next_permutation(str.begin(), str.end());
    cout << "Next Permutation of `abc`: " << str << endl;

    // we also have `previous_permutation()`

    /*
    max and min elements
    */
    vec = {1, 4, 2, 10, 6, -2};

    cout << "\nMax in array: " << *(max_element(vec.begin(), vec.end())) << endl;
    cout << "Min in array: " << *(min_element(vec.begin(), vec.end())) << endl;

    /*
    binary_search()
    */
    vec = {1, 2, 4, 6, 7, 8, 10};
    int target = 7;

    bool target_present = binary_search(vec.begin(), vec.end(), 8); // `1` if present `0` if not

    /*
    __builtin_popcount() -> returns the count of 1's of number in binary form

    for long and long long values -> use __builtin_popcountl() and __builtin_popcountll() respectively
    */
    int num = 15; // 00001111
    cout << "Count for " << num << " : " << __builtin_popcount(num) << endl;
    num = 16; // 00010000
    cout << "Count for " << num << " : " << __builtin_popcount(num) << endl;

    return 0;
}

// wow that was really cool!!