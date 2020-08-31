#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, k, l;
    cin >> n >> k >> l;
    vector<int> d(n), tin(n+1), tout(n+1);
    tin[0] = -k;
    tout[0] = k;
    for(int i = 0; i < n; ++i) {
        cin >> d[i];
        if(d[i] > l) {
            cout << "No\n";
            return;
        }
        tout[i+1] = min(k, l - d[i]);
        tin[i+1] = -tout[i];
    }
    for(int i = 1; i <= n; ++i) {
        if(tout[i] != k) {
            tin[i] = max(tin[i-1] + 1, tin[i]);
        }
        if(tin[i] > tout[i]) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}