#include <bits/stdc++.h>
using namespace std;

// checks whether a graph is bipartite via 2-coloring (BFS)
const int N = 1e5 + 5;
vector<int> g[N];
int color_[N]; // -1 = uncolored, 0/1 = the two colors

bool isBipartite(int n) {
    fill(color_ + 1, color_ + n + 1, -1);
    for (int start = 1; start <= n; start++) {
        if (color_[start] != -1) continue;
        color_[start] = 0;
        queue<int> q;
        q.push(start);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : g[u]) {
                if (color_[v] == -1) {
                    color_[v] = color_[u] ^ 1;
                    q.push(v);
                } else if (color_[v] == color_[u]) {
                    return false;
                }
            }
        }
    }
    return true;
}

int32_t main() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout << (isBipartite(n) ? "Bipartite" : "Not Bipartite") << endl;
    return 0;
}
