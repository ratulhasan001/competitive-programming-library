#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
int parent_[N], depth_[N], heavy[N], head_[N], pos_[N];
int cur_pos, sz[N];

void dfs_sz(int v, int p = -1) { // call first
    sz[v] = 1;
    parent_[v] = p;
    depth_[v] = (p == -1 ? 0 : depth_[p] + 1);
    int max_sz = 0;
    heavy[v] = -1;
    for (int c : adj[v]) {
        if (c != p) {
            dfs_sz(c, v);
            sz[v] += sz[c];
            if (sz[c] > max_sz) { max_sz = sz[c]; heavy[v] = c; }
        }
    }
}

void dfs_hld(int v, int h) { // call second: dfs_hld(root, root)
    head_[v] = h;
    pos_[v] = ++cur_pos;
    if (heavy[v] != -1) dfs_hld(heavy[v], h);
    for (int c : adj[v]) {
        if (c != parent_[v] && c != heavy[v]) dfs_hld(c, c);
    }
}

// query path u to v (plug in a segment-tree range query where marked below)
int query(int a, int b) {
    int res = 0;
    for (; head_[a] != head_[b]; b = parent_[head_[b]]) {
        if (depth_[head_[a]] > depth_[head_[b]]) swap(a, b);
        // res = max(res, seg_query(pos_[head_[b]], pos_[b]));
    }
    if (depth_[a] > depth_[b]) swap(a, b);
    // res = max(res, seg_query(pos_[a], pos_[b]));
    return res;
}

int32_t main() {
    int n, root = 1;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs_sz(root);
    cur_pos = 0;
    dfs_hld(root, root);
    return 0;
}
