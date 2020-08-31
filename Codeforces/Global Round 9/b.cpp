#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > a(n, vector<int>(m));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            int mp = 2 + (i > 0 && i < n-1) + (j > 0 && j < m-1);
            if(a[i][j] > mp) {
                cout << "NO\n";
                // for(int i = 0; i < n; ++i) {
                //     for(int j = 0; j < m; ++j) {
                //         cout << a[i][j] << ' ';
                //     }
                //     cout << '\n';
                // }
                // cout << '\n';
                return;
            }
            a[i][j] = mp;
        }
    }
    cout << "YES\n";
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
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