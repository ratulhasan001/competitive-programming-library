#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> g[N];
int indegree[N];

vector<int> kahn_toposort(int n) {
    queue<int> q;
    vector<int> topo;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for (int v : g[u]) {
            indegree[v]--;
            if (indegree[v] == 0) q.push(v);
        }
    }
    if ((int)topo.size() != n) {
        cout << "Cycle!\n";
        return {};
    }
    return topo;
}

int32_t main() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        indegree[v]++;
    }
    vector<int> topo = kahn_toposort(n);
    for (int x : topo) cout << x << " ";
    cout << endl;
    return 0;
}
