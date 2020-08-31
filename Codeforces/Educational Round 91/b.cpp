#include<bits/stdc++.h>

using namespace std;

void solve() {
    string S;
    cin >> S;
    int n = S.length();
    int r = 0, p = 0, s = 0;
    for(int i = 0; i < n; ++i) {
        if(S[i] == 'R') {
            ++r;
        } else if(S[i] == 'S') {
            ++s;
        } else {
            ++p;
        }
    }
    char ans;
    if(r > p) {
        if(r > s) {
            ans = 'P';
        } else {
            ans = 'R';
        }
    } else if(p > s) {
        ans = 'S';
    } else {
        ans = 'R';
    }
    string ret(n, ans);
    cout << ret << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}