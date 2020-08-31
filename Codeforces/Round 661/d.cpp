#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> z, o, a(n);
    int snum = 1;
    for(int i = 0; i < n; ++i) {
        if(s[i] == '0') {
            if(o.empty()) {
                a[i] = snum;
                z.push_back(snum++);
            } else {
                a[i] = o.back();
                z.push_back(o.back());
                o.pop_back();
            }
        } else {
            if(z.empty()) {
                a[i] = snum;
                o.push_back(snum++);
            } else {
                a[i] = z.back();
                o.push_back(z.back());
                z.pop_back();
            }
        }
    }
    cout << snum - 1 << '\n';
    for(int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
    cout << '\n';
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