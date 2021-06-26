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
    long long n, k, x;
    cin >> n >> k >> x;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<long long> e;
    int ans = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] - a[i - 1] > x) {
            ++ans;
            e.push_back((a[i] - a[i - 1] - 1) / x);
        }
    }
    sort(e.begin(), e.end());
    for (long long i : e) {
        if (i <= k) {
            --ans;
            k -= i;
        } else {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}