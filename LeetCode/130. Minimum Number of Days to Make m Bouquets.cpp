//  Minimum Number of Days to Make m Bouquets

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canMakeBouquets(vector<int>& bloomDay, int m, int k, int max_days) {
    int bouquets = 0;
    int i = 0, n = bloomDay.size();
    while (i < n) {
        int count = 0;
        while (i < n && bloomDay[i] <= max_days) {
            count++;
            i++;
        }
        bouquets += count / k;
        i++;
    }
    return bouquets >= m;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    int n = bloomDay.size();
    // if (n < m * k) return -1; // this can raise integer overflow

    int left = 1, right = *max_element(bloomDay.begin(), bloomDay.end());
    int mini = -1; // set it to -1 from the beginning

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canMakeBouquets(bloomDay, m, k, mid)) {
            mini = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }

    return mini;
}

int main(void) {
    vector<int> bloomDay = {7, 7, 7, 7, 12, 7, 7};
    int m = 3, k = 2;
    cout << "Minimum days for making " << m << " bouquets with " << k << " flowers in each is " << minDays(bloomDay, m, k) << " days.\n";

    return 0;
}