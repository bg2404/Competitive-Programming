#include<bits/stdc++.h>
#define MOD 1000000007
#define int long long 

using namespace std;

int32_t main() {
    int T = 1;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        int a[n];
        int o = 0, e = 0;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            if(a[i] & 1) ++o;
            else ++e;
        }
        if((e > 0 && o > 0) || (o > 0 && (o&1))) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}