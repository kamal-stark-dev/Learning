// Encode and Decode Strings - https://neetcode.io/problems/string-encode-and-decode/question

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string encode(vector<string> words) {
    string encoded = "";
    for (string word: words) {
        encoded += to_string(word.size()) + "%" + word;
    }
    return encoded;
}

vector<string> decode(string encoded) {
    vector<string> res;
    int i = 0;
    while (i < encoded.size()) {
        int j = i;
        while (encoded[j] != '%') {
            j++;
        }
        string len = encoded.substr(i, j - i);
        int length = stoi(len);
        res.push_back(encoded.substr(j + 1, length));
        i = j + 1 + length;
    }
    return res;
}

int main(void) {
    vector<string> words = {"Encode", "and", "decode", "strings", "."};

    string encoded = encode(words);
    cout  << "Encoded: `" << encoded << "`\n";

    vector<string> decoded = decode(encoded);
    cout << "Decoded: ";
    for (string word: decoded) {
        cout << "`" << word << "`, ";
    }
    cout << "\b\b \n";

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/