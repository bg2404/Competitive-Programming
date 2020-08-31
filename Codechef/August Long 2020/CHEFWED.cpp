#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > cnt, dp, start;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> f(n+1);
        cnt.assign(101, vector<int> (n+1, 0));
        dp.assign(n+1, vector<int>(n+1, 0));
        for(int i = 1; i <= n; ++i) {
            cin >> f[i];
            ++cnt[f[i]][i];
        }
        for(int i = 1; i < 101; ++i) {
            for(int j = 1; j <= n; ++j) {
                cnt[i][j] += cnt[i][j-1];
            }
        }
        for(int i = 1; i <= n; ++i) {
            dp[i][i] = k;
            for(int j = i+1; j <= n; ++j) {
                dp[i][j] = dp[i][j-1];
                int freq = cnt[f[j]][j] - cnt[f[j]][i-1];
                if(freq > 2) {
                    ++dp[i][j];
                } else if(freq == 2) {
                    dp[i][j] += 2;
                }
            }
        }
        vector<int> ans(n+1, 0);
        ans[1] = dp[1][1];
        for(int i = 2; i <= n; ++i) {
            ans[i] = dp[1][i];
            for(int j = 1; j < i; ++j) {
                ans[i] = min(ans[i], ans[j] + dp[j+1][i]);
            }
        }
        cout << ans[n] << '\n';
    }
    return 0;
}