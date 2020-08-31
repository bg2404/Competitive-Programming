#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007

using namespace std;

int32_t main() {
    int T = 1;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int o[2], j = 0;
        for(int i = 0; i < n; ++i) {
            if(((s[i]-'0')&1)) {
                o[j++] = s[i]-'0';
            }
            if(j == 2){
                break;
            }
        }
        if(j == 2) {
            cout << o[0] << o[1] << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}