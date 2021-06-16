#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m), t(n, 1000000000), train;
        for (int &i : a) {
            cin >> i;
        }
        for (int &i : b) {
            cin >> i;
        }
        t[0] = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == 1) {
                train.push_back(i);
            }
            if (!train.empty()) {
                t[i] = i - train.back();
            }
        }
        train.clear();
        for (int i = n - 1; i >= 0; --i) {
            if (a[i] == 2) {
                train.push_back(i);
            }
            if (!train.empty()) {
                t[i] = min(t[i], train.back() - i);
            }
        }
        for (int &i : t) {
            if (i > n) {
                i = -1;
            }
        }

        for (int i = 0; i < m; ++i) {
            cout << t[b[i] - 1] << ' ';
        }
        cout << endl;
    }
    return 0;
}