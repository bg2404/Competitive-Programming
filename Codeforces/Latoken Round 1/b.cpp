#include <bits/stdc++.h>

using namespace std;

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (long long &i : a) {
            cin >> i;
        }
        if (n == 1) {
            cout << a[0] << endl;
        } else {
            long long ugly = 0;
            if (a[0] > a[1]) {
                ugly += a[0] - a[1];
                a[0] = a[1];
            }
            if (a[n - 1] > a[n - 2]) {
                ugly += a[n - 1] - a[n - 2];
                a[n - 1] = a[n - 2];
            }
            for (long long i = 1; i + 1 < n; ++i) {
                if (a[i] > max(a[i - 1], a[i + 1])) {
                    ugly += a[i] - max(a[i + 1], a[i - 1]);
                    a[i] = max(a[i - 1], a[i + 1]);
                }
            }
            long long prev = 0;
            for (long long i = 0; i < n; ++i) {
                if (a[i] > prev) {
                    ugly += a[i] - prev;
                }
                prev = a[i];
            }
            prev = 0;
            for (long long i = n - 1; i >= 0; --i) {
                if (a[i] > prev) {
                    ugly += a[i] - prev;
                }
                prev = a[i];
            }
            cout << ugly << endl;
        }
    }
    return 0;
}