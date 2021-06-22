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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int maxl = max_element(a.begin(), a.end()) - a.begin();
        int minl = min_element(a.begin(), a.end()) - a.begin();
        int maxr = n - 1 - maxl;
        int minr = n - 1 - minl;
        int ans = min(2 + min(maxl, minl) + min(maxr, minr), 1 + min(max(maxl, minl), max(maxr, minr)));
        cout << ans << '\n';
    }
    return 0;
}