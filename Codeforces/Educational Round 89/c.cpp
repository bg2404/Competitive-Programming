#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > a(n, vector<int> (m));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    vector<vector<int> > num(n + m - 1, vector<int>());
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            num[(i+j >= (n + m - 1)/2 ? n + m - 2 - i - j: i + j)].push_back(a[i][j]);
        }
    }
    int cnt = 0;
    for(int i = 0; i < n + m - 1; ++i) {
        if(i + i == n + m - 2) {
            continue;
        }
        map<int, int> m;
        for(auto j: num[i]) {
            m[j]++;
        }
        int ma = 0;
        for(auto [k, v]: m) {
            ma = max(ma, v);
        }
        cnt += num[i].size() - ma;
    }
    cout << cnt << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}