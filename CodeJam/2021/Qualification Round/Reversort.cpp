#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n;
        cin >> n;
        vector<int> l(n);
        for (int i = 0; i < n; ++i) {
            cin >> l[i];
        }
        int ans = 0;
        for (int i = 0; i + 1 < n; ++i) {
            int j = min_element(l.begin() + i, l.end()) - l.begin();
            ans += j - i + 1;
            reverse(l.begin() + i, l.begin() + j + 1);
        }
        cout << "Case #" << t << ": " << ans << '\n';
    }
    return 0;
}