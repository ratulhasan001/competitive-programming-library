#include <bits/stdc++.h>
using namespace std;

// Sum over Subsets: for every mask, sums f[submask] over all submask subset-of mask.
// O(n * 2^n) instead of the O(3^n) brute force.
int32_t main() {
    int n; // number of bits
    cin >> n;
    int N = 1 << n;
    vector<long long> f(N);
    for (auto &x : f) cin >> x;

    vector<long long> sos = f;
    for (int bit = 0; bit < n; bit++) {
        for (int mask = 0; mask < N; mask++) {
            if (mask & (1 << bit)) {
                sos[mask] += sos[mask ^ (1 << bit)];
            }
        }
    }

    for (long long x : sos) cout << x << " ";
    cout << endl;
    return 0;
}
