#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

long long powerModP(int x, int n, int p = MOD) {
    if (n == 0) {
        return 1;
    }
    long long y = powerModP(x, n / 2, p);
    y = (y * y) % p;
    if (n & 1) {
        y = (y * x) % p;
    }
    return y;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        cout << powerModP((powerModP(2, n) - 1), m) << endl;
    }
    return 0;
}