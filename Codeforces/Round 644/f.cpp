#include<bits/stdc++.h>

using namespace std;

bool isPossible(const string &a, const vector<string> &b) {
    for(int i = 0; i < b.size(); ++i) {
        int cnt = 0;
        for(int j = 0; j < a.size(); ++j) {
            if(a[j] != b[i][j]) {
                ++cnt;
            }
        }
        if(cnt > 1) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    string ans;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ans = a[0];
    if(isPossible(ans, a)) {
        cout << ans << '\n';
        return;
    }
    for(int i = 0; i < m; ++i) {
        for(int j = 1; j < n; ++j) {
            ans[i] = a[j][i];
            if(isPossible(ans, a)) {
                cout << ans << '\n';
                return;
            }
        }
        ans = a[0];
    }
    cout << -1 << '\n';
}

int main() {
    int t;
    cin >> t;

    while(t--){
        solve();
    }
    return 0;
}