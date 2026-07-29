#include <bits/stdc++.h>
using namespace std;

// Kuhn's algorithm for maximum bipartite matching, O(V*E)
const int N = 505;
vector<int> g[N]; // g[u] = right-side nodes that left node u connects to
int matchR[N];    // matchR[v] = left node matched to right node v, or -1
bool used[N];

bool tryKuhn(int u) {
    for (int v : g[u]) {
        if (used[v]) continue;
        used[v] = true;
        if (matchR[v] == -1 || tryKuhn(matchR[v])) {
            matchR[v] = u;
            return true;
        }
    }
    return false;
}

int32_t main() {
    int n, m, e; // n = left size, m = right size, e = edges
    cin >> n >> m >> e;
    while (e--) {
        int u, v;
        cin >> u >> v; // 0-indexed: left node u, right node v
        g[u].push_back(v);
    }

    memset(matchR, -1, sizeof(matchR));
    int matching = 0;
    for (int u = 0; u < n; u++) {
        memset(used, false, sizeof(used));
        if (tryKuhn(u)) matching++;
    }

    cout << matching << endl;
    return 0;
}
