#include <iostream>
using namespace std;

// Patterns go brrr...

void br(int n = 25) {
    for (int i = 0; i < n; i++) {
        cout << "-";
    }
    cout << "\n";
}

int main(void) {
    br();
    cout << "Patterns go brrr...\n";
    br();

    // 01 - square pattern
    char pattern = '*';
    int n = 4;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << pattern << " ";
        }
        cout << "\n";
    }
    br();

    // 02 - lower triangle
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << pattern << " ";
        }
        cout << "\n";
    }
    br();

    // 03 - lower triangle with numbers
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << (j + 1) << " ";
        }
        cout << "\n";
    }
    br();

    // 04 - lower triangle with row numbers
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << (i + 1) << " ";
        }
        cout << "\n";
    }
    br();

    // 05 - upper triangle
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            cout << pattern << " ";
        }
        cout << "\n";
    }
    br();

    // 06 - upper triangle with numbers
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            cout << (j + 1) << " ";
        }
        cout << "\n";
    }
    br();

    // 07 - pyramid
    pattern = '$';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) { // add spaces
            cout << " ";
        }
        for (int j = 0; j <= i; j++) { // draw pattern
            cout << pattern << " ";
        }
        cout << endl;
    }
    br();

    // 08 - reversed pyramid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        for (int j = 0; j < n - i; j++) {
            cout << pattern << " ";
        }
        cout << endl;
    }
    br();

    // 09 - diamond
    pattern = '*';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) { // add spaces
            cout << " ";
        }
        for (int j = 0; j <= i; j++) { // draw pattern
            cout << pattern << " ";
        }
        cout << endl;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        for (int j = 0; j < n - i; j++) {
            cout << pattern << " ";
        }
        cout << endl;
    }
    br();

    // 10 - half diamond (vertically cut)
    for (int i = 1; i <= 2 * n - 1; i++) {
        int stars = i;
        if (i > n) stars = 2 * n - i;
        for (int j = 1; j <= stars; j++) {
            cout << pattern << " ";
        }
        cout << endl;
    }
    br();

    // 11 - triangle with 0s and 1s
    int bit = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (i % 2 == 0) bit = 1;
            else bit = 0;
            cout << bit << " ";
            bit = 1 - bit;
        }
        cout << "\n";
    }
    br();
}