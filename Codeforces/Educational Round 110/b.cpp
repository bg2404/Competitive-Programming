#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, o = 0, ans = 0;
        cin >> n;
        vector<int> a;
        for (int i = 0, x; i < n; ++i) {
            cin >> x;
            if (x & 1) {
                ++o;
                a.push_back(x);
            }
        }
        for (int e = o; e < n; ++e) {
            ans += e;
        }
        n = a.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (gcd(a[i], a[j]) > 1) {
                    ++ans;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}