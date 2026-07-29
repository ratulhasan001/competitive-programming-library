#include <bits/stdc++.h>
using namespace std;

void placeQueens(int i, vector<int> &cols, vector<int> &leftDiagonal, vector<int> &rightDiagonal,
                  vector<int> &cur, vector<vector<int>> &result) {
    int n = cols.size();
    if (i == n) {
        result.push_back(cur);
        return;
    }
    for (int j = 0; j < n; j++) {
        if (cols[j] || rightDiagonal[i + j] || leftDiagonal[i - j + n - 1]) continue;
        cols[j] = 1;
        rightDiagonal[i + j] = 1;
        leftDiagonal[i - j + n - 1] = 1;
        cur.push_back(j + 1);

        placeQueens(i + 1, cols, leftDiagonal, rightDiagonal, cur, result);

        cur.pop_back();
        cols[j] = 0;
        rightDiagonal[i + j] = 0;
        leftDiagonal[i - j + n - 1] = 0;
    }
}

vector<vector<int>> nQueen(int n) {
    vector<int> cols(n, 0);
    vector<int> leftDiagonal(n * 2, 0);
    vector<int> rightDiagonal(n * 2, 0);
    vector<int> cur;
    vector<vector<int>> result;
    placeQueens(0, cols, leftDiagonal, rightDiagonal, cur, result);
    return result;
}

int32_t main() {
    int n;
    cin >> n;
    vector<vector<int>> ans = nQueen(n);
    cout << ans.size() << " solutions\n";
    for (auto &sol : ans) {
        for (int c : sol) cout << c << " ";
        cout << "\n";
    }
    return 0;
}
