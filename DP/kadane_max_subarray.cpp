#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(vector<int> &v) {
    int res = v[0];
    int maxEnding = v[0];
    for (int i = 1; i < (int)v.size(); i++) {
        maxEnding = max(v[i], maxEnding + v[i]);
        res = max(res, maxEnding);
    }
    return res;
}

int32_t main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    cout << maxSubarraySum(v) << endl;
    return 0;
}
