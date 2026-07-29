#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
struct Edge { int v, rev, cap; };
vector<Edge> g[N];
int n, m;
int level_[N], ptr_[N];

void add_edge(int u, int v, int cap) {
    g[u].push_back({v, (int)g[v].size(), cap});
    g[v].push_back({u, (int)g[u].size() - 1, 0});
}

bool bfs(int s, int t) {
    fill(level_, level_ + n + 1, -1);
    queue<int> q;
    level_[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto &e : g[u]) {
            if (e.cap > 0 && level_[e.v] == -1) {
                level_[e.v] = level_[u] + 1;
                q.push(e.v);
            }
        }
    }
    return level_[t] != -1;
}

int dfs(int u, int t, int pushed) {
    if (u == t || pushed == 0) return pushed;
    for (int &cid = ptr_[u]; cid < (int)g[u].size(); cid++) {
        Edge &e = g[u][cid];
        if (e.cap > 0 && level_[e.v] == level_[u] + 1) {
            int tr = dfs(e.v, t, min(pushed, e.cap));
            if (tr == 0) continue;
            e.cap -= tr;
            g[e.v][e.rev].cap += tr;
            return tr;
        }
    }
    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    while (bfs(s, t)) {
        fill(ptr_, ptr_ + n + 1, 0);
        while (int pushed = dfs(s, t, INT_MAX)) flow += pushed;
    }
    return flow;
}

int32_t main() {
    cin >> n >> m;
    while (m--) {
        int u, v, c;
        cin >> u >> v >> c;
        add_edge(u, v, c);
    }
    int s, t;
    cin >> s >> t;
    cout << maxflow(s, t) << "\n";
    return 0;
}
