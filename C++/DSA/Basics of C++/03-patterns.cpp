#include <iostream>
using namespace std;

void br() {
    cout << "-------------------------" << endl;
}

int main() {

    int n = 5;
    char ch = 'A';

    br();
    cout << "Square Pattern" << endl;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << char(ch + j) << " ";
        }
        cout << endl;
    }
    br();

    cout << "Num Square Increment" << endl;
    n = 3;
    int k = 1;


    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << k++ << " ";
        }
        cout << endl;
    }
    br();

    cout << "Star Triangle" << endl;
    n = 3;

    for(int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    br();

    cout << "Numeric Triangle" << endl;
    n = 5;

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            cout << (i + 1) << " ";
        }
        cout << endl;
    }
    br();

    cout << "Another Numeric Triangle" << endl;
    n = 5;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            cout << j + 1 << " ";
        }
        cout << endl;
    }
    br();

    cout << "Reversed Numeric Triangle" << endl;
    n = 5;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j > 0; j--) {
            cout << j << " ";
        }
        cout << endl;
    }
    br();

    cout << "Incremental Numeric Triangle" << endl;
    n = 5, k = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            cout << k++ << " ";
        }
        cout << endl;
    }
    br();

    cout << "Reversed Numeric Triangle" << endl;
    n = 4;

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            cout << "  ";
        }

        for (int k = n - i; k > 0; k--) {
            cout << i + 1 << " ";
        }
        cout << endl;
    }
    br();

    cout << "Numeric Pyramid" << endl;
    n = 4;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "  ";
        }
        for (int j = 0; j < i + 1; j++) {
            cout << j + 1 << " ";
        }
        for (int j = i; j > 0; j--) {
            cout << j << " ";
        }
        cout << endl;
    }
    br();

    cout << "Hollow Diamond Pattern" << endl;
    n = 4;

    /*
    0 -> star and `--` --> one space

        ------0
        ----0---0
        --0-------0
        0-----------0
        --0-------0
        ----0---0
        ------0
    */

    for (int i = 0; i < n - 1; i++) {
        // spaces
        for (int j = 0; j < n - i; j++) {
            cout << " ";
        }
        if (i != 0) {
            cout << "*";
        }
        // inner spaces
        for (int j = 0; j < 2 * i - 1; j++) {
            cout << " ";
        }
        // star
        cout << "*" << endl;
    }

    for (int i = n - 1; i >= 0; i--) {
        // spaces
        for (int j = 0; j < n - i; j++) {
            cout << " ";
        }
        if (i != 0) {
            cout << "*";
        }
        // inner spaces
        for (int j = 0; j < 2 * i - 1; j++) {
            cout << " ";
        }
        // star
        cout << "*" << endl;
    }
    br();

    cout << "Butterfly Pattern" << endl;
    n = 4;

    /*

    *             *
    * *         * *
    * * *     * * *
    * * * * * * * *
    * * * * * * * *
    * * *     * * *
    * *         * *
    *             *

    */

    // upper part
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            cout << "* ";
        }
        for (int j = 0; j < (n - i) * 2 - 2; j++) {
            cout << "  ";
        }
        for (int j = 0; j < i + 1; j++) {
            cout << "* ";
        }
        cout << endl;
    }

    // lower part
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (n - i); j++) {
            cout << "* ";
        }
        for (int j = 0; j < i * 2; j++) {
            cout << "  ";
        }
        for (int j = 0; j < (n - i); j++) {
            cout << "* ";
        }
        cout << endl;
    }
    br();

    cout << "IF YOU CAN MAKE THESE\nYOU ARE GOOD ENOUGH IN LOOPING!!" << endl;

    br();

    return 0;
}