#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007

using namespace std;

int32_t main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int i, cur;
        for(i = 0; i < s.size(); ++i) {
            if(s[i] == '1') {
                cur = i;
                break;
            }
        }
        int sum = 0;
        for(++i; i < s.size(); ++i) {
            if(s[i] == '1') {
                sum += (i-cur-1);
                cur = i;
            }
        }
        cout << sum << '\n';
    }
    return 0;
}