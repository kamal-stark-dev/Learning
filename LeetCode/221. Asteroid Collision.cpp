// 735. Asteroid Collision

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> asteroidCollision(vector<int> asteroids) {
    stack<int> st;

    for (int b: asteroids) {
        bool destroyed = false;

        while (!st.empty() && st.top() > 0 && b < 0) {
            if (abs(st.top()) < abs(b)) { // top asteroid exploded keep checking
                st.pop();
                continue;
            }
            else if (abs(st.top()) == abs(b)) { // both asteroid explodes
                st.pop();
                destroyed = true;
                break;
            }
            else { // incoming asteroid explodes
                destroyed = true;
                break;
            }
        }
        if (!destroyed) st.push(b);
    }

    vector<int> ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(void) {
    // vector<int> asteroids = {5, 10, -5};
    vector<int> asteroids = {3, 5, -6, 2, -1, 4};

    vector<int> afterCollisions = asteroidCollision(asteroids);
    for (int n: afterCollisions) cout << n << " ";

    return 0;
}

/*
Time Complexity: O(n) -> O(2 * n)
Space Complexity: O(n)
*/