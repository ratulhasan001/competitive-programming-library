#include <bits/stdc++.h>
using namespace std;

// 0-1 BFS: shortest path when every edge weight is either 0 or 1
const int N = 1e5 + 5;
const int INF = 1e9;
vector<pair<int, int>> g[N]; // {neighbor, weight}
int dist_[N];

void bfs01(int start, int n) {
    fill(dist_, dist_ + n + 1, INF);
    deque<int> dq;
    dist_[start] = 0;
    dq.push_back(start);
    while (!dq.empty()) {
        int u = dq.front();
        dq.pop_front();
        for (auto [v, w] : g[u]) {
            if (dist_[u] + w < dist_[v]) {
                dist_[v] = dist_[u] + w;
                if (w == 0) dq.push_front(v);
                else dq.push_back(v);
            }
        }
    }
}

int32_t main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    int source;
    cin >> source;
    bfs01(source, n);
    for (int i = 1; i <= n; i++) cout << dist_[i] << " ";
    cout << endl;
    return 0;
}
