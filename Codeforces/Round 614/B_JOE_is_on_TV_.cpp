#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007

using namespace std;

int32_t main() {
    int T = 1;
    // cin >> T;
    while(T--) {
        int n;
        cin >> n;
        double ans = 0;
        for(int i = 1; i <= n; ++i ) {
            ans += (double)1/i;
        }
        printf("%.12f\n", ans);
    }
    return 0;
}