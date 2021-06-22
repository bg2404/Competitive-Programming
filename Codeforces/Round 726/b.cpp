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

long long dist(long long x1, long long y1, long long x2, long long y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, m, i, j;
        cin >> n >> m >> i >> j;
        long long cx[4] = {1, 1, n, n};
        long long cy[4] = {1, m, 1, m};
        long long maxa = 0, maxb = 0, maxd = 0;
        for (int a = 0; a < 4; ++a) {
            for (int b = a; b < 4; ++b) {
                long long d = dist(cx[a], cy[a], cx[b], cy[b]) + dist(cx[a], cy[a], i, j) + dist(cx[b], cy[b], i, j);
                if (d > maxd) {
                    maxd = d;
                    maxa = a;
                    maxb = b;
                }
            }
        }
        cout << cx[maxa] << ' ' << cy[maxa] << ' ' << cx[maxb] << ' ' << cy[maxb] << endl;
    }
    return 0;
}