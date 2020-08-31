#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &i: a) {
        cin >> i;
    }
    for(int i = 0; i + 1 < n; ++i) {
        int k = lower_bound(a.begin(), a.end(), a[i] + a[i+1]) - a.begin();
        if(k < n) {
            cout << i + 1 << ' ' << i + 2 << ' ' << k + 1 << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}