#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007

using namespace std;

int dp[1100][1100];

int nCr(int n, int r) {
    if(r == 0 || n == r) {
        return 1;
    }

    if(r == 1 || n == r + 1) {
        return n;
    }

    if(n < r) {
        return 0;
    }

    int ans = 0;
    if(dp[n-1][r] == 0) {
        dp[n-1][r] = nCr(n-1,r);
    }
    if(dp[n-1][r-1] == 0) {
        dp[n-1][r-1] = nCr(n-1,r-1);
    }

    ans = (dp[n-1][r] + dp[n-1][r-1]) % MOD;

    return ans;
}

int32_t main () {
    int n, m;
    cin >> n >> m;

    cout << nCr(n+2*m-1, 2*m) << '\n';
    return 0;
}