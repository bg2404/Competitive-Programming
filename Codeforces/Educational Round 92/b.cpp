#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, k, z, ans;
    cin >> n >> k >> z;
    vector<int> a(n), ps(n);
    for(int &i: a) {
        cin >> i;
    }
    vector<int> msp(k+1);
    msp[0] = -1;
    msp[1] = 1;
    ps[0] = a[0];
    ps[1] = a[0] + a[1];
    for(int i = 2; i <= k; ++i) {
        if(a[msp[i-1]-1] + a[msp[i-1]] < a[i-1] + a[i]) {
            msp[i] = i;
        } else {
            msp[i] = msp[i-1];
        }
        ps[i] = ps[i-1] + a[i];
    }
    ans = a[0];
    for(int i = k; i > 0; --i) {
        // cout << ans << ' ';
        int temp = ps[i];
        int rem = k - i, tz = z;
        if(rem > 2*z) {
            break;
        }
        if(rem) {
            if(rem & 1) {
                if(tz) {
                    temp += a[i-1];
                    --tz;
                }
                --rem;
            }

            temp += (a[msp[i]] + a[msp[i]-1])*(rem/2);
        }
        ans = max(ans, temp);
    }
    cout << ans << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}