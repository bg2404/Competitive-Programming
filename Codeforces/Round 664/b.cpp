#include<bits/stdc++.h>

using namespace std;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int n, m, sx, sy;
    cin >> n >> m >> sx >> sy;
    vector<vector<int> > grid(n, vector<int> (m, 0));
    int x = sx-1, y = sy-1;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(!grid[x][y]) {
                cout << x+1 << ' ' << y+1 << '\n';
                grid[x][y] = 1;
            }
            y = (y + 1) % m;
        }
        y = (y - 1 + m) % m;
        x = (x + 1) % n;
    }
    return 0;
}