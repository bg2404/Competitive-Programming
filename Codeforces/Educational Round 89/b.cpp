#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, x;
    cin >> n >> x >> m;
    set<int> s;
    s.insert(x);
    int l = x, r = x;
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        if(max(l, a) <= min(r, b)) {
            l = min(l, a);
            r = max(r, b);
        }
    }
    cout << r - l + 1 << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}