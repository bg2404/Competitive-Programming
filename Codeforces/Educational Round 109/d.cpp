#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

template <typename T>
ostream &operator<<(ostream &os, vector<T> &v) {
    cout << "[ ";
    for (T e : v) {
        cout << e << ' ';
    }
    cout << ']';
    return os;
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n), f, o;
    f.push_back(-1);
    o.push_back(-1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i]) {
            o.push_back(i);
        } else {
            f.push_back(i);
        }
    }
    n = o.size();
    int m = f.size();
    vector<vector<int> > dp(n, vector<int>(m, 0));
    for (int i = 1; i < n; ++i) {
        dp[i][0] = 1000000000;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            dp[i][j] = min(dp[i - 1][j - 1] + abs(o[i] - f[j]), dp[i][j - 1]);
        }
    }
    int ans = dp[n - 1][0];
    for (int j = 1; j < m; ++j) {
        ans = min(ans, dp[n - 1][j]);
    }
    cout << ans << endl;
    return 0;
}