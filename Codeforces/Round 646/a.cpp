#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, x, o = 0, e = 0, s = 0;
    cin >> n >> x;
    vector<int> a(n);
    for(int &i: a) {
        cin >> i;
        s += i;
        i & 1 ? ++o: ++e;
    }
    if(x == n) {
        if(s & 1) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    } else if(o && e) {
        cout << "Yes\n";
    } else if(o) {
        if(x & 1) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    } else {
        cout << "No\n";
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