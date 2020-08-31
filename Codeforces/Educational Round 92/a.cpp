#include<bits/stdc++.h>

using namespace std;

void solve() {
    int l, r;
    cin >> l >> r;
    if(r < l*2) {
        cout << -1 << ' ' << -1 << '\n';
        return;
    }
    cout << l << ' ' << l*2 << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}