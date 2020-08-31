#include<bits/stdc++.h>

using namespace std;

void solve() {
    int h, c, t;
    cin >> h >> c >> t;
    if(h + c >= 2*t) {
        cout << 2 << '\n';
        return;
    }
    long long c1 = 2, c2 = (h-c)/(2*t-h-c);
    if(c2 % 2 == 0) {
        --c2;
    }
    long long c3 = c2 + 2;
    long long d1 = abs(c2*c3*(2*t - h - c));
    long long d2 = abs(c3*(2*c2*t - (c2+1)*h - (c2-1)*c));
    long long d3 = abs(c2*(2*c3*t - (c3+1)*h - (c3-1)*c));
    long long ans = 2, d = d1;
    if(d2 < d || (d2 == d && c2 < ans)) {
        ans = c2;
        d = d2;
    }
    if(d3 < d || (d3 == d && c3 < ans)) {
        ans = c3;
        d = d3;
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