#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007

using namespace std;

int32_t main() {
    int t;
    cin >> t;
    while(t--) {
        int n, g, b;
        cin >> n >> g >> b;
        int days = 0;
        int req = ceil(((double)n)/2);
        int num_g = 0, numg_b = 0;
        int cycles = req / g;
        days = cycles * (g+b);
        num_g = cycles*g;
        if(num_g == req) {
            days -= b;
            if(days < n) {
                days = n;
            }
        } else {
            days += (req - num_g);
            if(days < n) {
                days = n;
            }
        }
        cout << days << '\n';
    }
    return 0;
}