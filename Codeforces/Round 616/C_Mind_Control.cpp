#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007

using namespace std;

int32_t main() {
    int T = 1;
    cin >> T;
    while(T--){
        int n, m, k;
        cin >> n >> m >> k;
        int a[n];
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int z = min(m-1,k);
        int ans = -1, temp;
        for(int x = 0; x <= z; ++x) {
            temp = 10000000000;
            for(int y = 0; y < m - z; ++y) {
                temp = min(temp, max(a[x+y], a[n-m+y+x]));
            }
            ans = max(ans, temp);
        }
        cout << ans << '\n';
    }
}