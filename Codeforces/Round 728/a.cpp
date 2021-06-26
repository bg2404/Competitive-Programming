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
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = i + 1;
        }
        for (int i = 1; i < n; i += 2) {
            swap(a[i - 1], a[i]);
        }
        if (n & 1) {
            swap(a[n - 1], a[n - 2]);
        }
        for (int& i : a) {
            cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}