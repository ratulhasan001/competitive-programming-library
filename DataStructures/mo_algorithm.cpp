#include <bits/stdc++.h>
using namespace std;

// Mo's algorithm: offline range queries (here: distinct-element count in [l, r])
const int N = 1e5 + 5;
const int MAXV = 1000005;
int arr[N], ans[N];
int freq[MAXV], curr = 0;

void add(int x) {
    freq[x]++;
    if (freq[x] == 1) curr++;
}

void remove_(int x) {
    freq[x]--;
    if (freq[x] == 0) curr--;
}

struct Query {
    int l, r, idx;
    bool operator<(const Query &other) const {
        int block = 320; // ~sqrt(n)
        if (l / block != other.l / block) return l / block < other.l / block;
        return (l / block & 1) ? r > other.r : r < other.r;
    }
};

int32_t main() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--;
        queries[i].r--; // 0-indexed
        queries[i].idx = i;
    }
    sort(queries.begin(), queries.end());

    int L = 0, R = -1;
    for (auto &qr : queries) {
        while (R < qr.r) add(arr[++R]);
        while (R > qr.r) remove_(arr[R--]);
        while (L < qr.l) remove_(arr[L++]);
        while (L > qr.l) add(arr[--L]);
        ans[qr.idx] = curr;
    }

    for (int i = 0; i < q; i++) cout << ans[i] << "\n";
    return 0;
}
