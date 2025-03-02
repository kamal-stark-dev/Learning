#include <iostream>
#include <cmath>
using namespace std;

void printDigits(int num) {
    while (num != 0) {
        cout << num % 10 << " ";
        num /= 10;
    }
    cout << endl;
}

int countDigits(int num) {
    int count = 0;
    while (num != 0) {
        count++;
        num /= 10;
    }
    return count;
}

int sumDigits(int num) {
    int sum = 0;
    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int productDigits(int num) {
    int product = 1;
    while (num != 0) {
        if (num % 10 == 0) return 0;
        product *= num % 10;
        num /= 10;
    }
    return product;
}

string isArmstrongNumber(int num) {
    int origionalNum = num;
    int sumOfCubes = 0;
    while (num != 0) {
        int digit = num % 10;
        sumOfCubes += digit * digit * digit;
        num /= 10;
    }
    return origionalNum == sumOfCubes ? "True" : "False";
}

int main() {
    int num = 123456789;
    printDigits(num);
    cout << "Number of Digits in " << num << " is: " << countDigits(num) << endl;
    cout << "The sum of all the digits in " << num << " is: " << sumDigits(num) << endl;
    cout << "The product of all the digits in " << num << " is: " << productDigits(num) << endl;

    /*
    Time Complexity for all the functions above is: O(log_10 n)
    -> as we are dividing the number with 10 each time
    */

    cout << "\nNumber of Digits in " << num << " is: " << (int)(log10(num) + 1) << endl;

    cout  << "153 is armstrong number: " << isArmstrongNumber(153) << endl;
    cout  << "1 is armstrong number: " << isArmstrongNumber(1) << endl;

    return 0;
}