#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

template <typename T>
ostream &operator<<(ostream &os, vector<T> &v) {
    cout << "[ ";
    for (T e : v) {
        cout << e << ' ';
    }
    cout << ']';
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
        bool is_sorted = true;
        int mi = a[0], ma = a[0];
        for (int i = 1; i < n; ++i) {
            if (a[i] < a[i - 1]) {
                is_sorted = false;
            }
            mi = min(mi, a[i]);
            ma = max(ma, a[i]);
        }
        if (is_sorted) {
            cout << 0;
        } else if (mi == a[0] || ma == a[n - 1]) {
            cout << 1;
        } else if (mi != a[n - 1] || ma != a[0]) {
            cout << 2;
        } else {
            cout << 3;
        }
        cout << endl;
    }
    return 0;
}