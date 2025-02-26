#include <iostream>
using namespace std;

/*
FUNCTIONS - BLOCK OF CODE WHICH CAN BE CALLED MULTIPLE TIMES WITH PARAMETERS
    return_type function_name(parameters...) {
        // function_body...
        return value
    }

- REDUCES REDUNDANCY (unnecessary repetition of code)
- BETTER STRUCTURE

Parameters - these are the variables which are used in the function and represent the values which we'll passing to the function.
Arguments - these are the actual values which are passed to a function.

EVERY FUNCTION IS STORED IN A STACK MEMORY

    ```
    int sum(int a, int b) {
        return a + b;
    }

    int main() {
        int a = 5, b = 10;
        int sum = sum(a, b);

        return 0;
    }
    ```

The STACK memory for the above program will look like this -

      CALLSTACK
|                   |
|                   |
|                   |
+-------------------+
| sum()             |
|        a, b       |
+-------------------+
| main()            |
|        a, b, sum  |
+-------------------+

When the `sum` function is called then the memory for that is assigned in the callstack and when it's work is done then it pops out or frees that memory.

NOTE: no lines of code is executed in the function that comes after the `return` statement.
*/

void greetWorld() {
    cout << "Hello, World!!\n";
}

void greetUser(string name) {
    cout << "Hello, " << name << ".\n";
}

int sum(int a, int b) {
    return a + b;
}

double square(double num) {
    return num * num;
}

double min(double a, double b) {    // a, b here are called parameters
    return a > b ? b : a;
}

int sumTillN(int till) {
    int sum = 0;

    for (int i = 1; i <= till; i++) {
        sum += i;
    }

    return sum;
}

/*
Pass by Value -

Here the values are passed in the functions and same value is stored in another memory which is independent of the variable we passed while calling the function. (means if we pass `a` (a = 5) inside a function and it modifies it to 10 then the actual variable `a` won't be affected.)

A copy of arguments is made inside the memory.

Their is one more way of passing arguments which is called Pass by Reference, we'll look at it in depth later.
*/
int mul(int a, int b) {    // here `a` and `b` are passed by value
    return a * b;
}

// sum of digits of a number
// ex: 143 --> 1 + 4 + 3 => 8
int sumDigits(int num) {
    int sum = 0;

    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

/*
Binomial Coefficient - nCr
nCr = n! / r! (n - r)!

for this we need factorials so let's make a separate function for that.
*/
int factorial(int num) {
    int fact = 1;
    if (num == 0) { return 1;}
    while (num > 0) {
        fact *= num;
        num--;
    }
    return fact;
}

int nCr(int n, int r) {
    if (n < 0 || r < 0) {
        cout << "Both values should be positive => ";
        return -1;
    }

    int fact_n = factorial(n);
    int fact_r = factorial(r);
    int fact_n_minus_r = factorial(n - r);

    int nCr = fact_n / (fact_r * fact_n_minus_r);

    return nCr;
}

/*
Prime or not Prime -
Prime numbers are those numbers which have only 2 factors, one and that number itself.
Examples - 2, 3, 5, 7, 11, 13, 17...

Basically a number `n` should only have 2 factors `1` and `n` itself.
*/
void isPrime(int num) {

    if (num < 1) {
        cout << num << " is not prime, infact negative numbers can never be prime.\n";
        return;
    }
    if (num == 1) {
        cout << num << " is not prime, as it only has 1 factor.\n";
        return;
    }

    for (int i = 2; i <= (num / 2); i++) {    // starting `i` from 2 as every number is divisible by 1
        if (num % i == 0) {
            cout << num << " is not prime\n";
            return;
        }
    }

    cout << num << " is prime.\n";
    return;
}

/*
Primes till N -
    just loop from 1 to N inclusive and use isPrime for each number.
*/
bool checkPrime(int num) {
    if (num < 1)
        return false;
    if (num == 1)
        return false;
    for (int i = 2; i <= (num / 2); i++)
        if (num % i == 0) { return false; }
    return true;
}

void primesTillN(int till) {
    for (int i = 2; i <= till; i++)
        if (checkPrime(i))
            cout << i << " ";
    cout << endl;
    return;
}

/*
Fibonacci Series -
    starts from 0 and 1, then the next element is the sum of previous 2 elements
    Series - 0, 1, 1, 2, 3, 5, 8, 13, 21, 34...
*/

void printFibonacci(int till) {
    if (till <= 0) {
        cout << "\nEmpty\n";
        return;
    }
    if (till == 1) {
        cout << "0\n";
        return;
    }
    if (till == 2) {
        cout << "0, 1\n";
        return;
    }

    int a = 0, b = 1;
    cout << "0, 1, ";
    for (int i = 2; i < till; i++) {
        int next = a + b;
        cout << next << ", ";
        a = b;
        b = next;
    }
    cout << "\b\b "; // remove the last comma
    return;
}

int main(void) {

    for (int i = 0; i < 3; i++) {
        greetWorld();
    }

    string name = "Kamalveer";
    greetUser(name);

    int c = sum(5, 10); // 15
    cout << "Sum is: " << c << endl;

    cout << "The square of 4.5 is: " << square(4.5) << endl;

    cout << "The minimum between 3.92 and 9.75 is: " << min(3.92, 9.75) << endl;    // 3.92 and 9.75 are called arguments

    cout << "Sum of all the numbers till 10 is: " << sumTillN(10) << endl;

    cout << "The factorial of 6 is: " << factorial(6) << endl;

    cout << "The sum of the digits of 143 is: " << sumDigits(143) << endl;

    cout << "The Binomial Coefficients:\n";

    cout << "    4C2 = " << nCr(4, 2) << endl;
    cout << "    4C4 = " << nCr(4, 4) << endl;
    cout << "    4C0 = " << nCr(4, 0) << endl;
    cout << "    4C5 = " << nCr(4, 5) << endl;    // this will be zero as their are 0 ways to select 5 things from a set of 4
    cout << "    -2C1 = " << nCr(-2, 1) << endl;

    cout << "\nLet's see if below numbers are primes or not: \n";
    isPrime(7);
    isPrime(2);
    isPrime(12);
    isPrime(1);
    isPrime(-3);

    cout << "\nPrime numbers between 1 and 50 are: ";
    primesTillN(50);
    cout << endl;

    cout << "Fibonacci series till 11th element: \n";
    printFibonacci(11);
    printFibonacci(0);
    printFibonacci(1);
    printFibonacci(2);

    return 0; // now do you get it why we type `return 0;` for the `int main()` function.
}