#include <bits/stdc++.h>
using namespace std;

// standard DSU with path compression + union by rank, O(a(n)) amortized per op
struct DSU {
    vector<int> parent, rnk, sz;
    DSU(int n) {
        parent.resize(n + 1);
        rnk.assign(n + 1, 0);
        sz.assign(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (rnk[a] < rnk[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        if (rnk[a] == rnk[b]) rnk[a]++;
        return true;
    }
    bool connected(int a, int b) { return find(a) == find(b); }
    int size(int x) { return sz[find(x)]; }
};

int32_t main() {
    int n, e;
    cin >> n >> e;
    DSU dsu(n);
    while (e--) {
        int a, b;
        cin >> a >> b;
        dsu.unite(a, b);
    }
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << (dsu.connected(a, b) ? "YES" : "NO") << "\n";
    }
    return 0;
}
