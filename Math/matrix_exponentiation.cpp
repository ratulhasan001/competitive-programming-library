#include <bits/stdc++.h>
using namespace std;

const long long MAT_MOD = 1e9 + 7;
const int SZ = 2; // matrix size, e.g. 2x2 for Fibonacci

struct Mat {
    long long m[SZ][SZ];
    Mat() { memset(m, 0, sizeof(m)); }
    void identity() { for (int i = 0; i < SZ; i++) m[i][i] = 1; }
    Mat operator*(const Mat &other) {
        Mat res;
        for (int i = 0; i < SZ; i++)
            for (int k = 0; k < SZ; k++)
                for (int j = 0; j < SZ; j++)
                    res.m[i][j] = (res.m[i][j] + m[i][k] * other.m[k][j]) % MAT_MOD;
        return res;
    }
};

Mat matPow(Mat a, long long b) {
    Mat res;
    res.identity();
    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int32_t main() {
    long long n;
    cin >> n;
    Mat base;
    base.m[0][0] = 1; base.m[0][1] = 1;
    base.m[1][0] = 1; base.m[1][1] = 0;
    Mat result = matPow(base, n);
    cout << result.m[0][1] << endl; // n-th Fibonacci number
    return 0;
}
