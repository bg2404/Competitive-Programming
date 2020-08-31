#include<bits/stdc++.h>

using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    if(a > b) {
        swap(a, b);
    }
    int d = b - a, ans = 0;
    if(a > d) {
        ans += d;
        a -= d;
        b -= d;
        b -= d;
    } else {
        ans = a;
        a = b = 0;
    }

    ans += a/3 + a/3 + (a%3 == 2);
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