#include <iostream>
using namespace std;

int main(void)
{
    int age = 19;
    char a = 'a';
    int arr[] = {1, 2, 3, 4, 5};
    const double pi = 3.14;

    cout << pi << endl;

    for (int i = 0; i < 5; i++) {
        cout << i << endl;
    }

    if (age > 18) {
        cout << "Adult" << endl;
    } else {
        cout << "Not Adult" << endl;
    }

    double number_ = 9.292;
    short age_ = 19;
    int length = 380;
    float area = 5.69f;
    long long_int = 37282923.14259L;
    char c = 'a';
    bool isAdult = true;
    // auto is pretty cool
    auto var = 4.3332L; // automatically sets the type

    int num1 {}; // 0
    cout << num1 << endl;

    int num2 {12};
    cout << num2 << endl;

    unsigned int num3 = 0;

    cout << --num3 << endl; // should be -1 but is 4294967295 as it's unsigned

    // Narrowing
    int number = 1'000'000; // you can use ' to make it more readable
    short another_num = number;

    cout << another_num << endl; // not correct right cause it has narrowed down to the short range

    return 0;
}

/*
Snake Case - hello_world
Pascal Case - HelloWorld -> naming classes
Camel Case - helloWorld -> varible naming
Hungarian Notation - iFileSize -> i refers to the integer and is outdated but it can be seen in legacy code
*/