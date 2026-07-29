#include <bits/stdc++.h>
using namespace std;

// bounded coin change (each coin i usable up to c[i] times), solved as a 0/1
// knapsack over O(log(c[i])) grouped items -- O(n * S * log(maxCount))
int32_t main() {
    int n;
    long long S;
    cin >> n >> S;
    vector<long long> w(n), c(n);
    for (auto &x : w) cin >> x;
    for (auto &x : c) cin >> x;

    vector<long long> dp(S + 1, 0);
    dp[0] = 1; // number of ways to form each sum

    for (int i = 0; i < n; i++) {
        long long coin = w[i], count = c[i];
        for (long long k = 1; count > 0; k <<= 1) {
            long long take = min(k, count);
            for (long long j = S; j >= take * coin; j--) {
                dp[j] += dp[j - take * coin];
            }
            count -= take;
        }
    }
    cout << dp[S] << endl;
    return 0;
}
