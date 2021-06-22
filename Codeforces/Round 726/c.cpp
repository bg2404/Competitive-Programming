#include <bits/stdc++.h>

using namespace std;

template <typename T>
ostream &operator<<(ostream &os, vector<T> &v) {
    os << "[ ";
    for (T e : v) {
        os << e << " ";
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
        vector<int> h(n);
        for (int &i : h) {
            cin >> i;
        }
        sort(h.begin(), h.end());
        if (n == 2) {
            cout << h[0] << ' ' << h[1] << '\n';
        } else {
            int diff = h[1] - h[0], idx = 1;
            for (int i = 2; i < n; ++i) {
                if (h[i] - h[i - 1] < diff) {
                    diff = h[i] - h[i - 1];
                    idx = i;
                }
            }
            for (int i = idx; i < n; ++i) {
                cout << h[i] << ' ';
            }
            for (int i = 0; i < idx; ++i) {
                cout << h[i] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}