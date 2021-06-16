#include <bits/stdc++.h>

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
    for (T e : v) {
        os << e << ' ';
    }
    return os;
}

int left(int x) {
    return 2 * x + 1;
}

int right(int x) {
    return 2 * x + 2;
}

int main() {
    int k, n;
    cin >> k;
    string s;
    cin >> s;
    n = s.length();
    reverse(s.begin(), s.end());
    vector<int> a(n, 0);
    for (int i = n - 1; i >= 0; --i) {
        if (left(i) >= n) {
            if (s[i] == '?') {
                a[i] = 2;
            } else {
                a[i] = 1;
            }
        } else {
            if (s[i] != '1') {
                a[i] += a[right(i)];
            }
            if (s[i] != '0') {
                a[i] += a[left(i)];
            }
        }
    }

    int q;
    cin >> q;
    // cout << a << endl;
    while (q--) {
        int p;
        char c;
        cin >> p >> c;
        p = n - p;
        s[p] = c;
        do {
            if (left(p) >= n) {
                if (s[p] == '?') {
                    a[p] = 2;
                } else {
                    a[p] = 1;
                }
            } else {
                a[p] = 0;
                if (s[p] != '1') {
                    a[p] += a[right(p)];
                }
                if (s[p] != '0') {
                    a[p] += a[left(p)];
                }
            }
            p = (p - 1) / 2;
        } while (p > 0);
        if (left(0) >= n) {
            if (s[0] == '?') {
                a[0] = 2;
            } else {
                a[0] = 1;
            }
        } else {
            a[0] = 0;
            if (s[0] != '1') {
                a[0] += a[right(0)];
            }
            if (s[0] != '0') {
                a[0] += a[left(0)];
            }
        }
        // cout << a << endl;
        cout << a[0] << endl;
    }
    return 0;
}