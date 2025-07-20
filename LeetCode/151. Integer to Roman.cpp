// 12. Integer to Roman

#include <iostream>
#include <vector>
using namespace std;

string intToRoman_Brute(int num) {
    string roman = "";

    if (num / 1000) {
        roman += string(num / 1000, 'M');
        while (num >= 1000) num -= 1000;
    }
    if (num / 900) {
        roman += "CM";
        num -= 900;
    }
    if (num / 500) {
        roman += 'D';
        num -= 500;
    }
    if (num / 400) {
        roman += "CD";
        num -= 400;
    }
    if (num / 100) {
        roman += string(num / 100, 'C');
        while (num >= 100) num -= 100;
    }
    if (num / 90) {
        roman += "XC";
        num -= 90;
    }
    if (num / 50) {
        roman += 'L';
        num -= 50;
    }
    if (num / 40) {
        roman += "XL";
        num -= 40;
    }
    if (num / 10) {
        roman += string(num / 10, 'X');
        while (num >= 10) num -= 10;
    }
    if (num / 9) {
        roman += "IX";
        num -= 9;
    }
    if (num / 5) {
        roman += 'V';
        num -= 5;
    }
    if (num / 4) {
        roman += "IV";
        num -= 4;
    }
    while (num >= 1) {
        roman += 'I';
        num -= 1;
    }
    return roman;
}

string intToRoman_Better(int num) {
    const vector<pair<int, string>> char_map {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    string roman = "";
    for (const auto& [value, symbol]: char_map) {
        if (num == 0) break;
        while (num >= value) {
            roman += symbol;
            num -= value;
        }
    }
    return roman;
}

int main(void) {
    vector<int> nums = {10, 58, 1994, 3749};

    for (int num: nums) {
        cout << num << " in roman is " << intToRoman_Better(num) << "\n";
    }

    return 0;
}

/*
Time Complexity: O(1)
Space Complexity: O(1)

The maximum number of symbols for any number ≤ 3999 is limited (as standard Roman numerals do not go beyond 3999).
Thus this has a constant time complexity.
*/