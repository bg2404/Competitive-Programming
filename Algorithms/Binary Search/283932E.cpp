#include<bits/stdc++.h>
#define epsilon 0.0000001
using namespace std;

double func(double x) {
    return x*x + sqrt(x);
}

double solve(double c) {
    double l = 0, r = sqrt(c), m, cur;
    while(l + epsilon <= r) {
        m = (l + r) / 2;
        cur = func(m);
        if(cur > c) {
            r = m - epsilon;
        } else {
            l = m + epsilon;
        }
    }
    return m;
}

signed main() {
    double c;
    cin >> c;
    cout << setprecision(10) << solve(c);
    return 0;
}