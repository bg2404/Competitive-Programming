#include <bits/stdc++.h>

using namespace std;

bool solve(long long x, long long y, long long a, long long b, long long n) {
    if (a == b) {
        return n * a <= x && n * b <= y;
    }
    long long r = floorl((x - (double)n * b) / (a - b));
    long long l = ceill(((double)n * a - y) / (a - b));
    return max(0LL, l) <= min(n, r);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        if (a < b) {
            swap(a, b);
        }
        int l = 0, r = x, m;
        while (l <= r) {
            m = (l + r) / 2;
            if (solve(x, y, a, b, m)) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        cout << r << endl;
    }
    return 0;
}