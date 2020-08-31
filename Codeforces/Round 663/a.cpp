#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cout << i << ' ';
    }
    cout << '\n';
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt" ,"w", stdout);
    #endif
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}