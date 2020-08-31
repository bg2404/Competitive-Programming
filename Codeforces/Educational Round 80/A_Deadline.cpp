#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main () {
    int T;
    cin >> T;
    while(T--) {
        int n, d;
        cin >> n >> d;
        bool flag = false;
        for(int i = 0; i*i <= d; ++i) {
            int x = i + ceil((float)d/(i+1));
            if(x <= n) {
                flag = true;
                break;
            }
        }
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}