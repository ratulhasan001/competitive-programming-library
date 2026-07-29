#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> cost;
vector<vector<int>> memo;

int totalCost(int mask, int pos, int n) {
    if (mask == (1 << n) - 1) return cost[pos][0];
    if (memo[mask][pos] != -1) return memo[mask][pos];
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        if ((mask & (1 << i)) == 0) {
            ans = min(ans, cost[pos][i] + totalCost(mask | (1 << i), i, n));
        }
    }
    return memo[mask][pos] = ans;
}

int tsp() {
    int n = cost.size();
    memo.assign(1 << n, vector<int>(n, -1));
    return totalCost(1, 0, n);
}

int32_t main() {
    int n;
    cin >> n;
    cost.assign(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];
    cout << tsp() << endl;
    return 0;
}
