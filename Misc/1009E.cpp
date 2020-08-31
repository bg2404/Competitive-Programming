#include<bits/stdc++.h>
#define MOD 998244353

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &i: a) {
        cin >> i;
    }
    long long p = 1;
    long long ans = a[n-1];
    for(int i = 1; i < n; ++i) {
        long long x = ((i+2)*p)%MOD;
        ans += (x * a[n-1-i])%MOD;
        p <<= 1;
        ans %= MOD;
        p %= MOD;
    }
    cout << ans << '\n';
    return 0;
}