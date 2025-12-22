// Alien Dictionary - https://neetcode.io/problems/foreign-dictionary/

#include <iostream>
#include <vector>
using namespace std;

string foreignDictionary(vector<string>& words) {
    vector<int> parent(26), rank(26, 1);
    for (int i = 0; i < 26; i++) {
        parent[i] = i;
    }

    
}

int main(void) {
    vector<string> words = {"hrn", "hrf", "er", "enn", "rfnn"};
    string orderOfLetters = foreignDictionary(words);

    cout << orderOfLetters << "\n";

    return 0;
}

/*
Time Complexity: O()
Space Complexity: O()
*/