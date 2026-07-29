#include <bits/stdc++.h>
using namespace std;

bool isPowerof(long long num, long long base) {
    if (num <= 0) return false;
    if (num % base == 0) return isPowerof(num / base, base);
    if (num == 1) return true;
    return false;
}

long long powmod(long long a, long long b, long long MOD) {
    long long res = 1;
    a %= MOD;
    assert(b >= 0);
    for (; b; b >>= 1) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
    }
    return res;
}

long long binpow(long long a, long long b) {
    if (b == 0) return 1;
    long long res = binpow(a, b / 2);
    if (b % 2) return res * res * a;
    else return res * res;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

bool isPowerOfTwo(long long x) { return x && !(x & (x - 1)); }

long long nextPowerOfTwo(long long x) {
    if (x <= 0) return 1;
    return 1LL << (64 - __builtin_clzll(x - 1));
}

int32_t main() {
    long long a, b;
    cin >> a >> b;
    cout << "gcd: " << gcd(a, b) << " lcm: " << lcm(a, b) << endl;
    cout << "binpow(a,b): " << binpow(a, b) << endl;
    return 0;
}
