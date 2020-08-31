//https://cses.fi/problemset/task/1071

#include<bits/stdc++.h>

using namespace std;

int main() {
    long long t, y, x, d, r;
    cin >> t;
    while(t--) {
        cin >> y >> x;
        r = max(y, x);
        if(r & 1) {
            d = y - 1 + r - x;
        } else {
            d = r - y + x - 1;
        }
        cout << r*r - d << '\n';
    }
    return 0;
}