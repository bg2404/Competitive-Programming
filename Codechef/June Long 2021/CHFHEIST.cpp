#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long D, d, P, Q, n;
        cin >> D >> d >> P >> Q;
        n = D / d;
        cout << (((n * (2 * P + (n - 1) * Q)) / 2) * d) + ((D % d) * (P + n * Q)) << endl;
    }
    return 0;
}