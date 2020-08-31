#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    set<int> x, y;
    for(int i = 1; i < 4*n; ++i) {
        int a, b;
        cin >> a >> b;
        if(x.count(a)) {
            x.erase(a);
        } else {
            x.insert(a);
        }
        if(y.count(b)) {
            y.erase(b);
        } else {
            y.insert(b);
        }
    }
    cout << *x.begin() << ' ' << *y.begin() << '\n';
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}