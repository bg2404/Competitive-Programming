#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        long long ans = 0;
        while (r > 0) {
            ans += r - l;
            r /= 10;
            l /= 10;
        }
        cout << ans << endl;
    }
}