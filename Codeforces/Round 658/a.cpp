#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, x;
    cin >> n >> m;
    vector<bool> a(1000, false);

    for(int i = 0; i < n; ++i) {
        cin >> x;
        a[x] = true;
    }
    int ans = -1;
    for(int i = 0; i < m; ++i) {
        cin >> x;
        if(a[x]) {
            ans = x;
        }
    }
    if(ans != -1) {
        cout << "YES\n" << 1 << ' ' << ans << '\n';
    } else {
        cout << "NO\n";
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