// Pointers

#include <iostream>
using namespace std;

// GO TO THE LAST FOR NOTES

void doubleNum(int* n) {    // pass by reference
    *n =  2 * (*n);
}

void tripleNum(int &b) {    // here `&` is not address but alias
    b = 3 * b;
}

int main() {

    int a = 10;
    cout << "The address of variable a is : " << &a << endl;

    int* ptr = &a; // the asterisk(*) tells that it's a pointer
    cout << "The value of pointer ptr is  : " << ptr << endl;

    // Pointer to Pointer
    double num = 100.25;
    double* ptr1 = &num;
    double** parentPtr = &ptr1;   // ussful when you want to store the address of a pointer

    cout << "\nAddress of ptr1 : " << &ptr1 << "\n";
    cout << "Value of parent : " << parentPtr << "\n";

    // Dereference Operator - (*)
    int b = 100;
    int* p = &b;

    cout << "\nDereferencing the address: " << *(&b) << endl;
    cout << "Dereferencing the pointer: " << *p << endl;

    // NULL pointer - doesn't points to any address
    int* nullPtr = NULL;
    cout << "Null pointer holds the value: " << nullPtr << "\n";
    // Null pointers will be used in linked list and trees implementation

    // Pass by Reference
    int c = 5;
    cout << "\nnum:" << c << endl;;
    doubleNum(&c);
    cout << "num:" << c << endl;

    int d = 5;
    cout << "\nanother num:" << d << endl;;
    tripleNum(d);
    cout << "another num:" << d << endl;

    // Array name is also a pointer
    int arr[] = {1, 2, 3, 4, 5};
    cout << "\nThe address of arr is: " << arr << "\n";
    cout << "The address of arr[0]: " << &(arr[0]) << "\n";
    cout << "The value at *arr: " << *arr << "\n";
    cout << "The value at arr[0]: " << arr[0] << "\n";

    // Now, this array pointer is a special ptr called the `constant ptr`(can't be changed throughout the program)

    // Pointer Arithmetic
    int e = 100;
    int *ptrE = &e;

    cout << "\nptr: " << ptrE << endl;
    cout << "++ptr: " << ++ptrE << endl;  // will add the bytes according to the data type -> for integer, 100 will be 104
    cout << "--ptr: " << --ptrE << endl;

    cout << "ptr + 2: " << ptrE + 2 << endl;  // will add 8 bytes
    cout << "ptr - 3: " << ptrE - 3 << endl;  // will subtract 12 bytes

    // we can use this knowledge in arrays

    cout << "\n*arr: " << *arr << endl;
    cout << "*(arr + 1): " << *(arr + 1) << endl;  // this works because arrays are contigous
    cout << "*(arr + 2): " << *(arr + 2) << endl;
    cout << "*(arr + 3): " << *(arr + 3) << endl;
    cout << "*(arr + 4): " << *(arr + 4) << endl;
    cout << "*(arr + 5) GARBAGE: " << *(arr + 5) << endl;  // garbage - out of index

    /*
    Moving on to Pointer Arithmetic:
    1. You can not add two pointers.
    2. When you subtract two pointers of same type, it'll give the ==> (difference bytes) / (size of pointer)
        ex: int -> ptr1 = 112 and ptr2 = 100
            ptr1 - ptr2 = 112 - 100 = 12 ==> 12 / 4 ==> `3`
    3. Comparision between pointers -> >, <, <=, >=, ==, !=
    */
    cout << "\n(arr + 3) - (arr + 1): " << (arr + 3) - (arr + 1) << endl;  // it'll return `2`
    cout << "(arr + 3) > (arr + 1): " << ((arr + 3) > (arr + 1)) << endl;
    cout << "(arr + 3) < (arr + 1): " << ((arr + 3) < (arr + 1)) << endl;
    cout << "(arr + 3) == (arr + 1): " << ((arr + 3) == (arr + 1)) << endl;
    cout << "(arr + 3) == (arr + 3): " << ((arr + 3) == (arr + 3)) << endl;

    /*
    Can you predict the output of the following?
    */
    int arr2[] = {10, 20, 30, 40};
    int *ptr2Arr = arr2; // note: I haven't written `&arr` can you guess why?

    cout << "\n*(ptr + 1): " << *(ptr2Arr + 1) << endl;
    cout << "*(ptr + 3): " << *(ptr2Arr + 3) << endl;
    cout << "*(++ptr): " << *(++ptr2Arr) << endl;

    return 0;
}

/*
Memory Addresses -> hexadecimal (0-9 & A-F), ex: 0x36a6 --> here `0x` tells that the number is base 16 and `36a6` is the value.

Now, if you want to take a took at the address you can use the address of operator `&`.
    ex: int a = 10;
        cout << &a << endl;

Pointers - Pointers are the variables that store the address of another variables.

var - a                 ptr - p
+-----------+-----------+-----------+-----------+-----------+
|  a = 10   |           |  p = 100  |           |           |
+-----------+-----------+-----------+-----------+-----------+
100         108         116         124         132         140

[We can see that the ptr var `p` holds the address of var `a`]

Dereferencing Operator(*) -> as reference means address, dereference means to refer to the value present at a particular address.
    ex: int a = 100;
        int* ptr = &a;
        cout << *(ptr) << endl;

NOTE:
    We use single `&` for three purposes
        1. bitwise operator (ex: 2 & 3)
        2. address of operator (ex: &var)
        3. alias in pass by reference (ex: void doubleNum (int &num) { // function code } )

    Similarly, we use `*` for three purposes
        1. multiply operator (ex: 2 * 3)
        2. pointer declaration (ex: int* ptr;)
        3. dereference operator (ex: *(ptr))
*/