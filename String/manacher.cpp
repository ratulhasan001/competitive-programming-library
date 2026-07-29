#include <bits/stdc++.h>
using namespace std;

// d1[i] = radius of the longest odd-length palindrome centered at i
// d2[i] = radius of the longest even-length palindrome centered between i-1 and i
void manacher(string s, vector<int> &d1, vector<int> &d2) {
    int n = s.length();
    d1.assign(n, 0);
    d2.assign(n, 0);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) k++;
        d1[i] = k--;
        if (i + k > r) { l = i - k; r = i + k; }
    }
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) k++;
        d2[i] = k--;
        if (i + k > r) { l = i - k - 1; r = i + k; }
    }
    // usage: max odd length centered at i = 2*d1[i]-1, max even length = 2*d2[i]
}

int32_t main() {
    string s;
    cin >> s;
    vector<int> d1, d2;
    manacher(s, d1, d2);
    int best = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        best = max(best, 2 * d1[i] - 1);
        best = max(best, 2 * d2[i]);
    }
    cout << best << endl;
    return 0;
}
