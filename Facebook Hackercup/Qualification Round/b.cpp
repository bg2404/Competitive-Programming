#include<bits/stdc++.h>

using namespace std;

void solve(int T) {
    int n;
    cin >> n;
    string s;
    int a = 0, b = 0;
    cin >> s;
    for(char c: s) {
        if(c == 'A') {
            ++a;
        } else {
            ++b;
        }
    }
    string ans = "N";
    if(abs(a - b) == 1) {
        ans = 'Y';
    }
    cout << "Case #" << T << ": ";
    cout << ans << '\n';
}

int main() {
    freopen("b.txt", "r", stdin);
    freopen("bout.txt", "w", stdout);
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        solve(i);
    }
    return 0;
}