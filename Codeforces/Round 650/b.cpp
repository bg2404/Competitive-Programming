#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, j;
    cin >> n;
    int o = 0, e = 0;
    for(int i = 0; i < n; ++i) {
        cin >> j;
        if((i&1) != (j&1)) {
            if(j & 1) {
                ++o;
            } else {
                ++e;
            }
        }
    }
    if(o != e) {
        cout << -1 << endl;
    } else {
        cout << o << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}