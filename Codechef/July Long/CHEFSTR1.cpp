#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> s(n);
    for(auto &inp: s) {
        cin >> inp;
    }
    long long ans = 0;
    for(int i = 1; i < n; ++i) {
        ans += abs(s[i] - s[i-1]) - 1;
    }
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}