#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n, c;
        cin >> n >> c;
        cout << "Case #" << t << ": ";
        if (c < n - 1 || c >= n * (n + 1) / 2) {
            cout << "IMPOSSIBLE" << '\n';
        } else {
            c -= n - 1;
            vector<int> l(n, -1);
            vector<int> r(n, 0);
            for (int i = 0; i < n; ++i) {
                if (c > (n - i - 1)) {
                    r[i] = n - i - 1;
                    c -= n - i - 1;
                } else if (c > 0) {
                    r[i] = c;
                    c = 0;
                } else {
                    break;
                }
            }
            l[n - 1] = n;
            for (int i = n - 2; i >= 0; --i) {
                l[i] = i + 1;
                reverse(l.begin() + i, l.begin() + i + r[i] + 1);
            }
            cout << l[0];
            for (int i = 1; i < n; ++i) {
                cout << ' ' << l[i];
            }
            cout << '\n';
        }
    }
    return 0;
}