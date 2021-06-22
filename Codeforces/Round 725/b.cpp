#include <bits/stdc++.h>

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
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, total = 0;
        cin >> n;
        vector<int> a(n);
        for (int &i : a) {
            cin >> i;
            total += i;
        }
        if (total % n == 0) {
            int indi = total / n, cnt = 0;
            for (int i : a) {
                if (i > indi) {
                    ++cnt;
                }
            }
            cout << cnt << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}