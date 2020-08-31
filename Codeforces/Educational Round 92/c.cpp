#include<bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> cnt(10, 0);
    vector<vector<int> > pos(10, vector<int> (n, -1));
    for(int i = 0; i < n; ++i) {
        ++cnt[s[i]-'0'];
    }
    for(int i = 0; i < 10; ++i) {
        for(int j = n-2; j >= 0; --j) {
            if(s[j+1] == (i+'0')) {
                pos[i][j] = j+1;
            } else {
                pos[i][j] = pos[i][j+1];
            }
        }
    }
    int ans = INT_MIN;
    for(int i = 0; i < 10; ++i) {
        ans = max(ans, cnt[i]);
    }
    for(int i = 0; i < 10; ++i) {
        for(int j = 0; j < 10; ++j) {
            int len = 0;
            char next = i;
            if(i != j) {
                if(s[0] == (next+'0')) {
                    ++len;
                    next = j;
                }
                int last = 0;
                while(pos[next][last] != -1) {
                    ++len;
                    last = pos[next][last];
                    if(next == i) {
                        next = j;
                    } else {
                        next = i;
                    }
                }
                len -= (len&1);
            }
            ans = max(ans, len);
        }
    }
    ans = n - ans;
    cout << ans << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}