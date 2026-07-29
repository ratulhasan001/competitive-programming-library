#include <bits/stdc++.h>
using namespace std;

// O(n log^2 n) suffix array construction + O(n) Kasai's algorithm for the LCP array
vector<int> buildSuffixArray(string s) {
    s += '\1'; // sentinel smaller than every character
    int n = s.size();
    vector<int> sa(n), rank_(n);
    for (int i = 0; i < n; i++) { sa[i] = i; rank_[i] = s[i]; }

    for (int k = 1; k < n; k <<= 1) {
        auto cmp = [&](int a, int b) {
            if (rank_[a] != rank_[b]) return rank_[a] < rank_[b];
            int ra = a + k < n ? rank_[a + k] : -1;
            int rb = b + k < n ? rank_[b + k] : -1;
            return ra < rb;
        };
        sort(sa.begin(), sa.end(), cmp);

        vector<int> tmp(n);
        tmp[sa[0]] = 0;
        for (int i = 1; i < n; i++)
            tmp[sa[i]] = tmp[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
        rank_ = tmp;
        if (rank_[sa[n - 1]] == n - 1) break;
    }
    sa.erase(sa.begin()); // drop the sentinel's own suffix
    return sa;
}

// lcp[i] = length of the longest common prefix between suffix sa[i] and suffix sa[i-1]
vector<int> kasaiLCP(string &s, vector<int> &sa) {
    int n = s.size();
    vector<int> rank_(n), lcp(n, 0);
    for (int i = 0; i < n; i++) rank_[sa[i]] = i;

    int h = 0;
    for (int i = 0; i < n; i++) {
        if (rank_[i] > 0) {
            int j = sa[rank_[i] - 1];
            while (i + h < n && j + h < n && s[i + h] == s[j + h]) h++;
            lcp[rank_[i]] = h;
            if (h > 0) h--;
        } else {
            h = 0;
        }
    }
    return lcp;
}

int32_t main() {
    string s;
    cin >> s;
    vector<int> sa = buildSuffixArray(s);
    vector<int> lcp = kasaiLCP(s, sa);

    for (int x : sa) cout << x << " ";
    cout << "\n";
    for (int x : lcp) cout << x << " ";
    cout << endl;
    return 0;
}
