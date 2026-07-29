#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;
vector<long long> fact(MAXN), inv_fact(MAXN);

long long modpow(long long a, long long b, long long m = MOD) {
    long long res = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void init_fact() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) fact[i] = fact[i - 1] * i % MOD;
    inv_fact[MAXN - 1] = modpow(fact[MAXN - 1], MOD - 2, MOD);
    for (int i = MAXN - 2; i >= 0; i--) inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
}

long long nPr(int n, int r) {
    if (r > n) return 0;
    long long res = 1;
    for (int i = 0; i < r; i++) res *= (n - i);
    return res;
}

long long nCr_plain(int n, int r) {
    if (r > n) return 0;
    r = min(r, n - r);
    long long res = 1;
    for (int i = 0; i < r; i++) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

int32_t main() {
    init_fact();
    int n, r;
    cin >> n >> r;
    cout << "nCr (mod): " << nCr(n, r) << endl;
    cout << "nPr: " << nPr(n, r) << endl;
    cout << "nCr (plain): " << nCr_plain(n, r) << endl;
    return 0;
}
