// 443. String Compression - https://leetcode.com/problems/string-compression/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int compress(vector<char>& chars) {
  int n = chars.size();
  
  int idx = 0;
  for (int i = 0; i < n; i++) {
    char ch = chars[i];
    int count = 0;

    while (i < n && chars[i] == ch) {
      count++; i++;
    }
    
    if (count == 1) chars[idx++] = ch;
    else {
      chars[idx++] = ch;
      string digits = to_string(count);
      for (char digit: digits) chars[idx++] = digit;
    }
    i--; // to cancel out the extra `i++` which will affect the for loop elsewise
  }

  // resizing the new string
  chars.resize(idx);
  
  return idx;
}

int main() {
  vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
  // output -> len(a2b2c3) -> {'a', '2', 'b', '2', 'c', '3'} -> 6
  
  cout << compress(chars) << endl;

  for (char ch: chars) cout << ch;
  cout << endl;

  return 0;
}
