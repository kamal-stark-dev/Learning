// 3169. Count Days Without Meetings

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// dry run to understand the code
int countDays(int days, vector<vector<int>>& meetings) {
    sort(meetings.begin(), meetings.end()); // O(n logn)

    int prevEnd = 0;
    for (auto& meeting: meetings) {
        int start = max(meeting[0], prevEnd + 1);
        int length = meeting[1] - start + 1;
        days -= max(length, 0);
        prevEnd = max(meeting[1], prevEnd);
    }
    return days;
}

int main(void) {
    int days = 10;
    vector<vector<int>> meetings = {{5, 7}, {1, 3}, {9, 10}};

    cout << countDays(days, meetings) << endl;

    return 0;
}