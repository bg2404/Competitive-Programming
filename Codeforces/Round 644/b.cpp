#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int s[n];
    for(int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    sort(s, s+n);
    int d = s[n-1] - s[0];
    for(int i = 1; i < n; ++i) {
        d = min(d, s[i] - s[i-1]);
    }
    cout << d << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}