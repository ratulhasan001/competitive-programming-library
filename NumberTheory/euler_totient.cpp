#include <bits/stdc++.h>
using namespace std;

vector<int> phi_1_to_n(int n) {
    vector<int> phi(n + 1);
    for (int i = 0; i <= n; i++) phi[i] = i;
    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) { // i is prime
            for (int j = i; j <= n; j += i) phi[j] -= phi[j] / i;
        }
    }
    return phi;
}

int32_t main() {
    int n;
    cin >> n;
    vector<int> phi = phi_1_to_n(n);
    for (int i = 1; i <= n; i++) cout << phi[i] << " ";
    cout << endl;
    return 0;
}
