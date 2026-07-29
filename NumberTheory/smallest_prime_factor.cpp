#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
int spf[MAXN];
vector<int> factor[MAXN];

vector<int> getFactorization(int x) {
    vector<int> ret;
    while (x != 1) {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

void sievefactor() {
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++) spf[i] = i;
    for (int i = 4; i < MAXN; i += 2) spf[i] = 2;
    for (int i = 3; (long long)i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
    for (int i = 1; i < MAXN; i++) factor[i] = getFactorization(i);
}

int32_t main() {
    sievefactor();
    int x;
    cin >> x;
    for (int p : factor[x]) cout << p << " ";
    cout << endl;
    return 0;
}
