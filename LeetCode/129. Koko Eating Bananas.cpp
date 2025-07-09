// Koko Eating Bananas

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValid(vector<int> piles, int h, int k) {
    int i = 0, n = piles.size();
    long long total_time = 0;
    while (i < n) {
        total_time += (piles[i] / k) + ((piles[i] % k == 0) ? 0 : 1);
        i++;
    }
    return total_time <= h;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int n = piles.size();
    int k = *max_element(piles.begin(), piles.end());
    if (n == h) return k;

    int left = 1, right = k;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (isValid(piles, h, mid)) {
            k = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }
    return k;
}

int main(void) {
    vector<int> piles = {332484035,524908576,855865114,632922376,222257295,690155293,112677673,679580077,337406589,290818316,877337160,901728858,679284947,688210097,692137887,718203285,629455728,941802184};
    int h = 823855818;

    // we need to find the minimum value of `k` such that all the bananas can be eaten in `h` hours.
    cout << "The minimum number of k is " << minEatingSpeed(piles, h) << " hours\n";

    return 0;
}