// Templates - Templates let you write a function or class that works with different data types. They help avoid repeating code and make programs more flexible.

#include <iostream>
using namespace std;

template <typename T>
T add(T a, T b) {
    return a + b;
}

/*
`T` is a placeholder for a data type (like int, float etc.)
You can use any name instead of T, but T is common.
*/

// You can also make Class Templates in a similar manner
template <typename T>
class Box {
public:
    T value;
    Box(T val) {
        value = val;
    }
    void show() {
        cout << "Value: " << value << "\n";
    }
};

// Using two different typenames for different conbinations of data types
template <typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;

    Pair(T1 first_, T2 second_) {
        first = first_;
        second = second_;
    }

    void display() {
        cout << "First: " << first << ", Second: " << second << "\n";
    }
};

int main(void) {
    // Function Template Usage
    cout << add<int>(10, 5) << "\n";
    cout << add<double>(3.5, 2.2) << "\n";

    // Class Template Usage
    Box<int> IntBox(10);
    IntBox.show();

    Box<string> StrBox("Hello, World!");
    StrBox.show();

    // Using Multiple Typenames
    Pair<string, int> person("Jake", 20);
    Pair<int, double> score(101, 78.9);

    person.display();
    score.display();

    return 0;
}

/*
Benefits of Templates:
    1. Avoid repeating the same logic for different types.
    2. Write cleaner and reusable code.
    3. Support generic programming.

Note: Templates must be defined in the same file where they are used (usually the `.h` file).
*/