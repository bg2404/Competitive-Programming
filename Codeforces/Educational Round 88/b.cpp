#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<string> a(n);
    for(auto &s: a) {
        cin >> s;
    }
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(a[i][j] == '.') {
                int c = 0;
                while(a[i][j] == '.' && j < m) {
                    ++c;
                    ++j;
                }
                if(c & 1) {
                    ans += x;
                    if(2*x < y) {
                        ans += x*(c-1);
                    } else {
                        ans += y*(c/2);
                    }
                } else {
                    if(2*x < y) {
                        ans += x*(c);
                    } else {
                        ans += y*(c/2);
                    }
                }
            }
        }
    }
    cout << ans << '\n';
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}