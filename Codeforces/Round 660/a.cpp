#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    if(n <= 30) {
        cout << "NO\n";
        return;
    }
    int a = 6, b = 10, c = 14, d = n - a - b - c;
    if(d == a) {
        d = 5;
        c = 15;
    } else if(d == b) {
        d = 9;
        c = 15;
    } else if(d == c) {
        d = 13;
        c = 15;
    }
    cout << "YES\n";
    cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}