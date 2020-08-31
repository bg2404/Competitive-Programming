#include<bits/stdc++.h>

using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    int ans1 = min(max(a+a, b), max(b+b, a)), ans = min(ans1, a+b);
    cout << ans*ans << '\n';
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        solve();
    }
    return 0;
}