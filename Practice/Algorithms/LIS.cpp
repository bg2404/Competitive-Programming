#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, maxIdx = 0;
    cin >> n;
    vector<int> a(n), dp(n, 1), prev(n, -1);
    for(int &i: a) {
        cin >> i;
    }
    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            if(a[j] < a[i]) {
                if(dp[i] <= dp[j]) {
                    prev[i] = j;
                    dp[i] = dp[j] + 1;
                }
            }
        }
        if(dp[maxIdx] < dp[i]) {
            maxIdx = i;
        }
    }
    cout << dp[maxIdx] << '\n';
    while(maxIdx >= 0) {
        cout << a[maxIdx] << ' ';
        maxIdx = prev[maxIdx];
    }
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}