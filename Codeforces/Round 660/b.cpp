#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int cont = n / 4 + (n%4 != 0);
    int l = n - cont;
    for(int i = 0; i < l; ++i) {
        cout << 9;
    }
    for(int i = 0; i < cont; ++i) {
        cout << 8;
    }
    cout << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}