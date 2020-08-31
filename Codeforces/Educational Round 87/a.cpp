#include<bits/stdc++.h>

using namespace std;

void solve() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    a -= b;
    if(a > 0) {
        if(c <= d) {
            cout << -1 << '\n';
        } else {
            d = c-d;
            long long ans = b + c*(long long)(ceil(double(a)/d));
            cout << ans << '\n';
        }
    } else {
        cout << b << '\n';
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