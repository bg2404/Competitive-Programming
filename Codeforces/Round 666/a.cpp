#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<string> a(n);
    for(auto &i: a) {
        cin >> i;
    }
    vector<int> cnt(26, 0);
    for(auto r: a) {
        for(auto c: r) {
            ++cnt[c-'a'];
        }
    }
    for(int i = 0; i < 26; ++i) {
        if(cnt[i] % n != 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}