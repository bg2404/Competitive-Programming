#include<bits/stdc++.h>

using namespace std;

void solve() {
    string s, p, ans = "";
    cin >> s >> p;
    vector<int> cnt(26, 0);
    for(char c: s) {
        ++cnt[c - 'a'];
    }
    for(char c: p) {
        --cnt[c - 'a'];
    }
    int i;
    int fc = p[0] - 'a';
    for(i = 0; i < fc; ++i) {
        for(int j = 0; j < cnt[i]; ++j) {
            ans.push_back(i+'a');
        }
    }
    {
        int nneci = 0;
        while(nneci < p.length() && p[0] == p[nneci]) ++nneci;
        if(nneci < p.length()) {
            if(p[nneci] > p[0]) {
                for(int j = 0; j < cnt[i]; ++j) {
                    ans.push_back(i + 'a');
                }
                ++i;
            }
        }
        ans = ans + p;
    }
    for(; i < 26; ++i) {
        for(int j = 0; j < cnt[i]; ++j) {
            ans.push_back(i+'a');
        }
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