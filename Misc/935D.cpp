#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int powerModP(long long x, int n, int p = MOD) {
    long long ans = 1;
    while (n) {
        if (n & 1) {
            ans = (ans * x) % p;
        }
        x = (x * x) % p;
        n >>= 1;
    }
    return ans;
}

int f(int a, int b, int p = MOD) {
    return ((long long)a * powerModP(b, p - 2, p)) % p;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n), p(n + 1, 0);
    for (int &i : a) {
        cin >> i;
    }
    for (int &i : b) {
        cin >> i;
    }
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] == 0) {
            if (b[i] == 0) {
                p[i] = (f(m - 1, m << 1) + (long long)f(1, m) * p[i + 1]) % MOD;
            } else {
                p[i] = (f(m - b[i], m) + (long long)f(1, m) * p[i + 1]) % MOD;
            }
        } else {
            if (b[i] == 0) {
                p[i] = (f(a[i] - 1, m) + (long long)f(1, m) * p[i + 1]) % MOD;
            } else if (a[i] < b[i]) {
                p[i] = f(0, 1);
            } else if (a[i] > b[i]) {
                p[i] = f(1, 1);
            } else {
                p[i] = p[i + 1];
            }
        }
    }
    cout << p[0] << endl;
    return 0;
}