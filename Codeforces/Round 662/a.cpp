#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    cout << n / 2 + 1 << '\n';
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