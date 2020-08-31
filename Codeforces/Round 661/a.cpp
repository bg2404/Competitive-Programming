#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &i: a) {
        cin >> i;
    }
    sort(a.begin(), a.end());
    for(int i = 1; i < n; ++i) {
        if(a[i] - a[i-1] > 1) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}