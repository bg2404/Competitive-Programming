#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, cnt = 0;
        cin >> n;
        string s;
        cin >> s;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                ++cnt;
            }
        }
        if (cnt > 1 && (cnt & 1)) {
            cout << "ALICE\n";
        } else {
            cout << "BOB\n";
        }
    }
    return 0;
}