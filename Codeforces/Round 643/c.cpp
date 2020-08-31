#include<bits/stdc++.h>

using  namespace std;

void solve() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    long long ans = 0;
    for(int x = a; x <= b; ++x) {
        // cout << x <<": ";
        long long l = x+b, r = x + c;
        // cout << "(" << l << ", " << r << ") ";
        if(r <= c) {
            ans += 0;
        } else if(r <= d) {
            if(l <= c) {
                l = c;
                ans += (r-l+1)*(r-l)/2;
            } else {
                ans += (r-c+1)*(r-c)/2 - (l-c-1)*(l-c)/2;
            }
        } else if(l <= d) {
            l = max(l, c);
            ans += (d-c+1)*(d-c)/2-(l-c)*(l-c-1)/2;
            ans += (r-d)*(d-c+1);
        } else {
            ans += (d-c+1)*(r-l+1);
        }
        // cout << ans << '\n';
    }
    cout << ans << '\n';
}

int main() {
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}