#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, cnt = 0, p0 = 0, a = 0, b = 0;
        cin >> n;
        string s;
        cin >> s;
        for (int i = 0, j = n - 1; i < n; ++i, --j) {
            if (s[i] == '0') {
                if (s[i] == s[j]) {
                    ++cnt;
                } else {
                    ++b;
                }
            }
        }
        if (b == 0) {
            if (cnt > 1 && (cnt & 1)) {
                cout << "ALICE\n";
            } else {
                cout << "BOB\n";
            }
        } else {
            if (!(cnt & 1) || b > 2) {
                cout << "ALICE\n";
            } else if (b == 2) {
                cout << "ALICE\n";
            } else {
                if (cnt == 1) {
                    cout << "DRAW\n";
                } else {
                    cout << "ALICE\n";
                }
            }
        }
    }
    return 0;
}