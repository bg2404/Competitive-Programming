#include<bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int k, n;
        cin >> k >> n;
        vector<int> a(n+1,0);
        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        int dp[n+1][k+1], max_so_far;
        memset(dp, 0 , sizeof(dp));
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= k; ++j) {
                max_so_far = -1000000;
                for(int k = 1; k < i; ++k) {
                    max_so_far = max(max_so_far, dp[k][j-1] + a[i] - a[k]);
                }
                dp[i][j] = max(dp[i-1][j], max_so_far);
                // cout << dp[i-1][j] << ' ' << max_so_far << ' ';
            }
        }
        cout << dp[n][k] << '\n';
    }
    return 0;
}