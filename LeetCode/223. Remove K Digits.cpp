// 402. Remove K Digits

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

/* --> this was my approach (not passing though ->
    failing for num="33526221184202197273" and k="19", it's giving "3" but correct is "0")
*/
string removeKdigits_myTake(string num, int k) {
    stack<char> st;
    int i = 0, n = num.size();
    while (i < n) {
        while (!st.empty() && st.top() > num[i] && k) {
            k--;
            st.pop();
        }
        st.push(num[i]);
        i++;
    }
    while (k > 0) {
        st.pop();
        k--;
    }

    if (st.empty()) return "0";

    string res = "";
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());

    int pos = res.find_first_not_of('0');
    if (pos != string::npos) {
        res = res.substr(pos);
    }
    else res = "0"; // handle the case where all are zeros, "0000" -> "0"

    return res;
}

// this uses string `res` as a stack itself -> saving the stack to str conversion (stack popping and reversal) and gets rid of `find_first_not_of()` function which is really uncommon
string removeKdigits(string num, int k) {
    string res = "";
    for (char digit: num) {
        while (!res.empty() && k > 0 && res.back() > digit) {
            res.pop_back();
            k--;
        }
        res.push_back(digit);
    }
    while (k-- > 0)
        res.pop_back();

    int i = 0;
    while (i < res.size() && res[i] == '0') i++;
    return (i == res.size()) ? "0" : res.substr(i);
}

int main(void) {
    string num = "123";
    int k = 1;

    cout << "The smallest number after removing " << k << " digits from `" << num << "` is: `" << removeKdigits(num, k) << "`.\n";

    return 0;
}

/*
Time Complexity: O(n + k) but since k <= n, it simplifies to O(n)
Space Complexity: O(n), to compute and store the result
*/

// Learnt a lot from this one and had fun doing this too ~