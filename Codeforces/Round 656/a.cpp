#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int x[3];
        cin >> x[0] >> x[1] >> x[2];
        sort(x, x + 3);
        if(x[2] != x[1]) {
            cout << "NO\n";
        } else {
            int a = x[1], b = x[0], c = x[0];
            cout << "YES\n" << a << ' ' << b << ' ' << c << '\n';
        }
    }
    return 0;
}