// 2226. Maximum Candies Allocated to K Children

#include <iostream>
#include <vector>
using namespace std;

bool canAllocateCandies(vector<int> candies, int k, int numOfCandies) { // O(n)
    long long maxNoOfChildren = 0;
    for (int i = 0; i < candies.size(); i++) {
        maxNoOfChildren += candies[i] / numOfCandies;
    }
    return maxNoOfChildren >= k;
}

int maximumCandies(vector<int> candies, long long k) { // O(log.m) -> [0, m] range
    int maxCandies = 0;
    for (int i = 0; i < candies.size(); i++) {
        maxCandies = max(maxCandies, candies[i]);
    }

    int left = 0, right = maxCandies;
    while (left < right) {
        int middle = (left + right + 1) / 2;

        if (canAllocateCandies(candies, k, middle)) left = middle + 1;
        else right = middle - 1;
    }
    return left;
}

int main(void) {
    vector<int> candies = {5, 8, 6};
    long long k = 3;

    long long maxCandies = maximumCandies(candies, k);
    cout << "The maximum candies that each children gets are: " << maxCandies << endl;

    return 0;
}
/*
Time Complexity: O(n log.m)
Space Complexity: O(1)
*/