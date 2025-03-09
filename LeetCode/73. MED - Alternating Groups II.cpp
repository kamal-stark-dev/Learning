// 3208. Alternating Groups II

#include <iostream>
#include <vector>
using namespace std;

int numberOfAlternatingGroups(vector<int>& colors, int k) {
    colors.insert(colors.end(), colors.begin(), colors.begin() + (k - 1));

    int left = 0, count = 0;
    for (int right = 0; right < colors.size(); right++) {
        if (right > 0 && colors[right] == colors[right - 1]) {
            left = right;
        }
        if (right - left + 1 >= k) {
            count ++;
        }
    }
    return count;
}

int numberOfAlternatingGroups_witnoutExtraSpace(vector<int>& colors, int k) {
    int n = colors.size();
    int left = 0, count = 0;
    for (int right = 0; right < n + k - 1; right++) {
        if (right > 0 && colors[right % n] == colors[(right - 1) % n]) {
            left = right;
        }
        if (right - left + 1 >= k) {
            count ++;
        }
    }
    return count;
}

int main(void) {
    vector<int> colors = {0, 1, 0, 1, 0};
    int k = 3;

    // cout << "There are " << numberOfAlternatingGroups(colors, k) << " alternating groups of size " << k << ".\n";
    cout << "There are " << numberOfAlternatingGroups_witnoutExtraSpace(colors, k) << " alternating groups of size " << k << ".\n";
    return 0;
}