#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool removed[N];
int sub_sz[N];

void calc_sz(int u, int p) {
    sub_sz[u] = 1;
    for (int v : adj[u]) {
        if (v != p && !removed[v]) {
            calc_sz(v, u);
            sub_sz[u] += sub_sz[v];
        }
    }
}

int find_centroid(int u, int p, int n) {
    for (int v : adj[u]) {
        if (v != p && !removed[v] && sub_sz[v] > n / 2)
            return find_centroid(v, u, n);
    }
    return u;
}

void decompose(int u, int p = -1) {
    calc_sz(u, -1);
    int centroid = find_centroid(u, -1, sub_sz[u]);

    // --- solve the problem for paths passing through `centroid` here ---
    // e.g. collect distances from centroid to all nodes in its subtree

    removed[centroid] = true;
    // parent_centroid[centroid] = p; // if building the centroid tree
    for (int v : adj[centroid]) {
        if (!removed[v]) decompose(v, centroid);
    }
}

int32_t main() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    decompose(1);
    return 0;
}
