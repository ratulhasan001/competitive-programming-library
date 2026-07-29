#include <bits/stdc++.h>
using namespace std;

// 2-SAT via implication graph + Kosaraju's SCC (two-pass DFS).
// variable i (0-indexed): node 2*i means "x_i = true", node 2*i+1 means "x_i = false".
struct TwoSat {
    int n;
    vector<vector<int>> g, rg;
    vector<int> comp, order_, val;
    vector<bool> visited;

    TwoSat(int n_) : n(n_), g(2 * n_), rg(2 * n_), comp(2 * n_, -1), val(n_) {}

    void addImplication(int u, int v) {
        g[u].push_back(v);
        rg[v].push_back(u);
    }

    // adds the clause (x_a == valA) OR (x_b == valB)
    void addClause(int a, bool valA, int b, bool valB) {
        int u = 2 * a + (valA ? 0 : 1);
        int v = 2 * b + (valB ? 0 : 1);
        addImplication(u ^ 1, v);
        addImplication(v ^ 1, u);
    }

    void dfs1(int u) {
        visited[u] = true;
        for (int v : g[u]) if (!visited[v]) dfs1(v);
        order_.push_back(u);
    }

    void dfs2(int u, int c) {
        comp[u] = c;
        for (int v : rg[u]) if (comp[v] == -1) dfs2(v, c);
    }

    bool solve() {
        visited.assign(2 * n, false);
        for (int i = 0; i < 2 * n; i++) if (!visited[i]) dfs1(i);

        int c = 0;
        for (int i = 2 * n - 1; i >= 0; i--) {
            int u = order_[i];
            if (comp[u] == -1) dfs2(u, c++);
        }

        for (int i = 0; i < n; i++) {
            if (comp[2 * i] == comp[2 * i + 1]) return false; // unsatisfiable
            val[i] = comp[2 * i] > comp[2 * i + 1];
        }
        return true;
    }
};

int32_t main() {
    int n, m;
    cin >> n >> m; // n variables, m clauses
    TwoSat ts(n);
    while (m--) {
        int a, b;
        bool va, vb;
        cin >> a >> va >> b >> vb; // clause: (var a == va) OR (var b == vb), a/b 0-indexed
        ts.addClause(a, va, b, vb);
    }
    if (!ts.solve()) {
        cout << "UNSATISFIABLE\n";
    } else {
        for (int i = 0; i < n; i++) cout << ts.val[i] << " ";
        cout << endl;
    }
    return 0;
}
