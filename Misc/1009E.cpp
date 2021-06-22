#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n+1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<long long> pow2(n, 1);
    for(int i = 1; i < n; ++i) {
        pow2[i] = (pow2[i-1]<<1) % MOD;
    }
    long long ans = 0;
    for(int i = 1; i < n; ++i) {
        ans = (ans + a[i] * ((pow2[n-i-1] * (n-i))%MOD)) % MOD;
    }
    for(int i = 1; i <= n; ++i) {
        ans = (ans +  a[i] * pow2[n-i]) % MOD;
    }

    cout << ans << endl;

    return 0;
}