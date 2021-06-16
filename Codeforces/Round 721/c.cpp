#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, pos = 0, x;
        cin >> n;
        vector<vector<int>> a;
        map<int, int> m;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            if (m.find(x) == m.end()) {
                a.push_back({i});
                m.insert(make_pair(x, pos++));
            } else {
                a[m[x]].push_back(i);
            }
        }
        long long ans = 0;
        for (auto r : a) {
            long long right = 0;
            for (int i = r.size() - 1; i >= 0; --i) {
                ans += right * (r[i] + 1);
                right += n - r[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}