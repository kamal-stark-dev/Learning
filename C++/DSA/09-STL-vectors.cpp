#include <iostream>
#include <vector>
using namespace std;

/*
STL - Standard Template Library

    1. Contaniers (*)
    2. Iterators
    3. Algorithms
    4. Functions
*/

void printVector(vector<int> nums, string msg = "vec") {
    cout << "\n" << msg << ": ";
    for (int n: nums) cout << n << " ";
    cout << endl;
}

int main(void) {
    // Vectors - these are one such containers in STL in which we can add or remove elements (i.e. dynamic arrays)
    vector<int> vec; // initially size -> 0

    cout << "Size: " << vec.size() << endl;
    cout << "Capacity: " << vec.capacity() << endl;

    vec.push_back(1);
    printVector(vec);
    cout << "Size: " << vec.size() << endl;
    cout << "Capacity: " << vec.capacity() << endl;

    vec.push_back(2);
    printVector(vec);
    cout << "Size: " << vec.size() << endl;
    cout << "Capacity: " << vec.capacity() << endl;

    vec.push_back(3);
    printVector(vec);
    cout << "Size: " << vec.size() << endl;
    cout << "Capacity: " << vec.capacity() << endl;

    vec.push_back(4);
    vec.emplace_back(5); // you can also use `emplace_back()` for pushing data
    printVector(vec);
    cout << "Size: " << vec.size() << endl;
    cout << "Capacity: " << vec.capacity() << endl;

    cout << "\nYou can see that the capacity doubles when the size overflows." << endl;

    vec.pop_back();
    printVector(vec, "Vector after pop_back()");

    cout << "\nValue at index 2: " << vec.at(2) << endl;

    cout << "\nFront of vector: (" << vec.front() << ") and Back of vector: (" << vec.back() << ")\n";

    /*
    Initialization:
        -> vector<int> vec;
        -> vector<int> vec = {1, 2, 3};
        -> vector<int> vec (5, 10);     // create a vector of size `5` all having values `10`
        -> vector<int> vec2(vec1);      // copy vector 1 to vector 2
    */

    // erase() and insert() both are costly functions -> takes O(n) TC & we pass iterators in them not indices

    vec.erase(vec.begin() + 1); // erase the second element
    printVector(vec, "Vector after erase()");

    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(7);
    vec.push_back(8);
    printVector(vec, "Pushing some values");

    vec.erase(vec.begin() + 2, vec.begin() + 6); // [start, end) -> 3rd to 5th elements
    printVector(vec, "Vec after removing a range");
    cout << "Note that the capacity remains same: " << vec.capacity() << endl;

    vec.insert(vec.begin() + 2, 4); // index (iterator) and value
    printVector(vec, "Vector after inserting 4");

    vec.clear();
    printVector(vec, "Vector after clear()");
    cout << "Note that the capacity remains same here too: " << vec.capacity() << endl;

    cout << "\nvec.empty(): " << vec.empty() << endl; // 1 -> true 0 -> false

    // iterators
    vec = {1, 2, 3, 4, 5};

    cout << "vec.begin(): " << *(vec.begin()) << endl;
    cout << "vec.end(): "<< *(vec.end()) << endl; // doesn't points to the last element (i.e. n - 1) but at the [n * size + begin]
    cout << "`vec.end() - 1`: "<< *(vec.end() - 1) << endl;
    cout << "vec.rbegin(): " << *(vec.rbegin()) << endl;
    cout << "vec.rend(): " << *(vec.rend()) << endl;
    cout << "`vec.rend() - 1`: " << *(vec.rend() - 1) << endl;

    // looping with iterators
    vector<int>::iterator it;
    for (it = vec.begin(); it != vec.end(); it++) {
        cout << *(it) << " ";
    }
    cout << endl;

    // reverse list
    vector<int>::reverse_iterator rit;
    for (rit = vec.rbegin(); rit != vec.rend(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // you can also use `auto` directly in the for loop --> for (auto it = ...)

    return 0; // cool
}
