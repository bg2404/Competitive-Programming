#include<bits/stdc++.h>

using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    if(n > k * (k-1)) {
        cout << "NO" << '\n';
        return 0;
    }
    vector<int> b(n), g(n);
    int x = 0, d = 0;
    for(int i = 0; i < n; ++i) {
        if(x == 0) {
            ++d;
        }
        b[i] = ++x;
        g[i] = b[i] + d;
        if(g[i] > k) {
            g[i] -= k;
        }
        x %= k;
    }
    cout << "YES" << '\n';
    for(int i = 0; i < n; ++i) {
        cout << b[i] << ' ' << g[i] << '\n';
    }
    return 0;
}