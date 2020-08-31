#include<bits/stdc++.h>
#define MOD 1000000007

using namespace std;

void solve() {
    int n;
    cin >> n;
    long long ans = n, rem = 1;
    for(int i = 1; i < n; ++i) {
        ans = (ans * i) % MOD;
        rem = (rem * 2) % MOD;
    }
    ans = (ans - rem + MOD) % MOD;
    cout << ans << '\n';
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