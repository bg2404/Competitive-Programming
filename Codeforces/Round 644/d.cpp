#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> factors;
    for(int i = 1; i*i <= n; ++i) {
        if(n % i == 0) {
            // cout << "#";
            factors.push_back(i);
            if(i != n / i) {
                // cout << "$";
                factors.push_back(n / i);
            }
        }
        // cout << "@";
    }
    int ans = n;
    for(int i = 0; i < factors.size(); ++i) {
        if(factors[i] <= k) {
            // cout << "%";
            ans = min(ans, n / factors[i]);
        }
        // cout << "!";
    }
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}