#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for(int &i: p) {
        cin >> i;
    }
    for(int i = 1; i +1 < n; ++i) {
        if(p[i] > p[i-1] && p[i] > p[i+1]) {
            cout << "YES\n" << i << ' ' << i+1 << ' ' << i+2 << '\n';
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}