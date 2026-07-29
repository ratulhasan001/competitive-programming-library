#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> g[N];
vector<bool> visited;
vector<int> ans;

void dfs(int source) {
    visited[source] = true;
    for (int child : g[source]) {
        if (visited[child]) continue;
        dfs(child);
    }
    ans.push_back(source);
}

void topological_sort(int n) {
    visited.assign(n + 1, false);
    ans.clear();
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) dfs(i);
    }
    reverse(ans.begin(), ans.end());
}

int32_t main() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v); // directed edge
    }
    topological_sort(n);
    for (int x : ans) cout << x << " ";
    cout << endl;
    return 0;
}
