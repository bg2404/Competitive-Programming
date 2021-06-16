#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

template <typename T>
using Point = pair<T, T>;

long long solve(vector<Point<long long>> &v) {
    long long n = v.size();
    sort(v.begin(), v.end());
    vector<long long> mie(n, v.back().y), mae(n, v.back().y);
    for (long long i = n - 2; i >= 0; --i) {
        mie[i] = min(mie[i + 1], v[i].y);
        mae[i] = max(mae[i + 1], v[i].y);
    }
    long long mib = 1000000000, mab = 0;
    long long ans = 1000000000000000000;
    for (long long i = 0; i <= n; ++i) {
        long long l, r;
        if (i == 0) {
            l = 0;
        } else {
            l = (mab - mib) * (v[i - 1].x - v[0].x);
        }
        if (i == n) {
            r = 0;
        } else {
            r = (mae[i] - mie[i]) * (v.back().x - v[i].x);
        }
        ans = min(ans, l + r);
        mib = min(mib, v[i].y);
        mab = max(mab, v[i].y);
    }
    return ans;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<Point<long long>> v(n);
        for (auto &[f, s] : v) {
            cin >> f >> s;
        }
        long long ans = solve(v);
        for (auto &[f, s] : v) {
            swap(f, s);
        }
        ans = min(ans, solve(v));
        cout << ans << endl;
    }
    return 0;
}