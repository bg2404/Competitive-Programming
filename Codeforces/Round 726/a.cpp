#include <bits/stdc++.h>

using namespace std;

template <typename T>
ostream &operator<<(ostream &os, vector<T> &v) {
    os << "[ ";
    for (T e : v) {
        os << e << " ";
    }
    os << ']';
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
        int n, a, s = 0;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a;
            s += a;
        }
        if (s < n) {
            cout << 1 << endl;
        } else {
            cout << s - n << endl;
        }
    }
    return 0;
}