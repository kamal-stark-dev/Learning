// 2594. Minimum Time to Repair Cars

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

long long repairCars(vector<int> ranks, int cars) {
    int minRank = ranks[0], maxRank = ranks[0];
    for (int rank : ranks) {
        minRank = min(rank, minRank);
        maxRank = max(rank, maxRank);
    }

    vector<int> freq(maxRank + 1);
    for (int rank : ranks) {
        freq[rank]++;
    }

    long long low = 1, high = minRank * cars * cars;

    while (low < high) {
        long long mid = (low + high) / 2;
        long long carsRepaired = 0;

        for (int i = 1; i <= maxRank; i++) {
            carsRepaired += freq[i] * sqrt(mid / i);
        }

        if (carsRepaired >= cars) high = mid;
        else low = mid + 1;
    }
    return low; // or high
}

int main(void) {
    vector<int> ranks = {4, 2, 3, 1};
    int cars = 10;

    long long minTimeToRepair = repairCars(ranks, cars);
    cout << "The minimum time required to fix all " << cars << " cars is " << minTimeToRepair << " minutes.\n";

    return 0;
}