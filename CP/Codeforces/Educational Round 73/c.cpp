#include<bits/stdc++.h>

using namespace std;

int main() {
    int q;
    cin >> q;
    while(q--) {
        int c, m, x;
        cin >> c >> m >> x;
        int min_cm = min(c, m);
        if(min_cm <= x) {
            cout << min_cm << '\n';
            continue;
        } else {
            int teams = x;
            c -= x; m -= x; min_cm -= x;
            int max_cm = max(c,m);
            int z = max_cm - min_cm;
            if(min_cm <= z) {
                teams += min_cm;
            } else {
                teams += z;
                min_cm -= z;
                teams += (min_cm*2)/3;
            }
            cout << teams << '\n';
        }
    }
    return 0;
}