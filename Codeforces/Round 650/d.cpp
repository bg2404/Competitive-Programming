#include<bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int m;
    cin >> m;
    vector<int> b(m);
    for(int &i: b) {
        cin >> i;
    }
    vector<int> alpha(26, 0);
    for(char c: s) {
        ++alpha[c-'a'];
    }
    string ans(m, ' ');
    for(int c = 25; c >= 0; --c) {
        if(alpha[c] == 0) continue;
        vector<int> v;
        alpha[c] = 0;
        for(int i = 0; i < m; ++i) {
            if(b[i] == 0) {
                v.push_back(i);
                b[i] = -1;
                ans[i] = c + 'a';
            }
        }
        for(int i = 0; i < m; ++i) {
            if(b[i] > 0) {
                for(int j = 0; j < v.size(); ++j) {
                    b[i] -= abs(i - v[j]);
                }
            }
        }
    }
    cout << ans << endl;
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        solve();
    }

    return 0;
}