#include<bits/stdc++.h>
#define mod 998244353

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m), smin(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for(int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    smin[n-1] = a[n-1];
    for(int i = n-2; i >= 0; --i) {
        smin[i] = min(smin[i+1], a[i]);
    }
    int j, i;
    long long ans = 1, cnt = 0;
    vector<bool> found(m, false);
    for(i = n-1, j = m - 1; i >= 0 && j >= 0; --i) {
        if(smin[i] == b[j]) {
            ++cnt;
            found[j] = true;
        } else if(smin[i] < b[j]) {
            ans *= cnt;
            ans %= mod;
            cnt = 0;
            --j;
            ++i;
        }
    }

    for(int k = 0; k < m; ++k) {
        if(!found[k]) {
            ans = 0;
        }
    }

    if(i >= 0) {
        ans = 0;
    }
    cout << ans << '\n';

    return 0;
}