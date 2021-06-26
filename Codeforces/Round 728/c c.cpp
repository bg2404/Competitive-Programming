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

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

signed main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> d(n);
        for (int i = 0; i < n; ++i) {
            cin >> d[i];
        }
        sort(d.begin(), d.end());
        for (int i = n - 1; i > 0; --i) {
            d[i] = d[i] - d[i - 1];
        }
        long long ans = 0;
        long long temp = 0;
        for (int i = 1; i < n; ++i) {
            // cout << ans << ' ';
            temp += i * d[i];
            ans += d[i] - temp;
        }
        cout << ans << endl;
    }
    return 0;
}