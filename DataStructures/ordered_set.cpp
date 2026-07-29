#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int32_t main() {
    ordered_set<int> o_set;
    int n;
    cin >> n;
    while (n--) {
        int value;
        cin >> value;
        o_set.insert(value);
    }
    // o_set.erase(value);
    cout << *(o_set.find_by_order(1)) << endl; // 2nd smallest value
    cout << o_set.order_of_key(4) << endl;     // count of elements strictly less than 4
    return 0;
}
