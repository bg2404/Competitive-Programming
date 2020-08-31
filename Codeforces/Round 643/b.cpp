#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, ans = 0;
    cin >> n;
    vector<int> e(n), c(n+1, 0);
    for(auto &i: e) {
        cin >> i;
        ++c[i];
    }
    for(int i = 1; i < n; ++i) {
        ans += c[i] / i;
        c[i+1] += c[i] % i;
    }
    ans += c[n] / n;
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