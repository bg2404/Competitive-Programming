#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007

using namespace std;

bool ok(int x, int y, int t) {
    int _t = abs(t);
    int ans;
    if((x-y)%_t == 0) {
        ans = (x-y)/_t;
    } else {
        return false;
    }
    if(t < 0) {
        ans *= -1;
    }

    if(ans >= 0) {
        return true;
    }
    return false;
}

int32_t main() {
    int TestCase = 1;
    cin >> TestCase;
    while(TestCase--) {
        int n, x;
        cin >> n >> x;
        string s;
        cin >> s;
        int c[n+1];
        c[0] = {0};
        bool found = false;
        for(int i = 0; i < n; ++i) {
            c[i+1] = c[i];
            if(s[i] == '0') {
                c[i+1]++;
            } else {
                c[i+1]--;
            }
            if(c[i+1] == x) {
                found = true;
                break;
            }
        }
        if(c[n] == 0) {
            if(found) {
                cout << -1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        } else {
            int count = 0;
            for(int i = 1; i <= n; ++i) {
                if(ok(x, c[i], c[n])) {
                    // printf("(%lld,%lld) ", i, c[i]);
                    count++;
                }
            }
            if(x == 0) {
                count++;
            }
            cout << count << '\n';
        }
    }
    return 0;
}