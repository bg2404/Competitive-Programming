#include <bits/stdc++.h>
#define PDDD pair<double, pair<double, double> >
#define r first
#define s second.first
#define p second.second
using namespace std;

template <typename T, typename U, typename V>
ostream &operator<<(ostream &os, pair<T, pair<U, V> > &e) {
    os << '{' << e.r << ',' << e.s << ',' << e.p << '}';
    return os;
}

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
    int rock, scissors, paper;
    cin >> rock >> scissors >> paper;
    vector<vector<vector<PDDD> > > dp(rock + 1, vector<vector<PDDD> >(scissors + 1, vector<PDDD>(paper + 1, {0, {0, 0}})));
    for (int i = 1; i <= rock; ++i) {
        for (int j = 0; j <= scissors; ++j) {
            dp[i][j][0] = {1, {0, 0}};
        }
    }
    for (int j = 1; j <= scissors; ++j) {
        for (int k = 0; k <= paper; ++k) {
            dp[0][j][k] = {0, {1, 0}};
        }
    }
    for (int k = 1; k <= paper; ++k) {
        for (int i = 0; i <= rock; ++i) {
            dp[i][0][k] = {0, {0, 1}};
        }
    }
    for (int i = 1, t; i <= rock; ++i) {
        for (int j = 1; j <= scissors; ++j) {
            for (int k = 1; k <= paper; ++k) {
                t = i * j + j * k + k * i;
                dp[i][j][k].r = (i * j * dp[i][j - 1][k].r + j * k * dp[i][j][k - 1].r + k * i * dp[i - 1][j][k].r) / t;
                dp[i][j][k].s = (i * j * dp[i][j - 1][k].s + j * k * dp[i][j][k - 1].s + k * i * dp[i - 1][j][k].s) / t;
                dp[i][j][k].p = (i * j * dp[i][j - 1][k].p + j * k * dp[i][j][k - 1].p + k * i * dp[i - 1][j][k].p) / t;
            }
        }
    }
    PDDD ans = dp[rock][scissors][paper];
    cout << setprecision(12) << ans.r << ' ' << ans.s << ' ' << ans.p << endl;
    return 0;
}