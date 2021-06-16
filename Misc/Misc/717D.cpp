#include <bits/stdc++.h>

using namespace std;

template <typename T>
using Matrix = vector<vector<T> >;

template <typename T>
Matrix<T> operator*(Matrix<T> &a, Matrix<T> &b) {
    int m = a.size();
    assert(m > 0);
    int n = a[0].size();
    assert(n == b.size());
    assert(n > 0);
    int o = b[0].size();
    assert(o > 0);
    Matrix<T> c(m, vector<T>(o, 0));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < o; ++j) {
            for (int k = 0; k < n; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

template <typename T>
Matrix<T> power(Matrix<T> &a, int p) {
    int n = a.size();
    assert(n > 0);
    assert(n == a[0].size());
    Matrix<T> b(n, vector<T>(n, 0));
    for (int i = 0; i < n; ++i) {
        b[i][i] = 1;
    }
    while (p) {
        if (p & 1) {
            b = b * a;
        }
        a = a * a;
        p >>= 1;
    }
    return b;
}

int main() {
    int n, x;
    cin >> n >> x;
    int s = 1;
    while (s <= x) {
        s <<= 1;
    }
    vector<double> p(s, 0.0);
    for (int i = 0; i <= x; ++i) {
        cin >> p[i];
    }
    Matrix<double> M(x + 1, vector<double>(x + 1, 0.0));
    for (int i = 0; i <= x; ++i) {
        for (int j = 0; j <= x; ++j) {
            M[i][j] = p[i ^ j];
        }
    }
    M = power(M, n);
    cout << setprecision(9) << 1 - M[0][0] << endl;
    return 0;
}