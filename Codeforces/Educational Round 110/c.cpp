#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        long long z = 0, o = 0, q = 0, ans = 0, n = s.length();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '?') {
                swap(o, z);
                ++q;
                ans += o + z + q;
            } else if (s[i] == '0') {
                z = 1 + o + q;
                o = q = 0;
                ans += z;
            } else {
                o = 1 + z + q;
                z = q = 0;
                ans += o;
            }
        }
        cout << ans << endl;
    }
    return 0;
}