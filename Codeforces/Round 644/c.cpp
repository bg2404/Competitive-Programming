#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n], o = 0, e = 0;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] & 1 ? ++o: ++e;
    }
    if(!(o & 1)) {
        cout << "YES\n";
        return;
    }
    sort(a, a + n);
    for(int i = 1; i < n; ++i) {
        if(a[i] == a[i-1] + 1) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
    return;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}