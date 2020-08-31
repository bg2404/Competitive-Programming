#include<bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int &i: a) {
        cin >> i;
    }
    for(int &i: b) {
        cin >> i;
    }
    set<int> s[n];
    vector<int> temp;
    for(int j = 0; j < m; ++j) {
        temp.push_back(j);
    }
    for(int i = 0; i < n; ++i) {
        s[i] = set<int> (temp.begin(), temp.end());
    }
    int ans = 0;
    vector<vector<int> > isZero(n, vector<int>(m));
    for(int x = 8; x >= 0; --x) {
        int mask = 1 << x;
        vector<int> zp(n, 0);
        bool flag = true;
        vector<int> tb;
        for(int i = 0; i < n; ++i) {
            for(int j: s[i]) {
                tb.push_back(j);
                if((a[i] & b[j] & mask) == 0) {
                    isZero[i][j] = 1;
                    zp[i] = 1;
                } else {
                    isZero[i][j] = 0;
                }
            }
            if(!zp[i]) {
                flag = false;
            }
        }
        if(flag) {
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < tb.size(); ++j) {
                    if(!isZero[i][tb[j]]) {
                        if(s[i].find(tb[j]) != s[i].end()) {
                            s[i].erase(tb[j]);
                        }
                    }
                }
            }
        } else {
            ans = ans | mask;
        }
    }
    cout << ans << '\n';
    return 0;
}