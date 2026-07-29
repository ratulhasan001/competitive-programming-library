#include <bits/stdc++.h>
using namespace std;

// KMP failure function: pi[i] = length of the longest proper prefix of s[0..i]
// that is also a suffix of s[0..i]
vector<int> prefixFunction(string &s) {
    int n = s.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

// find all occurrences of `pattern` in `text`
vector<int> kmpSearch(string &text, string &pattern) {
    string s = pattern + '#' + text;
    vector<int> pi = prefixFunction(s);
    vector<int> pos;
    int m = pattern.size();
    for (int i = m + 1; i < (int)s.size(); i++) {
        if (pi[i] == m) pos.push_back(i - 2 * m);
    }
    return pos;
}

int32_t main() {
    string text, pattern;
    cin >> text >> pattern;
    vector<int> pos = kmpSearch(text, pattern);
    for (int p : pos) cout << p << " ";
    cout << endl;
    return 0;
}
