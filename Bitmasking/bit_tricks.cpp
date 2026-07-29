#include <bits/stdc++.h>
using namespace std;

// a^a=0, a^0=a, a^b=0 => a=b, a^a^a=a
// n | (1<<k)              -> turn k-th bit on
// n & ((1<<30)-1-(1<<k))  -> turn k-th bit off
// n & ((1<<k)-1)          -> keep only the last k bits

bool checkBit(int n, int k) { return (n >> k) & 1; }
int setBit(int n, int k) { return n | (1 << k); }
int clearBit(int n, int k) { return n & ~(1 << k); }
int toggleBit(int n, int k) { return n ^ (1 << k); }

int countBitsll(long long n) { return __builtin_popcountll(n); }
int lowestBitPos(int n) { return __builtin_ctz(n); }        // count trailing zeros
int highestBitPos(int n) { return 31 - __builtin_clz(n); }  // index of MSB (0-indexed)

void invertBits(int num) {
    int numOfBits = (int)log2(num) + 1;
    cout << (((1 << numOfBits) - 1) ^ num);
}

int lowbit(int n) { return n & -n; }
int removeLowestBit(int n) { return n & (n - 1); }

#define bitcount(x) __builtin_popcountll(x)
#define lsb(x) __builtin_ctzll(x)
#define msb(x) (63 - __builtin_clzll(x))

int32_t main() {
    int n, k;
    cin >> n >> k;
    cout << "bit " << k << " set: " << checkBit(n, k) << endl;
    cout << "popcount: " << bitcount(n) << endl;
    return 0;
}
