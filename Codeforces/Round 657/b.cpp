#include<bits/stdc++.h>

using namespace std;

void solve() {
    long long l, r, m, b, c;
    cin >> l >> r >> m;
    long long x = m;
    for(int a = l; a <= r; ++a) {
        long long n = m / a;
        long long rem = m % a;
        long long re_ = a - rem;
        if(rem <= r-l && n > 0) {
            cout << a << ' ' << l + rem << ' ' << l << '\n';
            return;
        } else if(re_ <= r-l && n >= 0) {
            cout << a << ' ' << r - re_ << ' ' << r << '\n';
            return;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}