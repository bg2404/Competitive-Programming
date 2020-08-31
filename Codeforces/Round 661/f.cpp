#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, l, r;
    cin >> n;
    vector<pair<int, int> > segments;
    for(int i = 0; i < n; ++i) {
        cin >> l >> r;
        segments.push_back({l, r});
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}