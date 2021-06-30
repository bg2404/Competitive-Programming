#include<bits/stdc++.h>
#define int long long
using namespace std;

bool maxPossible(int w, int h, int n, int s) {
    int l = s / w, r = s / h;
    if((l >= n && r > 0) || (l > 0 && r >= n)) return true;
    return l * r >= n;
}

int solve(int w, int h, int n) {
    int ans = 1000000000000000000LL;
    int l = 1, r = ans, m;
    while(l <= r) {
        m = l + r >> 1;
        if(maxPossible(w, h, n, m)) {
            ans = min(ans, m);
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return ans;
}

signed main() {
    int w, h, n;
    cin >> w >> h >> n;
    cout << solve(w, h, n) << '\n';
    return 0;
}