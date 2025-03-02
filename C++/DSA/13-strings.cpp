#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    char cstring[] = {'C', 's', 't', 'r', 'i', 'n', 'g', '\0'}; // static in nature
    cout << "Str: "<< cstring << endl;

    char str[] = "Cstring";
    cout << "Str: " << str << endl;
    cout << "Len: " << strlen(str) << endl;

    /*
    Memory Representation of strings
    +-----+-----+-----+-----+-----+-----+-----+------+
    |  C  |  s  |  t  |  r  |  i  |  n  |  g  |  \0  |
    +-----+-----+-----+-----+-----+-----+-----+------+
    */

    for (int i = 0; i < strlen(str); i++)
        cout << "str[" << i << "]: `" << str[i] << "`\n";

    // this will be null character
    cout << "str[7]: `" << str[7] << "`\n";

    /*
    // storing string from input
    char input_string[100];

    cout << "Enter the string: ";
    cin >> input_string;
    cout << "The string is: " << input_string << endl;

    // but it'll ignore anything after a space(" ") character due to the `cin`
    */

    /*
    cout << "Enter string with spaces: ";
    cin.getline(input_string, 100, '.'); // '.' is delimiter
    cout << "The string is: " << input_string << endl;

    for (char c: input_string) {
        cout << c << " ";
    }
    cout << endl;

    // you'll see your string with more garbage like values, this happens because the size of the string is `100`
    */

    // find len with code
    char demo_str[] = "hello world";
    int len = 0;

    for (int i = 0; demo_str[i] != '\0'; i++) {
        len++;
    }
    cout << "\nLen: " << len << "\n";

    // string - inbuilt string class - dynamic in nature (resize at runtime)
    string str_example = "Hello World!";

    string a = "Hello";
    string b = "World";

    // concatenation of strings
    cout << "Str `a + b`: " << (a + " " + b) << endl;

    cout << "`a == a`: " << (a == a) << endl; // True
    cout << "`a == b`: " << (a == b) << endl; // False
    cout << "`a < b`: " << (a < b) << endl; // True: 'H' comes before 'W'

    cout << "Len of string `a`: " << a.length() << endl; // 5 - Hello

    // cin >> str; will ignore after spaces

    // getline(cin, str, delim);
    cout << "Enter a string (with spaces): ";
    getline(cin, str_example);

    cout << "Input String:\n";
    for (char c: str_example) cout << c << " ";
    cout << endl;

    // reversal with for loop
    // len = str_example.length();
    // int start = 0, end = len - 1;

    // while (start <= end) {
    //     swap(str_example[start++], str_example[end--]);
    // }

    reverse(str_example.begin(), str_example.end());
    cout << "\nReversed String:\n";
    for (char c: str_example) cout << c << " ";
    cout << endl;

    return 0;
}

// wow that was really cool!!