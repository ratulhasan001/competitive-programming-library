#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Counts how many integers in [0, N] satisfy some digit-based property.
// Example implemented here: digit sum <= limitSum.
string num;
int limitSum;
ll dp[20][200][2];
bool vis[20][200][2];

ll solve(int pos, int sumSoFar, bool tight) {
    if (pos == (int)num.size()) return sumSoFar <= limitSum;
    if (vis[pos][sumSoFar][tight]) return dp[pos][sumSoFar][tight];
    vis[pos][sumSoFar][tight] = true;

    int limit = tight ? (num[pos] - '0') : 9;
    ll ans = 0;
    for (int d = 0; d <= limit; d++) {
        bool nextTight = tight && (d == limit);
        ans += solve(pos + 1, sumSoFar + d, nextTight);
    }
    return dp[pos][sumSoFar][tight] = ans;
}

ll countUpTo(ll N) {
    if (N < 0) return 0;
    num = to_string(N);
    memset(vis, false, sizeof(vis));
    return solve(0, 0, true);
}

int32_t main() {
    ll l, r;
    cin >> l >> r >> limitSum;
    cout << countUpTo(r) - countUpTo(l - 1) << endl;
    return 0;
}
