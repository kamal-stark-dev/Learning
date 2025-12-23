// 198. House Robber

#include <iostream>
#include <vector>
using namespace std;

int rob(vector<int>& houses) {
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
    cout << "Max amount you can rob is " << rob(houses) << ".\n";

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/