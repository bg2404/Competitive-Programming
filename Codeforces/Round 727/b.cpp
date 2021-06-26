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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> v(1, 0);
    v.reserve(n + 1);
    for (char c : s) {
        v.push_back(c - 'a' + 1);
    }
    for (int i = 1; i <= n; ++i) {
        v[i] += v[i - 1];
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << v[r] - v[l - 1] << endl;
    }

    return 0;
}