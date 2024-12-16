// 231. Power of Two

#include <iostream>
using namespace std;

/*
LOGIC - let's see with examples

for num = 8 (1000)
    num - 1 = 7(0111) and (num & (num - 1)) ==> (1000 & 0111) ==> 0 == 0 (TRUE)

for num = 9 (1001)
    num - 1 = 8 (1000) and (num & (num - 1)) ==> (1001 & 1000) ==> 1 != 0 (FALSE)
*/

// time complexity - O(1)
bool isPowerOf2(int num) {
    if (num <= 0) return false;

    return (num & (num - 1)) == 0;
}

bool isPowerOf2_singleLine(int num){
    return num > 0 && (num & (num - 1)) == 0;
}

// time complexity - O(log n)
bool isPowerOf2_leftShift(int num) {
    if (num <= 0) return false;

    for (int i = 0; i < 31; i++) {
        if (1 << i == num) return true;
    }
    return false;
}

int main(void) {
    int num = 32;

    if(isPowerOf2_singleLine(num))
        cout << num << " is the power of 2 (TRUE)\n";
    else
        cout << num << " is not the power of 2 (FALSE)\n";

    return 0;
}