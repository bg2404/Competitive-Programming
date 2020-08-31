#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n+1] = {0};
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n + 1);
    int ans = 1;
    for(int i = n; i >= 0; --i) {
        if(a[i] <= i) {
            ans = i + 1;
            break;
        }
    }
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}