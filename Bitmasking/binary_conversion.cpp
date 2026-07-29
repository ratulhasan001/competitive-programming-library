#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

ull binaryToDecimal(const string &s) {
    ull ans = 0;
    for (char c : s) ans = (ans << 1) + (c - '0');
    return ans;
}

// prints the binary representation of a (possibly negative) decimal,
// followed by its two's complement bit pattern
void dec_to_bin_pos_neg() {
    ll decimal;
    cin >> decimal;
    ull x = (decimal < 0) ? (ull)(-decimal) : (ull)decimal;
    string s;
    if (x == 0) s = "0";
    else {
        while (x) {
            s += (x & 1ULL) ? '1' : '0';
            x >>= 1;
        }
        reverse(s.begin(), s.end());
    }
    cout << s << '\n';

    int w = (int)s.size() + 1;
    string sp = string(w - (int)s.size(), '0') + s;
    for (char &c : sp) c = (c == '1') ? '0' : '1';

    string neg;
    neg.reserve(sp.size());
    int carry = 1;
    for (int i = (int)sp.size() - 1; i >= 0; --i) {
        if (sp[i] == '0') {
            if (carry) { neg += '1'; carry = 0; }
            else neg += '0';
        } else {
            if (carry) { neg += '0'; carry = 1; }
            else neg += '1';
        }
    }
    reverse(neg.begin(), neg.end());
    cout << neg << '\n';
}

int32_t main() {
    dec_to_bin_pos_neg();
    return 0;
}
