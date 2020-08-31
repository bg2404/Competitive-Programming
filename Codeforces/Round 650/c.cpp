#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    string v(k, '0');
    if(n == k) {
        if(s == v) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
        return;
    }
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        if(s[i] == '1') {
            i += k;
        } else {
            bool one = false;
            int j;
            for(j = 1; j <= k && i + j < n; ++j) {
                if(s[i + j] == '1') {
                    one = true;
                    break;
                }
            }
            if(one) {
                i = i + j + k;
            } else {
                ++cnt;
                i += k;
            }
        }
    }
    cout << cnt << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}