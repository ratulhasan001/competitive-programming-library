#include <bits/stdc++.h>
using namespace std;

vector<int> zFunction(string &s) {
    int n = s.length();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r) {
            int k = i - l;
            z[i] = min(r - i + 1, z[k]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] - 1 > r) { l = i; r = i + z[i] - 1; }
    }
    return z;
}

// find all occurrences of `pattern` in `text` using the z-function
vector<int> search(string &text, string &pattern) {
    string s = pattern + '$' + text;
    vector<int> z = zFunction(s);
    vector<int> pos;
    int m = pattern.size();
    for (int i = m + 1; i < (int)z.size(); i++) {
        if (z[i] == m) pos.push_back(i - m - 1);
    }
    return pos;
}

int32_t main() {
    string text, pattern;
    cin >> text >> pattern;
    vector<int> pos = search(text, pattern);
    for (int p : pos) cout << p << " ";
    cout << endl;
    return 0;
}
