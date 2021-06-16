#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

template <typename T>
T gcd(T a, T b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string a;
        cin >> a;
        vector<int> l, r;
        for (int i = 0; i < n; ++i) {
            if (a[i] == '0') {
                if (l.size() == r.size()) {
                    l.push_back(i);
                }
            } else {
                if (l.size() > r.size()) {
                    r.push_back(i - 1);
                }
            }
        }
        if (l.size() > r.size()) {
            r.push_back(n - 1);
        }
        for (int i = 0; i < l.size(); ++i) {
            if (l[i] == 0) {
                --l[i];
            }
            if (r[i] == n - 1) {
                ++r[i];
            }
            if (l[i] > 0 || r[i] < n - 1) {
                for (int j = 0, x = l[i], y = r[i]; j < m && x < y; ++j) {
                    if (x > 0) {
                        a[x++] = '1';
                    }
                    if (y < n - 1) {
                        a[y--] = '1';
                    }
                }
            }
        }
        cout << a << endl;
    }
    return 0;
}