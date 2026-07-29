#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using u128 = __uint128_t;

ull binpower(ull base, ull e, ull mod) {
    ull result = 1;
    base %= mod;
    while (e) {
        if (e & 1) result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(ull n, ull a, ull d, int s) {
    ull x = binpower(a, d, n);
    if (x == 1 || x == n - 1) return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1) return false;
    }
    return true;
}

bool MillerRabin(ull n) {
    if (n < 2) return false;
    int r = 0;
    ull d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }
    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == (ull)a) return true;
        if (check_composite(n, a, d, r)) return false;
    }
    return true;
}

ull f(ull x, ull c, ull mod) {
    return ((u128)x * x + c) % mod;
}

ull PollardRho(ull n) {
    if (n % 2ULL == 0ULL) return 2ULL;
    static mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    while (true) {
        ull x = uniform_int_distribution<ull>(2, n - 2)(rng);
        ull y = x;
        ull c = uniform_int_distribution<ull>(1, n - 1)(rng);
        ull d = 1;
        while (d == 1) {
            x = f(x, c, n);
            y = f(f(y, c, n), c, n);
            d = gcd<ull>(x > y ? x - y : y - x, n);
            if (d == n) break;
        }
        if (d > 1 && d < n) return d;
    }
}

vector<ull> factors;
void factorize(ull n) {
    if (n == 1) return;
    if (MillerRabin(n)) {
        factors.push_back(n);
        return;
    }
    ull divisor = PollardRho(n);
    factorize(divisor);
    factorize(n / divisor);
}

int32_t main() {
    ull n;
    cin >> n;
    factorize(n);
    sort(factors.begin(), factors.end());
    for (ull p : factors) cout << p << " ";
    cout << endl;
    return 0;
}
