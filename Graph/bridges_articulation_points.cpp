#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> g[N];
int n, m;
vector<int> tin(N), low(N);
vector<bool> visited(N, false), isArt(N, false);
vector<pair<int, int>> bridges;
int timer_ = 0;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer_++;
    int children = 0;
    for (int to : g[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]) bridges.push_back({v, to});
            if (low[to] >= tin[v] && p != -1) isArt[v] = true;
            children++;
        }
    }
    if (p == -1 && children > 1) isArt[v] = true;
}

int32_t main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) dfs(i);
    }
    for (auto &b : bridges) cout << b.first << " - " << b.second << "\n";
    for (int i = 1; i <= n; i++)
        if (isArt[i]) cout << i << " ";
    cout << endl;
    return 0;
}
