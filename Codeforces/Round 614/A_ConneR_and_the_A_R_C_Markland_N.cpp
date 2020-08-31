#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007

using namespace std;

int32_t main() {
    int T;
    cin >> T;
    while(T--) {
        int n, s, k;
        cin >> n >> s >> k;
        int c_floor;
        map<int,bool> closed;
        for(int i = 0; i < k; ++i) {
            cin >> c_floor;
            closed[c_floor] = true;
        }
        int ans = 0;
        bool flag;
        for(int i = 0, j = 0; !(s <= i && s+j > n); ++i, ++j) {
            flag = false;
            if(s > i) {
                if(closed[s-i]) {
                    flag = true;
                } else {
                    break;
                }
            }
            if(s + j <= n) {
                if(closed[s+j]) {
                    flag = true;
                } else {
                    break;
                }
            }
            if(flag) {
                ++ans;
            }
        }
        cout << ans << '\n';
        closed.clear();
        
    }
    return 0;
}