// 198. House Robber

#include <iostream>
#include <vector>
using namespace std;

int rob(vector<int>& houses) { // Tc: O(n), SC: O(n)
    int n = houses.size();
    if (n == 1) return houses[0];

    vector<int> dp(n + 1);
    dp[1] = houses[0];
    dp[2] = max(houses[0], houses[1]);
    for (int i = 3; i <= n; i++) {
        dp[i] = max(dp[i - 1], houses[i - 1] + dp[i - 2]);
    }
    return dp[n];
}

int rob_optimized(vector<int>& houses) {
    int maxi = 0, prevMax = 0, temp = 0;
    for (int house: houses) {
        temp = maxi;
        maxi = max(maxi, prevMax + house);
        prevMax = temp;
    }
    return maxi;
}

int main(void) {
    vector<int> houses = {2, 7, 9, 3, 1};
    cout << "Max amount you can rob is " << rob_optimized(houses) << ".\n";

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/