//https://codeforces.com/contest/1324/problem/E

#include<bits/stdc++.h>
#define int long long

using namespace std;

template<typename T>
void printVector(vector<T> v) {
    for(auto u: v) {
        cout << u << ' ';
    }
    cout << '\n';
}

bool isGood(int l, int r, int a) {
    if(a >= l && a <= r) {
        return true;
    }
    return false;
}

int32_t main() {
    int n, h, l, r;
    cin >> n >> h >> l >> r;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int dp[n][h];
    memset(dp, -1, sizeof(dp));
    if(isGood(l, r, a[0])) {
        dp[0][a[0]] = 1;
    } else {
        dp[0][a[0]] = 0;
    }
    if(isGood(l, r, a[0]-1)) {
        dp[0][a[0]-1] = 1;
    } else {
        dp[0][a[0]-1] = 0;
    }

    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < h; ++j) {
            int e = dp[i-1][j];
            if(e < 0) {
                continue;
            }
            int s = (j + a[i]) % h;
            if(isGood(l, r, s)) {
                dp[i][s] = max(dp[i][s], dp[i-1][j] + 1);
            } else {
                dp[i][s] = max(dp[i][s], dp[i-1][j]);
            }
            s = (j + a[i] - 1) % h;
            if(isGood(l, r, s)) {
                dp[i][s] = max(dp[i][s], dp[i-1][j] + 1);
            } else {
                dp[i][s] = max(dp[i][s], dp[i-1][j]);
            }
        }
    }

    // for(int i = 0; i < h; ++i) {
    //     cout << setw(2) << i << ' ';
    // }
    // cout << '\n';
    // for(int i = 0; i < n; ++i) {
    //     for(int j = 0; j < h; ++j) {
    //         cout << setw(2) << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    int ans = 0;
    for(int i = 0; i < h; ++i) {
        ans = max(dp[n-1][i], ans);
    }
    cout << ans << '\n';
    return 0;
}