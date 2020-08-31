#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    vector<pair<int, int> > ab(n);
    for(int i = 0; i < n; ++i) {
        cin >> ab[i].first;
    }
    for(int i = 0; i < n; ++i) {
        cin >> ab[i].second;
        if(ab[i].second == -1) {
            ab[i].second = n;
        } else {
            --ab[i].second;
        }
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