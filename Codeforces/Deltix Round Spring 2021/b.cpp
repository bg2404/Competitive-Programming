#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &i : a) {
            cin >> i;
        }
        cout << 3 * n << '\n';
        for (int i = 1; i < n; i += 2) {
            cout << 1 << ' ' << i << ' ' << i + 1 << '\n';
            cout << 2 << ' ' << i << ' ' << i + 1 << '\n';
            cout << 1 << ' ' << i << ' ' << i + 1 << '\n';
            cout << 1 << ' ' << i << ' ' << i + 1 << '\n';
            cout << 2 << ' ' << i << ' ' << i + 1 << '\n';
            cout << 1 << ' ' << i << ' ' << i + 1 << '\n';
        }
    }
    return 0;
}
