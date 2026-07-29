#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

// single-mod hash of a whole string
struct Hash {
    long long p = 31, m = 1e9 + 9;
    long long hash_val;
    Hash(string const &s) {
        long long hash_so_far = 0;
        long long p_pow = 1;
        for (char c : s) {
            hash_so_far = (hash_so_far + (c - 'a' + 1) * p_pow) % m;
            p_pow = (p_pow * p) % m;
        }
        hash_val = hash_so_far;
    }
    bool operator==(const Hash &other) const { return hash_val == other.hash_val; }
};

// double-mod rolling hash, supports O(1) substring hash queries
struct PolyHash {
    const ull MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;
    const ull P1 = 31, P2 = 37;
    vector<ull> h1, h2, p1, p2;

    PolyHash(string &s) {
        int n = s.size();
        h1.resize(n + 1); h2.resize(n + 1);
        p1.resize(n + 1); p2.resize(n + 1);
        p1[0] = p2[0] = 1;
        for (int i = 0; i < n; i++) {
            p1[i + 1] = (p1[i] * P1) % MOD1;
            p2[i + 1] = (p2[i] * P2) % MOD2;
            h1[i + 1] = (h1[i] * P1 + (s[i] - 'a' + 1)) % MOD1;
            h2[i + 1] = (h2[i] * P2 + (s[i] - 'a' + 1)) % MOD2;
        }
    }

    pair<ull, ull> get(int l, int r) { // 0-indexed [l, r]
        ull res1 = (h1[r + 1] - (h1[l] * p1[r - l + 1]) % MOD1 + MOD1) % MOD1;
        ull res2 = (h2[r + 1] - (h2[l] * p2[r - l + 1]) % MOD2 + MOD2) % MOD2;
        return {res1, res2};
    }
};

int32_t main() {
    string s;
    cin >> s;
    PolyHash ph(s);
    int l, r;
    cin >> l >> r;
    auto [h1, h2] = ph.get(l, r);
    cout << h1 << " " << h2 << endl;
    return 0;
}
