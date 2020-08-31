#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x: a) {
        cin >> x;
    }
    if(a[0] > a[n-1]) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
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