#include <bits/stdc++.h>

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

int main() {
    int n;
    cin >> n;
    vector<vector<double> > a(n, vector<double>(n));
    for (auto &r : a) {
        for (auto &e : r) {
            cin >> e;
        }
    }
    int MAX = (1 << n);
    vector<double> dp(MAX, 0), prev(MAX, 0);
    prev[MAX - 1] = 1;
    int total;
    for (int i = 1; i < n; ++i) {
        total = ((n - i) * (n - i + 1)) / 2;
        for (int j = 0; j < MAX; ++j) {
            if (prev[j] > 0) {
                for (int x = 0, mx = 1; mx < j; ++x, mx <<= 1) {
                    if (mx & j) {
                        for (int y = x + 1, my = (mx << 1); my < j; ++y, my <<= 1) {
                            if (my & j) {
                                dp[j ^ my] += prev[j] * a[x][y] / total;
                                dp[j ^ mx] += prev[j] * a[y][x] / total;
                            }
                        }
                    }
                }
            }
        }
        prev = dp;
        dp.assign(MAX, 0);
    }
    for (int i = 1; i < MAX; i <<= 1) {
        cout << setprecision(9) << prev[i] << ' ';
    }
    cout << endl;
}