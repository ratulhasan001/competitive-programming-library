#include <bits/stdc++.h>
using namespace std;

// Returns g = gcd(a, b) and x, y such that a*x + b*y = g
long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) { x = 1; y = 0; return a; }
    long long x1, y1;
    long long d = extGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int32_t main() {
    long long a, b, x, y;
    cin >> a >> b;
    long long g = extGCD(a, b, x, y);
    cout << "gcd = " << g << ", x = " << x << ", y = " << y << endl;
    return 0;
}
