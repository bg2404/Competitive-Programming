#include<bits/stdc++.h>

using namespace std;

void solve2(string &a, string &b) {
    int isPos[4][4] = { {0, 1, 1, 0},
                        {1, 0, 0, 1},
                        {1, 0, 0, 1},
                        {0, 1, 1, 0} };
    int n = a.size();
    int dp[n][4];
    memset(dp, 1000000009, sizeof(dp));
    for(int i = 0; i < 4; ++i) {
        int cur = (a[0] == '1')*2 + (b[0] == '1');
        dp[0][i] = __builtin_popcount(cur ^ i);
    }
    int ans = 1000000009;
    for(int i = 1; i < n; ++i) {
        int cur = (a[i] == '1') * 2 + (b[i] == '1');
        for(int j = 0; j < 4; ++j) {
            for(int k = 0; k < 4; ++k) {
                if(isPos[j][k]) {
                    dp[i][k] = min(dp[i][k], dp[i-1][j] + __builtin_popcount(cur ^ k));
                }
            }
        }
    }

    ans = min(min(dp[n-1][0], dp[n-1][1]), min(dp[n-1][2], dp[n-1][3]));
    cout << ans << '\n';
}

void solve3(string &a, string &b, string &c) {
    
    int isPos[8][8] = { {0, 0, 1, 0, 0, 1, 0, 0},
                        {0, 0, 0, 1, 1, 0, 0, 0},
                        {1, 0, 0, 0, 0, 0, 0, 1},
                        {0, 1, 0, 0, 0, 0, 1, 0},
                        {0, 1, 0, 0, 0, 0, 1, 0},
                        {1, 0, 0, 0, 0, 0, 0, 1},
                        {0, 0, 0, 1, 1, 0, 0, 0},
                        {0, 0, 1, 0, 0, 1, 0, 0} };
    int n = a.size();
    int dp[n][8];
    memset(dp, 1000000009, sizeof(dp));
    for(int i = 0; i < 8; ++i) {
        int cur = (a[0] == '1')*4 + (b[0] == '1')*2 + (c[0] == '1');
        dp[0][i] = __builtin_popcount(cur ^ i);
        // cout << dp[0][i] << ' ';
    }
    // cout << '\n';
    int ans = 1000000009;
    for(int i = 1; i < n; ++i) {
        int cur = (a[i] == '1')*4 + (b[i] == '1')*2 + (c[i] == '1');
        for(int k = 0; k < 8; ++k) {
            for(int j = 0; j < 8; ++j) {
                if(isPos[j][k]) {
                    dp[i][k] = min(dp[i][k], dp[i-1][j] + __builtin_popcount(cur ^ k));
                }
            }
            // cout << dp[i][k] << ' ';
        }
        // cout << '\n';
    }

    ans = min(min(min(dp[n-1][0], dp[n-1][1]), min(dp[n-1][2], dp[n-1][3])), min(min(dp[n-1][4], dp[n-1][5]), min(dp[n-1][6], dp[n-1][7])));
    cout << ans << '\n';
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> matrix(n);
    for(auto &r: matrix) {
        cin >> r;
    }
    if(n > 3 && m > 3) {
        cout << -1 << '\n';
        return;
    }
    if(n == 1 || m == 1) {
        cout << 0 << '\n';
        return;
    }
    if(n == 2 || m == 2) {
        string a, b;
        if(n == 2) {
            a = matrix[0];
            b = matrix[1];
        } else {
            a = ""; b = "";
            for(int i = 0; i < n; ++i) {
                a.push_back(matrix[i][0]);
                b.push_back(matrix[i][1]);
            }
        }
        solve2(a, b);
    } else {
        string a, b, c;
        if(n == 3) {
            a = matrix[0];
            b = matrix[1];
            c = matrix[2];
        } else {
            a = ""; b = ""; c = "";
            for(int i = 0; i < n; ++i) {
                a.push_back(matrix[i][0]);
                b.push_back(matrix[i][1]);
                c.push_back(matrix[i][2]);
            }
        }
        solve3(a, b, c);
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt" ,"w", stdout);
    #endif
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}