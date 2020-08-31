#include<bits/stdc++.h>

using namespace std;

void solve() {
    long long n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int &i: a) {
        cin >> i;
        i = x / i + (x % i != 0);
    }
    sort(a.begin(), a.end());
    int ans = 0;
    int i = 0, len = 1;
    while(i < n) {
        if(a[i] <= len) {
            ++ans;
            len = 1;
        } else {
            ++len;
        }
        ++i;
    }
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}