#include <bits/stdc++.h>

using namespace std;

struct node {
    int v;
    int x;
    int y;
    bool operator<(const node &o) const {
        return v < o.v;
    }
};

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int r, c;
        cin >> r >> c;
        vector<node> v;
        v.reserve(r * c);
        vector<vector<int> > grid(r, vector<int>(c)), mex(r, vector<int>(c, 0));
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> grid[i][j];
                v.push_back({grid[i][j], i, j});
            }
        }
        sort(v.begin(), v.end());
        while (!v.empty()) {
            int i = v.back().x;
            int j = v.back().y;
            v.pop_back();
            int value = max(grid[i][j], mex[i][j]);
            //vertical
            for (int k = 0; k < r; ++k) {
                mex[k][j] = max(mex[k][j], value - abs(i - k));
            }
            //horizontal
            for (int k = 0; k < c; ++k) {
                mex[i][k] = max(mex[i][k], value - abs(j - k));
            }
        }
        long long ans = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (mex[i][j] > grid[i][j]) {
                    ans += mex[i][j] - grid[i][j];
                }
            }
        }
        cout << "Case #" << t << ": " << ans << '\n';
    }
    return 0;
}