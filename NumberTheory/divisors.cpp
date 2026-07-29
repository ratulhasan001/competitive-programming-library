#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    long long n;
    cin >> n;
    vector<long long> divs;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divs.push_back(i);
            if (i != n / i) divs.push_back(n / i);
        }
    }
    sort(divs.begin(), divs.end());
    for (long long d : divs) cout << d << " ";
    cout << endl;
    return 0;
}
