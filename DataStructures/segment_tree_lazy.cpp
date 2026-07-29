#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// range-sum segment tree with lazy propagation for range-add updates, 1-indexed
vector<ll> v, seg_tree, lazy;

void build(int node, int begin, int end) {
    if (begin == end) {
        seg_tree[node] = v[begin];
        return;
    }
    int mid = (begin + end) / 2;
    build(node * 2, begin, mid);
    build(node * 2 + 1, mid + 1, end);
    seg_tree[node] = seg_tree[node * 2] + seg_tree[node * 2 + 1];
}

void propagate(int node, int begin, int end) {
    if (lazy[node] != 0) {
        seg_tree[node] += (end - begin + 1) * lazy[node];
        if (begin != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void updateRange(int node, int begin, int end, int l, int r, ll val) {
    propagate(node, begin, end);
    if (r < begin || end < l) return;
    if (l <= begin && end <= r) {
        lazy[node] += val;
        propagate(node, begin, end);
        return;
    }
    int mid = (begin + end) / 2;
    updateRange(node * 2, begin, mid, l, r, val);
    updateRange(node * 2 + 1, mid + 1, end, l, r, val);
    seg_tree[node] = seg_tree[node * 2] + seg_tree[node * 2 + 1];
}

ll queryRange(int node, int begin, int end, int l, int r) {
    propagate(node, begin, end);
    if (r < begin || end < l) return 0;
    if (l <= begin && end <= r) return seg_tree[node];
    int mid = (begin + end) / 2;
    return queryRange(node * 2, begin, mid, l, r) + queryRange(node * 2 + 1, mid + 1, end, l, r);
}

int32_t main() {
    int n;
    cin >> n;
    v.assign(n + 1, 0);
    seg_tree.assign(4 * n + 5, 0);
    lazy.assign(4 * n + 5, 0);
    for (int i = 1; i <= n; i++) cin >> v[i];
    build(1, 1, n);

    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            ll val;
            cin >> l >> r >> val;
            updateRange(1, 1, n, l, r, val);
        } else {
            int l, r;
            cin >> l >> r;
            cout << queryRange(1, 1, n, l, r) << "\n";
        }
    }
    return 0;
}
