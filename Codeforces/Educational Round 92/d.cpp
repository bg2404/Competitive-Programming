#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k, l1, l2, r1, r2;
    cin >> n >> k >> l1 >> r1 >> l2 >> r2;
    if(l1 > l2) {
        swap(l1, l2);
        swap(r1, r2);
    }
    int lin = l2, rin = min(r1, r2);
    int inlen = 0, rem_len;
    if(lin < rin) {
        inlen = rin - lin;
    }
    long long I = inlen*n;
    if(I >= k) {
        cout << 0 << '\n';
        return;
    }
    int d = 0;
    if(I == 0) {
        d = l2-r1;
        l2 = r1;
    }
    rem_len = r2-l2+r1-l1-inlen*2;
    int ans = LLONG_MAX;
    for(int i = 1; i <= n; ++i) {
        int temp = i*d + min(i*rem_len, k-I) + max(k - i*rem_len - I, 0LL)*2;
        ans = min(ans, temp);
    }
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}