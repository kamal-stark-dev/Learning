#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

void findMoves(vector<pair<int, int>>& moves, pair<int, int> move) {
    moves[0].first += move.first;
    moves[0].second += move.second;
    moves[1].first -= move.first;
    moves[1].second -= move.second;
    moves[2].first += move.second;
    moves[2].second += move.first;
    moves[3].first -= move.second;
    moves[3].second += move.first;
    moves[4].first += move.first;
    moves[4].second -= move.second;
    moves[5].first -= move.first;
    moves[5].second += move.second;
    moves[6].first += move.second;
    moves[6].second -= move.first;
    moves[7].first -= move.second;
    moves[7].second += move.first;
}

void solve() {
    pair<int, int> move;
    int kx, ky, qx, qy;
    cin >> move.first >> move.second >> kx >> ky >> qx >> qy;

    vector<pair<int, int>> kMoves(8, {kx, ky});
    vector<pair<int, int>> qMoves(8, {qx, qy});

    findMoves(kMoves, move);
    findMoves(qMoves, move);

    cout << "King Moves:\n";
    for (auto move : kMoves) {
        cout << move.first << " " << move.second << "\n";
    }

    cout << "Queen Moves:\n";
    for (auto move : qMoves) {
        cout << move.first << " " << move.second << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
