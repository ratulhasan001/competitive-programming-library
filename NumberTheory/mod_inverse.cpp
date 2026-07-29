#include <bits/stdc++.h>
using namespace std;

long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) { x = 1; y = 0; return a; }
    long long x1, y1;
    long long d = extGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

// works even when m is not prime, as long as gcd(a, m) == 1
long long modInverse(long long a, long long m) {
    long long x, y;
    long long g = extGCD(a, m, x, y);
    if (g != 1) return -1;
    return (x % m + m) % m;
}

int32_t main() {
    long long a, m;
    cin >> a >> m;
    cout << modInverse(a, m) << endl;
    return 0;
}
