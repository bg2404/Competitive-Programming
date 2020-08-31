#include<bits/stdc++.h>
#define int long long

using namespace std;

int32_t main() {
    int u, v;
    cin >> u >> v;
    if(u > v) {
        cout << -1 << '\n';
    } else {
        
        int d = v - u;
        if(v == u) {
            if(v == 0) {
                cout << 0 << '\n';
                return 0;
            }
            cout << 1 << '\n' << v << '\n';
            return 0;
        }
        if(d & 1) {
            cout << -1 << '\n';
            return 0;
        }
        int x = d / 2;
        int y = x^u, z = x|u;

        if(y == z) {
            cout << 2 << '\n' << x << ' ' << y << '\n';
        } else {
            cout << 3 << '\n' << x << ' ' << x << ' ' << u << '\n';
        }
    }
    return 0;
}