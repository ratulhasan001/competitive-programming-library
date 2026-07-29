#include <bits/stdc++.h>
using namespace std;

// O(n log n) LIS length + reconstruction
int32_t main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<int> tails;       // tails[i] = smallest possible tail value of an increasing subsequence of length i+1
    vector<int> tailIdx;     // index in `a` of that tail value
    vector<int> prev(n, -1); // predecessor index, for reconstruction

    for (int i = 0; i < n; i++) {
        // strictly increasing -> lower_bound; non-decreasing (allow equal) -> upper_bound
        int pos = lower_bound(tails.begin(), tails.end(), a[i]) - tails.begin();
        if (pos == (int)tails.size()) {
            tails.push_back(a[i]);
            tailIdx.push_back(i);
        } else {
            tails[pos] = a[i];
            tailIdx[pos] = i;
        }
        prev[i] = (pos > 0) ? tailIdx[pos - 1] : -1;
    }

    cout << tails.size() << endl;

    vector<int> lis;
    for (int i = tailIdx.back(); i != -1; i = prev[i]) lis.push_back(a[i]);
    reverse(lis.begin(), lis.end());
    for (int x : lis) cout << x << " ";
    cout << endl;
    return 0;
}
