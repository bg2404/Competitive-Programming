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
        int ans = 0;
        int rem = 0;
        while(n > 0) {
            rem = n % 10;
            n -= rem;
            if(n == 0) {
                ans += rem;
                n = 0;
                break;
            } else {
                ans += n;
                n /= 10;
                n += rem;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}