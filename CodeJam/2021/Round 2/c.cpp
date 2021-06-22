#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

unsigned long long power(unsigned long long x, long long y, long long p) {
    unsigned long long res = 1;
    x = x % p;

    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;

        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

unsigned long long modInverse(unsigned long long n, long long p) {
    return power(n, p - 2, p);
}

unsigned long long nCrModP(unsigned long long n, long long r, long long p) {
    if (n < r)
        return 0;
    if (r == 0)
        return 1;

    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (long long i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;

    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}

long long solve(vector<long long> &v, long long l, long long r, long long n) {
    long long x;
    for (x = r; x >= l; --x) {
        if (v[x] == 1) {
            break;
        }
    }
    if (x < l) {
        return 0;
    }
    long long left = 1, right = 1;
    if (x > l) {
        left = solve(v, l, x - 1, x - l);
        if (left == 0) {
            return 0;
        }
    }
    if (x < r) {
        for (long long i = r; i > x; --i) {
            --v[i];
            if (v[i] < 0) {
                return 0;
            }
        }
        right = solve(v, x + 1, r, r - x);
        if (right == 0) {
            return 0;
        }
    }
    return (((left * right) % MOD) * nCrModP(n - 1, x - l, MOD)) % MOD;
}

int main() {
    long long totalNumberOfCases;
    cin >> totalNumberOfCases;
    for (long long caseNumber = 1; caseNumber <= totalNumberOfCases; ++caseNumber) {
        long long n;
        cin >> n;
        vector<long long> v(n);
        for (long long i = 0; i < n; ++i) {
            cin >> v[i];
        }
        cout << "Case #" << caseNumber << ": " << solve(v, 0, n - 1, n) << endl;
    }
    return 0;
}