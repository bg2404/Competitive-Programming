#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int &i: a) {
        cin >> i;
    }
    for(int &i: b) {
        cin >> i;
    }
    int am = *min_element(a.begin(), a.end()), bm = *min_element(b.begin(), b.end());
    // cout << am << ' ' << bm << ' ';
    long long ans = 0;
    for(int i = 0; i < n; ++i) {
        int ae = a[i] - am, be = b[i] - bm;
        ans = ans + min(ae, be);
        ans = ans + max(ae, be) - min(ae, be);
    }
    cout << ans << '\n';
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