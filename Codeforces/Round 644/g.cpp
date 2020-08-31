#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if(n*a != m * b) {
        cout << "NO\n";
        return;
    }
    int shift;
    for(int i = 1; i < m; ++i) {
        if((n * i) % m == 0) {
            shift = i;
            break;
        }
    }
    int grid[n][m];
    memset(grid, 0, sizeof(grid));

    for(int i = 0, x = 0; i < n; ++i, x += shift) {
        for(int j = 0; j < a; ++j) {
            grid[i][(j+x)%m] = 1;
        }
    }
    cout << "YES\n";
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cout << grid[i][j];
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