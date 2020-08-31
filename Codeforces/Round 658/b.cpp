#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        if(a[i] != 1) {
            b.push_back(a[i]);
        } else {
            int cnt = 0;
            while(i < n && a[i] == 1) {
                ++i;
                ++cnt;
            }
            --i;
            if(cnt & 1) {
                b.push_back(1);
                ++ans;
            }
        }
    }
    // for(int i = 0; i < b.size(); ++i) {
    //     cout << b[i] << ' ';
    // }
    if(b.size() == 0) {
        cout << "Second\n";
        return;
    }if(b.size() == 1) {
        cout << "First\n";
        return;
    }
    if(b[0] == 1) {
        cout << "Second\n";
    } else {
        cout << "First\n";
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