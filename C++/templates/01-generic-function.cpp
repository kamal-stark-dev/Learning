#include <iostream>
using namespace std;

template <template T> T myMax(T x, T y) {
    return (x > y) ? x : y;
}

int main() {
    cout << "Max of 3 and 7 is: " << myMax<int>(3,7) << "\n";
    cout << "Max of 3.5 and 6.9 is: " << myMax<double>(3.5, 6.9) << "\n";
    cout << "Max of 'g' and 'e' is: " << myMax<char>('g', 'e') << "\n";

    return 0;
}
