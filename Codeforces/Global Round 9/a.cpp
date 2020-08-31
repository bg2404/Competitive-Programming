#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] = abs(a[i]) * pow(-1, i & 1);
    }
    for(int x: a) {
        cout << x << ' ';
    }
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}