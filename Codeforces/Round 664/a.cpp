#include<bits/stdc++.h>

using namespace std;

void solve() {
    int c[4], o = 0, e = 0;
    for(int i = 0; i < 4; ++i) {
        cin >> c[i];
        if(c[i]&1) {
            ++o;
        } else {
            ++e;
        }
    }
    if(o == 1 || o == 0) {
        cout << "Yes\n";
    } else if(o == 3 || o == 4) {
        if(c[0] && c[1] && c[2]) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    } else {
        cout << "No\n";
    }
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