#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> b;
        int ans = 0;
        while (n > 1) {
            ans = (ans << 1) | 1;
            n >>= 1;
        }
        cout << ans << endl;
    }
    return 0;
}