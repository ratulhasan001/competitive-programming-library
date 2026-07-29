#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int LOG = 17;
vector<int> g[N];
int up[N][LOG + 1];
int depth_[N];

void dfs(int u, int p) {
    up[u][0] = p;
    for (int i = 1; i <= LOG; i++) {
        if (up[u][i - 1] != -1)
            up[u][i] = up[up[u][i - 1]][i - 1];
        else
            up[u][i] = -1;
    }
    for (int v : g[u]) {
        if (v == p) continue;
        depth_[v] = depth_[u] + 1;
        dfs(v, u);
    }
}

int lca(int a, int b) {
    if (depth_[a] < depth_[b]) swap(a, b);
    int diff = depth_[a] - depth_[b];
    for (int i = LOG; i >= 0; i--) {
        if ((diff >> i) & 1) a = up[a][i];
    }
    if (a == b) return a;
    for (int i = LOG; i >= 0; i--) {
        if (up[a][i] != -1 && up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

int32_t main() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    memset(up, -1, sizeof(up));
    depth_[1] = 0;
    dfs(1, -1);
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }
    return 0;
}
