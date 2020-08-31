#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string pg[n];
    for(int i = 0; i < n; ++i) {
        cin >> pg[i];
    }
    for(int i = n - 2; i >= 0; --i) {
        for(int j = n-2; j >= 0; --j) {
            if(pg[i][j] == '1') {
                if(pg[i+1][j] == '0' && pg[i][j+1] == '0') {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    cout << "YES\n";
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}