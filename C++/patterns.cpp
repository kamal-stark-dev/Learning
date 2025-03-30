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
        if (i % 2 == 0) bit = 1;
        else bit = 0;
        for (int j = 0; j <= i; j++) {
            cout << bit << " ";
            bit = 1 - bit; // flip 1 to 0 and 0 to 1
        }
        cout << "\n";
    }
    br();

    // 12 - valley cut
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << pattern << " ";
        }
        for (int j = 0; j < 2 * (n - i - 1); j++) {
            cout << "  ";
        }
        for (int j = 0; j <= i; j++) {
            cout << pattern << " ";
        }
        cout << "\n";
    }
    br();

    // 13 - valley cut with numbers
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << j + 1 << " ";
        }
        for (int j = 0; j < 2 * (n - i - 1); j++) {
            cout << "  ";
        }
        for (int j = i; j >= 0; j--) {
            cout << j + 1 << " ";
        }
        cout << "\n";
    }
    br();

    // 14 - increasing numbers triangle
    int num = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << num++ << " ";
        }
        cout << "\n";
    }
    br();

    // 15 - characters increasing triangle
    for (int i = 0; i < n; i++) {
        // char ch = 'A';
        // for (int j = 0; j <= i; j++) {
        //     cout << ch++ << " ";
        // }
        for (char ch = 'A'; ch <= 'A' + i; ch++) {
            cout << ch << " ";
        }
        cout << "\n";
    }
    br();

    // 16 - middle triangle with chars
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n - i - 1; j++) {
            cout << "  ";
        }
        for (char c = 'A'; c <= 'A' + i; c++) {
            cout << c << " ";
        }
        for (char c = 'A' + i - 1; c >= 'A'; c--) {
            cout << c << " ";
        }
        cout << "\n";
    }
    br();

    // 17 - reversed chars triangle
    for (int i = 0; i < n; i++) {
        char c = 'A' + n - 1;
        for (int j = 0; j <= i; j++) {
            cout << c << " ";
            c--;
        }
        cout << "\n";
    }
    br();

    // 18 - reverse diamond
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            cout << pattern << " ";
        }
        for (int j = 0; j < i * 2; j++) {
            cout << "  ";
        }
        for (int j = 0; j < n - i; j++) {
            cout << pattern << " ";
        }
        cout << "\n";
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << pattern << " ";
        }
        for (int j = 0; j < 2 * (n - i - 1); j++) {
            cout << "  ";
        }
        for (int j = 0; j <= i; j++) {
            cout << pattern << " ";
        }
        cout << "\n";
    }
    br();

    // 19 - butterfly pattern
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << pattern << " ";
        }
        for (int j = 0; j < 2 * (n - i - 1); j++) {
            cout << "  ";
        }
        for (int j = 0; j <= i; j++) {
            cout << pattern << " ";
        }
        cout << "\n";
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            cout << pattern << " ";
        }
        for (int j = 0; j < i * 2; j++) {
            cout << "  ";
        }
        for (int j = 0; j < n - i; j++) {
            cout << pattern << " ";
        }
        cout << "\n";
    }
    br();

    // 20 - hollow square
    n = 5;
    for (int i = 0; i < n; i++) {
        cout << pattern << " ";
        char s = ' ';
        if (i == 0 || i == n - 1) s = pattern;
        for (int j = 1; j < n - 1; j++) {
            cout << s << " ";
        }
        cout << pattern << " ";
        cout << "\n";
    }
    br();

    // 21 - numbers boundaries (master)
    n = 4;
    for (int i = 0; i < 2 * n - 1; i++) {
        for (int j = 0; j < 2 * n - 1; j++) {
            int top = i, left = j, right = (2 * n - 2) - j, bottom = (2 * n - 2) - i;

            cout << (n - min(min(top, bottom), min(left, right))) << " ";
        }
        cout << "\n";
    }
    br();

    return 0;
}