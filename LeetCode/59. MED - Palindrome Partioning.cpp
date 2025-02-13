// 131. Palindrome Partitioning

#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(string s) {
    int l = 0, r = s.length() - 1;
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++; r--;
    }
    return true;
}

void palindromepPartition(string s, vector<string>& part, vector<vector<string>>& partitions) {

    if (s.length() == 0) {
        partitions.push_back(part);
        return;
    }

    for (int i = 0; i < s.length(); i++) {
        string subStr = s.substr(0, i + 1);
        if (isPalindrome(subStr)) {
            part.push_back(subStr);
            palindromepPartition(s.substr(i + 1), part, partitions);
            part.pop_back();
        }
    }
}

/*
example: string = "aabcb" ==> [["a", "a", "b", "c", "b"], ["aa", "b", "c", "b"], ["aa", "bcb"], ["a", "a", "bcb"]]
*/
vector<vector<string>> partition(string s) {
    vector<vector<string>> partitions;
    vector<string> part;
    palindromepPartition(s, part, partitions);
    return partitions;
}

int main(void) {
    string s = "aab";
    vector<vector<string>> partitions = partition(s);

    for (vector<string> strs : partitions) {
        for (string s : strs) {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}
/*
Time Complexity: O(n * 2 ^ n) ==> `2 ^ n` is the total partition count and each is checked for palindrome or not which is `n`
*/