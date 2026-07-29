#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const long long MOD = 1e9 + 7;
long long save[N];

// memoized recursion
long long fibo(long long n) {
    if (n == 0 || n == 1) return 1;
    if (save[n] != -1) return save[n];
    return save[n] = fibo(n - 1) + fibo(n - 2);
}

int32_t main() {
    memset(save, -1, sizeof(save));

    int n;
    cin >> n;
    cout << fibo(n) << endl;

    // iterative version
    // vector<long long> a(n + 1);
    // a[0] = a[1] = 1;
    // for (int i = 2; i <= n; i++) a[i] = a[i - 1] + a[i - 2];

    // iterative version, under a mod
    // vector<long long> fib(n + 1, 0);
    // fib[1] = 1;
    // for (int i = 2; i <= n; i++) fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;

    return 0;
}
