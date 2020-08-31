#include<bits/stdc++.h>

using namespace std;

map<int, int> cnt;
vector<int> a, pre;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    a.assign(n+1, 0);
    pre.assign(n+1, 0);
    for(int i = 0; i < n; ++i) {
        a[i+1] = s[i] - '1';
    }
    for(int i = 1; i <= n; ++i) {
        pre[i] = pre[i-1] + a[i];
    }
    long long ans = 0;
    cnt.clear();
    for(int i = 0; i <= n; ++i) {
        ans += cnt[pre[i]];
        ++cnt[pre[i]];
    }
    cout << ans << '\n';
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