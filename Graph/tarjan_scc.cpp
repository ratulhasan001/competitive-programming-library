#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> g[N];
vector<int> disc(N, -1), low(N, -1);
vector<bool> inStack(N, false);
stack<int> st;
int timer_ = 0;
vector<vector<int>> sccs;

void tarjan(int u) {
    disc[u] = low[u] = ++timer_;
    st.push(u);
    inStack[u] = true;
    for (int v : g[u]) {
        if (disc[v] == -1) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (inStack[v]) {
            low[u] = min(low[u], disc[v]);
        }
    }
    if (low[u] == disc[u]) {
        vector<int> scc;
        while (true) {
            int node = st.top();
            st.pop();
            inStack[node] = false;
            scc.push_back(node);
            if (node == u) break;
        }
        sccs.push_back(scc);
    }
}

int32_t main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v); // directed edge
    }
    for (int i = 0; i < n; i++) {
        if (disc[i] == -1) tarjan(i);
    }
    for (auto &scc : sccs) {
        for (int node : scc) cout << node << " ";
        cout << "\n";
    }
    return 0;
}
