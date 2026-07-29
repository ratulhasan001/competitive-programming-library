#include <bits/stdc++.h>
using namespace std;

// number of permutations of n elements with no fixed point
long long disarrange(int n) {
    vector<long long> dp(n + 1);
    dp[1] = 0;
    if (n >= 2) dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        dp[i] = (long long)(i - 1) * (dp[i - 1] + dp[i - 2]);
    }
    return dp[n];
}

int32_t main() {
    int n;
    cin >> n;
    cout << disarrange(n) << endl;
    return 0;
}
