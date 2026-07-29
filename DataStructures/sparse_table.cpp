#include <bits/stdc++.h>
using namespace std;

// static range-maximum query in O(1) after an O(n log n) build
template <typename T>
struct SparseTable {
    vector<vector<T>> st;
    vector<int> lg;
    int n;
    int max_j;

    SparseTable(vector<T> &a) {
        n = a.size();
        lg.resize(n + 1);
        lg[1] = 0;
        for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;
        max_j = lg[n];
        st.assign(n, vector<T>(max_j + 1));
        for (int i = 0; i < n; i++) st[i][0] = a[i];
        for (int j = 1; j <= max_j; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    T query(int l, int r) { // inclusive [l, r], 0-indexed
        int j = lg[r - l + 1];
        return max(st[l][j], st[r - (1 << j) + 1][j]);
    }
};

int32_t main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    SparseTable<int> st(a);

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << st.query(l, r) << "\n";
    }
    return 0;
}
