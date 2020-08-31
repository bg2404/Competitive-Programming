#include<bits/stdc++.h>
#define MOD 1000000007
#define int long long
using namespace std;

int32_t main() {
    int L;
    cin >> L;
    string s;
    cin >> s;
    int ans  = 0;
    int f_a = 0, num_a = 0, num_b;
    for(int i = 0; i < L; ++i) {
        if(s[i] == 'b') {
            if(num_a > 0) {
                --num_a;
                ans += 2;
            }
        } else {
            ++num_a;
        }
    }
    ans = L - ans;
    // num_b = L - num_a - f_a;
    // int ans = f_a + max(num_a, num_b) - min(num_a, num_b);
    cout << ans << '\n';
    return 0;
}