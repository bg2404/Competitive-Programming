#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), cnt(n+1, 0);
    for(int &i: a) {
        cin >> i;
        ++cnt[i];
    }
    int mx = *max_element(cnt.begin(), cnt.end());
    int sum = 0;
    int ans = 0;
    for(int c: cnt) {
        if(c == mx) {
            ++ans;
            n -= c;
        }
    }
    cout << n/(mx-1)+ans-1 << "\n";
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}