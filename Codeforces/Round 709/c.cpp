#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > f(m);
        vector<pair<int, int> > cnt(m);
        for (int i = 0; i < m; ++i) {
            int k;
            cin >> k;
            f[i].resize(k);
            for (int j = 0; j < k; ++j) {
                cin >> f[i][j];
                --f[i][j];
            }
            cnt[i] = make_pair(k, i);
        }
        int threshold = (m + 1) / 2;
        vector<int> call(n, 0);
        vector<int> ans(m);
        sort(cnt.begin(), cnt.end());
        for (int i = 0; i < m; ++i) {
            int d = cnt[i].second;
            int k = f[d].size();
            // cout << d << ":" << k << ' ';
            int mf = f[d][0];
            for (int j = 1; j < k; ++j) {
                // cout << "(" << f[d][j] << ":" << call[f[d][j]] << ", " << mf << ":" << call[mf] << ") ";
                if (call[f[d][j]] < call[mf]) {
                    mf = f[d][j];
                }
            }
            ++call[mf];
            ans[d] = mf + 1;
        }
        bool pos = true;
        for (int i = 0; i < n; ++i) {
            if (call[i] > threshold) {
                pos = false;
                break;
            }
        }
        // cout << '\n';
        // for (int i = 0; i < n; ++i) {
            // cout << call[i] << ' ';
        // }
        // cout << '\n';
        if (pos) {
            cout << "YES\n";
            for (int i = 0; i < m; ++i) {
                cout << ans[i] << ' ';
            }
            cout << '\n';
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}