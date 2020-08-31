#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n<<1);
    for(int &i: p) {
        cin >> i;
    }
    vector<int> a(1, 0);
    int cnt = 0, len = p.size();
    while(len) {
        auto me = max_element(p.begin(), p.begin() + len);
        a.push_back(len - (int)(me - p.begin()));
        len = me - p.begin();
    }
    // for(auto i: a) {
    //     cout << i << ' ';
    // }
    // cout << '\n';
    vector<vector<bool> > dp(a.size(), vector<bool> (n+1, false));
    dp[0][0] = true;
    for(int i = 1; i < a.size(); ++i) {
        // cout << "(" << i << ", " << a[i] << ") ";
        for(int j = 0; j <= n; ++j) {
            dp[i][j] = dp[i-1][j];
            if(j >= a[i]) {
                dp[i][j] = dp[i][j] | dp[i-1][j-a[i]];
            }
            // cout << dp[i][j] << ' ';
        }
        // cout << '\n';
    }
    if(dp[a.size()-1][n]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}