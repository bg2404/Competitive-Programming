#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int ans = n*(m/2) + (m&1)*(n/2 + (n&1));
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}