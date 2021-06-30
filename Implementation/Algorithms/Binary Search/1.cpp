// Problem : Compute x^n % p

#include <bits/stdc++.h>

using namespace std;

int powModP(long long x, long long n, int p) {
    x = x % p;
    long long y = 1;
    while (n > 0) {
        if (n & 1) {
            y = y * x % p;
        }
        x = x * x % p;
        n >>= 1;
    }
    return y;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        long long x, n, p;
        cin >> x >> n >> p;
        cout << powModP(x, n, p) << endl;
    }
    return 0;
}