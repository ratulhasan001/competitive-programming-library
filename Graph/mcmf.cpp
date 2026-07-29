#include <bits/stdc++.h>
using namespace std;

// Min-Cost Max-Flow via successive shortest augmenting paths (SPFA), O(V*E*flow)
const int N = 505;
const long long INF = 1e18;

struct MCMF {
    struct Edge { int to, rev; long long cap, cost; };
    vector<Edge> g[N];
    int n;

    void init(int n_) {
        n = n_;
        for (int i = 0; i < n; i++) g[i].clear();
    }

    void add_edge(int u, int v, long long cap, long long cost) {
        g[u].push_back({v, (int)g[v].size(), cap, cost});
        g[v].push_back({u, (int)g[u].size() - 1, 0, -cost});
    }

    pair<long long, long long> minCostMaxFlow(int s, int t) {
        long long flow = 0, cost = 0;
        while (true) {
            vector<long long> dist(n, INF);
            vector<int> inQueue(n, 0), prevEdge(n, -1), prevNode(n, -1);
            dist[s] = 0;
            queue<int> q;
            q.push(s);
            inQueue[s] = true;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                inQueue[u] = false;
                for (int i = 0; i < (int)g[u].size(); i++) {
                    auto &e = g[u][i];
                    if (e.cap > 0 && dist[u] + e.cost < dist[e.to]) {
                        dist[e.to] = dist[u] + e.cost;
                        prevNode[e.to] = u;
                        prevEdge[e.to] = i;
                        if (!inQueue[e.to]) {
                            q.push(e.to);
                            inQueue[e.to] = true;
                        }
                    }
                }
            }
            if (dist[t] == INF) break; // no more augmenting paths

            long long pushFlow = INF;
            for (int v = t; v != s; v = prevNode[v]) {
                pushFlow = min(pushFlow, g[prevNode[v]][prevEdge[v]].cap);
            }
            for (int v = t; v != s; v = prevNode[v]) {
                auto &e = g[prevNode[v]][prevEdge[v]];
                e.cap -= pushFlow;
                g[v][e.rev].cap += pushFlow;
            }
            flow += pushFlow;
            cost += pushFlow * dist[t];
        }
        return {flow, cost};
    }
};

int32_t main() {
    int n, m;
    cin >> n >> m;
    MCMF mcmf;
    mcmf.init(n);
    while (m--) {
        int u, v;
        long long cap, cost;
        cin >> u >> v >> cap >> cost;
        mcmf.add_edge(u, v, cap, cost);
    }
    int s, t;
    cin >> s >> t;
    auto [flow, cost] = mcmf.minCostMaxFlow(s, t);
    cout << flow << " " << cost << endl;
    return 0;
}
