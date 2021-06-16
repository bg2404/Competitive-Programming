#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &i: a) {
        cin >> i;
    }
    vector<vector<int> > dp(n, vector<int> (n, 0));
    for(int i = 0; i < n; ++i) {
        for(int l = 0; l + i < n; ++l) {
            int r = l + i;
            if(r == l) {
                dp[l][r] = a[l]; 
            } else if(r == l + 1) {
                dp[l][r] = max(a[l], a[r]);
            } else {
                dp[l][r] = max(a[l] + min(dp[l+2][r], dp[l+1][r-1]), a[r] + min(dp[l+1][r-1], dp[l][r-2]));
            }
        }
    }
    cout << dp[0][n-1] << '\n';
    return 0;
}