#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for(int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        if(grid[i].back() == 'R') {
            ++ans;
        }
    }
    for(int i = 0; i < m; ++i) {
        if(grid.back()[i] == 'D') {
            ++ans;
        }
    }
    cout << ans << '\n';
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt" ,"w", stdout);
    #endif
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}