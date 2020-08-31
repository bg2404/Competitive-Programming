#include<bits/stdc++.h>

using namespace std;

vector<int> r, g, b;
int dp[201][201][201];

void main2() {
    int R, G, B;
    cin >> R >> G >> B;
    r.resize(R);
    g.resize(G);
    b.resize(B);
    for(int &i: r) {
        cin >> i;
    }
    for(int &i: g) {
        cin >> i;
    }
    for(int &i: b) {
        cin >> i;
    }
    sort(r.begin(), r.end());
    sort(g.begin(), g.end());
    sort(b.begin(), b.end());
    memset(dp, 0, sizeof(dp));
    int ans = 0;
    for(int i = 0; i <= R; ++i) {
        for(int j = 0; j <= G; ++j) {
            for(int k = 0; k <= B; ++k) {
                if(i == 0) {
                    if(j != 0 && k != 0) {
                        dp[i][j][k] = dp[i][j-1][k-1] + g[j-1]*b[k-1];
                    }
                } else {
                    if(j == 0) {
                        if(k != 0) {
                            dp[i][j][k] = dp[i-1][j][k-1] + r[i-1]*b[k-1];
                        }
                    } else if(k == 0) {
                        dp[i][j][k] = dp[i-1][j-1][k] + r[i-1]*g[j-1];
                    } else {
                        dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k] + r[i-1]*g[j-1]);
                        dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k-1] + g[j-1]*b[k-1]);
                        dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1] + b[k-1]*r[i-1]);
                    }
                }
                // cout << dp[i][j][k] << ' ';;
                ans = max(ans, dp[i][j][k]);
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int t = 1;
    // cin >> t;
    while(t--) {
        main2();
    }
    return 0;
}