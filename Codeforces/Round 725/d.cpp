#include <bits/stdc++.h>

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

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    vector<int> primes;
    vector<bool> sieve(32000, true);
    for (int i = 2; i < 32000; ++i) {
        if (sieve[i]) {
            primes.push_back(i);
            for (int j = i + i; j < 32000; j += i) {
                sieve[j] = false;
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int a, b, k;
        cin >> a >> b >> k;
        if (k == 1) {
            int g = gcd(a, b);
            if ((g == a && g < b) || (g < a && g == b)) {
                cout << "YES\n";
            } else {
                cout << "NO \n";
            }
        } else {
            int f = 0;
            for (int i = 0; primes[i] * primes[i] <= a; ++i) {
                while (a % primes[i] == 0) {
                    a /= primes[i];
                    ++f;
                }
            }
            if (a > 1) {
                ++f;
            }
            for (int i = 0; primes[i] * primes[i] <= b; ++i) {
                while (b % primes[i] == 0) {
                    b /= primes[i];
                    ++f;
                }
            }
            if (b > 1) {
                ++f;
            }
            if (f >= k) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}