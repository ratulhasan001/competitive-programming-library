#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;

ll extGCD(ll a, ll b, ll &x, ll &y) {
    if (b == 0) { x = 1; y = 0; return a; }
    ll x1, y1;
    ll d = extGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

// Combines x = r1 (mod m1), x = r2 (mod m2) into x = r (mod lcm(m1, m2)).
// Returns {r, lcm}; returns {-1, -1} if no solution exists. Moduli need not be coprime.
pair<ll, ll> crt(ll r1, ll m1, ll r2, ll m2) {
    ll p, q;
    ll g = extGCD(m1, m2, p, q);
    if ((r2 - r1) % g != 0) return {-1, -1};

    ll lcm = m1 / g * m2;
    i128 x = (i128)r1 + (i128)m1 * ((i128)p * ((r2 - r1) / g) % (m2 / g));
    x = ((x % lcm) + lcm) % lcm;
    return {(ll)x, lcm};
}

int32_t main() {
    int n;
    cin >> n;
    ll r, m;
    cin >> r >> m;
    bool ok = true;
    for (int i = 1; i < n; i++) {
        ll r2, m2;
        cin >> r2 >> m2;
        auto [nr, nm] = crt(r, m, r2, m2);
        if (nm == -1) { ok = false; break; }
        r = nr;
        m = nm;
    }
    if (!ok) cout << "No solution\n";
    else cout << r << " mod " << m << endl;
    return 0;
}
