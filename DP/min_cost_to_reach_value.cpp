#include <bits/stdc++.h>
using namespace std;

// dp[val] = minimum weight needed to achieve exactly `val` total value from
// a 0/1 selection of items (v[i], w[i]).
// answer: the largest val achievable with total weight <= W
int32_t main() {
    int n;
    long long W;
    cin >> n >> W;
    vector<long long> v(n), w(n);
    for (auto &x : v) cin >> x;
    for (auto &x : w) cin >> x;

    long long V = 0;
    for (long long val : v) V += val;
    const long long INF = 1e18;

    vector<long long> dp(V + 1, INF);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        // 0/1 version: iterate value downward
        for (long long val = V; val >= v[i]; val--) {
            dp[val] = min(dp[val], dp[val - v[i]] + w[i]);
        }
        // unbounded version: iterate value upward instead
        // for (long long val = v[i]; val <= V; val++) dp[val] = min(dp[val], dp[val - v[i]] + w[i]);
    }

    long long ans = 0;
    for (long long val = 0; val <= V; val++) {
        if (dp[val] <= W) ans = val;
    }
    cout << ans << endl;
    return 0;
}
