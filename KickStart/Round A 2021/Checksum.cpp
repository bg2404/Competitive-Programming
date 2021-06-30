#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n;
        cin >> n;
        vector<vector<int> > a(n, vector<int>(n)), b(n, vector<int>(n));
        vector<int> r(n), c(n), v;
        int cnt = (n - 1) * (n - 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
                if (a[i][j] >= 0) {
                    --cnt;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> b[i][j];
                if (a[i][j] == -1) {
                    v.push_back(b[i][j]);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            cin >> r[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> c[i];
        }
        sort(v.begin(), v.end(), greater<int>());
        long long ans = 0;
        while (cnt-- > 0) {
            ans += v.back();
            v.pop_back();
        }
        cout << "Case #" << t << ": " << ans << '\n';
    }
    return 0;
}