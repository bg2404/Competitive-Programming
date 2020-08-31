#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    bool pos = false;
    int s = 0;
    for(auto &i: a) {
        cin >> i;
        s += i;
        pos = pos || (i % x != 0);
    }
    if(!pos) {
        cout << -1 << '\n';
        return;
    }
    if(s % x != 0) {
        cout << n << '\n';
    } else {
        int l = 0, r = n-1;
        while(a[l] % x == 0) {
            ++l;
        }
        while(a[r] % x == 0) {
            --r;
        }
        cout << max(n - l - 1, r) << '\n';
    }

}

int main() {
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}