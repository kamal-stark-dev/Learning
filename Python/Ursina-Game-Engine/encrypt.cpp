// Fking Ceasar Cipher (shifts the characters by a certain value)

#include<iostream>
#include<vector>
using namespace std;

string encrypt(string s, int key) {
    string res;
    key = ((key % 26) + 26) % 26;

    for (char c: s) {
        if (c == ' ') {
            res += ' ';
            continue;
        }
        char base = (c >= 'a' && c <= 'z') ? 'a': 'A';
        res += (c + key - base) % 26 + base;
    }
    return res;
}

string decrypt(string s, int key) {
    return encrypt(s, -key);
}

vector<string> breakCeasarCipher(string s) {
    vector<string> candidates(26);
    for (int i = 0; i < 26; i++) {
        candidates[i] = decrypt(s, i);
    }
    return candidates;
}

int main(void) {
    string s = "Simple but good";
    int key = 13;

    string encoded = encrypt(s, key);

    cout << encoded << "\n";
    cout << decrypt(encoded, key) << "\n\n";

    // Breaking the Ceasar Cipher
    cout << "Candidates:\n";
    vector<string> candidates = breakCeasarCipher(encoded);
    for (int i = 0; i < 26; i++) {
        cout << i << " : `" << candidates[i] << "`\n";
    }

    return 0;
}