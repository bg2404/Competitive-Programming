//https://codeforces.com/problemset/problem/209/A

#include<bits/stdc++.h>
#define MOD 1000000007
#define int long long

using namespace std;

int32_t main() {
    int n;
    cin >> n;

    int dp[n][2];
    dp[0][0] = 1;
    dp[0][1] = 0;

    for(int i = 1; i < n; ++i) {
        if(i & 1) {
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][0] + dp[i-1][1] + 1;
        } else {
            dp[i][0] = dp[i-1][0] + dp[i-1][1] + 1;
            dp[i][1] = dp[i-1][1];
        }

        dp[i][0] %= MOD;
        dp[i][1] %= MOD;        
    }

    cout << (dp[n-1][0] + dp[n-1][1]) % MOD << '\n';
    return 0;
}