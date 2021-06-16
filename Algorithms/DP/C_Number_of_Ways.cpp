//https://codeforces.com/problemset/problem/466/C

#include<bits/stdc++.h>
#define int long long

using namespace std;

int32_t main() {
    int n;
    cin >> n;
    vector<int> a(n), sum(n, 0);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sum[0] = a[0];
    for(int i = 1; i < n; ++i) {
        sum[i] = sum[i-1] + a[i];
    }
    int s = sum[n-1] / 3;

    if(s*3 != sum[n-1]) {
        cout << 0 << '\n';
        return 0;
    }
    
    vector<int> dp(n);
    if(sum[0] == s) {
        dp[0] = 1;
    }
    for(int i = 1; i < n; ++i) {
        if(sum[i] == s) {
            dp[i] = dp[i-1]+1;
        } else {
            dp[i] = dp[i-1];
        }
    }
    s *= 2;
    int ans = 0;
    for(int i = 1; i < n-1; ++i) {
        if(sum[i] == s) {
            ans += dp[i];
            if(dp[i] > dp[i-1]) {
                --ans;
            }
        }
    }

    // cout << s/2 << '\n';
    // for(int i = 0; i < n; ++i) {
    //     cout << sum[i] << ' ';
    // }
    // cout << '\n';
    // for(int i = 0; i < n; ++i) {
    //     cout << dp[i] << ' ';
    // }
    // cout << '\n';

    cout << ans << '\n';

    return 0;
}