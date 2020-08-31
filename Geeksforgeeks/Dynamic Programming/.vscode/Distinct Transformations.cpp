#include<bits/stdc++.h>

using namespace std;


int solve(string a, string b) {
    int n = a.size();
    int m = b.size();
    int dp[n+1][m+1];
    
    for(int i = 0; i <= n; ++i) {
        dp[i][0] = 1;
        for(int j = 1; j <= m; ++j) {
            dp[i][j] = 0;
        }
    }
    
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m && j <= i; ++j) {
            dp[i][j] = dp[i-1][j];
            if(a[i-1] == b[j-1]) {
                dp[i][j] += dp[i-1][j-1];
            }
            // cout << dp[i][j] << ' ';
        }
        // cout << endl;
    }
    
    return dp[n][m];
}

int main()
 {
	int T;
	cin >> T;
	while(T--) {
	    string a, b;
	    cin >> a >> b;
	    cout << solve(a,b) << '\n';
	}
	return 0;
}