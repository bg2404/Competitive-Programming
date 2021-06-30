#include <bits/stdc++.h>

using namespace std;

vector<long long> a;
vector<long long> c;
vector<vector<long long> > p;

pair<long long, long long> operator+(pair<long long, long long> a, pair<long long, long long> b) {
    return {a.first + b.first, a.second + b.second};
}

pair<long long, long long> buyGold(long long v, long long& w) {
    for (long long i = 19; i >= 0; --i) {
        if (a[p[v][i]] > 0) {
            v = p[v][i];
        }
    }
    long long cost, gold;
    if (a[v] > w) {
        cost = c[v] * w;
        gold = w;
        a[v] -= w;
        w = 0;
    } else {
        cost = c[v] * a[v];
        gold = a[v];
        w -= a[v];
        a[v] = 0;
    }
    return {gold, cost};
}

int main() {
    long long q;
    cin >> q;
    a.resize(q + 1, 0);
    c.resize(q + 1, 0);
    p.resize(q + 1, vector<long long>(20, 0));
    cin >> a[0] >> c[0];
    long long t, v, w;
    for (long long i = 1; i <= q; ++i) {
        cin >> t;
        if (t == 1) {
            cin >> p[i][0] >> a[i] >> c[i];
            for (long long j = 1; j < 20; ++j) {
                p[i][j] = p[p[i][j - 1]][j - 1];
            }
        } else {
            cin >> v >> w;
            pair<long long, long long> ans = {0, 0};
            while (a[v] > 0 && w > 0) {
                ans = ans + buyGold(v, w);
            }
            cout << ans.first << ' ' << ans.second << endl;
        }
    }
    return 0;
}