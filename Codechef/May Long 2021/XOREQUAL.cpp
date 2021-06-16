#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int powModP(int x, int n, int p = MOD) {
    int y = 1;
    while (n > 0) {
        if (n & 1) {
            y = ((long long)y * x) % p;
        }
        x = ((long long)x * x) % p;
        n >>= 1;
    }
    return y;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        cout << powModP(2, N - 1) << endl;
    }
    return 0;
}