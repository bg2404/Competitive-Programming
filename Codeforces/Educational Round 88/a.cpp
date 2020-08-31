#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int x = n / k, y;
    if(x >= m) {
        y = 0;
        x = m;
    } else {
        m -= x;
        y = (m+k-2)/(k-1);
    }
    cout << x - y << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}