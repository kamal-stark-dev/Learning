// Stock Span Problem - https://www.hackerearth.com/problem/algorithm/stock-span-4-a0d4600b-b5c6efe0/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(void) {
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};

    int size = prices.size();
    vector<int> ans(size, 0);
    stack<int> s;

    for (int i = 0; i < size; i++) { // O(n)
        while(!s.empty() && prices[s.top()] <= prices[i]) s.pop(); // O(1) -> constant time
        if (s.empty()) ans[i] = i + 1;
        else ans[i] = i - s.top();

        s.push(i);
    }

    for (int n : ans) cout << n << " ";
    cout << endl;

    return 0;
}
/*
Time Complexity: O(n)
Space Complexity: O(n) -> stack
*/