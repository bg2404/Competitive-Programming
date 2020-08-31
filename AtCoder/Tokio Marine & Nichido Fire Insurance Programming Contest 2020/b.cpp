#include<bits/stdc++.h>

using namespace std;

int main() {
    long long a, b, v, w, t, d, da, db;
    cin >> a >> v >> b >> w >> t;

    d = abs(a - b);
    da = v*t;
    db = w*t;
    if(da >= db + d || d == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}