// 125. Valid Palindrome - https://leetcode.com/problems/valid-palindrome/

#include <iostream>
#include <string> // it's included already within `iostream`, written just for reference
using namespace std;

/*
Approach:

for the string "A man, a plan, a canal: Panama"

we need to remove the not alpha-numeric characters first -> "AmanaplanacanalPanama"

then convert it into lowercase -> "amanaplanacanalpanama"

now check for palindrome or not
*/

bool validPalindrome(string s) {
    int left = 0, right = s.size() - 1;

    while (left < right) {
        if (!isalnum(s[left])) {
            left++;
            continue;
        }
        if (!isalnum(s[right])) {
            right--;
            continue;
        }
        if (tolower(s[left]) != tolower(s[right])) return false;

        left++; right--;
    }
    return true;
}

int main() {
    string s = "A man, a plan, a canal: Panama";

    bool isValidPalindrome = validPalindrome(s);

    if (isValidPalindrome) cout << "Valid Palindrome!!\n";
    else cout << "Not Valid Palindrome!!\n";

    return 0;
}

/*
Time Complexity: O(1) -> traverses once
Space Complexity: O(1) -> no extra space required
*/