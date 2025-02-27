#include <iostream>
#include <vector>    // include this header file - you may also see a header file like - <bits/c++.h>
using namespace std;

/*
VECTORS - these are another data structure which are very similar to arrays but it's dynamic (their size can be changed).

We need the STL (Standard Template Library) for the same which has the implementation for structures like stack, linked list, queue etc. which we will be looking at later.

STL --> vector, queue, stack and set are called STL containers.

VECTOR SYNTAX -
    vector<int> vec;
    vector<int> vec = {1, 2, 3};
    vector<int> vec (3, 0);
*/

void reverseVector(vector<int>& reverseme);

int main(void) {

    vector<int> vec; // size 0

    vec = {1, 2, 3, 4, 5};

    cout << "First element in vector: " << vec[0] << endl;

    vector<int> defaultVector (3, 0);
    // above will create a vector of size 3 and each element will have the value 0

    cout << "The default vector is: ";
    for (int i: defaultVector) {
        cout << i << " ";
    } cout << endl;

    // similarly we can create a vector of characters and print them
    vector<char> chars = {'a', 'b', 'c', 'd', 'e'};

    for (char ch: chars) {
        cout << ch << " ";
    } cout << endl;

    /*
    VECTOR FUNCTIONS -
    1. size
    2. push_back
    3. pop_back
    4. front
    5. back
    6. at
    */

    cout << "Size of chars - " << chars.size() << endl;

    chars.push_back('f');  // places the new element at the end of the vector
    chars.push_back('g');
    cout << "New size after pushing - " << chars.size() << endl;

    chars.pop_back();
    cout << "New size after popping - " << chars.size() << endl;

    cout << "Front and back values in `chars` vector are `" << chars.front() << "` and `" << chars.back() << "` respectively.\n";

    // vec[i] ==> vec.at(i)
    cout << "The third element is: `" << chars.at(2) << "`\n";

    // there are more functions but for now it's sufficient

    /*
    Arrays  are created and modified at the compile time (static).
    Vectors are created and modified at the run-time (dynamic), for example when we add or remove an element from vector a new memory is given or taken from the vector at run-time.

    NOTE: Static memory allocation is done in `Stack Memory` and Dynamic memory allocation is done in `Heap Memory`.

    If you have a vector - `1, 2, 3` and now you push back `4` to it, so it'll create another vector double the current size `1, 2, 3, _, _, _` and add the `4` in it -> `1, 2, 3, 4, _, _` and remove the `1, 2, 3` one.

    +-------+-------+-------+-------+
    |   1   |   2   |   3   |       |
    +-------+-------+-------+-------+
    size = 3, capacity = 4

    SIZE - number of elements in vector.
    CAPACITY - number of elements it can have.
    */

    // let's see the concept of size and capacity
    vector<int> test = {1, 2};

    cout << "\nOriginally -\n";
    cout << "Size: " << test.size() << "\nCapacity: " << test.capacity() << endl;

    test.push_back(3);
    cout << "\nAfter pushing one element -\n";
    cout << "Size: " << test.size() << "\nCapacity: " << test.capacity() << endl;


    test.push_back(4);
    test.push_back(4);
    cout << "\nAfter pushing two more elements -\n";
    cout << "Size: " << test.size() << "\nCapacity: " << test.capacity() << endl;

    cout << "\nWe can see that the capacity doubles when the (size == capacity) and a new element is added.\n";

    // Linear search using vectors
    vector<char> searchVector = {'a', 'b', 'c', 'd', 'e', 'f'};
    char key = 'd';
    int indexOfKey = -1;

    for (int i = 0; i < searchVector.size(); i++) {
        if (searchVector[i] == key) {
            indexOfKey = i;
            break;
        }
    }

    if (indexOfKey != -1)
        cout << "\nElement found at index: " << indexOfKey << endl;
    else
        cout << "\nElement is not in the list.\n";

    // Reversing a vector
    vector<int> reverseMe = {2, 4, 6, 8, 10};

    reverseVector(reverseMe);

    cout << "The reversed vector is: ";
    for (int i: reverseMe) {
        cout << i << " ";
    } cout << endl;

    return 0;
}

void reverseVector(vector<int>& reverseMe) {    // remember to add the `&` for changing the vector be reference
    int left = 0, right = reverseMe.size() - 1;

    while (left < right) {
        int temp = reverseMe.at(left);
        reverseMe.at(left) = reverseMe.at(right);
        reverseMe.at(right) = temp;

        left ++;
        right --;
    }
}