// 342. Power of Four

#include <iostream>
using namespace std;

// time complexity - O(log n)
bool isPowerOf4(int num) {
    if (num <= 0) return false;

    for (int i = 0; i < 31; i++) {
        if ((1 << i == num) && (i % 2 == 0))
            return true;
    }
    return false;
}

bool isPowerOf4_oneLiner(int num) {
    return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0; // 64 - 1 % 3 == 0 (true) and 32 - 1 % 3 != 0 (false)
}

int main(void) {
    int num = 8;

    if(isPowerOf4_oneLiner(num))
        cout << num << " is the power of 4 (TRUE)\n";
    else
        cout << num << " is not the power of 4 (FALSE)\n";
}