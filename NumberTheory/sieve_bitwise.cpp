#include <bits/stdc++.h>
using namespace std;

// bitwise sieve: packs 32 numbers into each int of `status`
bool Check(int N, int pos) { return (bool)(N & (1 << pos)); }
int Set(int N, int pos) { return N = N | (1 << pos); }

const int mx = 100000000;
int N = mx;
int status_[(mx / 32) + 2];
vector<int> primes;

void sieve() {
    int i, j, sqrtN;
    sqrtN = int(sqrt(N));
    for (i = 3; i <= sqrtN; i += 2) {
        if (Check(status_[i >> 5], i & 31) == 0) {
            for (j = i * i; j <= N; j += (i << 1)) {
                status_[j >> 5] = Set(status_[j >> 5], j & 31);
            }
        }
    }
    primes.push_back(2);
    for (i = 3; i <= N; i += 2) {
        if (Check(status_[i >> 5], i & 31) == 0) {
            primes.push_back(i);
        }
    }
}

int32_t main() {
    sieve();
    cout << "Total primes up to " << N << ": " << primes.size() << endl;
    return 0;
}
