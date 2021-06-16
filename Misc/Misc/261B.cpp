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

double prob(long long cnt, long long n) {
    double ans = 1;
    long long m = n;
    for (long long i = cnt; i > 0; --i) {
        ans *= (double)i / (n--);
    }
    for (long long i = m - cnt - 1; i > 0; --i) {
        ans *= (double)i / (n--);
    }
    return ans;
}

signed main() {
    long long n, p;
    cin >> n;
    vector<long long> a(n);
    long long sum = 0;
    for (long long i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    cin >> p;
    if (sum <= p) {
        cout << n << endl;
        return 0;
    }
    long long last = 0;
    double ans = 0;
    while (last < n) {
        swap(a[0], a[last++]);
        vector<vector<vector<long long> > > dp(n, vector<vector<long long> >(n, vector<long long>(p + 1, 0)));
        dp[0][0][0] = 1;
        long long i;
        for (i = 1; i < n; ++i) {
            for (long long j = 0; j <= i; ++j) {
                for (long long k = 0; k <= p; ++k) {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (j > 0 && k >= a[i]) {
                        dp[i][j][k] += dp[i - 1][j - 1][k - a[i]];
                    }
                }
            }
        }
        i = n - 1;
        for (long long j = 1; j < n; ++j) {
            for (long long k = max(0LL, p - a[0] + 1); k <= p; ++k) {
                ans += j * dp[i][j][k] * prob(j, n);
            }
        }
    }
    cout << setprecision(9) << ans << endl;
    return 0;
}
