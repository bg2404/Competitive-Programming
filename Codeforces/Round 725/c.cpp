#include <bits/stdc++.h>

using namespace std;

template <typename T>
ostream &operator<<(ostream &os, vector<T> &v) {
    os << "[ ";
    for (T e : v) {
        os << e << ' ';
    }
    os << ']';
    return os;
}

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
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> a(n);
        for (int &i : a) {
            cin >> i;
        }
        sort(a.begin(), a.end());
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            long long ajl = lower_bound(a.begin(), a.end(), l - a[i]) - a.begin();
            long long ajr = upper_bound(a.begin(), a.end(), r - a[i]) - a.begin();
            ans += max(0LL, ajr - max(ajl, i + 1LL));
            // cout << ajl << ' ' << ajr << '\n';
        }
        cout << ans << '\n';
    }
    return 0;
}