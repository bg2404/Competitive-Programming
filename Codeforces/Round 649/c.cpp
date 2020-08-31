#include<bits/stdc++.h>

using namespace std;

set<int> s, t;
void solve() {
    int n;
    cin >> n;
    for(int i = 0; i <= n; ++i) {
        s.insert(i);
    }
    vector<int> a(n), b(n, -1);
    set<int> A;
    for(int &i: a) {
        cin >> i;
    }
    for(int i = 1; i < n; ++i) {
        if(a[i] != a[i-1]) {
            b[i] = a[i-1];
            s.erase(b[i]);
        }
    }
    s.erase(a[n-1]);
    for(int i = 0; i < n; ++i) {
        if(b[i] == -1) {
            b[i] = *s.begin();
            s.erase(s.begin());
        }
    }
    vector<bool> check(n+2, false);
    int j = 0;
    for(int i = 0; i < n; ++i) {
        check[b[i]] = true;
        while(j <= n && check[j]) {
            ++j;
        }
        if(a[i] == j) {
            check[j] = true;
        } else {
            cout << j << ' ';
            for(int i = 0; i <= n; ++i) {
                cout << check[i] << ' ';
            }

            cout << -1 << '\n';
            return;
        }
        cout << "!";
    }
    for(int i = 0; i < n; ++i) {
        cout << b[i] << ' ';
    }
    cout << '\n';
}

int main() {
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}