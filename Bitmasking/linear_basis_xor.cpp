#include <bits/stdc++.h>
using namespace std;

// linear basis over GF(2) -- used to find the maximum XOR subset value
const int BITS = 60;
long long basis[BITS];
int sz = 0;

void insertVector(long long mask) {
    for (int i = BITS - 1; i >= 0; i--) {
        if (!(mask & (1LL << i))) continue;
        if (!basis[i]) {
            basis[i] = mask;
            sz++;
            return;
        }
        mask ^= basis[i];
    }
}

long long maxXor() {
    long long ans = 0;
    for (int i = BITS - 1; i >= 0; i--) {
        if (!basis[i]) continue;
        if ((ans ^ basis[i]) > ans) ans ^= basis[i];
    }
    return ans;
}

int32_t main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        insertVector(x);
    }
    cout << maxXor() << endl;
    return 0;
}
