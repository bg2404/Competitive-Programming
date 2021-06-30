#include <bits/stdc++.h>

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

int main() {
    int n;
    cin >> n;
    vector<double> p(n + 1), P(n + 1, 1), R(n + 1, 0), Q(n + 1, 0), dp(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    for (int i = 1; i <= n; ++i) {
        P[i] = P[i - 1] * p[i];
    }
    // cout << P << endl;

    for (int i = 1; i <= n; ++i) {
        R[i] = R[i - 1] * p[i] + (1 - p[i]);
    }
    // cout << R << endl;

    for (int i = 1; i < n; ++i) {
        Q[i + 1] = Q[i] * p[i] + 2 * p[i] * R[i - 1] + (1 - p[i]);
    }
    // cout << Q << endl;

    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1] + p[i]*(P[i-1] * (2 * i - 1) + Q[i]);
    }
    // cout << dp << endl;

    cout << setprecision(9) << dp[n] << endl;

    return 0;
}