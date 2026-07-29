#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
bitset<N> is_prime;

void sieve() {
    is_prime.set();
    is_prime[1] = 0;
    for (int i = 2; i * i < N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < N; j += i) {
                is_prime[j] = 0;
            }
        }
    }
}

int32_t main() {
    sieve();
    vector<int> prime;
    prime.push_back(2);
    for (int i = 3; i < N; i += 2)
        if (is_prime[i]) prime.push_back(i);
    cout << "Total primes: " << prime.size() << endl;
    return 0;
}
