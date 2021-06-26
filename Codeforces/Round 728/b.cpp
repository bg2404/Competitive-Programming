#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
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
        vector<int> a(n + 1);
        vector<int> m(n + n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            m[a[i]] = i;
        }
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            int min_sum = i + i + 1, max_sum = n + i;
            for (int j = ceil((1.0 * min_sum) / a[i]); j * a[i] <= max_sum; ++j) {
                if (m[j] + i == a[i] * j) {
                    ++ans;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}