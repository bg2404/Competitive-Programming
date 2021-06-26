#include <bits/stdc++.h>
#define MOD 1000000007

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
    return b == 0 ? 0 : gcd(b, a % b);
}

int main() {
    int k;
    cin >> k;
    while (k--) {
        long long n, x, t;
        cin >> n >> x >> t;
        long long y = t / x, ans = y * n - (y * (y + 1)) / 2;
        if (n < y) {
            y -= n;
            ans += (y * (y + 1)) / 2;
        }
        cout << ans << endl;
    }
    return 0;
}