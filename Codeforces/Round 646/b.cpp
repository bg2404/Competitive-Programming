#include<bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    vector<int> pz(s.size(), 0), po(s.size(), 0), so(s.size(), 0), sz(s.size(), 0);
    pz[0] = s[0] == '0';
    po[0] = s[0] == '1';
    for(int i = 1; i < s.length(); ++i) {
        pz[i] = pz[i-1];
        po[i] = po[i-1];
        s[i] == '0' ? ++pz[i]: ++po[i];
    }
    sz[s.length()-1] = s[s.length()-1] == '0';
    so[s.length()-1] = s[s.length()-1] == '1';
    for(int i = s.length()-2; i >= 0; --i) {
        sz[i] = sz[i+1];
        so[i] = so[i+1];
        s[i] == '0' ? ++sz[i]: ++so[i];
    }
    // cout << '\n' << '\n' << s << '\n';
    // for(int i = 0; i < s.length(); ++i) {
    //     cout << pz[i] << ' ';
    // }
    // cout << '\n';
    // for(int i = 0; i < s.length(); ++i) {
    //     cout << po[i] << ' ';
    // }
    // cout << '\n';
    // for(int i = 0; i < s.length(); ++i) {
    //     cout << sz[i] << ' ';
    // }
    // cout << '\n';
    // for(int i = 0; i < s.length(); ++i) {
    //     cout << so[i] << ' ';
    // }
    // cout << '\n';
    int ans = (min(so[0], sz[0]), min(po[s.length()-1], pz[s.length()-1]));
    for(int i = 0; i < s.length()-1; ++i) {
        ans = min(ans, (pz[i] + so[i+1]));
        ans = min(ans, (po[i] + sz[i+1]));
    }
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}