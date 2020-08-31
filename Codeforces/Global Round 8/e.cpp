#include<bits/stdc++.h>

using namespace std;

void solve() {
    long long a, b, n;
    cin >> a >> b >> n;
    if(a < b) {
        swap(a, b);
    }
    int ans = 0;
    int i = 0;
    while(a <= n && b <= n) {
        if(i & 1) {
            a += b;
        } else {
            b += a;
        }
        ++ans;
        ++i;
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}