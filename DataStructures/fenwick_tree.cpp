#include <bits/stdc++.h>
using namespace std;

// Fenwick / Binary Indexed Tree, 1-indexed, supports range update + range query
template <class T>
struct BIT {
    int n;
    vector<T> t;
    BIT() {}
    BIT(int _n) {
        n = _n;
        t.assign(n + 1, 0);
    }
    T query(int i) {
        T ans = 0;
        for (; i >= 1; i -= (i & -i)) ans += t[i];
        return ans;
    }
    void upd(int i, T val) {
        if (i <= 0) return;
        for (; i <= n; i += (i & -i)) t[i] += val;
    }
    void upd(int l, int r, T val) { // range update
        upd(l, val);
        upd(r + 1, -val);
    }
    T query(int l, int r) { // range query
        return query(r) - query(l - 1);
    }
};

int32_t main() {
    int n;
    cin >> n;
    BIT<long long> bit(n);
    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        bit.upd(i, x);
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << bit.query(l, r) << "\n";
    }
    return 0;
}
