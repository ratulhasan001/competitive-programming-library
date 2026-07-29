#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    int n, target;
    cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    cin >> target;

    int cnt = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        int sum = 0;
        for (int i = 0; i < n; i++)
            if (mask & (1 << i)) sum += arr[i];
        if (sum == target) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
