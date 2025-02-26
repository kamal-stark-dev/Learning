/*
THIS IS JUST FOR REVISION - BEGINNERS ARE SUGGESTED TO LEARN C++ FROM SOMEWHERE ELSE - (ApnaCollege, BroCode etc.)
*/

#include <iostream>
using namespace std;

int main() {
    cout << "Hello World\nMy name is Kamal Stark" << endl;    // semicolon is a statement terminator -> like a full stop (period ".") in english.

    /*
    variables (or identifiers) -> var names can start with '_' or 'a-z' or 'A-Z' but not numbers
    Remember: we need to declare variables with data types (int, float, char, double, bool etc.)

    0 or 1 -> 1 bit
    01101001 -> 8 bits -> 1 byte

    int -> 4 bytes (64-bit systems) and 2 bytes (32-bit systems)
    float -> 8 bytes
    char -> 1 byte
    bool -> 1 byte (may vary between languages)

    you can use - sizeof() to find the size of any variable
    */
    int age = 19;
    cout << "My age is: " << age << endl;
    cout << "Size of age (int): " << sizeof(age) << " bytes" << endl;

    bool isAdult;
    if (age >= 18) {
        isAdult = true;
    } else {
        isAdult = false;
    }

    cout << "isAdult = " << isAdult << endl;

    /*
    Type Casting: In this process one data type is converted into the other
    1. Conversion (Implicit): small size --> bigger size
        eg: char to int, float to double etc.
    2. Casting (Explicit): usually big size --> smaller size
        eg: int to char, double to int etc.
    */
    char character = 'k';
    int char_value = character;    // char to int
    cout << "The integer value of " << character << " is " << char_value << endl;

    double marks = 99.999;
    int marks_int = (int) marks;    // note: 99.999 will not be rounded off instead only the integer part will be taken out
    cout << marks << " in integer are " << marks_int << endl;

    /*
    Taking inputs from the user - use of `cin` from the iostram.

    NOTE: Many people confuse `cin` and `cout` as functions but they are objects not functions,
          and the `<<` and `>>` are used for overloading which you'll get to know more in Object Oriented Programming.
    */
    int user_age;

    // cout << "\nPlease enter your age: ";
    // cin >> user_age;
    // cout << "Confirming...\nyour age is " << user_age << endl;

    /*
    OPERATORS: these are used to performs some operations.

    1. Arithemetic   --> +, -, *, /, %
    2. Relational    --> <. >, <=, >=, ==, !=    --> returns a bool (true or false)
    3. Logical       --> &&, ||, !
    4. Bitwise       --> &, |, ^, <<, >>

    NOTE: in division (/) -> for a / b
        if both a and b are int then the answer will be an integer  -->  11 / 2 = 4
        but if either a or b or both are float or double then       -->  11.0 / 2 or 11 / 2.0 = 4.5
        here we use `typecasting` to make our job easier (a and b are int)   --> 11 / (float) 2 = 4.5

    TYPES OF OPERATORS
    1. Unary (single operand)   --> increment (++) and decrement (--)    --> prefix and postfix
    2. Binary (two operands)    --> arithmetic (+, -, *, /, %)
    3. Ternary (three operands) --> (condition ? if true : if false)
    */

    /*
    CONDITIONALS
    if-else are most commonly used for running a code block if a ceratin condition is met. <<curly braces `{}` represent a block of code>>

    syntax -
        if (condition) {
            // if block code
        } else {
            // else block code
        }
    */

    // Bitwise Operators
    int a = 5, b = 11;
    cout << "\nBitwise Operators:\n";
    cout << a << " & " << b << " = " << (a & b) << endl;
    cout << a << " | " << b << " = " << (a | b) << endl;
    cout << a << " ^ " << b << " = " << (a ^ b) << endl;
    cout << a << " << 2 is: " << (a << 2) << endl;
    cout << b << " >> 1 is: " << (b >> 1) << endl << endl;

    char ch = 'K';

    // lowercase - 97 to 122
    // uppercase - 65 to 90
    // otherwise - special

    if (ch >= 'a' && ch <= 'z' )
        cout << ch << " is a lowercase character.\n";
    else if (ch >= 65 && ch <= 90)
        cout << ch << " is an uppercase character.\n";
    else
        cout << ch << " is a special character.\n";

    // Ternary Usecase
    int num = 10;
    num % 2 == 0? cout << "EVEN\n" : cout << "ODD\n";

    /*
    LOOPS - USED TO RUN A SAME CODE MULTIPLE NUMBER OF TIMES
        1. FOR
        2. WHILE
        3. DO-WHILE
    */

    // make a program to add all the odd numbers from 1 to N
    int max = 100, i = 1, sum = 0;
    while (i <= max) {
        sum += i;
        i += 2;
    }
    cout << "the sum of odd numbers between 1 and " << max << " is " << sum << endl;

    /*
    SWITCH STATEMENT - It's a substitute for long if else ladders.
    */
    char lang = 'h';

    switch (lang) {
        case 'h': // hindi
            cout << "namaste" << endl;
            break;
        case 'e': // english
            cout << "hello\n";
            break;
        case 'p': // punjabi
            cout << "satshriakal\n";
            break;
        case 's': // spanish
            cout << "hola\n";
            break;
        case 'f': // french
            cout << "bonjour\n";
            break;
        case 'i': // italian
            cout << "ciao\n";
            break;
        case 'j': // japanese
            cout << "konnichiwa\n";
            break;
        case 'c': // chinese
            cout << "ni hao\n";
            break;
        default:
            cout << "haha car go vroom vroom boom boom brrrrr....\n";
            break;
    }

    // ASCII art for fun : )
    cout << "\n";
    cout << "~*~~~~~~~~~~~*~~~~~~~~~~\n";
    cout << "~~~~~~~~_______~~~~~*~~~\n";
    cout << "~*~~___/       \\___~~~~~\n";
    cout << "~~~/__           ___\\~~~\n";
    cout << "======\\_/=====\\_/=======\n";
    cout << "========================\n";

    return 0;
}

/*
To run this c++ script you'll now need to open the terminal at where you have the file and enter the following -
    `g++ file_name.cpp` ==> replace the file_name with the name of your file
It'll create a file in the same folder with the name `a.exe` and when you'll run that your code will run.

If you want to give your compiled (.exe) file a different name use -
    `g++ file_name.cpp -o chossen_name`

If you want to compile and run the code in the same command then use -
    `g++ hello.cpp && ./a.exe`
    `g++ hello.cpp -o greet && ./name.exe`

NOTE: if you are a MAC user you will have a `a.out` file rather than the `.exe` file rest of the things are same.
*/