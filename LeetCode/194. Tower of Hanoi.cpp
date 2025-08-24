// Tower of Hanoi

#include <iostream>
using namespace std;

void tower_of_hanoi(int n, string source, string auxiliary, string target) {
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << target << "\n";
        return;
    }
    tower_of_hanoi(n - 1, source, target, auxiliary); // move the disk from source to auxiliary
    cout << "Move disk " << n << " from " << source << " to " << target << "\n";
    tower_of_hanoi(n - 1, auxiliary, source, target); // move disk from auxiliary to target
}

int main(void) {
    int n = 4;
    tower_of_hanoi(n, "A", "B", "C");

    return 0;
}

/*
Time Complexity: O((2 ^ n) - 1)
Space Complexity: O(n), total ((2 ^ n) - 1) calls will be made but longest chain would be of `n` length.

Note: Space Complexity is the maximum recursion depth reached (n in this case).
*/