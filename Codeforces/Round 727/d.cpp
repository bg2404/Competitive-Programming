#include <bits/stdc++.h>
#define PLL pair<long long, long long>
#define a first
#define b second

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

int main() {
    int n;
    cin >> n;
    vector<PLL> v(n);
    vector<long long> l;
    long long ans = 0, cnt = 0;
    for (auto &e : v) {
        cin >> e.a >> e.b;
    }
    sort(v.begin(), v.end(), [](PLL a, PLL b) {
        return a.b < b.b;
    });
    int i = 0;
    while (i < n) {
        if (v[i].b <= cnt) {
            ans += v[i].a;
            cnt += v[i].a;
            ++i;
        } else {
            long long d = v[i].b - cnt;
            if (d < v[n - 1].a) {
                ans += d * 2;
                cnt += d;
                v[n - 1].a -= d;
            } else {
                ans += v[n - 1].a * 2;
                cnt += v[n - 1].a;
                v.pop_back();
                --n;
            }
        }
    }
    cout << ans << endl;
    return 0;
}