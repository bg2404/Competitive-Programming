#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n), ans;
    for(auto &i: p) {
        cin >> i;
    }
    int pd = 0, nd = 0;
    for(int i = 1; i < n; ++i) {
        if(p[i] > p[i-1]) {
            nd = 1;
        } else {
            nd = -1;
        }
        if(nd != pd) {
            ans.push_back(p[i-1]);
            pd = nd;
        }
    }
    ans.push_back(p[n-1]);
    cout << ans.size() << '\n';
    for(auto i: ans) {
        cout << i << ' ';
    }
    cout << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}