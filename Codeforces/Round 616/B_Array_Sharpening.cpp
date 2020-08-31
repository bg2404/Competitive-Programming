#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007

using namespace std;

int32_t main() {
    int T = 1;
    cin >> T;
    while(T--){
        int n, inc = 1;
        cin >> n;
        int a[n];
        bool pos = true, dec = false;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        if(n > 0 && a[1] > 0) {
            a[0] = 0;
        }
        for(int i = 1; i < n; ++i) {
            if(a[i-1] >= a[i]) {
                if(a[i] >= i) {
                    continue;
                }
                inc = i;
                dec = true;
                break;
            }
            // cout << a[i] << ' ';
        }
        if(!dec) inc = n + 1;

        for(int i = inc; i < n; ++i) {
            if(a[i] >= a[i-1]) {
                a[i] = a[i-1]-1;
                if(a[i] < 0) {
                    pos = false;
                    break;
                }
            }
            // cout << a[i] << ' ';
        }
        if(pos) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}