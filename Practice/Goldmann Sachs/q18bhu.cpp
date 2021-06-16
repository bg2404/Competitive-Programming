#include<bits/stdc++.h>

using namespace std;

int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    int x, y;
    cin >> x >> y;
    int n = a.length(), m = b.length();
    vector<vector<int> > dp(n+1, vector<int>(m+1, 0)), dir;
    dir = dp;
    for(int i = 1; i <= n; ++i) {
        dp[i][0] = i*x;
        dir[i][0] = 1;
    }
    for(int j = 1; j <= m; ++j) {
        dp[0][j] = j*x;
        dir[0][j] = 2;
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            dp[i][j] = dp[i-1][j-1] + (y*(a[i-1] != b[j-1]));
            if(dp[i][j] > dp[i-1][j] + x) {
                dp[i][j] = dp[i-1][j] + x;
                dir[i][j] = 1;
            }
            if(dp[i][j] > dp[i][j-1] + x) {
                dp[i][j] = dp[i][j-1] + x;
                dir[i][j] = 2;
            }
        }
    }
    cout << dp[n][m] << '\n';
    string na = "" , nb = "";
    int i = n, j = m;
    while(i != 0 || j != 0) {
        if(dir[i][j] == 0) {
            --i;
            --j;
            na.push_back(a[i]);
            nb.push_back(b[j]);
        } else if(dir[i][j] == 1) {
            --i;
            na.push_back(a[i]);
            nb.push_back('_');
        } else {
            --j;
            na.push_back('_');
            nb.push_back(b[j]);
        }
    }
    reverse(na.begin(), na.end());
    reverse(nb.begin(), nb.end());
    cout << na << '\n' << nb << '\n';
    return 0;
}