#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        long long m;
        cin >> m;
        vector<int> p;
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            while (b--) {
                p.push_back(a);
            }
        }
        long long ans = 0;
        int n = p.size();
        vector<int> b(n, 0);
        int x, y;
        long long s;
        // long long m;
        do {
            x = 0;
            y = 0;
            s = 0;
            m = 1;
            int c = 1;
            for (int i = 0; i < n; ++i) {
                if (b[i]) {
                    ++y;
                    m *= p[i];
                } else {
                    ++x;
                    s += p[i];
                }
                b[i] += c;
                c = b[i] == 2 ? 1 : 0;
                b[i] %= 2;
            }
            if (s == m) {
                ans = max(ans, s);
            }
        } while (x != 0);
        cout << "Case #" << t << ": " << ans << '\n';
    }
}