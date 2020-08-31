#include<bits/stdc++.h>
#define epsilon 0.0000001
using namespace std;

int timeRequired(int n, int x, int y, int m) {
    if(m > n || m < 0) {
        return 1000000007;
    }
    if(x*m > y*(n-m)) {
        return x*m;
    }
    return y*(n-m);
}

int solve(int n, int x, int y) {
    int l = 1, r = n, ans = x*n, m;
    while(l <= r) {
        m = l + r >> 1;
        int prev = timeRequired(n, x, y, m - 1);
        int cur  = timeRequired(n, x, y, m);
        int next = timeRequired(n, x, y, m + 1);
        if(prev >= cur && cur <= next) {
            return cur;
        } else if(prev >= cur && cur >= next) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return ans;
}

signed main() {
    int n, x, y;
    cin >> n >> x >> y;
    if(x > y) {
        swap(x, y);
    }
    cout << x + solve(n-1, x, y);
    return 0;
}